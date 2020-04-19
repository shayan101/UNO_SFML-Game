#include "Card.h"

Card::Card()
{
	sprite.setTexture(Texture());
	color = ' ';
	value = ' ';
	posX = 0;
	posY = 0;
}

void Card::setSprite(const Sprite& t)
{
	sprite = t;
}

void Card::setColor(char c)
{
	color = c;
}

void Card::setValue(char v)
{
	value = v;
}

void Card::setPos(int x, int y)
{
	posX = x;
	posY = y;
	sprite.setPosition(Vector2f(x, y));
}

Sprite Card::getSprite()
{
	return sprite;
}

char Card::getColor() const
{
	return color;
}

char Card::getValue() const
{
	return value;
}

int Card::getPosX() const
{
	return posX;
}

int Card::getPosY() const
{
	return posY;
}