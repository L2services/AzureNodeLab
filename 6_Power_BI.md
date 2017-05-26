## Create and publish a Power BI report to visualize the data

1. Sign in to your [Power BI](https://powerbi.microsoft.com/en-us/) account.
   > Note: You'll need to use an organizational account in order to access Power BI 
1. Go to the group workspace that you set when you created the output for the Stream Analytics job.
1. Click the Dataset name you created as the output for the [Stream Analytics job](5_Stream_Analytics.md) section.
   
1. Create a line chart by clicking on the Line chart icon under **Visualization** to show real-time sensor data over time.
   1. On the report creation page, add a line chart.
   1. On the **Fields** pane, expand the table that you specified when you created the output for the Stream Analytics job.
   1. Drag **EventEnqueuedUtcTime** to the Line chart you just added in the page.
   1. Drag **Temperature** to the Line chart you just added in the page.

      Now a line chart is created. The x-axis of chart displays date and time in the UTC time zone. The y-axis displays temperature from the sensor.
      
      ![Add a line chart for temperature to a Microsoft Power BI report](/images/Azure_configuration/PowerBI_Dataset.png)

1. Create another line chart to show real-time accelerometer data over time. To do this, follow the same steps above and place **EventEnqueuedUtcTime** on the x-axis and **AcceX**, **AcceY**, and **AcceZ** on the y-axis.

   ![Add a line chart for accelerometer to a Microsoft Power BI report](/images/Azure_configuration/PowerBI_Dataset_2.png)

1. Click **Save** to save the report.
1. Click **File** > **Publish to web**.
1. Click **Create embed code**, and then click **Publish**.

You're provided the report link that you can share with anyone for report access and a code snippet to integrate the report into your blog or website.

![Publish a Microsoft Power BI report](/images/Azure_configuration/PowerBI_Dataset_publish.png)

Microsoft also offers the [Power BI mobile apps](https://powerbi.microsoft.com/en-us/documentation/powerbi-power-bi-apps-for-mobile-devices/) for viewing and interacting with your Power BI dashboards and reports on your mobile device.



# [Next ▻](7_Web_Dashboard.md)
Now that we have our NodeMCU communicating with Azure, let's use some Azure Features to visualize and analyze the data!

*Next Step*: [Web Dashboard](7_Web_Deshboard.md)