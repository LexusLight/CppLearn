#ifndef BLOCKSFIELD
#define BLOCKSFIELD

#include <list>
#include "Ball.h"

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

#endif
