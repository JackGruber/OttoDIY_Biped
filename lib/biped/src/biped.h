#pragma once
#ifndef _BIPED_H
#define _BIPED_H

#include <Arduino.h>
#include <ServoOsc.h>

class Biped
{
    public:
        Biped(int LL, int LF, int RL, int RF);
        void Home(void);
        void AttachServos(void);
        void DetachServos(void);
        void UpdateServos(void);
        void Jump(int time);
        void TrimServos(int left_leg, int right_leg, int left_foot, int right_foot);
    private:
        int servo_pins[4];
        int servo_trims[4];
        int servo_positions[4];

        ServoOsc servos[4];
        void MoveServos(int time, int target[4]);
};

#endif