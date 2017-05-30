# Web Dashboard
In the previous activities, we connected sensors to a NodeMCU which is configured to send the data to Azure IoT Hub, and visualize the data in PowerBI. In this activity, we will deploy a web application to Azure to visualize the data. In the spirit of open source, we'll deploy a NodeJS application to Azure App Service via an automated Git connected deployment. 

The web app subscribes to the IoT Events and forwards them onto our webpage where the data is trended in a HTML5 chart via ChartJS. 

1. Open the [Azure Portal](http://portal.azure.com)
1. Select **+ New** → **Web + Mobile** → **Web App**
1. Enter a unique name for your Web App, such as `{firstname}{lastname}IoTWeb`
   > The name will be used to create your URL: `{firstname}{lastname}IoTWeb.azurewebsites.net`
1. Select the subscription to create the App Service in
1. Create a new Resource Group or use the Resource Group you created in [section 3](3_Azure_IoT_Hub)  
   > The recommended resource group from Section 3 was: `IoT_{firstname}_{lastname}`
1. Create a new App Service Plan
   > In order to minimize network costs, select the same region as before: **West Central US**

   > Select an appropriate App Service Plan. For this demo, a Free plan is sufficient, but you scale up or scale down as is desired. If you have an existing App Service Plan, you can use it for this excercise
1. Ensure the "Pin to dashboard" option is selected and click **Create** to continue.

## Add IoT Hub Consumer Group

Consumer groups are used by applications to pull data from Azure IoT Hub. In this lesson, you create a consumer group to be used by a coming Azure service to read data from your IoT hub.

To add a consumer group to your IoT hub, follow these steps:

1. In the [Azure portal](https://ms.portal.azure.com/), open your IoT hub.
1. Click **Endpoints** on the left pane, select **Events** on the middle pane, enter `IoTWebApp` as the name under **Consumer groups** on the right pane, and then click **Save**.

   ![Create consumer group in Azure IoT Hub](https://github.com/Microsoft/azure-docs/raw/master/articles/iot-hub/media/iot-hub-create-consumer-group/1_iot-hub-create-consumer-group-azure.png)

## Configure the Web App
1. Once the Web App deployment is completed, open the Web App from the Dashboard
1. Scroll down and select **Deployment Options**
1. Tap **Choose Source**
1. Select **External Repository**
   > Azure has integrations with several Source Control and file sharing systems that make deploying code from secure, ***private*** locations easy. In our case, we'll use an external repository to get the code from a public GitHub repository.
1. In the **Repository URL**, enter:  
   ```
   https://github.com/L2services/web-apps-node-iot-hub-data-visualization.git
   ```
   ![Deployment Configuration](/images/webapp_configuration/Deployment_Configuration.png)
1. Leave the default selections for `master` branch, `git` type and select **OK** to continue.

## Enable Web Sockets and Set Configuration
1. Scroll down and select **Application Settings**
1. Change **Web Sockets** to `On`
   ![WebSockets](/images/webapp_configuration/WebSockets_Enable.png)
1. Scroll down to **App Settings** and add the following keys:
   `Azure.IoT.IoTHub.ConnectionString`  
   `Azure.IoT.IoTHub.ConsumerGroup`
1. Fill in the keys with the Connection String and Consumer Group your IoT Hub
   > The recommended **Consumer Group** was `IoTWebApp` and the **Connection String** can be found in Device Explorer on the Configuration Tab or in the Azure Portal by selecting your IoT Hub → Shared Access Polices → `iothubowner` and copy the **Connection string-primary key** field.
1. Check that the git based deployment is complete by selecting the **Deployment Options**
   > If the app service deployment is complete, you should see a checkmark and timestamp of the deployment:  
   >
   >![Deployment Complete](/images/webapp_configuration/Deployment_Complete.png)
1. Click the **Overview** tab and then click the link in the **URL** field to open the web app.
   > Every three seconds, the NodeMCU will send sensor values to IoT Hub which the web app is subscribed to. The web app will then push the data to your browser where it should be displayed in a chart similar to below.
   >
   >![Web App Trend](/images/webapp_configuration/Webapp_2.png)

# Hooray!
Summary of activities. Recommended next steps!