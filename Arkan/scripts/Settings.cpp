#include "Settings.h"

using namespace sf;

//задаём высоту и ширину окна, а так же скорость шарика. 
const float Settings::windowWidth = 612.0f;
const float Settings::windowHeight = 612.0f;
const float Settings::speed = 300.0f;
int Settings::score = 0;
int Settings::level = 1; //Не успели доделать 
int Settings::lifes = 3;

RenderWindow Settings::window(VideoMode(windowWidth, windowHeight), "Arkanoid", Style::Close | Style::Titlebar);
