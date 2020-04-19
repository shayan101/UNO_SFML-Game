#ifndef UNO_H
#define UNO_H
#include <iostream>
#include "Player.h"
#include "SFML\Graphics.hpp"
#include "SFML\System\Time.hpp"
using namespace sf;

class UNO
{
private:
	int turn;
	Texture normalCards[4][13];
	Texture specialCards[2];
	Sprite normalSprite[4][13];
	Sprite specialSprite[2];
	static int normalCardCount[4][13];
	static int specialCardCount[2];
	void getRandomCard(int &, int &);
	void addCardInPlayer(Player &, int,bool);
	int getCardSelectedID(const Player &, int, int);
	void initializePC(Player &);
	Sprite * * getCardBackArray(const Sprite &,int);
	void initializeCenterCard(Card &);
	void initializePlayer(Player &);
	int announceWinner(int, int);
	int getIndexOfBars(const Card &);
	int getColorOfMouseClick(int, int);
	char getColorOfIndex(int);
	int pcAutoPlay(Player &, const Card &);
	bool changeTurn(int &, const Card &, bool);
	bool hasValidMove(Player &p, const Card &c);
public:
	UNO();
	static void play();
};

#endif