#include <SFML/Graphics.hpp>
#include <iostream>
#include "Settings.hpp"
#include "BlocksField.hpp"
#include "Raketka.hpp"
#include "Game.hpp"

using namespace sf;
int main() 
{
    Event event;
    Clock clock;
    float deltaTime;

	//Инициализация блока с кирпичиками, шара и ракетки
    BlocksField blocksField(Vector2f(Settings::windowWidth, 200.f), Vector2f(0.f, 0.f), Color(82, 255, 0), 10, 3); 
    Game::newBall(Ball(10.f, Vector2f(225.0710f, 400.f), Color::Magenta, Settings::speed, 110.f));
    Game::newRaketka(Raketka(Vector2f(100.f, 10.f), Vector2f(256.f, 600.f), Color::Cyan, Settings::speed-50));
	

    while (Settings::window.isOpen())
    {
        

        while (Settings::window.pollEvent(event))
        {
            if (event.type == Event::Closed)
				Settings::window.close();
        }

		deltaTime = clock.restart().asSeconds();
        Game::Update(deltaTime, blocksField);
		Settings::window.clear(Color(24,0,64));
        blocksField.Draw(Settings::window);
        Game::Draw(Settings::window);
        Settings::window.display();
    }

    return 0;
}
