#ifndef SETTINGS_HPP_
#define SETTINGS_HPP_

#include <SFML/Graphics.hpp>

using namespace sf;
class Settings
{ 
private:
	Settings() = delete;

public:
    static const float windowWidth, windowHeight, speed;
	static const int level, lifes;
	static RenderWindow window;
};

#endif 
