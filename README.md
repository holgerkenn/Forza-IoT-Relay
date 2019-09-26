# Forza-IoT-Relay
This is a toy project to take telemetry from the Forza Horizon 4 game and sent it to an Azure IoT Hub using an Azure IoT Dev kit.

## requirements
To run this, you need:
1. an XBox One (but a powerful PC might also do)
2. Forza Horizon 4 Standard or higher (the demo version lacks the telemetry output)
3. A MXChip-based Azure IoT dev kit (see https://microsoft.github.io/azure-iot-developer-kit/)
4. Visual Studio Code and the Arduino Toolchain, see https://docs.microsoft.com/en-us/azure/iot-hub/iot-hub-arduino-iot-devkit-az3166-get-started#prepare-the-development-environment for the setup instructions

## setup instructions
1. Start VS code
2. run command "Azure IOT Device Workbench: Create Project". Name the project. Chose "Arduino" as platform
3. chose "MXChip IoT DevKit with Azure IoT Hub" as project template
4. Right-Click "device folder" and click "reveal in explorer"
5. Open Git bash, navigate to the same folder.
6. Close VS Code
7. mv Device DeviceOld
8. git clone https://github.com/holgerkenn/Forza-IoT-Relay.git Device
9. mv DeviceOld/.* Device (ignore the errors)
10. rm -rf DeviceOld

## compile and upload instructions
1. Open the project in VS Code
2. Attach the MXChip Dev kit to an USB port
3. Run command "Azure IoT Device Workbench: Upload Device Code". This triggers the compile process and will ask for the serial port the kit is connected to.
4. After the code is uploaded, the device will reset.

## set up wifi and Azure iot hub credentials
1. Install a serial port terminal program, e.g. putty for Windows (https://www.chiark.greenend.org.uk/~sgtatham/putty/)
2. Attach the MXChip Dev kit to an USB port.
3. Hold down button A and press the reset button
4. Use the terminal program to connect to the USB serial port of the board, use 115200 as speed and 8n1 as connection parameters.
5. Press enter and you should see a prompt '#'
6. type 'help' and enter, you should see a list of commands
7. type 'set_wifissid ' and your wifi ssid and enter
8. type 'set_wifipwd ' and your wifi password and enter
9. type 'set_az_iothub ' and your iot hub connection string and enter
10. type 'exit' and the board will reboot
11. The board should display its IP address if the connection to wifi was successful. You can watch the serial output for further debug information.

## set up Forza Horizon 4 telemetry output
1. start the game, play through the first run experience if you haven't yet.
2. Press the hamburger key (three horizontal lines) on the controler
3. Go to settings
4. Go to HUD and Gameplay
5. Scroll down to the bottom
6. Enable telemerty/data output
7. Enter ip address of the board (press x on controller to edit)
8. Enter 6669 as ip port (press x on controller to edit)
9. return to game and drive. The display of the MXChip dev kit should now display timestamp, speed, RPM and gear.



