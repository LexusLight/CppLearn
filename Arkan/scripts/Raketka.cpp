#include "Raketka.hpp"

using namespace sf;
Raketka::Raketka(const Vector2f & size, const Vector2f & position, const Color & color, float speed)
{
    paddle.setSize(size);
    paddle.setPosition(position);
    paddle.setFillColor(color);
    paddle.setOrigin(size.x / 2.f, size.y / 2.f);

    this->speed = speed;
}

void Raketka::Update(float deltaTime)
{
    if (Keyboard::isKeyPressed(Keyboard::Left) && paddle.getPosition().x > 0.f)
        paddle.move(-speed * deltaTime, 0.f);
    if (Keyboard::isKeyPressed(Keyboard::Right) && paddle.getPosition().x < GlobalObjects::windowWidth)
        paddle.move(speed * deltaTime, 0.f);
}

void Raketka::Draw(RenderWindow & window)
{
    window.draw(paddle);
}
