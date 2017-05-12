# Azure IoT Workshop: NodeMCU Lab



## Lab Guides
1. [Software Installation](1_Software_Installation.md)
    * [Install the Arduino IDE](1_Software_Installation.md#install-the-arduino-ide)
1. [Configure Software](2_Configure_Software.md)
    * [Configure Arduino IDE for ESP8266](2_Configure_Software.md#configure-arduino-ide-for-esp8266)
    * [Configure Libraries](2_Configure_Software.md#configure-libraries)
1. [Configure Azure Services](#configure-azure-services)
    * [Create Azure IoT Hub](#create-azure-iot-hub)
    * [Create Azure Streaming Analytics](#create-azure-streaming-analytics)
1. [Configure PowerBI](#configure-powerbi)  
* [FAQ / Help](FAQ.md)


## Activity Summary

In this lab, we'll walk through the basics of: 
* Creating and configuring an Azure IoT Hub
* Configuring a sample Arduino sketch to communicate with Azure IoT Hub
* Deploying the sketch to the NodeMCU device
* Monitoring the data received from the NodeMCU
* Visualizing and analyzing the IoT data in PowerBI

## Requirements
The following components are required to follow this lab in its entirety. If you have experience with prototyping boards and developing Arduino sketches, you can substitute many of the sensors and components in this guide and achieve the same general output. This is the power of Azure IoT Hub: device agnostic support through standards based protocols like AMQP, MQTT, and HTTPS. That being said, the lab is written for use with a specific set of devices and hardware and the supporting source code matches this hardware.

### Hardware

* [NodeMCU (v1.0)](http://amzn.to/2qTRR2F)
* [Grove Base Shield for NodeMCU](http://amzn.to/2qTtH7E) (or from [Mouser](http://www.mouser.com/ProductDetail/Seeed-Studio/105020008/))
* Sensors: 
  * [Temperature/Humidity Sensor](http://amzn.to/2psBJnC) (or from [Mouser](http://www.mouser.com/ProductDetail/Seeed-Studio/101020074/))
  * [Vibration Sensor](http://amzn.to/2qTDpqN) (or from [Mouser](http://www.mouser.com/ProductDetail/Seeed-Studio/101020054/))
  * [LED Multicolor](http://amzn.to/2qTHSdP) (or from [Mouser](http://www.mouser.com/ProductDetail/Seeed-Studio/104030014/))
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
We will create Azure IoT Hub and Streaming Analytics jobs in this step. 
   ### Create Azure IoT Hub
   1. Login to [Azure poral](https://portal.azure.com) 
   1. "+ New" from the left menu → search for "IoT Hub" → select "IoT Hub" → Create
   [Creat AZ IoT Hub](/images/Azure_configuration/Create_IoTHub.png)
   1. 
      
   ### Create Azure Streaming Analytics
  
## Configure PowerBI
