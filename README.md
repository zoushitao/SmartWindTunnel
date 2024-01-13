# SmartWindTunnel

## Notice

This project is a control system developed for the wind tunnel laboratory located at Harbin Institute of Technology. Also as my personal internship project. The first version of the software has been developed, but **maintenance has been discontinued** due to the fact that the IIC module of the STM32 is not stable enough in complex communication environments. The second version is still under development.

The PCB board was designed by another member of the group. It is not complicated and you can easily design it by referring to the chip manual of PCA9685.

## Description
Smart Wind Tunnel Control System Design. The smart wind tunnel is a wall consisting of a 40x40 fan array, which can be controlled independently by the I2C protocol. The speed of each fan can be controlled independently through I2C protocol to simulate the large gas movement that exists in nature. The wind tunnel is a wall consisting of a 40x40 fan array. The wind tunnel can provide the basic facilities for UAV testing, and a variety of complex wind patterns, including uniform winds, gusts, and winds, can be accomplished in an indoor environment. The wind tunnel can provide the basic facilities for UAV testing, and can perform a variety of complex wind modes in an indoor environment, including uniform wind, gust wind, gradient wind, and wave wind, and is equipped with corresponding GUI software to facilitate the interaction of users. GUI software is equipped to facilitate user interaction. The intelligent wind tunnel also has a perfect sensor system, which applies a variety of sensor algorithms to obtain the wind speed. wind speed. At the same time, the vision system is considered to obtain the position information of the vehicle, and the perfect GUI technology is utilized to provide visualization for the user. technology to provide the user with visualized interaction.

## Demonstration
![Alt Text](example/qt_terminal.png)
