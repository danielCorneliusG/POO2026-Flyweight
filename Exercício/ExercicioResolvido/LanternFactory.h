#include <map>
#include <string>
#include "LanternModel.h"

class LanternFactory
{
private:
    std::map<std::string, LanternModel *> models;

public:
    LanternModel *getModel(std::string texture);
};