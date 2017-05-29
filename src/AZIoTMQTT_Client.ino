#include <math.h>
#include <ESP8266WiFi.h>
#include <Wire.h>
#include <ADXL345.h>

#include <WiFiClientSecure.h>
#include <AzureIoTHubMQTTClient.h>

/****************************************
 * Const var for Temp Sensor 
 ****************************************/
const int B = 4275;               // B value of the thermistor
const int R0 = 100000;            // R0 = 100k
const int pinTempSensor = A0;     // Grove - Temperature Sensor connect to A0

ADXL345 adxl; //variable adxl is an instance of the ADXL345 library

const char *AP_SSID = "L2demo";
const char *AP_PASS = "11111111";

// Azure IoT Hub Settings --> CHANGE THESE
#define IOTHUB_HOSTNAME         "jameslabiothub.azure-devices.net"
#define DEVICE_ID               "NodeMCU1"
#define DEVICE_KEY              "iNpN+lCGdjt2Ex/IfDBK7fcz+nJ0bxeDMF6KecejSm8=" //Primary key of the device

WiFiClientSecure tlsClient;
AzureIoTHubMQTTClient client(tlsClient, IOTHUB_HOSTNAME, DEVICE_ID, DEVICE_KEY);
WiFiEventHandler  e1, e2;


const int LED_PIN = 14; //Pin to turn on/off LED (C2D command from IoT Hub)
unsigned long lastMillis = 0;

void connectToIoTHub(); // <- predefine connectToIoTHub() for setup()
void onMessageCallback(const MQTT::Publish& msg);
void onSTAGotIP(WiFiEventStationModeGotIP ipInfo) {
    Serial.printf("Got IP: %s\r\n", ipInfo.ip.toString().c_str());

    //do connect upon WiFi connected
    connectToIoTHub();
}

void onSTADisconnected(WiFiEventStationModeDisconnected event_info) {
    Serial.printf("Disconnected from SSID: %s\n", event_info.ssid.c_str());
    Serial.printf("Reason: %d\n", event_info.reason);
}

void onClientEvent(const AzureIoTHubMQTTClient::AzureIoTHubMQTTClientEvent event) {
    if (event == AzureIoTHubMQTTClient::AzureIoTHubMQTTClientEventConnected) {

        Serial.println("Connected to Azure IoT Hub");

        //Add the callback to process cloud-to-device message/command
        client.onMessage(onMessageCallback);
    }
}

void onActivateRelayCommand(String cmdName, JsonVariant jsonValue) {

    //Parse cloud-to-device message JSON. In this example, I send the command message with following format:
    //{"Name":"ActivateRelay","Parameters":{"Activated":0}}

    JsonObject& jsonObject = jsonValue.as<JsonObject>();
    if (jsonObject.containsKey("Parameters")) {
        auto params = jsonValue["Parameters"];
        auto isAct = (params["Activated"]);
        if (isAct) {
            Serial.println("Activated true");
            digitalWrite(LED_PIN, HIGH); //visualize relay activation with the LED
        }
        else {
            Serial.println("Activated false");
            digitalWrite(LED_PIN, LOW);
        }
    }
}

void setup() {
  initSerial(); 
  delay(1000);
  initADXL();
  delay(1000);

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  Serial.print("Connecting to WiFi...");
  //Begin WiFi joining with provided Access Point name and password
  WiFi.begin(AP_SSID, AP_PASS);

  //Handle WiFi events
  e1 = WiFi.onStationModeGotIP(onSTAGotIP);// As soon WiFi is connected, start the Client
  e2 = WiFi.onStationModeDisconnected(onSTADisconnected);

  //Handle client events
  client.onEvent(onClientEvent);

  //Add command to handle and its handler
  //Command format is assumed like this: {"Name":"[COMMAND_NAME]","Parameters":[PARAMETERS_JSON_ARRAY]}
  client.onCloudCommand("ActivateRelay", onActivateRelayCommand);
}

void onMessageCallback(const MQTT::Publish& msg) {

    //Handle Cloud to Device message by yourself.

//    if (msg.payload_len() == 0) {
//        return;
//    }

//    Serial.println(msg.payload_string());
}

void connectToIoTHub() {

    Serial.print("\nBeginning Azure IoT Hub Client... ");
    if (client.begin()) {
        Serial.println("OK");
    } else {
        Serial.println("Could not connect to MQTT");
    }
}

void readTemp(float *temp) {

  int a = analogRead(pinTempSensor);

  float R = 1023.0/a-1.0;
  R = R0*R;

  float temperature = 1.0/(log(R/R0)/B+1/298.15)-273.15; // convert to temperature via datasheet
  *temp = temperature;
  
}


