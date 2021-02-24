#include "MimicArm.h"
#include <Arduino.h>
#include <PinChangeInterrupt.h>
#include "MimicJoint.h"


MimicArm* MimicArm::MimicArmInstance;


void MimicArm::Setup() {
    int BaseSignalPin = A8;
    int ShoulderSignalPin = A9;
    int ElbowSignalPin = A10;
    int WristSignalPin = A11;
    int ClawSignalPin = A12;

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

    MimicArmInstance->Base.Setup(BaseSignalPin, BaseAngleOffset, BaseAngleMin, BaseAngleMax);
    MimicArmInstance->Shoulder.Setup(ShoulderSignalPin, ShoulderAngleOffset, ShoulderAngleMin, ShoulderAngleMax);
    MimicArmInstance->Elbow.Setup(ElbowSignalPin, ElbowAngleOffset, ElbowAngleMin, ElbowAngleMax);
    MimicArmInstance->Wrist.Setup(WristSignalPin, WristAngleOffset, WristAngleMin, WristAngleMax);
    MimicArmInstance->Claw.Setup(ClawSignalPin, ClawAngleOffset, ClawAngleMin, ClawAngleMax);
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