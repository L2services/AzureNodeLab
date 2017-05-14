# Software Installation

> **Note**: If you are completing the lab in person, check with your lab leader to see if there is a local copy of the files available.  If so, use the portable installation on your thumb drive and skip to [Install Device Explorer](#install-device-explorer) and then proceed to the Install Libraries (Offline) step.

## Install the Arduino IDE
1. Download the [Windows Installer](https://downloads.arduino.cc/arduino-1.8.2-windows.exe)
1. Run the `arduino-1.8.2-windows.exe` executable  
1. Leave the default options selected to install the IDE and supporting drivers  
![Installation Options](/images/software_install/arduino-windows_install_options.png)
1. Leave the default installation **Destination Folder** unchanged and select **Install**  <!--![Installation Folder](/images/software_install/arduino-windows_install_folder.png)-->
1. Wait for the installation to complete. Toward the end of the installation, you may be prompted to install several drivers. Select **Install** for each prompt.  
    * Adafruit Ports  
    * Arduino USB Driver (from Arduino srl)  
    * Arduino USB Driver (from Arduino LLC)  <!--![Arduino USB Driver LLC](/images/software_install/driver_arduino_llc.png)-->
1. Click **Close** to complete the Arduino IDE installation  
  <!--![First Driver](/images/software_install/arduino-windows_finish.png)-->

## Configure Arduino IDE for ESP8266
1. Open the Arduino IDE and click on **File** → **Preferences**  
![Arduino Desktop Icon](/images/software_configuration/Arduino_Desktop_Icon.png)  
![Arduino File Preferences](/images/software_configuration/Arduino_File_Preferences_Annotated.png)
1. Find the **Aditional Boards Manager URLs** and enter the following:
`http://arduino.esp8266.com/stable/package_esp8266com_index.json`  
**Note**: If you already use the Arduino IDE and already have a URL in this field, you can also click the small box to the right of the field to open a larger window to enter the ESP8266 package on a new line.
![Boards Manager URLs](/images/software_configuration/Arduino_Preference_BM.png)
1. Click **OK** to close the Preference Screen
1. Open the menu: **Tools** → **Board** → **Boards Manager**  
![Arduino File Preferences](/images/software_configuration/Arduino_Boards_Manager.png)  
**Note**: If this is your first time running the Boards Manager, you may have to wait a moment while it downloads the packages.
1. Type `ESP8266` in the search box at the top of the Boards Manager screen
1. Click the **esp8266** record to select the row then select `Install` to install the package.
![ESP8266 Package Installation](/images/software_configuration/Board_Manager_ESP8266.png)  
**Note**: The installation may take several minutes as the file is a large download. The version of the esp8266 package used in this lab is 2.3.0
1. Open the menu: **Tools** → **Board** and select **NodeMCU 1.0**  
![Select Board 1](/images/software_configuration/board_selection1.png)  
![Select Board 2](/images/software_configuration/board_selection2.png)  

Note: If any of the board configuration settings have been changed, be sure to change them back to the defaults documented below:
   > **Board**: "NodeMCU 1.0 (ESP-12E Module)"  
   >**CPU Frequency**: "80 MHz"  
   >**Flash Size**: "4M (3M SPIFFS)"  
   >**Upload Speed**: "115200"  
   >**Port**: *{see Device Manager}*  

   ![Board Configuration](/images/board_configuration/board_configuration.png)

## Install Device Explorer
While many of the steps for provisioning new devices and managing IoT Hub can be completed via the Azure Portal, the Azure Device Explorer is a great tool for development and debugging. In addition to the Azure Device Explorer linked to below, Microsoft also offers a cross-platform CLI tool called [IoT Hub Explorer](https://github.com/Azure/iothub-explorer).

1. Download the [Device Explorer](https://github.com/Azure/azure-iot-sdk-csharp/releases/download/2017-5-5/SetupDeviceExplorer.msi) installer
2. Run the installer and follow the on-screen prompts to complete the installation
   > Note: After completing the installation, if you can't find the shortcut in your Start Menu, try looking for the executable at:  
   >`C:\Program Files (x86)\Microsoft\DeviceExplorer\DeviceExplorer.exe`

# [Next ▻](2_B_Install_Libraries_offline.md)
Now that we've installed the Arduino IDE and configured the IDE to interact with our NodeMCU prototyping board, let's install the supporting libraries!

*Next Step*: [Install Libraries (offline)](2_B_Install_Libraries_offline.md)