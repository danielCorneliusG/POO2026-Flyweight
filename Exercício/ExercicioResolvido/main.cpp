#include "LanternFactory.h"
#include <iostream>

int main()
{
    LanternFactory factory;

    LanternModel* lanternIron =
        factory.getModel("iron.png");

    LanternModel* lanternIron2 =
        factory.getModel("iron.png");

    LanternModel* lanternSteel =
        factory.getModel("steel.png");

    lanternIron->Create(10, 20);
    lanternIron2->Create(30, 40);
    lanternSteel->Create(50, 60);

    std::cout << "\nlanternIron  = " << lanternIron << std::endl;
    std::cout << "lanternIron2 = " << lanternIron2 << std::endl;
    std::cout << "lanternSteel = " << lanternSteel << std::endl;

    std::cout << "\nIron lanterns are the same object as displayed by their address" << std::endl;

    return 0;
}