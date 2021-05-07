#include "MimicArm.h"
#include <Arduino.h>
#include <PinChangeInterrupt.h>
#include "MimicJoint.h"


MimicArm* MimicArm::MimicArmInstance;


void MimicArm::Setup() {
    delete MimicArmInstance;            //Much responsible. Wow.
    MimicArmInstance = new MimicArm();

    MimicArmInstance->Base.Setup(BASE_SIGNAL_PIN, BASE_SIGNAL_MIN, SIGNAL_TO_ANGLE_CONVERSION);
    MimicArmInstance->Shoulder.Setup(SHOULDER_SIGNAL_PIN, SHOULDER_SIGNAL_MIN, SIGNAL_TO_ANGLE_CONVERSION);
    MimicArmInstance->Elbow.Setup(ELBOW_SIGNAL_PIN, ELBOW_SIGNAL_MIN, SIGNAL_TO_ANGLE_CONVERSION);
    MimicArmInstance->Wrist.Setup(WRIST_SIGNAL_PIN, WRIST_SIGNAL_MIN, SIGNAL_TO_ANGLE_CONVERSION);
    //MimicArmInstance->Forearm.Setup(FOREARM_SIGNAL_PIN, FOREARM_SIGNAL_MIN, SIGNAL_TO_ANGLE_CONVERSION);
    //MimicArmInstance->Claw.Setup(CLAW_SIGNAL_PIN, CLAW_SIGNAL_MIN, SIGNAL_TO_ANGLE_CONVERSION);
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
    return (analogRead(FOREARM_SIGNAL_PIN) - FOREARM_SIGNAL_MIN) * POT_SIGNAL_TO_ANGLE_CONVERSION;
}


int MimicArm::GetClawAngle() {
    return (analogRead(CLAW_SIGNAL_PIN) - CLAW_SIGNAL_MIN) * POT_SIGNAL_TO_ANGLE_CONVERSION;
}
