#include <biped.h>

Biped::Biped(int left_leg, int right_leg, int left_foot, int right_foot)
{
    servo_pins[0] = left_leg;
    servo_pins[1] = right_leg;
    servo_pins[2] = left_foot;
    servo_pins[3] = right_foot;
}

void Biped::AttachServos(void)
{
    servos[0].attach(servo_pins[0]);
    servos[1].attach(servo_pins[1]);
    servos[2].attach(servo_pins[2]);
    servos[3].attach(servo_pins[3]);
}

void Biped::DetachServos(void)
{
    servos[0].detach();
    servos[1].detach();
    servos[2].detach();
    servos[3].detach();
}

void Biped::Home(void)
{
    AttachServos();
    for (int i = 0; i < 4; i++) 
    {
        servos[i].setAmplitude(0);
        servos[i].setOffset(0);
        servos[i].stop();
        servos[i].positionServo(0);       
    }

    // Save servo positions
    for (int i = 0; i < 4; i++) servo_positions[i] = 0;

    delay(500);
    DetachServos();
}

void Biped::MoveServos(int time, int target[4])
{
    unsigned long final_time;
    unsigned long step_time;
    float increments[4];

    AttachServos();
    
    if(time>10)
    {
        // calculate servo change for each update
        for (int i = 0; i < 4; i++) 
        {
            increments[i] = (target[i] - servo_positions[i]) / (time / 10.0);
        }

        final_time =  millis() + time;

        for (int iteration = 1; millis() < final_time; iteration++)
        {
            step_time = millis() + 10;
            for (int i = 0; i < 4; i++) 
            {
                servos[i].positionServo(servo_positions[i] + (iteration * increments[i]));
            }
            while (millis() < step_time); //pause
        }

        // for time problems, set servo to target position
        for (int i = 0; i < 4; i++) 
        {
            servos[i].positionServo(target[i]);
            delay(10);
        }
    }
    else
    {   
        for (int i = 0; i < 4; i++) 
        {
            servos[i].positionServo(target[i]);
            delay(10);
        }
    }

    // Save servo positions
    for (int i = 0; i < 4; i++) servo_positions[i] = target[i];
}

void Biped::UpdateServos(void)
{
    for (int i = 0; i < 4; i++) servos[i].update();
}

void Biped::Jump(int time)
{
    int up[4]={0,0,60,-60};
    int down[4]={0,0,0,0};
    MoveServos(time, up);
    MoveServos(time, down);
}

void Biped::TrimServos(int left_leg, int right_leg, int left_foot, int right_foot)
{
    servos[0].setTrim(left_leg);
    servos[1].setTrim(right_leg);
    servos[2].setTrim(left_foot);
    servos[3].setTrim(right_foot);
}

