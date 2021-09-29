# UVC-Water-Sensor
#Scott Mikus
#Northmeadow Medical
#https://www.northmeadowmedical.com
#scott@northmeadowmedical.com
#September 29, 2021

Arduino project that senses the pressure in a water filtration system and disables the UVC light when water is not flowing through the system and the system is fully charged.

This project uses a MWMNUN Pressure Transducer (https://crit.ws/transducer) to measure an Express Water FLTSETALKUV1110Q (https://crit.ws/express) 11 stage water filtration systems working pressure at the UVC sterilizer pod (https://crit.ws/UVC) to monitor whether water is flowing through the system or if the system is charged and at rest. If the system is fully charged and no water is flowing through the system, the pressure transducer is read by an Arduino Nano (https://crit.ws/NANO) and then once processed either enables the UVC lamp or disables it via an Iot Relay (https://crit.ws/IoTRelay). Extending the life of the UVC bulb and lowering the temperature of the UVC pod and the temperature of the water that flows through it, lowering the temperature of the entire system and saving electricity.

Currently, the software is set to take 20 readings each 500 ms apart and display them via the Serial connection at 9600 Baud which can be viewed either via the supplied USB port or via a Bluetooth module (https://crit.ws/hc05). On the 16th reading the software compares the sensor to the selected pressure in Psi which is set to 35 Psi and if the pressure is lower than 35 Psi the lamp is enabled. Otherwise, the lamp is kept off. The reason behind the large number of readings before a change to the lamp is made is due to the instability of the pressure. 10 seconds (20 * 500 ms = 10 sec) allows for pressure spikes and stops the relay from switch back and forth causing noise.

Variables used can be changed and are as follows:
setpoint: Pressure at which system is charged and lamp should be turned off in Psi (35 Psi)
PowerPin: Digital pin that is connected to the Iot Relay (D2)
Pressure: Pressure that is updated by the pressure sensor in Psi
I: Increment for sensor reading (0, 1, 2, …)
Readings: number of readings to be taken as a whole (20 default)
Lamp: Lamp status (On, Off)
