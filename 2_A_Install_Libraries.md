# Install Libraries

1. Open the Arduino IDE
1. From the menu, select **Sketch** → **Include Library** → **Manage Libraries**
1. Use the filter box to search for each of the following libraries and select **Install** for each:

   | Library                | Author         | Version |
   |------------------------|----------------|---------|
   | AzureIoTHubMQTTClient  | Andri Yadi     | 0.2.2   |
   | ArduinoJson            | Benoit Blanchon| 5.9.0   |

1. Download the following Libraries and manually add them by going to **Sketch** → **Include Library** → **Add .Zip Library**
   1. [Time](https://github.com/PaulStoffregen/Time)
   1. [Grove ADXL345 (Accelerometer)](https://github.com/Seeed-Studio/Accelerometer_ADXL345)

   > **Note**: From the linked GitHub repositories, you can select the **Clone or Download** and then **Download ZIP** to save a copy of the library to your computer. Once the ZIP file is on your machine, you can include the ZIP file following the instruction above.  
   > 
   >  ![GitHub: Download ZIP](/images/library_installation/GitHub_DownloadZip.jpg)

   
   
---  
### Other Notes    
To keep the sketch in a single C++ file (`.ino`), we've chosen to use a set of third party libraries for the lab. If you'd like to use the C libraries from Microsoft in a future project, you would install the following:  

| Library                | Author         | Version |
|------------------------|----------------|---------|
| AzureIoTHub            | Arduino        | 1.0.30  |
| AzureIoTProtocol_HTTP  | Microsoft      | 1.0.30  |
| AzureIoTProtocol_MQTT  | Microsoft      | 1.0.30  |
| AzureIoTUtility        | Microsoft      | 1.0.30  |

---

# Next
Now that we've installed and configured the Arduino IDE and added our libraries, let's create the Azure IoT Hub that our NodeMCU will communicate with!

*Next Step*: [Create Azure IoT Hub](3_Azure_IoT_Hub.md)