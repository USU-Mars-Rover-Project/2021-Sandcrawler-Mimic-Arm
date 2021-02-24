#pragma once
#include "MimicJoint.h"

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
