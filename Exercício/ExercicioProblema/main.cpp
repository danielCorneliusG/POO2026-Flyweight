#include "Lantern.h"
#include <list>

int main()
{
    std::list<Lantern> flashLights;

    flashLights.push_back(
        Lantern("Lantern.png", 10, 10)
    );

    flashLights.push_back(
        Lantern("Lantern.png", 20, 20)
    );

    flashLights.push_back(
        Lantern("Lantern.png", 30, 30)
    );

    flashLights.push_back(
        Lantern("Lantern.png", 40, 40)
    );

    for (Lantern& lantern : flashLights)
    {
        lantern.create();
    }

    return 0;
}