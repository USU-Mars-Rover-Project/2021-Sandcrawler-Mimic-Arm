#pragma once
#include "MimicJoint.h"

#define BASE_SIGNAL_PIN A8
#define SHOULDER_SIGNAL_PIN A9
#define ELBOW_SIGNAL_PIN A10
#define WRIST_SIGNAL_PIN A11
#define CLAW_SIGNAL_PIN A12

class MimicArm {
    public:
        static void Setup();

        static int GetBaseAngle();
        static int GetShoulderAngle();
        static int GetElbowAngle();
        static int GetWristAngle();
        static int GetClawAngle();

    private:
        static MimicArm* MimicArmInstance;  //Look up "singleton". It's kinda that.
        MimicJoint Base;
        MimicJoint Shoulder;
        MimicJoint Elbow;
        MimicJoint Wrist;
        MimicJoint Claw;
        MimicArm();
};
