#include "lights.h"
#include <iostream>

Lights::Lights():
    m_dimmingState(0)
{

}

void Lights::turnOnLights(int dimmingState)
{
    m_dimmingState = dimmingState;
    std::cout<<"Light power: " << dimmingState<< "%"<<std::endl;
}

int Lights::getDimmingState()
{
    return m_dimmingState;
}

void Lights::turnOffLights()
{
    std::cout<<"Lights turned off"<<std::endl;
}
