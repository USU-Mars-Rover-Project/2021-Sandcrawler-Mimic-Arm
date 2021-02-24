#pragma once

#include <Arduino.h>
#include <Servo.h>


#define BASE_OUTPUT_PIN 9
#define SHOULDER_OUTPUT_PIN 10
#define ELBOW_OUTPUT_PIN 11
#define WRIST_OUTPUT_PIN 12
#define CLAW_OUTPUT_PIN 13


class RoboticArm {
    public:
        void Setup();

        void SetBaseAngle(int baseAngle);
        void SetShoulderAngle(int shoulderAngle);
        void SetElbowAngle(int elbowAngle);
        void SetWristAngle(int wristAngle);
        void SetClawAngle(int clawAngle);

        void UpdateArmPosition();

    private:
        int BaseSignalPin;
        int ShoulderSignalPin;
        int ElbowSignalPin;
        int WristSignalPin;
        int ClawSignalPin;

        int BaseAngle;
        int ShoulderAngle;
        int ElbowAngle;
        int WristAngle;
        int ClawAngle;

        Servo BaseServo;
        Servo ShoulderServo;
        Servo ElbowServo;
        Servo WristServo;
        Servo ClawServo;
};