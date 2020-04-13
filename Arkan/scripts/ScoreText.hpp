#ifndef SCORETEXT_HPP_
#define SCORETEXT_HPP_

#include <string>
#include <SFML/Graphics.hpp>

using namespace sf;
class ScoreText
{
private:
	Text scoretext;
	String text;

public:
	ScoreText(const String & text, const Font &font);
	void Draw(RenderWindow & window);
};

#endif 