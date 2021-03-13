#include "homedoors.h"
#include <iostream>

HomeDoors::HomeDoors()
{

}

void HomeDoors::openDoors()
{
    std::cout<<"Doors opened"<<std::endl;
}

void HomeDoors::closeDoors()
{
    std::cout<<"Doors closed"<<std::endl;
}

void HomeDoors::lockDoors()
{
    std::cout<<"Doors locked"<<std::endl;
}

void HomeDoors::unlockDoors()
{
    std::cout<<"Doors unlocked"<<std::endl;
}
