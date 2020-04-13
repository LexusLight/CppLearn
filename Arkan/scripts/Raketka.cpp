#include "Raketka.h"

using namespace sf;

	//задаём параметры ракетки и скорость
Raketka::Raketka(const Vector2f & size, const Vector2f & position, const Color & color, float speed) //Реализация ракетки из хедера
{
	
	raketka.setSize(size);
	raketka.setPosition(position);
	raketka.setFillColor(color);
	raketka.setOrigin(size.x / 2.f, size.y / 2.f);

    this->speed = speed;
}
	
	//фактически сталкиваем позицию ракетки с краями окна
void Raketka::Update(float deltaTime)
{
    if (Keyboard::isKeyPressed(Keyboard::Left) && raketka.getPosition().x > 0.f + 50.f)
		raketka.move(-speed * deltaTime, 0.f);
    if (Keyboard::isKeyPressed(Keyboard::Right) && raketka.getPosition().x < Settings::windowWidth - 50.f)
		raketka.move(speed * deltaTime, 0.f);
}

	//Отрисовываем шейп
void Raketka::Draw(RenderWindow & window)
{
    window.draw(raketka);
}
