#include <Arduino.h>
#include <Servo.h>
#include "RoboticArm.h"


RoboticArm::RoboticArm() {
    BaseSignalPin = 9;
    ShoulderSignalPin = 10;
    ElbowSignalPin = 11;
    WristSignalPin = 12;
    ClawSignalPin = 13;
}


void RoboticArm::Setup() {
    BaseServo.attach(BaseSignalPin);
    ShoulderServo.attach(ShoulderSignalPin);
    ElbowServo.attach(ElbowSignalPin);
    WristServo.attach(WristSignalPin);
    ClawServo.attach(ClawSignalPin);
}


void RoboticArm::SetBaseAngle(int baseAngle) {
    BaseAngle = baseAngle;
}


void RoboticArm::SetShoulderAngle(int shoulderAngle) {
    ShoulderAngle = shoulderAngle;
}


void RoboticArm::SetElbowAngle(int elbowAngle) {
    ElbowAngle = elbowAngle;
}


void RoboticArm::SetWristAngle(int wristAngle) {
    WristAngle = wristAngle;
}


void RoboticArm::SetClawAngle(int clawAngle) {
    ClawAngle = clawAngle;
}


void RoboticArm::UpdateArmPosition() {
    BaseServo.write(BaseAngle);
    ShoulderServo.write(ShoulderAngle);
    ElbowServo.write(ElbowAngle);
    WristServo.write(WristAngle);
    ClawServo.write(ClawAngle);
}