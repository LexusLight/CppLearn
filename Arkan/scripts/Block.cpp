#include "Block.h"

using namespace sf;

//элементарно
Block::Block(const Vector2f & size, const Vector2f & position, const Color & color)
{
    rect.setSize(size);
    rect.setPosition(position);
    rect.setFillColor(color);
}

void Block::Draw(RenderWindow & window)
{
    window.draw(rect);
}
