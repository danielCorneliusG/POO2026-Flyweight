#include "Lantern.h"
#include <iostream>

Lantern::Lantern(std::string t, int px, int py)
{
    texture = t;
    x = px;
    y = py;
}

void Lantern::create()
{
    std::cout << "Lantern is position "
              << x << "," << y
              << " with texture " << texture
              << std::endl;
}