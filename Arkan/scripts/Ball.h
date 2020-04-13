#ifndef BALL
#define BALL

#include <SFML/Graphics.hpp>
#include "Block.h"
#include "Settings.h"
#include "Raketka.h"

class Ball
{
private:
    
    float speed;
    sf::Vector2f velocity;

    void setAngle(float ang);
    float getAngle();

public:
	sf::CircleShape circle;
    Ball(float radius, const sf::Vector2f & position, const sf::Color & color, float speed, float angle);

    bool checkColission(const Block & block);
    bool checkColission(const Raketka & raketka);
    bool exist() { return bottom() < Settings::windowHeight; }

    void Update(float deltaTime);

    void Draw(sf::RenderWindow & window);

    float left()   const { return circle.getPosition().x - circle.getRadius(); }
    float rigth()  const { return circle.getPosition().x + circle.getRadius(); }
    float top()    const { return circle.getPosition().y - circle.getRadius(); }
    float bottom() const { return circle.getPosition().y + circle.getRadius(); }

    float getX() const { return circle.getPosition().x; }
    float getY() const { return circle.getPosition().y; }
    sf::Vector2f getPosition() const { return circle.getPosition(); }
    float getRadius() const { return circle.getRadius(); }
    sf::Vector2f getVelocity() const {return velocity; }

};

#endif
