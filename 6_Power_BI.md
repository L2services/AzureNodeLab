## Create and publish a Power BI report to visualize the data

1. Sign in to your [Power BI](https://powerbi.microsoft.com/en-us/) account.
   > Note: You'll need to use an organizational account in order to access Power BI 
1. Go to the group workspace that you set when you created the output for the Stream Analytics job.
1. Click **Streaming datasets**.

   You should see the listed dataset that you specified when you created the output for the [Stream Analytics job](5_Stream_Analytics.md).
1. Under **ACTIONS**, click the first icon to create a report.

   ![Create a Microsoft Power BI report](https://github.com/Microsoft/azure-docs/raw/master/articles/iot-hub/media/iot-hub-live-data-visualization-in-power-bi/7_create-power-bi-report-microsoft.png)

1. Create a line chart to show real-time temperature over time.
   1. On the report creation page, add a line chart.
   1. On the **Fields** pane, expand the table that you specified when you created the output for the Stream Analytics job.
   1. Drag **EventEnqueuedUtcTime** to **Axis** on the **Visualizations** pane.
   1. Drag **temperature** to **Values**.

      Now a line chart is created. The x-axis of chart displays date and time in the UTC time zone. The y-axis displays temperature from the sensor.

      ![Add a line chart for temperature to a Microsoft Power BI report](https://github.com/Microsoft/azure-docs/raw/master/articles/iot-hub/media/iot-hub-live-data-visualization-in-power-bi/8_add-line-chart-for-temperature-to-power-bi-report-microsoft.png)

1. Create another line chart to show real-time humidity over time. To do this, follow the same steps above and place **EventEnqueuedUtcTime** on the x-axis and **humidity** on the y-axis.

   ![Add a line chart for humidity to a Microsoft Power BI report](https://github.com/Microsoft/azure-docs/raw/master/articles/iot-hub/media/iot-hub-live-data-visualization-in-power-bi/9_add-line-chart-for-humidity-to-power-bi-report-microsoft.png)

1. Click **Save** to save the report.
1. Click **File** > **Publish to web**.
1. Click **Create embed code**, and then click **Publish**.

You're provided the report link that you can share with anyone for report access and a code snippet to integrate the report into your blog or website.

![Publish a Microsoft Power BI report](https://github.com/Microsoft/azure-docs/raw/master/articles/iot-hub/media/iot-hub-live-data-visualization-in-power-bi/10_publish-power-bi-report-microsoft.png)

Microsoft also offers the [Power BI mobile apps](https://powerbi.microsoft.com/en-us/documentation/powerbi-power-bi-apps-for-mobile-devices/) for viewing and interacting with your Power BI dashboards and reports on your mobile device.



# [Next ▻](7_Web_Dashboard.md)
Now that we have our NodeMCU communicating with Azure, let's use some Azure Features to visualize and analyze the data!

*Next Step*: [Stream Analytics](5_Stream_Analytics.md)