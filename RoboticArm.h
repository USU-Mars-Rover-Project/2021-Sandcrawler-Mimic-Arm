#pragma once

#include <Arduino.h>
#include <Servo.h>


#define BASE_OUTPUT_PIN 8
#define SHOULDER_OUTPUT_PIN 9
#define ELBOW_OUTPUT_PIN 10
#define WRIST_OUTPUT_PIN 11
#define FOREARM_OUTPUT_PIN 12
#define CLAW_OUTPUT_PIN 13


class RoboticArm {
    public:
        void Setup();

        void SetBaseAngle(int baseAngle);
        void SetShoulderAngle(int shoulderAngle);
        void SetElbowAngle(int elbowAngle);
        void SetWristAngle(int wristAngle);
        void SetForearmAngle(int forearmAngle);
        void SetClawAngle(int clawAngle);

        void UpdateArmPosition();

    private:
        int BaseAngle;
        int ShoulderAngle;
        int ElbowAngle;
        int WristAngle;
        int ForearmAngle;
        int ClawAngle;

        Servo BaseServo;
        Servo ShoulderServo;
        Servo ElbowServo;
        Servo WristServo;
        Servo ForearmServo;
        Servo ClawServo;
};