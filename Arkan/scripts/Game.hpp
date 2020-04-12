#ifndef GAME_HPP_
#define GAME_HPP_

#include <SFML/Graphics.hpp>
#include "BlocksField.hpp"

using namespace sf;
class Game
{
private:
    static Ball * ball;
    static Raketka * paddle;
    Game() = delete;

public:
    static void createBall(const Ball & bll) { ball = new Ball(bll); }
    static void createPaddle(const Raketka & padd) { paddle = new Raketka(padd); }
    static bool Update(float deltaTime, BlocksField & blocksField);
    static void Draw(RenderWindow & window);
};

#endif // GAME_HPP_
