#ifndef SETTINGS
#define SETTINGS

#include <SFML/Graphics.hpp>

using namespace sf;
class Settings
{ 
private:
	Settings() = delete;

public:
    static const float windowWidth, windowHeight, speed;
	static int score, level, lifes;
	static RenderWindow window;
};

#endif 
