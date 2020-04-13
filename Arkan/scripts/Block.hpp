#ifndef BLOCK_HPP_
#define BLOCK_HPP_

#include <cmath>
#include <SFML/Graphics.hpp>
#define PI 3.14159265358979323846

using namespace sf;
class Block
{
private:
    sf::RectangleShape rect;

public:
    Block(const Vector2f & size, const Vector2f & position, const Color & color);

    void Draw(RenderWindow & window);

    float left()   const { return rect.getPosition().x; }
    float rigth()  const { return rect.getPosition().x + rect.getSize().x; }
    float top()    const { return rect.getPosition().y; }
    float bottom() const { return rect.getPosition().y + rect.getSize().y; }
};

#endif // BLOCK_HPP_
