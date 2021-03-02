#include <Arduino.h>
#include "MimicArm.h"
#include "RoboticArm.h"


RoboticArm roboticArm;


void setup() {
    Serial.begin(9600);

    delay(1000);

    MimicArm::Setup();
    roboticArm.Setup();
}


void loop() {
    int baseAngle = MimicArm::GetBaseAngle();
    int shoulderAngle = MimicArm::GetShoulderAngle();
    int elbowAngle = MimicArm::GetElbowAngle();
    int wristAngle = MimicArm::GetWristAngle();
    int forearmAngle = MimicArm::GetForearmAngle();
    int clawAngle = MimicArm::GetClawAngle();
//*
    Serial.println(baseAngle);
    Serial.print("Shoulder: ");
    Serial.println(shoulderAngle);
    Serial.println(elbowAngle);
    Serial.println(wristAngle);
    Serial.println(forearmAngle);
    Serial.println(clawAngle);
//*/
    roboticArm.SetBaseAngle(baseAngle);
    roboticArm.SetShoulderAngle(shoulderAngle);
    roboticArm.SetElbowAngle(elbowAngle);
    roboticArm.SetWristAngle(wristAngle);
    roboticArm.SetForearmAngle(forearmAngle);
    roboticArm.SetClawAngle(clawAngle);

    roboticArm.UpdateArmPosition();
}
