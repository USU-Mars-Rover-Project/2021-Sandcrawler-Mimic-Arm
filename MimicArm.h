#pragma once
#include "MimicJoint.h"

#define BASE_SIGNAL_PIN A8
#define SHOULDER_SIGNAL_PIN A9
#define ELBOW_SIGNAL_PIN A10
#define WRIST_SIGNAL_PIN A11
#define FOREARM_SIGNAL_PIN A12
#define CLAW_SIGNAL_PIN A13

#define BASE_ANGLE_OFFSET 0
#define SHOULDER_ANGLE_OFFSET 0
#define ELBOW_ANGLE_OFFSET 0
#define WRIST_ANGLE_OFFSET 0
#define FOREARM_ANGLE_OFFSET 0
#define CLAW_ANGLE_OFFSET 0

#define BASE_ANGLE_MIN 0
#define SHOULDER_ANGLE_MIN 0
#define ELBOW_ANGLE_MIN 0
#define WRIST_ANGLE_MIN 0
#define FOREARM_ANGLE_MIN 0
#define CLAW_ANGLE_MIN 0

#define BASE_ANGLE_MAX 360
#define SHOULDER_ANGLE_MAX 360
#define ELBOW_ANGLE_MAX 360
#define WRIST_ANGLE_MAX 360
#define FOREARM_ANGLE_MAX 360
#define CLAW_ANGLE_MAX 360

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
