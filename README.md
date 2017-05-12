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
