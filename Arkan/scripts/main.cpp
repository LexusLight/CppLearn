#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Settings.h"
#include "BlocksField.h"
#include "Raketka.h"
#include "Game.h"

using namespace sf;
int main() 
{
    Event event;
    Clock clock;
	Text text;
	Text text2;
	Text text3;
	Font font;
    float deltaTime;


	//Инициализация блока с кирпичиками, шарика и ракетки
    BlocksField blocksField(Vector2f(Settings::windowWidth, 200.f), Vector2f(0.f, 0.f), Color(82, 255, 0), 10, 3); 
    Game::newBall(Ball(15.f, Vector2f(225.0710f, 400.f), Color::Magenta, Settings::speed, 110.f));
    Game::newRaketka(Raketka(Vector2f(100.f, 10.f), Vector2f(256.f, 550.f), Color::Cyan, Settings::speed-50));

	//Находим шрифт и задаём его вместе с размером 
	font.loadFromFile("../res/FFFFORWA.TTF"); 
	text.setCharacterSize(15);
	text.setFont(font);
	text2.setCharacterSize(15);
	text2.setFont(font);
	text3.setCharacterSize(30);
	text3.setFont(font);
	
	//Задаём позиции текстовых обьектов
	text.setPosition(Vector2f(50.f, 580.f));
	text2.setPosition(Vector2f(520.f, 580.f)); 
	text3.setPosition(Vector2f(206.f, 306.f));
	

    while (true)
    {
		if (Settings::lifes < 1) {
			Settings::window.clear(Color::Red);
			text3.setString("YOU LOSER");
			Settings::window.draw(text3);
			Settings::window.display();
			continue;
		}

        while (Settings::window.pollEvent(event))
        {
            if (event.type == Event::Closed)
				Settings::window.close();
        }

		deltaTime = clock.restart().asSeconds();
		//апдейтаем игру, далее зачищаем окно и отрисовываем:
        Game::Update(deltaTime, blocksField);
		Settings::window.clear(Color(24,0,64)); 
        blocksField.Draw(Settings::window); //поле с кирпичиками
        Game::Draw(Settings::window); //отрисовываем шарик и ракетку через класс Игра

		//По кд обновляем и отрисовыаем счёт и жизни
		text.setString("SCORE:" + std::to_string(Settings::score));
		text2.setString("LIFES:" + std::to_string(Settings::lifes));
		Settings::window.draw(text);
		Settings::window.draw(text2);
		//Выводим отрисовку
        Settings::window.display();
    }

    return 0;
}
