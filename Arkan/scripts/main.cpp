#include <SFML/Graphics.hpp>
#include <iostream>
#include "GlobalObjects.hpp"
#include "BlocksField.hpp"
#include "Raketka.hpp"
#include "Game.hpp"

using namespace sf;
int main()
{
    Event event;
    Clock clock;
    float deltaTime;

    BlocksField blocksField(Vector2f(GlobalObjects::windowWidth, 200.f), Vector2f(0.f, 0.f), Color::Yellow, 9, 7);
    Game::createBall(Ball(10.f, Vector2f(225.0710f, 400.f), Color::Magenta, 180.f, 110.f));
    Game::createPaddle(Raketka(Vector2f(100.f, 10.f), Vector2f(256.f, 450.f), Color::Cyan, 200.f));

    while (GlobalObjects::window.isOpen())
    {
        

        while (GlobalObjects::window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                GlobalObjects::window.close();
        }

		deltaTime = clock.restart().asSeconds();
        Game::Update(deltaTime, blocksField);
        GlobalObjects::window.clear(Color(24,0,64));
        blocksField.Draw(GlobalObjects::window);
        Game::Draw(GlobalObjects::window);
        GlobalObjects::window.display();
    }

    return 0;
}
