#pragma once

class MimicJoint {
    public:
        void Setup(int signalPin, int angleOffset, int angleMin, int angleMax);
        int GetAngle();

    private:
        int SignalPin;

        int AngleOffset;
        int AngleMin;
        int AngleMax;

        volatile int Angle;
        volatile unsigned long MicrosAtFall;
        volatile unsigned long MicrosAtRise;

        static void Falling();
        static void Rising();
        
        class JointInstances {
            public:
                MimicJoint* GetInstance(int jointPin) {
                    for(int i = 0; i <= elements; i++)
                        if(Pins[i] == jointPin)
                            return Joints[i];
                    return nullptr;
                };
                void Append(int jointPin, MimicJoint* jointInstance) {
                    Pins[elements] = jointPin;
                    Joints[elements] = jointInstance;
                    elements++;
                };
            private:
                int elements = 0;
                #define NUM_JOINTS 5    //Sorry, it's hard coded to avoid dynamic horror
                int Pins[NUM_JOINTS];
                MimicJoint* Joints[NUM_JOINTS];
        };
        static JointInstances jointInstances;
};