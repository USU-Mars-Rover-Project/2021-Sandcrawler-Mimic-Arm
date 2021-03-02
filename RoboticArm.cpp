#include <Arduino.h>
#include <Servo.h>
#include "RoboticArm.h"


void RoboticArm::Setup() {
    pinMode(SHOULDER_OUTPUT_PIN, OUTPUT);
    this->BaseServo.attach(BASE_OUTPUT_PIN);
    this->ShoulderServo.attach(SHOULDER_OUTPUT_PIN);
    this->ElbowServo.attach(ELBOW_OUTPUT_PIN);
    this->WristServo.attach(WRIST_OUTPUT_PIN);
    this->ForearmServo.attach(FOREARM_OUTPUT_PIN);
    this->ClawServo.attach(CLAW_OUTPUT_PIN);
}


void RoboticArm::SetBaseAngle(int baseAngle) {
    this->BaseAngle = baseAngle;
}


void RoboticArm::SetShoulderAngle(int shoulderAngle) {
    this->ShoulderAngle = shoulderAngle;
}


void RoboticArm::SetElbowAngle(int elbowAngle) {
    this->ElbowAngle = elbowAngle;
}


void RoboticArm::SetWristAngle(int wristAngle) {
    this->WristAngle = wristAngle;
}


void RoboticArm::SetForearmAngle(int forearmAngle) {
    this->ForearmAngle = forearmAngle;
}


void RoboticArm::SetClawAngle(int clawAngle) {
    this->ClawAngle = clawAngle;
}


void RoboticArm::UpdateArmPosition() {
    this->BaseServo.write(BaseAngle);
    this->ShoulderServo.write(ShoulderAngle);
    this->ElbowServo.write(ElbowAngle);
    this->WristServo.write(WristAngle);
    this->ForearmServo.write(ForearmAngle);
    this->ClawServo.write(ClawAngle);
}