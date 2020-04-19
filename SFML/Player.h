#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"

class Player
{
private:
	Card * * cards;
	int noOfCards;
	int capacity;
public:
	Player();
	void setCardValue(int i,char c);
	void setCardColor(int i, char v);
	Card getCard(int) const;
	bool addCard(const Sprite &, int x, int y);
	Card* removeCard(int, bool);
	int getNoOfCards() const;
	~Player();
private:
	bool isValidIndex(int) const;
	void reSize(int);
	void getRandomCard(int &, int &);
};

#endif