# Azure IoT Workshop: NodeMCU Lab


## Lab Guides
1. [Software Installation](1_Software_Installation.md)
1. Install Arduino Libraries
    * [Online Installation](2_A_Install_Libraries.md)
    * [Offline Installation](2_B_Install_Libraries_offline.md)
1. [Create Azure IoT Hub](3_Azure_IoT_Hub.md)
1. [NodeMCU Build](4_NodeMCU_Build.md)
1. [Stream Analytics](5_Stream_Analytics.md)
1. [Power BI](6_Power_BI.md)  
1. [Web Dashboard](7_Web_Dashboard.md)
* [FAQ / Help](FAQ.md)

## Activity Summary

In this lab, we'll walk through the basics of: 
* Creating and configuring an Azure IoT Hub
* Configuring a sample Arduino sketch to communicate with Azure IoT Hub
* Deploying the sketch to the NodeMCU device
* Monitoring the data received from the NodeMCU
* Visualizing and analyzing the IoT data in PowerBI
* Visualizing and analyzing the IoT data in custom web application

## Requirements
The following components are required to follow this lab in its entirety. If you have experience with prototyping boards and developing Arduino sketches, you can substitute many of the sensors and components in this guide and achieve the same general output. This is the power of Azure IoT Hub: device agnostic support through standards based protocols like AMQP, MQTT, and HTTPS. That being said, the lab is written for use with a specific set of devices and hardware and the supporting source code matches this hardware.

### Hardware

* [NodeMCU (v1.0)](http://amzn.to/2qTRR2F)
* [Grove Base Shield for NodeMCU](http://amzn.to/2qTtH7E) (or from [Mouser](http://www.mouser.com/ProductDetail/Seeed-Studio/105020008/))
* Sensors: 
  * [Temperature Sensor](http://amzn.to/2s7oFpv) (or from [Mouser](http://www.mouser.com/ProductDetail/Seeed-Studio/101020015/))
  * [Vibration Sensor](http://amzn.to/2qTDpqN) (or from [Mouser](http://www.mouser.com/ProductDetail/Seeed-Studio/101020054/))
  * [LED](http://amzn.to/2qA5VNv) (or from [Mouser](http://www.mouser.com/ProductDetail/Seeed-Studio/104030005))
  * [Button](http://amzn.to/2pZvedb) (or from [Mouser](http://www.mouser.com/ProductDetail/Seeed-Studio/101020003/))

### Software

* [Arduino IDE](https://www.arduino.cc/en/Main/Software) (v1.8.2)
  * [Windows Installer](https://downloads.arduino.cc/arduino-1.8.2-windows.exe)
  * [Windows Zip for non-admin install](https://downloads.arduino.cc/arduino-1.8.2-windows.zip)
  * [Windows Store](https://www.microsoft.com/en-us/store/p/arduino-ide/9nblggh4rsd8)
* Azure Subscription
  * If you already have an Azure Organizational Account, you may use that for this lab.
  * If you don't already have an Azure Subscription, you can create a [free trial](https://azure.microsoft.com/en-us/free/) ($200 credit)
* [Azure Device Explorer](https://github.com/Azure/azure-iot-sdk-csharp/releases/download/2017-5-5/SetupDeviceExplorer.msi)



# Let's get started!
We'll start by installing the Arduino IDE and Azure Device Explorer!

*Next Step*: [Software Installation](1_Software_Installation.md)