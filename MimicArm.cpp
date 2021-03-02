#include "MimicArm.h"
#include <Arduino.h>
#include <PinChangeInterrupt.h>
#include "MimicJoint.h"


MimicArm* MimicArm::MimicArmInstance;


void MimicArm::Setup() {
    delete MimicArmInstance;            //Much responsible. Wow.
    MimicArmInstance = new MimicArm();

    MimicArmInstance->Base.Setup(BASE_SIGNAL_PIN, BASE_ANGLE_OFFSET, BASE_ANGLE_MIN, BASE_ANGLE_MAX);
    MimicArmInstance->Shoulder.Setup(SHOULDER_SIGNAL_PIN, SHOULDER_ANGLE_OFFSET, SHOULDER_ANGLE_MIN, SHOULDER_ANGLE_MAX);
    MimicArmInstance->Elbow.Setup(ELBOW_SIGNAL_PIN, ELBOW_ANGLE_OFFSET, ELBOW_ANGLE_MIN, ELBOW_ANGLE_MAX);
    MimicArmInstance->Wrist.Setup(WRIST_SIGNAL_PIN, WRIST_ANGLE_OFFSET, WRIST_ANGLE_MIN, WRIST_ANGLE_MAX);
    MimicArmInstance->Forearm.Setup(FOREARM_SIGNAL_PIN, FOREARM_ANGLE_OFFSET,FOREARM_ANGLE_MIN,FOREARM_ANGLE_MAX);
    MimicArmInstance->Claw.Setup(CLAW_SIGNAL_PIN, CLAW_ANGLE_OFFSET, CLAW_ANGLE_MIN, CLAW_ANGLE_MAX);
}


int MimicArm::GetBaseAngle() {
    return MimicArmInstance->Base.GetAngle();
}


int MimicArm::GetShoulderAngle() {
    return MimicArmInstance->Shoulder.GetAngle();
}


int MimicArm::GetElbowAngle() {
    return MimicArmInstance->Elbow.GetAngle();
}


int MimicArm::GetWristAngle() {
    return MimicArmInstance->Wrist.GetAngle();
}


int MimicArm::GetForearmAngle() {
    return MimicArmInstance->Forearm.GetAngle
}


int MimicArm::GetClawAngle() {
    return MimicArmInstance->Claw.GetAngle();
}