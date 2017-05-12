# NodeMCU Build
```
//TODO: Add instructions on configuring the NodeMCU

```

1. Plug the NodeMCU into the Grove Base Board
   > **IMPORTANT**: Ensure the antenna on the NodeMCU is aligned with the antenna sketch on the Grove Base Board.
1. Plug the sensors in to their respective ports:

   | Sensor               | Port on Grove<br/>Base Board |
   | -------------------- | :--------------------------: |
   | Temperature Sensor   |             A0               |
   | LED                  |             D3               |
   | 3-Axis Accelerometer |             I2C              |
   | Switch               |             D7               |


   > **Note**: You can plug the accelerometer into either I2C port.

1. Open the `AZIoTMQTT_Client.ino` sketch in the Arduino IDE
1. Change the variables: `Device ID`, `Key`, `Host`
   > Optional: `SSID`, `Password`
1. Deploy the sketch

```
//TODO: Fix variable names above and add detail to instructions
```


# Next
Now that we have our NodeMCU communicating with Azure, let's use some Azure Features to visualize and analyze the data!

*Next Step*: [Stream Analytics](5_Stream_Analytics.md)