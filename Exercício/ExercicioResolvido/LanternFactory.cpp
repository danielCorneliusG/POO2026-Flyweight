#include "LanternFactory.h"

LanternModel *LanternFactory::getModel(std::string texture)
{
    if (models.find(texture) == models.end())
    {
        models[texture] = new LanternModel(texture);
    }

    return models[texture];
}