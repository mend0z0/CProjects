## Medical Watch

This project is about reading some sensor input and to extract data from the person who is wearing this wrist watch. By the following, you'll see a block diagram of the whole project.

This project would be run by ATmega32 MCU which is an 8-bit MCU. The firmware will develop in C language in Microchip Studio IDE and the hardware would design by KiCAD CAD. The 3D files for electronic components or any enclosure would be done by FreeCAD CAD.

![image](D:/Projects/SiavashTP/OSSH/CProjects/MedicalWatch_ATmega32/MedicalWatch.drawio.png)

#### Block Diagram Explanation

* ATmega32: It's an 8-bit MCU from Microchip Technology corporation and it will control everything.

* MAX30102: Reading the heartbeat of the person who wore the watch. It can be used to check the heartbeat and I guess it's possible to extract the body temperature. It can be used to check if the person has any blood pressure or any other diseases. I'll write thoroughly how I am going to use it when I am writing its library.

* MPU6050: The IMU usually will be used to track the person's activities. It has more hospital purposes and also can be used by athletes.

* MCP7940: This is an RTC chip (Real Time Clock), well it's a watch!

* USB C Controller: I want to use a USB C receptacle and it must be compatible with that. I still couldn't find a good IC with I2C protocol for that but when I found it I'll edit the block diagram.

* Push Buttons: This watch includes 4 push buttons. One of the usage of push buttons is muting the vibrator or setting the time and so on...

* ATWILC1000: This IC will make the wireless connection via WIFI for two purposes, first is to update ATmega32 firmware that is called OTA (Over The Air), and secondly, for reading the stored data in the SPI flash and checking the situation the person who wore the watch.

* Serial Flash: Storing the data that has been sampled periodically from sensors for a limited amount of time.

* OLED: Displaying the extracted data from sensors, time, the battery situation, and any necessary alert.

* Vibrator: For any alarm that has been set or it'll get activated by the WIFI and the person who is observing the patient.