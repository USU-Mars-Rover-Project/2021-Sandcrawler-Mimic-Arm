#include <Arduino.h>
#include "MimicArm.h"


void setup() {
    Serial.begin(9600);

    delay(1000);

    MimicArm::Setup();
}


void loop() {
    int baseAngle = MimicArm::GetBaseAngle();
    int shoulderAngle = MimicArm::GetShoulderAngle();
    int elbowAngle = MimicArm::GetElbowAngle();
    int wristAngle = MimicArm::GetWristAngle();
    int forearmAngle = MimicArm::GetForearmAngle();
    int clawAngle = MimicArm::GetClawAngle();

    Serial.println(baseAngle);
    Serial.print("Shoulder: ");
    Serial.println(shoulderAngle);
    Serial.println(elbowAngle);
    Serial.println(wristAngle);
    Serial.println(forearmAngle);
    Serial.println(clawAngle);
}