void loop() {
 
   //MUST CALL THIS in loop()
    client.run();

    if (client.connected()) {

        // Publish a message roughly every 3 second. Only after time is retrieved and set properly.
        if(millis() - lastMillis > 3000 && timeStatus() != timeNotSet) {
            lastMillis = millis();

            //Read the actual temperature from sensor
            float temp;            
            readTemp(&temp);

            //read the accelerometer values and store them in variables  x,y,z
            int x,y,z;  
            adxl.readXYZ(&x, &y, &z); 
  
            double xyz[3];
            double ax,ay,az;
            adxl.getAcceleration(xyz);
            ax = xyz[0];
            ay = xyz[1];
            az = xyz[2];
            
            //
            Serial.print("temperature = ");
            Serial.println(temp);
            Serial.print("values of X , Y , Z: ");
            Serial.print(x);
            Serial.print(" , ");
            Serial.print(y);
            Serial.print(" , ");
            Serial.println(z);
            Serial.print("X=");
            Serial.print(ax);
            Serial.println(" g");
            Serial.print("Y=");
            Serial.print(ay);
            Serial.println(" g");
            Serial.print("Z=");
            Serial.println(az);
            Serial.println(" g");
            Serial.println("**********************");
            delay(500);
  
            //Get current timestamp, using Time lib
            time_t currentTime = now();

            // You can do this to publish payload to IoT Hub
            /*
            String payload = "{\"DeviceId\":\"" + String(DEVICE_ID) + "\", \"MTemperature\":" + String(temp) + ", \"EventTime\":" + String(currentTime) + "}";
            Serial.println(payload);

            //client.publish(MQTT::Publish("devices/" + String(DEVICE_ID) + "/messages/events/", payload).set_qos(1));
            client.sendEvent(payload);
            */

            //Or instead, use this more convenient way
            AzureIoTHubMQTTClient::KeyValueMap keyVal = {{"Temperature", temp}, {"X", x}, {"Y", y},{"Z", z},{"AcceX", ax},{"AcceY", ay},{"AcceZ", az},{"DeviceId", DEVICE_ID}, {"EventTime", currentTime}};
            client.sendEventWithKeyVal(keyVal);
        }
    }
    else {

    }

    delay(10); // <- fixes some issues with WiFi stability
} 


void initSerial() {
    // Start serial and initialize stdout
    Serial.begin(115200);
    Serial.setDebugOutput(true);
}


void initADXL(){
  
  adxl.powerOn();

  //set activity/ inactivity thresholds (0-255)
  adxl.setActivityThreshold(75); //62.5mg per increment
  adxl.setInactivityThreshold(75); //62.5mg per increment
  adxl.setTimeInactivity(10); // how many seconds of no activity is inactive?
 
  //look of activity movement on this axes - 1 == on; 0 == off 
  adxl.setActivityX(1);
  adxl.setActivityY(1);
  adxl.setActivityZ(1);
 
  //look of inactivity movement on this axes - 1 == on; 0 == off
  adxl.setInactivityX(1);
  adxl.setInactivityY(1);
  adxl.setInactivityZ(1);
 
  //look of tap movement on this axes - 1 == on; 0 == off
  adxl.setTapDetectionOnX(0);
  adxl.setTapDetectionOnY(0);
  adxl.setTapDetectionOnZ(1);
 
  //set values for what is a tap, and what is a double tap (0-255)
  adxl.setTapThreshold(50); //62.5mg per increment
  adxl.setTapDuration(15); //625us per increment
  adxl.setDoubleTapLatency(80); //1.25ms per increment
  adxl.setDoubleTapWindow(200); //1.25ms per increment
 
  //set values for what is considered freefall (0-255)
  adxl.setFreeFallThreshold(7); //(5 - 9) recommended - 62.5mg per increment
  adxl.setFreeFallDuration(45); //(20 - 70) recommended - 5ms per increment
 
  //setting all interrupts to take place on int pin 1
  //I had issues with int pin 2, was unable to reset it
  adxl.setInterruptMapping( ADXL345_INT_SINGLE_TAP_BIT,   ADXL345_INT1_PIN );
  adxl.setInterruptMapping( ADXL345_INT_DOUBLE_TAP_BIT,   ADXL345_INT1_PIN );
  adxl.setInterruptMapping( ADXL345_INT_FREE_FALL_BIT,    ADXL345_INT1_PIN );
  adxl.setInterruptMapping( ADXL345_INT_ACTIVITY_BIT,     ADXL345_INT1_PIN );
  adxl.setInterruptMapping( ADXL345_INT_INACTIVITY_BIT,   ADXL345_INT1_PIN );
 
  //register interrupt actions - 1 == on; 0 == off  
  adxl.setInterrupt( ADXL345_INT_SINGLE_TAP_BIT, 1);
  adxl.setInterrupt( ADXL345_INT_DOUBLE_TAP_BIT, 1);
  adxl.setInterrupt( ADXL345_INT_FREE_FALL_BIT,  1);
  adxl.setInterrupt( ADXL345_INT_ACTIVITY_BIT,   1);
  adxl.setInterrupt( ADXL345_INT_INACTIVITY_BIT, 1);
}
