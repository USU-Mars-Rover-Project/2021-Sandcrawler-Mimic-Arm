Very Basic Use
==============
For those less familiar with Arduinos

Uploading code to Arduino
-------------------------
- Open the .ino file in Arduino IDE
- Plug in Arduino Mega through USB
- Confirm these under tools (only board and port will usually change):
  - **Board:** Arduino Mega or Mega2560
  - **Precessor:** ATmega2560 (Mega2560)
  - **Port:** COM1 or /dev/ttyACM0 or something similar
  - **Programmer:** AVRISP mkII should work
- Press the right arrow button to upload

Wiring
------

Mimic Arm 

The mimic arm has a mixture of potentiometers and encoders (which makes it confusing) with three pins: black, red, and yellow. Black is ground, red is 5V, and yellow is the signal. This code uses analog pins on the arduino (but it doesn't use them as analog pins (except for the potentiometers)). The pins for the mimic arm are found in MimicArm.h. Connect the yellow wires to these pins. 

Robotic Arm

The roboric arm reads PWM signals form the the wires labeled DOF0-DOF5 (degree of freedom) to determine its target position. This code uses the PWM pins on the arduino (for sending PWM signals). The pins used for the robotic arm are found in RoboticArm.h. Connect the DOF wires to these pins.

Code Overview
=============
This code has two sides to it. It measures the position of the mimic arm by reading the PWM signals sent by the encoders. It also generates its own PWM signal to tell the robotic arm the disired position. The code has one class for the robotic arm: RoboticArm. The code has two classes for the mimic arm: MimicArm and MimicJoint. MimicJoint is used by MimicArm.

Mimic Arm
----------
The mimc arm encoders send PWM signals. This code uses pin change interupts to read the signals.

MimicArm

This class handles the settings for the mimic arm. The settings include:
  - pin - the pin the arduino uses to measure the angle, one for each joint
  - signal minimum - the signal the arduino recieves at the minimum desired angle, one for each joint
  - signal to angle conversion - multiplier to convert signal to angle, one for each type of angle measuring device (there are encoders and pots)

The MimicArm object stores this data in the MimicJoint Objects

MimicJoint

This class handles communication with the encoders. It uses pin change interrups and callbacks to measure the length of each high and low pulse. It also calculates the angle, which is accessible through the GetAngle() member function.

Robotic Arm
-----------
See RoboticArm repository.
