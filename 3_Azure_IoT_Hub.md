# Azure IoT Hub

## Create Azure IoT Hub
1. Login to the [Azure poral](https://portal.azure.com) 
   > https://portal.azure.com
  
1. Select **+ New** → **Internet of Things** → **IoT Hub**
![Create AZ IoT Hub](/images/Azure_configuration/Create_IoTHub.png)
1. Enter a unique Name for your hub such as `IoTHub{firstname}{lastname}`
   > Note: Use alphanumeric characters or '-' only
1. Click **Pricing and scale tier** and then select **F1 Free tier**
1. Create a new Resource Group if you don't have one already, or select an existing group in the drop down
   > For example, `IoT_{firstname}_{lastname}`
1. Click **Location** and select **West Central US**
1. At the bottom of the pane, ensure the **Pin to dashboard** checked and then click the **Create** button

### Register Device to Azure IoT Hub
1. Once IoT Hub is deployed, copy the connection string from **Shared access policies** → **`iothubowner`** → **Connection string-primary key**.  
![Grant access to IoT Hub](/images/Azure_configuration/GrantAccess_IoTHub.png)
1. Open Device Explorer (installed during the [Software Installation](1_Software_Installation.md) step)
1. Paste the connection string into the **IoT Hub Connection String** field in **Configuration** tab, and click **Update**. 
![Setting Device Explorer](/images/Azure_configuration/Setting_Device_Explorer.png)
1. To create a new device, select the **Management** tab and then the **Create** button under actions
1. Input a device identifier, such as `MyNode1` in the prompt and then select the **Create** button in the dialog and then **Done** when prompted 
![Create New Device](/images/Azure_configuration/Create_Device.png)
1. Right click on the newly created device row and select **Copy Connection String for Selected Device**
1. Open the Arduino IDE and paste the entry on the end of the line:
   ```
   // Azure IoT Hub Settings --> CHANGE THESE 
   ```
1. Copy the **HostName**, **DeviceID**, and **SharedAccessKey** into the respective variables at the top of the Arduino code where `IOTHUB_HOSTNAME`, `DEVICE_ID` and `DEVICE_KEY`
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
   ![Device Info in Code](/images/Azure_configuration/Device_Info_In_Code.png)
1. Connect your NodeMCU device to your laptop/computer.
1. Compile and Upload the code to the NodeMCU board by clicking on Upload button at left top.
![Upload code](/images/Azure_configuration/Upload_Code_To_Device.png)
1. Review the output in Arduino IDE. Click Tools in Sketch → Serial Port Monitor and you should see it connects to Azure successfully.
1. Go back to Device Explorer → Data tab → make sure Event Hub name is the IoT Hub we just created → select the new created device in **Device ID** field → click on Monitor
1. Verify IoT Hub is receiving data like the screenshot below
![Receiving Data](/images/Azure_configuration/Receiving_IoT_Data.png)
  



# Next
Now that we've created our Azure IoT Hub instance, let's wire up our NodeMCU and test out the communication!

*Next Step*: [NodeMCU Build and Deploy](4_NodeMCU_Build.md)