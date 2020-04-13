#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>
#include "BlocksField.h"

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

#endif
