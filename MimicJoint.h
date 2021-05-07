#pragma once
#include <Arduino.h>

class MimicJoint {
    public:
        void Setup(int signalPin, double signalMin, int signalToAngleConversion);
        int GetAngle();

    private:
        int SignalPin;

        double SignalMin;
        int SignalToAngleConversion;

        volatile int Angle = 0;
        volatile unsigned long MicrosAtFall;
        volatile unsigned long MicrosAtRise;

        static void Falling();
        static void Rising();
        
        class JointInstances {
            public:
                MimicJoint* GetInstance(int jointPin) {
                    for(int i = 0; i < this->elements; i++)
                        if(this->Pins[i] == jointPin)
                            return this->Joints[i];
                    return nullptr;
                };
                void Append(int jointPin, MimicJoint* jointInstance) {
                    this->Pins[elements] = jointPin;
                    this->Joints[elements] = jointInstance;
                    this->elements++;
                };
            private:
                int elements = 0;
                #define NUM_JOINTS 6    //Sorry, it's hard coded to avoid dynamic horror
                int Pins[NUM_JOINTS];
                MimicJoint* Joints[NUM_JOINTS];
        };
        static JointInstances jointInstances;
};
