/***********************************************************************
* FILENAME:
*       him_servo.h
*
* DESCRIPTION:
*       Him Simple Arduino Servo Wrapper Routines.
*
* NOTES:
*       This library was written to design just for fun.
*
* AUTHOR:
*       Sven Himstedt
*
* COPYRIGHT: 
*       Sven Himstedt 2021, All rights reserved.
*
* LICENSE:
*       This library is free software.
*       You can redistribute it and/or modify it.
*       But give credit or you are an asshole.
*
* START DATE:
*       2021/30/08
*
* CHANGES:
*
***********************************************************************/

#ifndef _HIM_SERVO_H_
#define _HIM_SERVO_H_

#include <Servo.h>


class HimServo
{
public:
    HimServo(unsigned int pinPWM, unsigned int revolution_time = 1000);
    ~HimServo();

    void init();

    bool setPos(int pos);
    int getPos();

private:
    Servo m_servo;
    unsigned int m_revolution_time;
    int m_pos;

    bool m_initialized;
    bool m_wrong_pin;

    unsigned int m_pinPWM;
};

#endif /* _HIM_SERVO_H_ */
