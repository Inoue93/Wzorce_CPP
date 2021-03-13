#ifndef HOMEFACADE_H
#define HOMEFACADE_H
#include <iostream>
#include "string"
#include "aircondition.h"
#include "homedoors.h"
#include "homewindows.h"
#include "lights.h"
#include "alarm.h"


class HomeFacade
{
    HomeDoors m_homeDoors;
    AirCondition m_airCondition;
    HomeWindows m_homeWindows;
    Lights m_lights;
    Alarm m_alarm;
public:
    HomeFacade();
    void LeaveHome();
    void EnterHome();
};


#endif // HOMEFACADE_H
