#include <iostream>
#include "homefacade.h"

using namespace std;

int main()
{
    //cout << "Hello World!" << endl;
    HomeFacade *facade = new HomeFacade();

    facade->EnterHome();
    facade->LeaveHome();

    return 0;

}
