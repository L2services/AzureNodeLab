## Create and publish a Power BI report to visualize the data

1. Sign in to your [Power BI](https://powerbi.microsoft.com/en-us/) account.
   > Note: You'll need to use an organizational account in order to access Power BI 
1. Go to the group workspace that you set when you created the output for the Stream Analytics job.
1. Verify the Dataset you created as the output for the [Stream Analytics job](5_Stream_Analytics.md) section exists, and craete a Dashboard
   ![Create Dashboard](/images/Azure_configuration/PowerBI_CreateDashboard.png)
1. Fill in the Dashboard name and **Create**
   ![Input Dashboard name](/images/Azure_configuration/PowerBI_CreateDashboard_2.png)
   
1. In the newly created Dashboard, click **+ Add tile** to add a live data tile.
   ![Add tile](/images/Azure_configuration/PowerBI_AddTile.png)

1. Select **CUSTOM STREAMING DATA**

   ![Custom Streaming Data](/images/Azure_configuration/PowerBI_LiveTile_2a.png)
   
1. Select the Dataset we just created

   ![Select Dataset](/images/Azure_configuration/PowerBI_LiveTile_3a.png)
   
1. Select **Line chart** in Visualization Type, **eventenqueuedutctime** in Axis, and **temperature_f** in Values.

   ![Configure Visualization](/images/Azure_configuration/PowerBI_LiveTile_4a.png)

1. Input Tile Title, and Apply

   ![Input Tile Title](/images/Azure_configuration/PowerBI_LiveTile_5a.png)

1. Verify the streaming temperature data is displayed in the line chart.
   ![Input Tile Title](/images/Azure_configuration/PowerBI_LiveTile.png)

   > You can follow the same steps to create another Line chart for accelerometer data.

Microsoft also offers the [Power BI mobile apps](https://powerbi.microsoft.com/en-us/documentation/powerbi-power-bi-apps-for-mobile-devices/) for viewing and interacting with your Power BI dashboards and reports on your mobile device.


# [Next ▻](7_Web_Dashboard.md)
Now we have seen the live streaming data in PowerBI with just a few clicks. Let's take a look of how custom web app can also pull live streaming data from IoT Hub using Node.js Azure IoT SDK.

*Next Step*: [Web Dashboard](7_Web_Dashboard.md)