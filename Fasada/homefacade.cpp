#include "homefacade.h"
#include <iostream>


HomeFacade::HomeFacade()
{

}

void HomeFacade::LeaveHome()
{
        std::cout << " Leave Home" << std::endl;
        m_lights.turnOffLights();
        m_airCondition.~AirCondition();
        m_homeWindows.closeWindows();
        m_homeDoors.closeDoors();
        m_alarm.alarmOn();
}

void HomeFacade::EnterHome()
{
    std::cout << " Enter Home" << std::endl;
    m_homeDoors.openDoors();
    m_lights.turnOnLights(5);
    m_alarm.alarmOff();
}
