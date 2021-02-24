#include <Arduino.h>
#include <Servo.h>
#include "RoboticArm.h"


void RoboticArm::Setup() {
    BaseServo.attach(BASE_OUTPUT_PIN);
    ShoulderServo.attach(SHOULDER_OUTPUT_PIN);
    ElbowServo.attach(ELBOW_OUTPUT_PIN);
    WristServo.attach(WRIST_OUTPUT_PIN);
    ClawServo.attach(CLAW_OUTPUT_PIN);
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