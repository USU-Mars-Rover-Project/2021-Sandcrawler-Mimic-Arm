#include <Arduino.h>
#include "MimicArm.h"
#include <SPI.h>
#include <RF24.h>


RF24 radio(2, 3);
const byte address[] = "00001";
const char payload[20];


void setup() {
    Serial.begin(9600);

    Serial.println(radio.begin());
    radio.openWritingPipe(address);
    radio.stopListening();
    
    MimicArm::Setup();
}


void loop() {
    int baseAngle = MimicArm::GetBaseAngle();
    int shoulderAngle = MimicArm::GetShoulderAngle();
    int elbowAngle = MimicArm::GetElbowAngle();
    int wristAngle = MimicArm::GetWristAngle();
    int forearmAngle = MimicArm::GetForearmAngle();
    int clawAngle = MimicArm::GetClawAngle();

        (String('<')
      + String(baseAngle) + String(',')
      + String(shoulderAngle) + String(',')
      + String(elbowAngle) + String(',')
      + String(wristAngle) + String(',')
      + String(forearmAngle) + String(',')
      + String(clawAngle)
      + String('>')).toCharArray(payload, 20);

    radio.write(&payload, sizeof(payload));
    Serial.println(payload);
}
