## Create and publish a Power BI report to visualize the data

1. Sign in to your [Power BI](https://powerbi.microsoft.com/en-us/) account.
   > Note: You'll need to use an organizational account in order to access Power BI 
1. Go to the group workspace that you set when you created the output for the Stream Analytics job.
1. Click the Dataset name you created as the output for the [Stream Analytics job](5_Stream_Analytics.md) section.
   
1. Create a line chart by clicking on the Line chart icon under **Visualization** to show real-time sensor data over time.
   1. On the report creation page, add a line chart.
   1. On the **Fields** pane, expand the table that you specified when you created the output for the Stream Analytics job.
   1. Drag **EventEnqueuedUtcTime** to the Line chart you just added in the page.
   1. Drag **Temperature_F** to the Line chart you just added in the page.

      Now a line chart is created. The x-axis of chart displays date and time in the UTC time zone. The y-axis displays temperature from the sensor.
      
      ![Add a line chart for temperature to a Microsoft Power BI report](/images/Azure_configuration/PowerBI_Dataset.png)

1. Create another line chart to show real-time accelerometer data over time. To do this, follow the same steps above and place **EventEnqueuedUtcTime** on the x-axis and **AcceX**, **AcceY**, and **AcceZ** on the y-axis.

   ![Add a line chart for accelerometer to a Microsoft Power BI report](/images/Azure_configuration/PowerBI_Dataset_2.png)

1. Click **Save** to save the report.
1. Click **File** > **Publish to web**.
1. Click **Create embed code**, and then click **Publish**.

You're provided the report link that you can share with anyone for report access and a code snippet to integrate the report into your blog or website.

![Publish a Microsoft Power BI report](/images/Azure_configuration/PowerBI_Dataset_publish.png)


## View Streaming Data in PowerBI Dashboard
1. Once the report is published, we can now add report(s) into Dashboard
   1. In the report we just created, click **Pin Live Page**

      ![Pin Report to Dashboard](/images/Azure_configuration/PowerBI_PinDashboard.png)

   1. Fill in Dashboard name and **Pin Live**
      
      ![Create new Dashboard](/images/Azure_configuration/PowerBI_PinDashboard_2.png)

1. Add Streaming Data Tile to Dashboard
   1. Click on **Add tile**

      ![Add Tile](/images/Azure_configuration/PowerBI_LiveTile.png)
   
   1. Select **CUSTOM STREAMING DATA**

      ![Custom Streaming Data](/images/Azure_configuration/PowerBI_LiveTile_2a.png)
   
   1. Select the Dataset we just created

      ![Select Dataset](/images/Azure_configuration/PowerBI_LiveTile_3a.png)
   
   1. Select **Line chart** in Visualization Type, **eventenqueuedutctime** in Axis, and **temperature_f** in Values.

      ![Configure Visualization](/images/Azure_configuration/PowerBI_LiveTile_4a.png)

   1. Input Tile Title, and Apply

         ![Input Tile Title](/images/Azure_configuration/PowerBI_LiveTile_5a.png)

   > Note: While the data in Dashboard can be scheduled to be refreshed periodically, Live Streaming Data Tile allows near real-time data display.

Microsoft also offers the [Power BI mobile apps](https://powerbi.microsoft.com/en-us/documentation/powerbi-power-bi-apps-for-mobile-devices/) for viewing and interacting with your Power BI dashboards and reports on your mobile device.



# [Next ▻](7_Web_Dashboard.md)
Now we have seen the live streaming data in PowerBI with just a few clicks. Let's take a look of how custom web app can also pull live streaming data from IoT Hub using Node.js Azure IoT SDK.

*Next Step*: [Web Dashboard](7_Web_Dashboard.md)