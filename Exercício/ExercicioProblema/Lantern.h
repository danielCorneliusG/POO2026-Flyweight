#include <string>

class Lantern{
private:
    std::string texture;
    int x, y;

public:
    Lantern(std::string t, int px, int py);
    void create();
};