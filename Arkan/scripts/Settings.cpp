#include "Settings.hpp"

using namespace sf;
const float Settings::windowWidth = 612.0f;
const float Settings::windowHeight = 612.0f;
const float Settings::speed = 300.0f;
int Settings::score = 0;
int Settings::level = 1;
int Settings::lifes = 3;

RenderWindow Settings::window(VideoMode(windowWidth, windowHeight), "Arkanoid", Style::Close | Style::Titlebar);
