#ifndef GLOBALOBJECTS_HPP_
#define GLOBALOBJECTS_HPP_

#include <SFML/Graphics.hpp>

using namespace sf;
class GlobalObjects
{
private:
    GlobalObjects() = delete;

public:
    static const float windowWidth, windowHeight;
    static RenderWindow window;
};

#endif // GLOBALOBJECTS_HPP_
