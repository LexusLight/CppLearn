#include "Game.h"
#include "Settings.h"
#include <iostream>

using namespace sf;

// двойной указатель
Ball * Game::ball = nullptr;
Raketka * Game::raketka = nullptr;

bool Game::Update(float deltaTime, BlocksField & blocksField)
{
    if (raketka != nullptr)
        raketka->Update(deltaTime);


    if (ball != nullptr && ball->exist())
    {
        ball->Update(deltaTime);
        ball->checkColission(*raketka);
        blocksField.Update(*ball);
        return true;
	} if (ball->Ball::top() >= 560.f) //Вычитаем жизнь  и возвращаем шарик на место при его пропуске
	{
		ball->circle.setPosition(raketka->getPosition().x, raketka->getPosition().y - 50.f);  
		Settings::lifes--;
	}	
    else //Условие при котором пропадает мячик и спавнится новый
    {
        delete ball;
        ball = nullptr;
        return false;
    }
}

void Game::Draw(RenderWindow & window)
{ 
	//Всё понятно
    if (ball != nullptr)
        ball->Draw(window);
    if (raketka != nullptr)
        raketka->Draw(window);
}
