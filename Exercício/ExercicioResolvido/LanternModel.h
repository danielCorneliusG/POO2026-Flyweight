#include <string>

class LanternModel
{
private:
    std::string texture;

public:
    LanternModel(std::string t);

    void Create(int x, int y);
};