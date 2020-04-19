#include "Player.h"
#include<time.h>
#include<cstdlib>

Player::Player()
{
	capacity = 20;
	noOfCards = 0;
	cards = new Card *[capacity];
	for (int i = 0; i < capacity; i++)
		cards[i] = nullptr;
}

void Player::setCardValue(int i, char v)
{
	cards[i]->setValue(v);
}

void Player::setCardColor(int i, char c)
{
	cards[i]->setColor(c);
}

bool Player::addCard(const Sprite &s, int x, int y)
{
	if (noOfCards >= capacity)
		reSize(capacity * 2);
	cards[noOfCards] = new Card;
	cards[noOfCards]->setSprite(s);
	cards[noOfCards]->setPos(x, y);
	noOfCards++;
	return true;
}

Card Player::getCard(int i) const
{
	if(isValidIndex(i))
		return *cards[i];
}

Card* Player::removeCard(int i, bool turn)
{
	if (!isValidIndex(i))
		return nullptr;
	int tempX = cards[i]->getPosX();
	Card * c = cards[i];
	for (int j = i; j < noOfCards - 1; j++)
	{
		cards[j] = cards[j + 1];
		cards[j]->setPos(tempX, cards[j]->getPosY());
		if(!turn)
			tempX += 40;
	}
	noOfCards--;
	cards[noOfCards] = nullptr;
	return c;
}

int Player::getNoOfCards() const
{
	return noOfCards;
}

void Player::reSize(int newCap)
{
	if (newCap <= 0)
	{
		this->~Player();
		return;
	}
	Card * * temp;
	temp = new Card *[newCap];
	capacity = newCap;
	for (int i = 0; i < capacity; i++)
		temp[i] = nullptr;
	for (int i = 0; i < noOfCards; i++)
	{
		temp[i] = new Card;
		temp[i] = cards[i];
		cards[i] = nullptr;
	}
	delete[] cards;
	cards = temp;
	temp = nullptr;
}

void Player::getRandomCard(int &i, int &j)
{
	i = rand() % 5 - 1;
	if (i == -1)
	{
		j = rand() % 2;
	}
	else
	{
		j = rand() % 13;
	}
}

Player::~Player()
{
	if (cards)
	{
		for (int i = 0; i < noOfCards; i++)
		{
			delete cards[i];
			cards[i] = nullptr;
		}
		delete[] cards;
		cards = nullptr;
	}
	noOfCards = 0;
	capacity = 0;
}

bool Player::isValidIndex(int i) const
{
	return i >= 0 && i < noOfCards;
}