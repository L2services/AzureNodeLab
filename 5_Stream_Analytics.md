## Create, configure, and run a Stream Analytics job

### Add a consumer group to your IoT hub

Consumer groups are used by applications to pull data from Azure IoT Hub. In this lesson, you create a consumer group to be used by a coming Azure service to read data from your IoT hub.

To add a consumer group to your IoT hub, follow these steps:

1. In the [Azure portal](https://ms.portal.azure.com/), open your IoT hub.
1. Click **Endpoints** on the left pane, select **Events** on the middle pane, enter a name under **Consumer groups** on the right pane, and then click **Save**.

   ![Create consumer group in Azure IoT Hub](https://github.com/Microsoft/azure-docs/raw/master/articles/iot-hub/media/iot-hub-create-consumer-group/1_iot-hub-create-consumer-group-azure.png)

### Create a Stream Analytics job

1. In the Azure portal, click New > Internet of Things > Stream Analytics job.
1. Enter the following information for the job.

   **Job name**: The name of the job. The name must be globally unique.

   **Resource group**: Use the same resource group that your IoT hub uses.

   **Location**: Use the same location as your resource group.

   **Pin to dashboard**: Check this option for easy access to your IoT hub from the dashboard.

   ![Create a Stream Analytics job in Azure](https://github.com/Microsoft/azure-docs/raw/master/articles/iot-hub/media/iot-hub-live-data-visualization-in-power-bi/2_create-stream-analytics-job-azure.png)

1. Click **Create**.

### Add an input to the Stream Analytics job

1. Open the Stream Analytics job.
1. Under **Job Topology**, click **Inputs**.
1. In the **Inputs** pane, click **Add**, and then enter the following information:

   **Input alias**: The unique alias for the input.

   **Source**: Select **IoT hub**.

   **Consumer group**: Select the consumer group you just created.
1. Click **Create**.

   ![Add an input to a Stream Analytics job in Azure](https://github.com/Microsoft/azure-docs/raw/master/articles/iot-hub/media/iot-hub-live-data-visualization-in-power-bi/3_add-input-to-stream-analytics-job-azure.png)

### Add an output to the Stream Analytics job

1. Under **Job Topology**, click **Outputs**.
1. In the **Outputs** pane, click **Add**, and then enter the following information:

   **Output alias**: The unique alias for the output.

   **Sink**: Select **Power BI**.
1. Click **Authorize**, and then sign into your Power BI account.

   > Note: You'll need to use an organizational account in order to access Power BI 
1. Once authorized, enter the following information:

   **Group Workspace**: Select your target group workspace.

   **Dataset Name**: Enter a dataset name.

   **Table Name**: Enter a table name.
1. Click **Create**.

   ![Add an output to a Stream Analytics job in Azure](https://github.com/Microsoft/azure-docs/raw/master/articles/iot-hub/media/iot-hub-live-data-visualization-in-power-bi/4_add-output-to-stream-analytics-job-azure.png)

### Configure the query of the Stream Analytics job

1. Under **Job Topology**, click **Query**.
1. Replace `[YourInputAlias]` with the input alias of the job.
1. Replace `[YourOutputAlias]` with the output alias of the job.
1. Click **Save**.

   ![Add a query to a Stream Analytics job in Azure](https://github.com/Microsoft/azure-docs/raw/master/articles/iot-hub/media/iot-hub-live-data-visualization-in-power-bi/5_add-query-stream-analytics-job-azure.png)

### Run the Stream Analytics job

In the Stream Analytics job, click **Start** > **Now** > **Start**. Once the job successfully starts, the job status changes from **Stopped** to **Running**.

![Run a Stream Analytics job in Azure](https://github.com/Microsoft/azure-docs/raw/master/articles/iot-hub/media/iot-hub-live-data-visualization-in-power-bi/6_run-stream-analytics-job-azure.png)



# [Next ▻](6_Power_BI.md)
We now have our NodeMCU streaming data from sensors to Azure IoT Hub and Stream Analytics is processing that data on the fly and sending it to Power BI! Using similar steps as above, we could create different logic, processing, and output locations for our IoT data. In the next section, we'll configure a Power BI display to visualize the IoT data.

*Next Step*: [Stream Analytics](5_Stream_Analytics.md)