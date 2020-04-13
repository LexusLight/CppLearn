#include <iostream>
#include "BlocksField.h"

using namespace sf;
//вводим аргумент == ширине поля, делим его на столбцы и в цикле совершаем множимые отступы, получаем поле.
BlocksField::BlocksField(const Vector2f & size, const Vector2f & position, const Color & color, int columns, int rows) //Реализуем поле
{
    Vector2f blockSize(size.x / columns, size.y / rows);

    for (int i = 0; i < columns; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            blocks.push_back(Block(blockSize - Vector2f(4.f, 4.f), position + Vector2f(blockSize.x * i + 2.f, blockSize.y * j + 2.f), color));
        }
    }
}

void BlocksField::Update(Ball & ball)
{
	//Вызывается лямбда выражение для проверки коллизий и если столкновения этого блока с шариком подтверждается
    blocks.remove_if([&ball, this](const Block & block)->bool{return ball.checkColission(block); }); 
}

void BlocksField::Draw(RenderWindow & window)
{
    for (auto &block : blocks)
    {
       block.Draw(window);
    }
}
