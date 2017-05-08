# Azure IoT Workshop: NodeMCU Lab
IoT Workshop Lab using the NodeMCU (ESP8266) board.

This serves as a working document for the Azure Internet of Things Workshop in which the NodeMCU (ESP8266) Arduino compatible prototyping board is used to connect to Azure IoT.  

## Table of Contents
* [Activity Summary](#activity-summary)
* [Requirements](#requirements)
  * [Hardware](#hardware)
  * [Software](#software)
* [Configure Arduino IDE for ESP8266](#configure-arduino-ide-for-esp8266)

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
**Note**: If you have some experience with prototyping boards and developing Arduino sketches, you can substitute many of the sensors and components in this guide and achieve the same general output. This is the power of Azure IoT Hub - device agnostic support through standards based protocols like AMQP, MQTT, and HTTPS.

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


# Configure Arduino IDE for ESP8266
1. Open the Arduino IDE and click on `File` → `Preferences`
1. Scroll down and select `Adittional Boards Manager URLs`
1. Add the following line: `http://arduino.esp8266.com/stable/package_esp8266com_index.json`
1. Click `OK`
1. Open the menu: `Tools` → `Board` → `Boards Manager"
1. Type "ESP8266" and install it.
1. Open the menu: `Tools` → `Board` and select `NodeMCU 1.0`
