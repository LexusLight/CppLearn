#ifndef GAME_HPP_
#define GAME_HPP_

#include <SFML/Graphics.hpp>
#include "BlocksField.hpp"

using namespace sf;
class Game
{
private:
    static Ball * ball;
    static Raketka * raketka;
    Game() = delete;

public:
    static void newBall(const Ball & bll) { ball = new Ball(bll); }
    static void newRaketka(const Raketka & padd) { raketka = new Raketka(padd); }
    static bool Update(float deltaTime, BlocksField & blocksField);
    static void Draw(RenderWindow & window);
};

#endif // GAME_HPP_
