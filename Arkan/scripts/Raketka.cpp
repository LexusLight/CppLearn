#include "Raketka.hpp"

using namespace sf;
Raketka::Raketka(const Vector2f & size, const Vector2f & position, const Color & color, float speed)
{
	raketka.setSize(size);
	raketka.setPosition(position);
	raketka.setFillColor(color);
	raketka.setOrigin(size.x / 2.f, size.y / 2.f);

    this->speed = speed;
}

void Raketka::Update(float deltaTime)
{
    if (Keyboard::isKeyPressed(Keyboard::Left) && raketka.getPosition().x > 0.f)
		raketka.move(-speed * deltaTime, 0.f);
    if (Keyboard::isKeyPressed(Keyboard::Right) && raketka.getPosition().x < Settings::windowWidth)
		raketka.move(speed * deltaTime, 0.f);
}

void Raketka::Draw(RenderWindow & window)
{
    window.draw(raketka);
}
