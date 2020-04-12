#ifndef BLOCKSFIELD_HPP_
#define BLOCKSFIELD_HPP_

#include <list>
#include "Ball.hpp"

using namespace sf;
class BlocksField
{
private:
    std::list<Block> blocks;

public:
    BlocksField(const Vector2f & size, const Vector2f & position, const Color & color, int columns, int rows);

    void Update(Ball & ball);

    void Draw(RenderWindow & window);
};

#endif // BLOCKSFIELD_HPP_
