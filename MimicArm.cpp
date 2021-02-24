#include "MimicArm.h"
#include <Arduino.h>
#include <PinChangeInterrupt.h>
#include "MimicJoint.h"


MimicArm* MimicArm::MimicArmInstance;


void MimicArm::Setup() {
    int BaseAngleOffset = 0;
    int ShoulderAngleOffset = 0;
    int ElbowAngleOffset = 0;
    int WristAngleOffset = 0;
    int ClawAngleOffset = 0;

    int BaseAngleMin = 0;
    int ShoulderAngleMin = 0;
    int ElbowAngleMin = 0;
    int WristAngleMin = 0;
    int ClawAngleMin = 0;

    int BaseAngleMax = 360;
    int ShoulderAngleMax = 360;
    int ElbowAngleMax = 360;
    int WristAngleMax = 360;
    int ClawAngleMax = 360;

    delete MimicArmInstance;            //Much responsible. Wow.
    MimicArmInstance = new MimicArm();

    MimicArmInstance->Base.Setup(BASE_SIGNAL_PIN, BaseAngleOffset, BaseAngleMin, BaseAngleMax);
    MimicArmInstance->Shoulder.Setup(SHOULDER_SIGNAL_PIN, ShoulderAngleOffset, ShoulderAngleMin, ShoulderAngleMax);
    MimicArmInstance->Elbow.Setup(ELBOW_SIGNAL_PIN, ElbowAngleOffset, ElbowAngleMin, ElbowAngleMax);
    MimicArmInstance->Wrist.Setup(WRIST_SIGNAL_PIN, WristAngleOffset, WristAngleMin, WristAngleMax);
    MimicArmInstance->Claw.Setup(CLAW_SIGNAL_PIN, ClawAngleOffset, ClawAngleMin, ClawAngleMax);
}


int MimicArm::GetBaseAngle() {
    return MimicArmInstance->Base.GetAngle();
}


int MimicArm::GetClawAngle() {
    return MimicArmInstance->Claw.GetAngle();
}


int MimicArm::GetElbowAngle() {
    return MimicArmInstance->Elbow.GetAngle();
}


int MimicArm::GetShoulderAngle() {
    return MimicArmInstance->Shoulder.GetAngle();
}


int MimicArm::GetWristAngle() {
    return MimicArmInstance->Wrist.GetAngle();
}


MimicArm::MimicArm() {

}