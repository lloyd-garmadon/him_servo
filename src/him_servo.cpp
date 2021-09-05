/***********************************************************************
* FILENAME:
*       him_servo.cpp
*
* DESCRIPTION:
*       Him Simple Arduino Servo Wrapper Routines
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

#define HIM_LIBRARY_COMPILE

#include "Arduino.h"

#include "him_servo.h"


HimServo::HimServo(unsigned int pinPWM, unsigned int revolution_time) :
    m_pinPWM(pinPWM),
    m_revolution_time(revolution_time),
    m_pos(0),
    m_wrong_pin(false),
    m_initialized(false)
{
    switch(m_pinPWM) {
        case 9:     //  Timer 1
        case 10:    //  Timer 1
            break;
        default:
            m_wrong_pin = true;
    }

}

HimServo::~HimServo()
{
}


void HimServo::init()
{
    if(!m_wrong_pin && !m_initialized) {
        // attaches the servo on pin 9 to the servo object
        m_servo.attach(m_pinPWM);  

        m_initialized = true;
        m_pos = 0;
        setPos(m_pos);
        delay(m_revolution_time);
    }
}



bool HimServo::setPos(int pos)
{
    if (!m_initialized) {
        return false;
    } else if (pos < -90) {
        return false;
    } else if (pos > 90) {
        return false;
    } else {
        int distance;

        // calculate the absolute revolution distance
        distance = m_pos - pos;
        distance = (distance > 0) ? distance : -distance;

        // set the servo
        m_servo.write(pos + 90);

        // wait till position is reached
        delay(m_revolution_time * distance / 180);

        // remember the position
        m_pos = pos;

        return true;
    }
}

int HimServo::getPos()
{
    return m_pos;
}
