# NodeMCU Build
```
//TODO: Add instructions on configuring the NodeMCU

```
Ensure you have all of the required components:
* [NodeMCU (v1.0)](http://amzn.to/2qTRR2F)
* [Grove Base Board for NodeMCU](http://amzn.to/2qTtH7E) (or from [Mouser](http://www.mouser.com/ProductDetail/Seeed-Studio/105020008/))
* Sensors: 
  * [Temperature/Humidity Sensor](http://amzn.to/2psBJnC) (or from [Mouser](http://www.mouser.com/ProductDetail/Seeed-Studio/101020074/))
  * [Vibration Sensor](http://amzn.to/2qTDpqN) (or from [Mouser](http://www.mouser.com/ProductDetail/Seeed-Studio/101020054/))
  * [LED Multicolor](http://amzn.to/2qTHSdP) (or from [Mouser](http://www.mouser.com/ProductDetail/Seeed-Studio/104030014/))
  * [Button](http://amzn.to/2pZvedb) (or from [Mouser](http://www.mouser.com/ProductDetail/Seeed-Studio/101020003/))
* [Micro USB cable](http://amzn.to/2pI5VLP) (or from [Monoprice](https://www.monoprice.com/product?p_id=5137))

> Note: Each of the Grove Sensors come with a 4-pin Grove cable which is used to connect the sensor to the Grove Base Board.

## Configure Hardware
1. Plug the NodeMCU into the Grove Base Board
   > **IMPORTANT**: Ensure the antenna on the NodeMCU is aligned with the antenna sketch on the Grove Base Board.  
   > ![Alignment](/images/NodeMCU/NodeMCU_alignment.jpg)
1. Plug the sensors in to their respective ports:

   | Sensor               | Port on Grove<br/>Base Board |
   | -------------------- | :--------------------------: |
   | Temperature Sensor   |             A0               |
   | LED                  |             D3               |
   | 3-Axis Accelerometer |             I2C              |
   | Switch               |             D7               |


   > **Note**: You can plug the accelerometer into either I2C port.

   ![Finished NodeMCU](/images/NodeMCU/NodeMCU_Wired.jpg)

## Deploy Code
1. Open the [AZIoTMQTT_Client.ino](/src/AZIoTMQTT_Client.ino) sketch in the Arduino IDE
1. Paste the Connection String from [section 3](3_Azure_IoT_Hub#Register-Device-to-Azure-IoT-Hub) of the lab on the end of the line:
   ```
   // Azure IoT Hub Settings --> CHANGE THESE 
   ```
1. Copy the **HostName**, **DeviceID**, and **SharedAccessKey** into the respective variables at the top of the Arduino code where `IOTHUB_HOSTNAME`, `DEVICE_ID` and `DEVICE_KEY` are located.
   ![Device Info in Code](/images/Azure_configuration/Device_Info_In_Code.png)
   > Note: For each variable, copy the content after the `variable=` and before the `;nextVariable`.   
   >  
   > For example: 
   > ```
   > HostName=jameslabiothub.azure-devices.net;DeviceId=NodeMCU1;SharedAccessKey=gMGLXHhiVz/GGhvBklA1xsZlGlPlSBc5+Q1nBUBKP/0= 
   > ```
   > Would result in
   > ```
   > # define IOTHUB_HOSTNAME    "jameslabiothub.azure-devices.net"
   > # define DEVICE_ID          "NodeMCU1"
   > # define DEVICE_KEY         "gMGLXHhiVz/GGhvBklA1xsZlGlPlSBc5+Q1nBUBKP/0=" //Primary key of the device
   > ```
1. Connect your NodeMCU device to your computer
   > Connect the USB-A side of the Micro USB cable to your computer and the Micro connector into the NodeMCU
1. Compile and Upload the code to the NodeMCU board by clicking on Upload button at left top of the Arduino IDE  
   ![Upload code](/images/Azure_configuration/Upload_Code_To_Device.png)
1. Review the console output in Arduino IDE: click Tools → Serial Monitor to view the serial output printed out from the NodeMCU
   > The Serial Monitor will show debug statements during the WiFi Connection Process, Azure Connection, and as data is sent to IoT Hub.

   > **Note**: The NodeMCU is an Arduino compatible device which communicates over a virtual serial port through the USB connection. This allows you to print text to the serial port and view that while the device is connected to your computer. The NodeMCU can also operate completely indepently of a computer when powered by a battery or direct power source. 
1. Select the **Data** tab
1. Ensure the newly created device is selected in the **Device ID** field and then click the **Monitor** button
   > Verify IoT Hub is receiving data. Event data should be displayed in the "Event Hub Data" section of the screen as shown in the following screenshot. The data should update every 3 seconds.
   ![Receiving Data](/images/Azure_configuration/Receiving_IoT_Data.png)



# [Next ▻](5_Stream_Analytics.md)
Now that we have our NodeMCU communicating with Azure, let's use some Azure features to visualize and analyze the data!

*Next Step*: [Stream Analytics](5_Stream_Analytics.md)