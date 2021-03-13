#include "aircondition.h"
#include <iostream>

AirCondition::AirCondition():
    m_airTemp(0)
{
}

void AirCondition::turnAirConditionON()
{
    std::cout<<"Air condition turned"<<std::endl;
}

void AirCondition::setAirTemp(int newTemp)
{
    m_airTemp = newTemp;
    std::cout<<"Set air temp to: "<<newTemp<<std::endl;
}

int AirCondition::getAirTemp()
{
    return m_airTemp;
}
