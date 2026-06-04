#include "LanternModel.h"
#include <iostream>

LanternModel::LanternModel(std::string t)
{
    texture = t;
}

void LanternModel::Create(int x, int y)
{
    std::cout << "Lantern is position "
              << x << "," << y
              << " with texture " << texture
              << std::endl;
}