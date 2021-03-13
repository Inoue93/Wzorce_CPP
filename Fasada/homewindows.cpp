#include "homewindows.h"
#include <iostream>

HomeWindows::HomeWindows()
{

}

void HomeWindows::openWindows()
{
    std::cout<<"Home windows opened"<<std::endl;
}

void HomeWindows::closeWindows()
{
    std::cout<<"Home windows closed"<<std::endl;
}

void HomeWindows::coverWindows()
{
    std::cout<<"Home windows covered"<<std::endl;
}

void HomeWindows::uncoverWindows()
{
    std::cout<<"Home windows uncovered"<<std::endl;
}
