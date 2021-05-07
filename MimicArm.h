#pragma once
#include "MimicJoint.h"

#define BASE_SIGNAL_PIN A8
#define SHOULDER_SIGNAL_PIN A9
#define ELBOW_SIGNAL_PIN A10
#define WRIST_SIGNAL_PIN A11
#define FOREARM_SIGNAL_PIN A12
#define CLAW_SIGNAL_PIN A13

#define BASE_SIGNAL_MIN 0
#define SHOULDER_SIGNAL_MIN 0.371
#define ELBOW_SIGNAL_MIN 0
#define WRIST_SIGNAL_MIN 0
#define FOREARM_SIGNAL_MIN (0.9 * 1024)
#define CLAW_SIGNAL_MIN (1.0 * 1024)

#define SIGNAL_TO_ANGLE_CONVERSION 542
#define POT_SIGNAL_TO_ANGLE_CONVERSION (-360.0 / 1024)

class MimicArm {
    public:
        static void Setup();

        static int GetBaseAngle();
        static int GetShoulderAngle();
        static int GetElbowAngle();
        static int GetWristAngle();
        static int GetForearmAngle();
        static int GetClawAngle();

    private:
        static MimicArm* MimicArmInstance;  //Look up "singleton". It's kinda that.

        MimicJoint Base;
        MimicJoint Shoulder;
        MimicJoint Elbow;
        MimicJoint Wrist;
        MimicJoint Forearm;
        MimicJoint Claw;
        MimicArm() {};
};
