#ifndef PADDLE_HPP_
#define PADDLE_HPP_

#include <SFML/Graphics.hpp>
#include "GlobalObjects.hpp"

using namespace sf;
class Raketka
{
private:
    sf::RectangleShape paddle;
    float speed;

public:
	Raketka(const Vector2f & size, const Vector2f & position, const Color & color, float speed);

    void Update(float deltaTime);
    Vector2f getPosition() const { return paddle.getPosition(); }
    Vector2f getSize() const { return paddle.getSize(); }

    void Draw(RenderWindow & window);

    float left()   const { return paddle.getPosition().x - paddle.getSize().x / 2.f; }
    float rigth()  const { return paddle.getPosition().x + paddle.getSize().x / 2.f; }
    float top()    const { return paddle.getPosition().y - paddle.getSize().y / 2.f; }
    float bottom() const { return paddle.getPosition().y + paddle.getSize().y / 2.f; }
};

#endif // PADDLE_HPP_
