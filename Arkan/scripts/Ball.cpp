#include "Ball.hpp"
#include "Settings.hpp"
#include <iostream>

using namespace sf;
Ball::Ball(float radius, const Vector2f & position, const Color & color, float speed, float angle)
{
    circle.setRadius(radius);
    circle.setPosition(position);
    circle.setFillColor(color);
    circle.setOrigin(radius, radius);

    this->speed = speed;
    setAngle(angle);
}

void Ball::setAngle(float angle)
{
    velocity.x = speed * std::cos(angle * PI / 180);
    velocity.y = -speed * std::sin(angle * PI / 180);
}

float Ball::getAngle()
{
    // angle in range [-180; 180]
    float angle = std::atan2(-velocity.y, velocity.x) * 180 / PI;
    // angle in range [0; 360]
    if (angle < 0.f)
        angle += 360.f;
    return angle;
}

bool Ball::checkColission(const Block & block)
{
    if ( (getX() >= block.left() && getX() <= block.rigth()) ||
         (getY() >= block.top() && getY() <= block.bottom()) )
    {
        if (left() < block.rigth() && rigth() > block.left() && top() < block.bottom() && bottom() > block.top())
        {
            if (getX() < block.left() || getX() > block.rigth())
            {
                velocity.x *= -1;
            }
            else
            {
                velocity.y *= -1;
            }
			Settings::score++;
            return true;
        }
    }
    else
    {
        auto distance = [](sf::Vector2f x1, Vector2f x2)->float { return std::sqrt( pow(x1.x - x2.x, 2) + pow(x1.y - x2.y, 2) ); };

        Vector2f corner;

        if      ( distance(getPosition(), Vector2f(block.left() , block.top())   ) <= getRadius() )
            corner = Vector2f(block.left(), block.top());
        else if ( distance(getPosition(), Vector2f(block.left() , block.bottom())) <= getRadius() )
            corner = Vector2f(block.left(), block.bottom());
        else if ( distance(getPosition(), Vector2f(block.rigth(), block.top())   ) <= getRadius() )
            corner = Vector2f(block.rigth(), block.top());
        else if ( distance(getPosition(), Vector2f(block.rigth(), block.bottom())) <= getRadius() )
            corner = Vector2f(block.rigth(), block.bottom());
        else
            return false;

        float a = (-getY() + corner.y) / (getX() - corner.x);
        a = -1 / a;
        float alpha = std::atan(a) * 180 / PI;
        if (alpha < 0)
            alpha += 180;
        float beta = getAngle();

        // angle in range [0; 360]
        float angle = 2 * alpha - beta;
        // angle in range [-180; 180]
        if (angle > 180.f)
            angle -= 360.f;
        else if (angle <= -180.f)
            angle += 360.f;

        if (angle <= 0.f && angle > -8.f)
            angle = -8.f;
        else if (angle > 0.f && angle < 8.f)
            angle = 8.f;

        setAngle(angle);
        return true;
    }

    return false;
}

bool Ball::checkColission(const Raketka & raketka)
{
    if (left() < raketka.rigth() && rigth() > raketka.left() && top() < raketka.bottom() && bottom() >= raketka.top())
    {
        /*float minAngle = 120.f, maxAngle = 60.f;
        float percantage = getX() - paddle.left() / paddle.getSize().x;
        float angle = minAngle - (minAngle - maxAngle) * percantage;
        setAngle(angle);*/

        float deviation = 50.f;
        bool leftSide = getX() < raketka.getPosition().x;
        float distanceFromCenter = std::abs(getX() - raketka.getPosition().x);
        float percantage = distanceFromCenter / (raketka.getSize().x / 2.f);
        float angle = 90.f - percantage * deviation * (leftSide ? -1.f : 1.f);
        setAngle(angle);

        return true;
    }
    return false;
}

void Ball::Update(float deltaTime) //Отталкивание шарика и заскок за платформу
{
    circle.move(velocity * deltaTime);
    if (left() < 0.f + 2.f)
        velocity.x = -velocity.x;
    if (rigth() > Settings::windowWidth - 2.f)
        velocity.x = -velocity.x;
    if (top() < 0.f + 2.f)
        velocity.y = -velocity.y;
}

void Ball::Draw(RenderWindow & window)
{
    window.draw(circle);
}
