#ifndef CARD_H
#define CARD_H
#include "SFML\Graphics.hpp"
using namespace sf;

class Card
{
private:
	Sprite sprite;
	char color;
	char value;
	int posX;
	int posY;
public:
	Card();
	void setSprite(const Sprite &t);
	void setColor(char);
	void setValue(char);
	void setPos(int, int);
	Sprite getSprite();
	char getColor() const;
	char getValue() const;
	int getPosX() const;
	int getPosY() const;
};

#endif