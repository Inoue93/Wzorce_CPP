#include "alarm.h"
#include <iostream>


Alarm::Alarm()
{
}

void Alarm::alarmOn()
{
    std::cout<<"Alarm turned on"<<std::endl;
}

void Alarm::alarmOff()
{
    std::cout<<"Alarm turned off"<<std::endl;
}
