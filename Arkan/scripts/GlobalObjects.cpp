#include "GlobalObjects.hpp"

using namespace sf;
const float GlobalObjects::windowWidth = 1024.f;
const float GlobalObjects::windowHeight = 1024.f;
RenderWindow GlobalObjects::window(VideoMode(windowWidth, windowHeight), "Arkanoid", Style::Close | Style::Titlebar);
