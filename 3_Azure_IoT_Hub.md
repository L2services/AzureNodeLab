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
1. Input a device identifier, such as `MyNode1` in the prompt and then select the **Create** button in the dialog and then **Done** when prompted.  
   ![Create New Device](/images/Azure_configuration/Create_Device.png)
1. Right click on the newly created device row and select **Copy Connection String for Selected Device**
   > Keep a copy of the connection string on your clip board as it will be needed for the next step of the lab.
  



# [Next ▻](4_NodeMCU_Build.md)
Now that we've created our Azure IoT Hub instance, let's wire up our NodeMCU and test out the communication!

*Next Step*: [NodeMCU Build and Deploy](4_NodeMCU_Build.md)