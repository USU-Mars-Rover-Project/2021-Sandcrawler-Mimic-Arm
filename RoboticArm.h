#pragma once

#include <Arduino.h>
#include <Servo.h>

class RoboticArm {
    public:
        RoboticArm();

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