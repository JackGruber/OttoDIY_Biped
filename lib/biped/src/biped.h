#pragma once
#ifndef _BIPED_H
#define _BIPED_H

#include <Arduino.h>
#include <ServoOsc.h>

#define FORWARD 1
#define BACKWARD -1

class Biped
{
    public:
        Biped(int left_leg, int right_leg, int left_foot, int right_foot);
        void Home(void);
        void AttachServos(void);
        void DetachServos(void);
        void UpdateServos(void);
        void Jump(int time);
        void TrimServos(int left_leg, int right_leg, int left_foot, int right_foot);
        void OscillateServos(int amplitude[4], int offset[4], int phase[4], int time, float cycles);
        void Walk(int steps, int time, int direction);

    private:
        int servo_pins[4];
        int servo_trims[4];
        int servo_positions[4];

        ServoOsc servos[4];
        void MoveServos(int time, int target[4]);
};

#endif