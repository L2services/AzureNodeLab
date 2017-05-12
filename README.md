# Azure IoT Workshop: NodeMCU Lab

## Table of Contents
* [Activity Summary](#activity-summary)
* [Requirements](#requirements)
  * [Hardware](#hardware)
  * [Software](#software)
* [Software Installation](#software-installation)
  * [Install the Arduino IDE](#install-the-arduino-ide)
  * [Configure Arduino IDE for ESP8266](#configure-arduino-ide-for-esp8266)
  * [Configure Libraries](#configure-libraries)
* [Configure Azure Services](#configure-azure-services)
  * [Create Azure IoT Hub](#create-azure-iot-hub)
  * [Create Azure Stream Analytics](#create-azure-stream-analytics)
* [Configure PowerBI](#configure-powerbi)  
* [FAQ / Help](#faq)

## Activity Summary

In this lab, we'll walk through the basics of: 
* Creating and configuring an Azure IoT Hub
* Configuring a sample Arduino sketch to communicate with Azure IoT Hub
* Deploying the sketch to the NodeMCU device
* Monitoring the data received from the NodeMCU
* Visualizing and analyzing the IoT data in PowerBI

## Requirements
The following components are required to follow this lab in its entirety. If you have experience with prototyping boards and developing Arduino sketches, you can substitute many of the sensors and components in this guide and achieve the same general output. This is the power of Azure IoT Hub - device agnostic support through standards based protocols like AMQP, MQTT, and HTTPS. That being said, the lab is written for use with a specific set of devices and hardware and the supporting source code matches this hardware.

### Hardware

* [NodeMCU (v1.0)](http://amzn.to/2qTRR2F)
* [Grove Base Shield for NodeMCU](http://amzn.to/2qTtH7E) (or from [Mouser](http://www.mouser.com/ProductDetail/Seeed-Studio/105020008/))
* Sensors: 
  * [Temperature/Humidity Sensor](http://amzn.to/2psBJnC) (or from [Mouser](http://www.mouser.com/ProductDetail/Seeed-Studio/101020074/))
  * [Vibration Sensor](http://amzn.to/2qTDpqN) (or from [Mouser](http://www.mouser.com/ProductDetail/Seeed-Studio/101020054/))
  * [LED Multicolor](http://amzn.to/2qTHSdP) (or from [Mouser](http://www.mouser.com/ProductDetail/Seeed-Studio/104030014/))
  * [Button](http://amzn.to/2pZvedb) (or from [Mouser](http://www.mouser.com/ProductDetail/Seeed-Studio/101020003/))
  * [Grove cables](http://amzn.to/2pUQ2Es) (or from [Mouser](http://www.mouser.com/ProductDetail/Seeed-Studio/110990027))

### Software

* [Arduino IDE](https://www.arduino.cc/en/Main/Software)
  * [Windows Installer](https://downloads.arduino.cc/arduino-1.8.2-windows.exe)
  * [Windows Zip for non-admin install](https://downloads.arduino.cc/arduino-1.8.2-windows.zip)
  * [Windows Store](https://www.microsoft.com/en-us/store/p/arduino-ide/9nblggh4rsd8)
* ESP8266 Board Package (for Arduino IDE)
* CP210x Driver (if it's not already installed on your system)
* Azure Subscription
  * If you already have an Azure Organizational Account, you may use that for this lab.
  * If you don't already have an Azure Subscription, you can create a [free trial](https://azure.microsoft.com/en-us/free/)
    * $200 in credit at the time of writing. 
* Azure Device Explorer


## Software Installation

### Install the Arduino IDE
1. Download the [Windows Installer](https://downloads.arduino.cc/arduino-1.8.2-windows.exe)
1. Run the `arduino-1.8.2-windows.exe`  
1. Leave the default options selected to install the IDE and supporting drivers
![Installation Options](/images/software_install/arduino-windows_install_options.png)
1. Leave the default installation Destination Folder unchanged and select `Install`  <!--![Installation Folder](/images/software_install/arduino-windows_install_folder.png)-->
1. Wait for the installation to complete. Toward the end of the installation, you may be prompted to install several drivers. Select `Install` for each prompt.  
    * Adafruit Ports  
    * Arduino USB Driver (from Arduino srl)  
    * Arduino USB Driver (from Arduino LLC)  <!--![Arduino USB Driver LLC](/images/software_install/driver_arduino_llc.png)-->
1. Click `Close` to complete the Arduino IDE installation  
  <!--![First Driver](/images/software_install/arduino-windows_finish.png)-->

### Configure Arduino IDE for ESP8266
1. Open the Arduino IDE and click on `File` → `Preferences`  
![Arduino Desktop Icon](/images/software_configuration/Arduino_Desktop_Icon.png)  
![Arduino File Preferences](/images/software_configuration/Arduino_File_Preferences_Annotated.png)
1. Find the `Aditional Boards Manager URLs` and enter the following:
`http://arduino.esp8266.com/stable/package_esp8266com_index.json`  
**Note**: If you already use the Arduino IDE and already have a URL in this field, you can also click the small box to the right of the field to open a larger window to enter the ESP8266 package on a new line.
![Boards Manager URLs](/images/software_configuration/Arduino_Preference_BM.png)
1. Click `OK` to close the Preference Screen
1. Open the menu: `Tools` → `Board` → `Boards Manager`  
![Arduino File Preferences](/images/software_configuration/Arduino_Boards_Manager.png)  
**Note**: If this is your first time running the Boards Manager, you may have to wait a moment while it downloads the packages.
1. Type `ESP8266` in the search box at the top of the Boards Manager screen
1. Click the `esp8266` record to select the row then select `Install` to install the package.
![ESP8266 Package Installation](/images/software_configuration/Board_Manager_ESP8266.png)  
**Note**: The installation may take several minutes as the file is a large download. The version of the esp8266 package used in this lab is 2.3.0
1. Open the menu: `Tools` → `Board` and select `NodeMCU 1.0`  
![Select Board 1](/images/software_configuration/board_selection1.png)  
![Select Board 2](/images/software_configuration/board_selection2.png)  

Note: If any of the board configuration settings have been changed, be sure to change them back to the defaults documented below:
* Board: "NodeMCU 1.0 (ESP-12E Module)"
* CPU Frequency: "80 MHz"
* Flash Size: "4M (3M SPIFFS)"
* Upload Speed: "115200"
* Port: *{see Device Manager}*  

  ![Board Configuration](/images/board_configuration/board_configuration.png)


### Configure Libraries

1. Sketch → Include Library → Manage Libraries
1. Type `azure` in the filter box
1. Select each of the below libraries and choose install for each

   | Library                | Author         | Version |
   |------------------------|----------------|---------|
   | AzureIoTHub            | Arduino        | 1.0.30  |
   | AzureIoTProtocol_HTTP  | Microsoft      | 1.0.30  |
   | AzureIoTProtocol_MQTT  | Microsoft      | 1.0.30  |
   | AzureIoTUtility        | Microsoft      | 1.0.30  |
   | AzureIoTHubMQTTClient  | Andri Yadi     | 0.2.2   |
   | ArduinoJson            | Benoit Blanchon| 5.9.0   |
1. Download the following Libraries and manually add them by going to Sketch → Include Library → Add .Zip Library
    1. [Time](https://github.com/PaulStoffregen/Time)
    1. [Grove ADXL345 (Accelerometer)](https://github.com/Seeed-Studio/Accelerometer_ADXL345)

## Configure Azure Services
We will create Azure IoT Hub and Stream Analytics jobs in this step. 
   ### Create Azure IoT Hub
   1. Login to [Azure poral](https://portal.azure.com) 
   1. "+ New" from the left menu → search for "IoT Hub" → select "IoT Hub" → Create
   ![Creat AZ IoT Hub](/images/Azure_configuration/Create_IoTHub.png)
   1. Enter Name (alphanumeric character or '-' only)
   1. Select **F1 Free tier** in **Pricing and scale tier**
   1. Create a new Resource Group if you don't have one already, or select an existing group in the drop down
   1. Select **West Central US** in **Location**
   1. Create

   ### Register Deveice to Azure IoT Hub
   1. Once IoT Hub is deployed, copy the connection string info from Shared access policies → iothubowner → Connection string - Primary key.  
   ![Grant access to IoT Hub](/images/Azure_configuration/GrantAccess_IoTHub.png)
   1. Open Device Explorer that we installed on your laptop/computer earlier
   1. Pasted the connecstion string to the **IoT Hub Connection String** field in **Configuration** tab, and click **Update**. 
   ![Setting Device Explorer](/images/Azure_configuration/Setting_Device_Explorer.png)
   1. Create a new device. Management tab → Create → input a device name in the prompt → Create 
  ![Create New Device](/images/Azure_configuration/Create_Device.png)
   1. Copy the new device's ***ID***, ***PrimaryKey***, and the IoT Hub's host name information, and paste them in the Arduino code where ***IoTHub_HOSTNAME***, ***DEVICE_ID***, and ***DEVICE_KEY*** are declared
   ![Device Info in Code](/images/Azure_configuration/Device_Info_In_Code.png)
   1. Connect your NodeMCU device to your laptop/computer. Compile and Upload the code to the NodeMCU board by clicking on Upload button at left top.
   ![Upload code](/images/Azure_configuration/Upload_Code_To_Device.png)
   1. Review the output in Arduino IDE. Click Tools in Sketch → Serial Port Monitor and you should see it connects to Azure successfully.
   1. Go back to Device Explorer → Data tab → make sure Event Hub name is the IoT Hub we just created → select the new created device in **Device ID** field → click on Monitor
   1. Verify IoT Hub is receiving data like the screenshot below
  ![Receiving Data](/images/Azure_configuration/Receiving_IoT_Data.png)
  








      
   ### Create Azure Stream Analytics
  
## Configure PowerBI


## FAQ
* **Q: The text in my Serial Port Monitor is all boxes/squares, what should I do?**  
  A: Make sure to select the correct baud rate in the bottom-right corner of the Serial Port Monitor. For this lab, we are using `115200`.  
* **Q: I'm getting a `XYZ` error in my Serial Port Monitor, what should I do?**  
  A: Try closing reopening the Serial Port by selecting Tools → Port and then reselecting your desired port.  
* **Q: Are there other debugging steps I can take related to a failed WiFi connection?**  
  A: Set "Debug Port: Serial" and "Debug Level: Core" in the Arduino IDE Tools menu. Add `Serial.setDebugOutput(true);` after `Serial.begin(9600);`. This will print additional information from the WiFi stack which may provide hints as to what is going wrong.  
* **Q: How can I check if the WiFi connection is established before connecting?**  
  A: Use the following snippet:
  ```
  if (WiFi.status() != WL_CONNECTED) {
    WiFi.begin(ssid, password);
  }
  ```  
* **Q: I'm still having issues connecting to WiFi even after trying the above troubleshooting steps**  
  A: Try the following:
  ```
  WiFi.persistent(false);
  WiFi.mode(WIFI_OFF);   // this is a temporary line, to be removed after SDK update to 1.5.4
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  ```  
* **Q: This isn't working for me on `ESP-01`, `ESP-003`, or other alternative board - what can I do?**  
  A: Try adding the following snippet immediately before the `WiFi.begin(ssid, password);` line:
  ```
  WiFi.setOutputPower(0);
  ```  
* **Q: Can I set a fallback where the device will broadcast it's own Access Point?**  
  A: Check out the following snippet: [AP Fallback GitHub comment](https://github.com/esp8266/Arduino/issues/2186#issuecomment-260182998)