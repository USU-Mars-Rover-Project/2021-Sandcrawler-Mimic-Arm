#include <Arduino.h>
#define EI_ARDUINO_INTERRUPTED_PIN
#include <EnableInterrupt.h>
#include "MimicJoint.h"


MimicJoint::JointInstances MimicJoint::jointInstances;


void MimicJoint::Setup(int signalPin, int angleOffset, int angleMin, int angleMax) {
    this->SignalPin = signalPin;
    this->AngleOffset = angleOffset;
    this->AngleMin = angleMin;
    this->AngleMax = angleMax;

    jointInstances.Append(this->SignalPin, this);
    
    pinMode(this->SignalPin, INPUT);
    enableInterrupt(this->SignalPin, Falling, FALLING);
}


int MimicJoint::GetAngle() {
    return this->Angle;
}


void MimicJoint::Falling() {
    MimicJoint* currentJoint = jointInstances.GetInstance(arduinoInterruptedPin);
    unsigned long previousMicrosAtFall = currentJoint->MicrosAtFall;
    currentJoint->MicrosAtFall = micros();
    unsigned long microsWhileHigh = currentJoint->MicrosAtFall - currentJoint->MicrosAtRise;
    unsigned long totalPulseLength = currentJoint->MicrosAtFall - previousMicrosAtFall;
    currentJoint->Angle = currentJoint->AngleOffset + (double)microsWhileHigh/totalPulseLength * (currentJoint->AngleMax-currentJoint->AngleMin) + currentJoint->AngleMin;

    enableInterrupt(currentJoint->SignalPin, Rising, RISING);
}


void MimicJoint::Rising() {
    MimicJoint* currentJoint = jointInstances.GetInstance(arduinoInterruptedPin);
    currentJoint->MicrosAtRise = micros();

    enableInterrupt(currentJoint->SignalPin, Falling, FALLING);
}
