# Frequently Asked Questions
* **Q: Do I need any special drivers?**  
  A: You may need the [CP210x Driver](https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers) if it's not already installed on your system. Windows Update can also install these drivers if you are connected to the internet and your computer policy allows it.
* **Q: The text in my Serial Port Monitor is all boxes/squares, what should I do?**  
  A: Make sure to select the correct baud rate in the bottom-right corner of the Serial Port Monitor. For this lab, we are using `115200`.  
* **Q: I'm getting a `XYZ` error in my Serial Port Monitor, what should I do?**  
  A: Try closing reopening the Serial Port by selecting Tools → Port and then reselecting your desired port.  
* **Q: Are there other debugging steps I can take related to a failed WiFi connection?**  
  A: Set "Debug Port: Serial" and "Debug Level: Core" in the Arduino IDE Tools menu. Add `Serial.setDebugOutput(true);` after `Serial.begin(9600);`. This will print additional information from the WiFi stack which may provide hints as to what is going wrong.  
* **Q: How can I check if the WiFi connection is established before connecting?**  
  A: Use the following snippet:
  ```
  if (WiFi.status() != WL_CONNECTED) {
    WiFi.begin(ssid, password);
  }
  ```  
* **Q: I'm still having issues connecting to WiFi even after trying the above troubleshooting steps**  
  A: Try the following:
  ```
  WiFi.persistent(false);
  WiFi.mode(WIFI_OFF);   // this is a temporary line, to be removed after SDK update to 1.5.4
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  ```  
* **Q: This isn't working for me on `ESP-01`, `ESP-003`, or other alternative board - what can I do?**  
  A: Try adding the following snippet immediately before the `WiFi.begin(ssid, password);` line:
  ```
  WiFi.setOutputPower(0);
  ```  
* **Q: Can I set a fallback where the device will broadcast it's own Access Point?**  
  A: Check out the following snippet: [AP Fallback GitHub comment](https://github.com/esp8266/Arduino/issues/2186#issuecomment-260182998)