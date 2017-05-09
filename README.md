# Azure IoT Workshop: NodeMCU Lab
IoT Workshop Lab using the NodeMCU (ESP8266) board.

This serves as a working document for the Azure Internet of Things Workshop in which the NodeMCU (ESP8266) Arduino compatible prototyping board is used to connect to Azure IoT.  

## Table of Contents
* [Activity Summary](#activity-summary)
* [Requirements](#requirements)
  * [Hardware](#hardware)
  * [Software](#software)
* [Software Installation](#software-installation)
  * [Install the Arduino IDE](#install-the-arduino-ide)
  * [Configure Arduino IDE for ESP8266](#configure-arduino-ide-for-esp8266)
  * [Configure Libraries](#configure-libraries)
* [FAQ / Help](#faq)

## Activity Summary

In this lab, we'll walk through the basics of: 
* Creating and configuring an Azure IoT Hub
* Configuring a sample Arduino sketch to communicate with Azure IoT Hub
* Deploying the sketch to the NodeMCU device
* Monitoring the data received from the NodeMCU
* Visualizing and analyzing the IoT data in PowerBI

## Requirements
The following components are required to follow this lab in its entirety.  

### Hardware
**Note**: If you have some experience with prototyping boards and developing Arduino sketches, you can substitute many of the sensors and components in this guide and achieve the same general output. This is the power of Azure IoT Hub - device agnostic support through standards based protocols like AMQP, MQTT, and HTTPS. That being said, the lab is written for use with the following hardware:

* [NodeMCU (v1.0)](http://amzn.to/2qTRR2F)
* [Grove Base Shield for NodeMCU](http://amzn.to/2qTtH7E) (or from [Mouser](http://www.mouser.com/ProductDetail/Seeed-Studio/105020008/))
* Sensors: 
  * [Temperature/Humidity Sensor](http://amzn.to/2psBJnC) (or from [Mouser](http://www.mouser.com/ProductDetail/Seeed-Studio/101020074/))
  * [Vibration Sensor](http://amzn.to/2qTDpqN) (or from [Mouser](http://www.mouser.com/ProductDetail/Seeed-Studio/101020054/))
  * [LED Multicolor](http://amzn.to/2qTHSdP) (or from [Mouser](http://www.mouser.com/ProductDetail/Seeed-Studio/104030014/))
  * [Button](http://amzn.to/2pZvedb) (or from [Mouser](http://www.mouser.com/ProductDetail/Seeed-Studio/101020003/))
  * [Grove cables](http://amzn.to/2pUQ2Es) (or from [Mouser](http://www.mouser.com/ProductDetail/Seeed-Studio/110990027))

### Software
Similar to the hardware, if you have a preferred Arduino / ESP8266 IDE, you may be able to use an alternative development environment to achieve the goals of this lab, but the instructions are designed with the following in mind:

* [Arduino IDE](https://www.arduino.cc/en/Main/Software)
  * [Windows Installer](https://downloads.arduino.cc/arduino-1.8.2-windows.exe)
  * [Windows Zip for non-admin install](https://downloads.arduino.cc/arduino-1.8.2-windows.zip)
  * [Windows Store](https://www.microsoft.com/en-us/store/p/arduino-ide/9nblggh4rsd8)
* ESP8266 Board Package (for Arduino IDE)
* CP210x Driver (if it's not already installed on your system)
* Azure Subscription
  * If you already have an Azure Organizational Account, you may use that for this lab.
  * If you don't already have an Azure Subscription, you can create a free trial 
* Azure Device Explorer

## Create Azure IoT Hub

```
//TODO: Instructions on creating and configuring IoT Hub
```

## Software Installation

### Install the Arduino IDE
1. Download the [Windows Installer](https://downloads.arduino.cc/arduino-1.8.2-windows.exe)
1. Run the `arduino-1.8.2-windows.exe`  
1. Leave the default options selected to install the IDE and supporting drivers
![Installation Options](/images/software_install/arduino-windows_install_options.png)
1. Leave the default installation Destination Folder unchanged and select `Install`  
![Installation Folder](/images/software_install/arduino-windows_install_folder.png)
1. Wait for the installation to complete. Toward the end of the installation, you may be prompted to install several drivers. Select `Install` for each prompt.  
    * Adafruit Ports  
    * Arduino USB Driver (from Arduino srl)  
    * Arduino USB Driver (from Arduino LLC)  
    ![Arduino USB Driver LLC](/images/software_install/driver_arduino_llc.png)
1. Click `Close` to complete the Arduino IDE installation  
  ![First Driver](/images/software_install/arduino-windows_finish.png)

### Configure Arduino IDE for ESP8266
1. Open the Arduino IDE and click on `File` → `Preferences`  
![Arduino Desktop Icon](/images/software_configuration/Arduino_Desktop_Icon.png)  
![Arduino File Preferences](/images/software_configuration/Arduino_File_Preferences.png)
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

   | Library                | Author    | Version |
   |------------------------|-----------|---------|
   | AzureIoTHub            | Arduino   | 1.0.30  |
   | AzureIoTProtocol_HTTP  | Microsoft | 1.0.30  |
   | AzureIoTProtocol_MQTT  | Microsoft | 1.0.30  |
   | AzureIoTUtility        | Microsoft | 1.0.30  |

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