Color Detection Sensor Project

This project uses the GY-31 TCS3200/TCS230 color sensor module with an Arduino-compatible board to detect the intensity of red, green, and blue light.

Features

Reads RGB frequency values using the TCS3200/TCS230 sensor.

Converts frequency readings into approximate color intensity.

Outputs processed RGB values via the serial monitor.

Hardware Used

Arduino (Uno/Nano/compatible)

GY-31 (TCS3200/TCS230) Color Sensor Module

Jumper wires

Wiring
Sensor Pin	Arduino Pin
S0	         4
S1	         5
S2	         6
S3	         7
OUT	         8
VCC	         5V
GND	         GND
Code Overview

The uploaded .ino file performs the following:

Sets up control pins for the color sensor.

Selects color filters (R/G/B) by adjusting the S2 and S3 pins.

Reads frequency using pulseIn() to determine each color intensity.

Prints results to the Serial Monitor.

Main Functions

TCS() – Reads RGB frequency values.

setup() – Initializes pins and serial communication.

loop() – Continuously measures and prints RGB values.

Usage

Upload the code to your Arduino.

Open the Serial Monitor at 9600 baud.

Place different colored objects in front of the sensor to see RGB readings.

Included File

Color_detection_sensor_code.ino – Main program source code.
