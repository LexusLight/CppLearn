#include "Settings.hpp"

using namespace sf;
const float Settings::windowWidth = 612.0f;
const float Settings::windowHeight = 612.0f;
const float Settings::speed = 300.0f;
const int Settings::level = 1;
const int Settings::lifes = 1;

RenderWindow Settings::window(VideoMode(windowWidth, windowHeight), "Arkanoid", Style::Close | Style::Titlebar);
