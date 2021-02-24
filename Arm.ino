#include <Arduino.h>
#include "MimicArm.h"
#include "RoboticArm.h"


RoboticArm roboticArm;


void setup() {
    Serial.begin(9600);
    MimicArm::Setup();
    roboticArm.Setup();

    Serial.println('k');
}


void loop() {
    int baseAngle = MimicArm::GetBaseAngle();
    int shoulderAngle = MimicArm::GetShoulderAngle();
    int elbowAngle = MimicArm::GetElbowAngle();
    int wristAngle = MimicArm::GetWristAngle();
    int clawAngle = MimicArm::GetClawAngle();

    roboticArm.SetBaseAngle(baseAngle);
    roboticArm.SetShoulderAngle(shoulderAngle);
    roboticArm.SetElbowAngle(elbowAngle);
    roboticArm.SetWristAngle(wristAngle);
    roboticArm.SetClawAngle(clawAngle);

    roboticArm.UpdateArmPosition();
}
