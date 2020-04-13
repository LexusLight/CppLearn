#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Settings.hpp"
#include "BlocksField.hpp"
#include "Raketka.hpp"
#include "Game.hpp"

using namespace sf;
int main() 
{
    Event event;
    Clock clock;
	Text text;
	Text text2;
	Font font;
    float deltaTime;


	//Инициализация блока с кирпичиками, шара и ракетки
    BlocksField blocksField(Vector2f(Settings::windowWidth, 200.f), Vector2f(0.f, 0.f), Color(82, 255, 0), 10, 3); 
    Game::newBall(Ball(10.f, Vector2f(225.0710f, 400.f), Color::Magenta, Settings::speed, 110.f));
    Game::newRaketka(Raketka(Vector2f(100.f, 10.f), Vector2f(256.f, 550.f), Color::Cyan, Settings::speed-50));

	font.loadFromFile("../res/FFFFORWA.TTF");
	text.setCharacterSize(15);
	text.setFont(font);
	text2.setCharacterSize(15);
	text2.setFont(font);
	
	text.setPosition(Vector2f(50.f, 580.f));
	text2.setPosition(Vector2f(520.f, 580.f));
	

    while (true)
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

		text.setString("SCORE:" + std::to_string(Settings::score));
		text2.setString("LIFES:" + std::to_string(Settings::lifes));
		Settings::window.draw(text);
		Settings::window.draw(text2);
        Settings::window.display();
    }

    return 0;
}
