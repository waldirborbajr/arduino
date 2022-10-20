# Arduino & NodeMCU (ESP32)

![image](https://user-images.githubusercontent.com/40029512/196993872-2bbfe6c7-3aca-4855-a3fc-4a5a6fe7a9ab.png)
![image](https://user-images.githubusercontent.com/40029512/196994196-4d54993c-9770-46b7-9ce0-74809c05a4c5.png)

# Troubleshooting - adding support to NodeMCU 

### Prerequisites: Arduino IDE 2.0 Installed

1. In your Arduino IDE 2.0, go to **File** > **Preferences**.

![image](https://user-images.githubusercontent.com/40029512/196991789-cac2d8ff-931e-4cd7-8517-a100738652a0.png)

2. Copy and paste the following line to the **Additional Boards Manager URLs** field

`http://arduino.esp8266.com/stable/package_esp8266com_index.json`

![image](https://user-images.githubusercontent.com/40029512/196991952-27d66882-4004-4727-8ad4-f01649d233c3.png)

3. Open the Boards Manager. You can go to **Tools > Board > Boards Manager**… or you can simply click the **Boards Manager** icon at the left-side corner.

![image](https://user-images.githubusercontent.com/40029512/196992053-c52789d6-1c27-4561-bfe8-bfe0578008ce.png)

4. Search for **ESP8266** and press the install button for **esp8266** by **ESP8266** Community.

![image](https://user-images.githubusercontent.com/40029512/196992102-bbdb76e6-82d0-4657-8642-3a6fba26856f.png)

# Troubleshooting - NodeMCU not detected by MacOS

1. Install the driver for the NodeMCU

https://github.com/adrianmihalko/ch340g-ch34g-ch34x-mac-os-x-driver

or 

https://github.com/nodemcu/nodemcu-devkit/tree/master/Drivers

