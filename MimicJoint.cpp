#include <Arduino.h>
#define EI_ARDUINO_INTERRUPTED_PIN
#include <EnableInterrupt.h>
#include "MimicJoint.h"


MimicJoint::JointInstances MimicJoint::jointInstances;


void MimicJoint::Setup(int signalPin, int angleOffset, int angleMin, int angleMax) {
    signalPin = signalPin;
    AngleOffset = angleOffset;
    AngleMin = angleMin;
    AngleMax = angleMax;

    jointInstances.Append(signalPin, this);

    pinMode(signalPin, INPUT);

    enableInterrupt(signalPin, Falling, FALLING);
    enableInterrupt(signalPin, Rising, RISING);
}


int MimicJoint::GetAngle() {
    return Angle;
}


void MimicJoint::Falling() {
    MimicJoint currentJoint = *jointInstances.GetInstance(arduinoInterruptedPin);
    int microsWhileLow = currentJoint.MicrosAtRise - currentJoint.MicrosAtFall;
    currentJoint.MicrosAtFall = micros();
    int microsWhileHigh = currentJoint.MicrosAtFall - currentJoint.MicrosAtRise;
    int totalPulseLength = microsWhileLow + microsWhileHigh;
    currentJoint.Angle = map(microsWhileHigh, 0, totalPulseLength, currentJoint.AngleMin, currentJoint.AngleMax);
}


void MimicJoint::Rising() {
    MimicJoint currentJoint = *jointInstances.GetInstance(arduinoInterruptedPin);
    currentJoint.MicrosAtRise = micros();
}
