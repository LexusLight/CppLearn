#ifndef RAKETKA_HPP_
#define RAKETKA_HPP_

#include <SFML/Graphics.hpp>
#include "Settings.hpp"

using namespace sf;
class Raketka
{
private:
    RectangleShape raketka;
    float speed;

public:
	Raketka(const Vector2f & size, const Vector2f & position, const Color & color, float speed);

    void Update(float deltaTime);
    Vector2f getPosition() const { return raketka.getPosition(); }
    Vector2f getSize() const { return raketka.getSize(); }

    void Draw(RenderWindow & window);

    float left()   const { return raketka.getPosition().x - raketka.getSize().x / 2.f; }
    float rigth()  const { return raketka.getPosition().x + raketka.getSize().x / 2.f; }
    float top()    const { return raketka.getPosition().y - raketka.getSize().y / 2.f; }
    float bottom() const { return raketka.getPosition().y + raketka.getSize().y / 2.f; }
};

#endif
