# Install Libraries (Offline)

In the previous lab, we acquired the Arduino IDE and installed Device Explorer. If you are following along online, you may have installed a copy of the the Arduino IDE to your computer and then configured the Board Manager to download the ESP8266 package. If you are following along in person and have been provided a flash drive, you'll find a copy of the Arduino IDE on the flash drive.

1. Open the Arduino IDE
   > If you are using the offline package, open the IDE from the `arduino-1.8.2-esp8266` folder. 
   <!--Copy the files to your computer for the best performance. Be sure to copy to a directory close to the root of your hard-drive such as `C:\AzureLab` as Windows may have issues with long file/directory names (some of the support package have deep nested directories).-->
   >
   > If you have installed the IDE to your computer, make sure you have the [ESP8266 board package](1_Software_Installation.md#configure-arduino-ide-for-esp8266) installed before continuing.
1. Copy the content from the `/arduino-libraries/unpacked` folder to the folder:  
   ```
   /arduino-1.8.2-esp8266/portable/sketchbook/libraries
   ```
   > You can also install the required libraries in a permanent installation. On Windows, the sketchbook location defaults to `..\{username}\Documents\Arduino` and you can confirm the sketchbook location in your Arduino Preferences. Alternatively, you can follow the [Install Libraries (Online)](2_A_Install_Libraries.md) instructions.
   >
   > Make sure to copy the libraries to the `/sketchbook/libraries/` folder as there are "tools" and similar folders for other types of packages.

For your reference, the following libraries are required for this project and are installed as part of the process above:

   | Library                | Author           | Version |
   |------------------------|------------------|---------|
   | AzureIoTHubMQTTClient  | Andri Yadi       | 0.2.2   |
   | ArduinoJson            | Benoit Blanchon  | 5.9.0   |
   | Time                   | Michael Margolis | 1.5.0   |
   | Grove ADXL345 (Accel)  | Seeed Studio     | x.x.x   |

---
### Other Notes    
To keep the sketch in a single C++ file (`.ino`), we've chosen to use a set of third party libraries for the lab. If you'd like to use the C libraries from Microsoft in a future project, you would install the following libraries. All of these libraries are included in the `/arduino-libraries` folder and can also be installed directly from the Arduino IDE via Sketch → Include Library → Manage Libraries.  

| Library                | Author         | Version |
|------------------------|----------------|---------|
| AzureIoTHub            | Arduino        | 1.0.30  |
| AzureIoTProtocol_HTTP  | Microsoft      | 1.0.30  |
| AzureIoTProtocol_MQTT  | Microsoft      | 1.0.30  |
| AzureIoTUtility        | Microsoft      | 1.0.30  |
---

# [Next ▻](3_Azure_IoT_Hub.md)
Now that we've installed and configured the Arduino IDE and added our libraries, let's create the Azure IoT Hub that our NodeMCU will communicate with!

*Next Step*: [Create Azure IoT Hub](3_Azure_IoT_Hub.md)