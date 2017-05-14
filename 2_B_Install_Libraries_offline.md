# Install Libraries (Offline)

In the previous lab, we acquired the Arduino IDE and installed Device Explorer. If you are following along online, you may have installed a copy of the the Arduino IDE to your computer and then configured the Board Manager to download the ESP8266 package. If you are following along in person and have been provided a flash drive, you'll find a copy of the Arduino IDE on the flash drive - be sure to copy the files from the flash drive to your computer for the best performance.

1. Open the Arduino IDE
   > If you are using the offline package, open the IDE from the `arduino-1.8.2-esp8266` folder. Copy the files to your computer for the best performance.
   >
   > If you have installed the IDE to your computer, make sure you have the [ESP8266 board package](1_Software_Installation.md#configure-arduino-ide-for-esp8266) installed before continuing.
1. Open the **Sketch** menu , select **Include Library**, then **Add .ZIP Library**
1. Select the `/Arduino_Libraries` folder containing the .ZIP files for the following libraries

   | Library                | Author         | Version |
   |------------------------|----------------|---------|
   | AzureIoTHub            | Arduino        | 1.0.30  |
   | AzureIoTProtocol_HTTP  | Microsoft      | 1.0.30  |
   | AzureIoTProtocol_MQTT  | Microsoft      | 1.0.30  |
   | AzureIoTUtility        | Microsoft      | 1.0.30  |
   | AzureIoTHubMQTTClient  | Andri Yadi     | 0.2.2   |
   | ArduinoJson            | Benoit Blanchon| 5.9.0   |
   | Time                   | tbd            | x.x.x   |
   | Grove ADXL345 (Accel)  | Seeed Studio   | x.x.x   |



# [Next ▻](3_Azure_IoT_Hub.md)
Now that we've installed and configured the Arduino IDE and added our libraries, let's create the Azure IoT Hub that our NodeMCU will communicate with!

*Next Step*: [Create Azure IoT Hub](3_Azure_IoT_Hub.md)