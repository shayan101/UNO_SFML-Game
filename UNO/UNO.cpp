#include "UNO.h"
using namespace std;
using namespace sf;

int UNO::normalCardCount[4][13] =
{
	{ 2,2,2,1,2,2,2,2,2,2,2,2,2 },
	{ 2,2,2,1,2,2,2,2,2,2,2,2,2 },
	{ 2,2,2,1,2,2,2,2,2,2,2,2,2 },
	{ 2,2,2,1,2,2,2,2,2,2,2,2,2 }
};

int UNO::specialCardCount[2] = { 4,4 };

void UNO::getRandomCard(int & i, int & j)
{
	i = rand() % 5 - 1;
	if (i == -1)
		j = rand() % 2;
	else
		j = rand() % 13;
}

void UNO::addCardInPlayer(Player &p, int size, bool turn)
{
	int x, y;
	int posX = p.getCard(p.getNoOfCards() - 1).getPosX() + 40;
	int posY = p.getCard(p.getNoOfCards() - 1).getPosY();
	int limit = p.getNoOfCards() + size;
	if (!turn)
	{
		posX = p.getCard(p.getNoOfCards() - 1).getPosX() + 40;
		posY = p.getCard(p.getNoOfCards() - 1).getPosY();
	}
	else
	{
		posX = 0;
		posY = 0;
	}
	srand(time(NULL));
	for (int i = p.getNoOfCards(); p.getNoOfCards() < limit;)
	{
		getRandomCard(x, y);
		if (x == -1 && specialCardCount[y] > 0)
		{
			if (p.addCard(specialSprite[y], posX, posY))
			{
				if (y == 0)
					p.setCardValue(i, 'W');
				else if (y == 1)
					p.setCardValue(i, 'F');
				p.setCardColor(i, 'b');
				if (!turn)
					posX += 40;
				specialCardCount[y]--;
				i++;
			}
		}
		else if (x != -1 && normalCardCount[x][y] > 0)
		{
			if (p.addCard(normalSprite[x][y], posX, posY))
			{
				if (x == 0)
					p.setCardColor(i, 'R');
				else if (x == 1)
					p.setCardColor(i, 'Y');
				else if (x == 2)
					p.setCardColor(i, 'G');
				else if (x == 3)
					p.setCardColor(i, 'B');
				if (y == 0)
					p.setCardValue(i, 'S');
				else if (y == 1)
					p.setCardValue(i, 'R');
				else if (y == 2)
					p.setCardValue(i, 'T');
				else if (y >= 3)
					p.setCardValue(i, y - 3 + 48);
				if (!turn)
					posX += 40;
				normalCardCount[x][y]--;
				i++;
			}
		}
	}
}

UNO::UNO()
{
	turn = 0;
	normalCards[0][0].loadFromFile("cards/skipRed.png");
	normalCards[0][1].loadFromFile("cards/reverseRed.png");
	normalCards[0][2].loadFromFile("cards/drawtwoRed.png");
	normalCards[0][3].loadFromFile("cards/zeroRed.png");
	normalCards[0][4].loadFromFile("cards/oneRed.png");
	normalCards[0][5].loadFromFile("cards/twoRed.png");
	normalCards[0][6].loadFromFile("cards/threeRed.png");
	normalCards[0][7].loadFromFile("cards/fourRed.png");
	normalCards[0][8].loadFromFile("cards/fiveRed.png");
	normalCards[0][9].loadFromFile("cards/sixRed.png");
	normalCards[0][10].loadFromFile("cards/sevenRed.png");
	normalCards[0][11].loadFromFile("cards/eightRed.png");
	normalCards[0][12].loadFromFile("cards/nineRed.png");
	normalCards[1][0].loadFromFile("cards/skipYellow.png");
	normalCards[1][1].loadFromFile("cards/reverseYellow.png");
	normalCards[1][2].loadFromFile("cards/drawtwoYellow.png");
	normalCards[1][3].loadFromFile("cards/zeroYellow.png");
	normalCards[1][4].loadFromFile("cards/oneYellow.png");
	normalCards[1][5].loadFromFile("cards/twoYellow.png");
	normalCards[1][6].loadFromFile("cards/threeYellow.png");
	normalCards[1][7].loadFromFile("cards/fourYellow.png");
	normalCards[1][8].loadFromFile("cards/fiveYellow.png");
	normalCards[1][9].loadFromFile("cards/sixYellow.png");
	normalCards[1][10].loadFromFile("cards/sevenYellow.png");
	normalCards[1][11].loadFromFile("cards/eightYellow.png");
	normalCards[1][12].loadFromFile("cards/nineYellow.png");
	normalCards[2][0].loadFromFile("cards/skipGreen.png");
	normalCards[2][1].loadFromFile("cards/reverseGreen.png");
	normalCards[2][2].loadFromFile("cards/drawtwoGreen.png");
	normalCards[2][3].loadFromFile("cards/zeroGreen.png");
	normalCards[2][4].loadFromFile("cards/oneGreen.png");
	normalCards[2][5].loadFromFile("cards/twoGreen.png");
	normalCards[2][6].loadFromFile("cards/threeGreen.png");
	normalCards[2][7].loadFromFile("cards/fourGreen.png");
	normalCards[2][8].loadFromFile("cards/fiveGreen.png");
	normalCards[2][9].loadFromFile("cards/sixGreen.png");
	normalCards[2][10].loadFromFile("cards/sevenGreen.png");
	normalCards[2][11].loadFromFile("cards/eightGreen.png");
	normalCards[2][12].loadFromFile("cards/nineGreen.png");
	normalCards[3][0].loadFromFile("cards/skipBlue.png");
	normalCards[3][1].loadFromFile("cards/reverseBlue.png");
	normalCards[3][2].loadFromFile("cards/drawtwoBlue.png");
	normalCards[3][3].loadFromFile("cards/zeroBlue.png");
	normalCards[3][4].loadFromFile("cards/oneBlue.png");
	normalCards[3][5].loadFromFile("cards/twoBlue.png");
	normalCards[3][6].loadFromFile("cards/threeBlue.png");
	normalCards[3][7].loadFromFile("cards/fourBlue.png");
	normalCards[3][8].loadFromFile("cards/fiveBlue.png");
	normalCards[3][9].loadFromFile("cards/sixBlue.png");
	normalCards[3][10].loadFromFile("cards/sevenBlue.png");
	normalCards[3][11].loadFromFile("cards/eightBlue.png");
	normalCards[3][12].loadFromFile("cards/nineBlue.png");
	specialCards[0].loadFromFile("cards/wild.png");
	specialCards[1].loadFromFile("cards/drawfour.png");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
			normalSprite[i][j].setTexture(normalCards[i][j]);
	}
	specialSprite[0].setTexture(specialCards[0]);
	specialSprite[1].setTexture(specialCards[1]);
}

int UNO::getCardSelectedID(const Player &p, int x, int y)
{
	for (int i = p.getNoOfCards() - 1; i >= 0; i--)
	{
		if (
			x >= p.getCard(i).getPosX() &&
			x <= p.getCard(i).getPosX() + p.getCard(i).getSprite().getGlobalBounds().width &&
			y >= p.getCard(i).getPosY() &&
			y <= p.getCard(i).getPosY() + p.getCard(i).getSprite().getGlobalBounds().height
			)
			return i;
	}
	return -1;
}

void UNO::initializePC(Player&pc)
{
	int x, y, i = 0;
	while (pc.getNoOfCards() < 7)
	{
		getRandomCard(x, y);
		if (x == -1 && specialCardCount[y] > 0)
		{
			pc.addCard(specialSprite[y], 0, 0);
			if (y == 0)
				pc.setCardValue(i, 'W');
			else if (y == 1)
				pc.setCardValue(i, 'F');
			pc.setCardColor(i, 'b');
			specialCardCount[y]--;
			i++;
		}
		else if (x != -1 && normalCardCount[x][y] > 0)
		{
			pc.addCard(normalSprite[x][y], 0, 0);
			if (x == 0)
				pc.setCardColor(i, 'R');
			else if (x == 1)
				pc.setCardColor(i, 'Y');
			else if (x == 2)
				pc.setCardColor(i, 'G');
			else if (x == 3)
				pc.setCardColor(i, 'B');
			if (y == 0)
				pc.setCardValue(i, 'S');
			else if (y == 1)
				pc.setCardValue(i, 'R');
			else if (y == 2)
				pc.setCardValue(i, 'T');
			else if (y >= 3)
				pc.setCardValue(i, y - 3 + 48);
			normalCardCount[x][y]--;
			i++;
		}
	}
}

Sprite ** UNO::getCardBackArray(const Sprite &s, int n)
{
	Sprite **arr = new Sprite*[n];
	int x = 1000, y = 36;
	for (int i = 0; i < n; i++)
	{
		arr[i] = new Sprite(s);
		arr[i]->setPosition(Vector2f(x, y));
		x -= 40;
	}
	return arr;
}

void UNO::initializeCenterCard(Card & c)
{
	int x, y;
	bool flag = false;
	srand(time(NULL));
	while (!flag)
	{
		getRandomCard(x, y);
		if (x != -1 && normalCardCount[x][y] > 0)
		{
			c.setSprite(normalSprite[x][y]);
			if (x == 0)
				c.setColor('R');
			else if (x == 1)
				c.setColor('Y');
			else if (x == 2)
				c.setColor('G');
			else if (x == 3)
				c.setColor('B');
			if (y == 0)
				c.setValue('S');
			else if (y == 1)
				c.setValue('R');
			else if (y == 2)
				c.setValue('T');
			else if (y >= 3)
				c.setValue(y - 3 + 48);
			normalCardCount[x][y]--;
			flag = true;
		}
	}
	c.setPos(567, 237);
}

void UNO::initializePlayer(Player &p)
{
	int x, y, i = 0;
	int currentX = 10, currentY = 460;
	while (p.getNoOfCards() < 7)
	{
		getRandomCard(x, y);
		if (x == -1 && specialCardCount[y] > 0)
		{
			p.addCard(specialSprite[y], currentX, currentY);
			if (y == 0)
				p.setCardValue(i, 'W');
			else if (y == 1)
				p.setCardValue(i, 'F');
			p.setCardColor(i, 'b');
			i++;
			specialCardCount[y]--;
			currentX += 40;
		}
		else if (x != -1 && normalCardCount[x][y] > 0)
		{
			p.addCard(normalSprite[x][y], currentX, currentY);
			if (x == 0)
				p.setCardColor(i, 'R');
			else if (x == 1)
				p.setCardColor(i, 'Y');
			else if (x == 2)
				p.setCardColor(i, 'G');
			else if (x == 3)
				p.setCardColor(i, 'B');
			if (y == 0)
				p.setCardValue(i, 'S');
			else if (y == 1)
				p.setCardValue(i, 'R');
			else if (y == 2)
				p.setCardValue(i, 'T');
			else if (y >= 3)
				p.setCardValue(i, y - 3 + 48);
			i++;
			normalCardCount[x][y]--;
			currentX += 40;
		}
	}
}

int UNO::announceWinner(int a, int b)
{
	if (a == 0)
		return 1;
	else if (b == 0)
		return 2;
	else
		return 0;
}

int UNO::getIndexOfBars(const Card & c)
{
	if (c.getColor() == 'R')
		return 0;
	else if (c.getColor() == 'Y')
		return 1;
	else if (c.getColor() == 'G')
		return 2;
	else if (c.getColor() == 'B')
		return 3;
	else if (c.getColor() == 'b')
		return 4;
}

int UNO::getColorOfMouseClick(int x, int y)
{
	if (x >= 392 && x <= 465 && y >= 237 && y <= 336)
		return 0;
	else if (x >= 474 && x <= 545 && y >= 237 && y <= 336)
		return 1;
	else if (x >= 554 && x <= 624 && y >= 237 && y <= 336)
		return 2;
	else if (x >= 633 && x <= 711 && y >= 237 && y <= 336)
		return 3;
	else
		return -1;
}

char UNO::getColorOfIndex(int i)
{
	if (i == 0)
		return 'R';
	else if (i == 1)
		return 'Y';
	else if (i == 2)
		return 'G';
	else if (i == 3)
		return 'B';
	else
		return 'b';
}

int UNO::pcAutoPlay(Player & pc, const Card & c)
{
	bool specialSelected = false,
		colorSelected = false,
		valueSelected = false;
	int specialCardIndex = -1,
		sameColorIndex = -1,
		sameValueIndex = -1,
		j = -1, k = -1, l = -1, index = -1;
	bool haveSpecialCard = false,
		haveSameColorCard = false,
		haveSameValueCard = false;
	int indexes[3];
	int m = 0;
	srand(time(NULL));
	for (int i = 0; i < pc.getNoOfCards(); i++)
	{
		if (pc.getCard(i).getColor() == 'b')
		{
			haveSpecialCard = true;
			j = i;
			if (rand() % 2 == 1)
			{
				specialCardIndex = j;
				specialSelected = true;
			}
		}
		else
		{
			if (pc.getCard(i).getColor() == c.getColor())
			{
				haveSameColorCard = true;
				k = i;
				if (rand() % 2 == 0)
				{
					colorSelected = true;
					sameColorIndex = k;
				}
			}
			if (pc.getCard(i).getValue() == c.getValue())
			{
				haveSameValueCard = true;
				l = i;
				if (rand() % 2 == 1)
				{
					valueSelected = true;
					sameValueIndex = l;
				}
			}
		}
	}
	if (haveSameColorCard || haveSameValueCard || haveSpecialCard)
	{
		if (!specialSelected && j != -1)
			specialCardIndex = j;
		if (!colorSelected && k != -1)
			sameColorIndex = k;
		if (!valueSelected && l != -1)
			sameValueIndex = l;
	}
	else
		return -1;
	if (specialCardIndex != -1)
	{
		indexes[m] = specialCardIndex;
		m++;
	}
	if (sameColorIndex != -1)
	{
		indexes[m] = sameColorIndex;
		m++;
	}
	if (sameValueIndex != -1)
	{
		indexes[m] = sameValueIndex;
		m++;
	}
	if (m == 0)
		return -1;
	srand(time(NULL));
	return indexes[rand() % m];
}

bool UNO::changeTurn(int & t, const Card & c, bool change)
{
	if ((c.getValue() != 'R' && c.getValue() != 'S') || change)
	{
		if (t == 0)
			t++;
		else t--;
		return true;
	}
	else
		return false;
}

bool UNO::hasValidMove(Player & p, const Card & c)
{
	for (int i = 0; i < p.getNoOfCards(); i++)
	{
		if (
			p.getCard(i).getColor() == c.getColor() ||
			p.getCard(i).getValue() == c.getValue() ||
			p.getCard(i).getColor() == 'b'
			)
			return true;
	}
	return false;
}

void UNO::play()
{
	int screenWidth = 1100, screenHeight = 600;
	bool main_screen = true;
	bool resultDeclared = false;
	bool chooseBarActive = false;
	bool validCardPick = true;
	bool noValidCard = false;
	bool turnChange = false;
	bool startTimer = false;
	int chooseBarX = 387, chooseBarY = 233;
	int barX = 660, barY = 230;
	int currentX = 10;
	int currentY = 460;
	const int setX = 470;
	const int setY = 240;
	int playerCardBoundX = currentX;
	int playerCardBoundW;
	int pcX = 1000;
	int pcY = 36;
	int barIndex = -1;
	int resultIndex = -1;
	int buttonIndex = 0;
	UNO uno;
	RenderWindow window(VideoMode(screenWidth, screenHeight), "UNO");

	Texture mainScreen;
	mainScreen.loadFromFile("MainScreen/PlayScreen.png");
	Texture playButton[4];
	playButton[0].loadFromFile("MainScreen/PlayButtonR.png");
	playButton[1].loadFromFile("MainScreen/PlayButtonY.png");
	playButton[2].loadFromFile("MainScreen/PlayButtonG.png");
	playButton[3].loadFromFile("MainScreen/PlayButtonB.png");
	Sprite screen(mainScreen);
	Sprite play[4];
	play[0].setTexture(playButton[0]);
	play[1].setTexture(playButton[1]);
	play[2].setTexture(playButton[2]);
	play[3].setTexture(playButton[3]);

	Texture cardbackTexture;
	cardbackTexture.loadFromFile("cards/cardbackside.png");
	Sprite cardback(cardbackTexture);
	cardback.setPosition(Vector2f(464, 237));

	Texture backgroundTexture;
	backgroundTexture.loadFromFile("cards/background.png");
	Sprite background(backgroundTexture);
	background.setScale(Vector2f(0.43, 0.416));

	Texture choose;
	choose.loadFromFile("ColorBars/ColorChoose.png");
	Sprite colorChoose(choose);
	colorChoose.setPosition(Vector2f(chooseBarX, chooseBarY));

	Texture colorBarsTextures[4];
	colorBarsTextures[0].loadFromFile("ColorBars/redBar.png");
	colorBarsTextures[1].loadFromFile("ColorBars/yellowBar.png");
	colorBarsTextures[2].loadFromFile("ColorBars/greenBar.png");
	colorBarsTextures[3].loadFromFile("ColorBars/blueBar.png");
	Sprite bars[4];
	bars[0].setTexture(colorBarsTextures[0]);
	bars[1].setTexture(colorBarsTextures[1]);
	bars[2].setTexture(colorBarsTextures[2]);
	bars[3].setTexture(colorBarsTextures[3]);

	Texture resultTextures[2];
	resultTextures[0].loadFromFile("ResultStatements/Win.png");
	resultTextures[1].loadFromFile("ResultStatements/Lose.png");
	Sprite result[2];
	result[0].setTexture(resultTextures[0]);
	result[1].setTexture(resultTextures[1]);

	Card * centerCard = new Card;

	Player player[2];

	srand(time(NULL));
	uno.initializeCenterCard(*centerCard);
	uno.initializePlayer(player[0]);
	uno.initializePC(player[1]);

	Time elapsed;
	Clock clock;

	Sprite **pcCards;
	Event event;

	while (window.isOpen())
	{
		elapsed += clock.getElapsedTime();
		if (!chooseBarActive)
			barIndex = uno.getIndexOfBars(*centerCard);
		bars[barIndex].setPosition(Vector2f(barX, barY));
		playerCardBoundW = player[0].getNoOfCards() * 40 + 32;
		srand(time(NULL));
		int mX = 0, mY = 0;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			else if (event.key.code == Mouse::Left && event.type == Event::MouseButtonPressed)
			{
				if (main_screen)
				{
					if (
						Mouse::getPosition(window).x >= play[buttonIndex].getPosition().x &&
						Mouse::getPosition(window).x <= play[buttonIndex].getPosition().x + play[buttonIndex].getGlobalBounds().width &&
						Mouse::getPosition(window).y >= play[buttonIndex].getPosition().y &&
						Mouse::getPosition(window).y <= play[buttonIndex].getPosition().x + play[buttonIndex].getGlobalBounds().height
						)
						main_screen = false;
				}
				else
				{
					if (resultDeclared)
						window.close();
					//Card Pressed by Player
					if (
						!chooseBarActive &&
						Mouse::getPosition(window).x >= playerCardBoundX &&
						Mouse::getPosition(window).x <= playerCardBoundX + playerCardBoundW &&
						Mouse::getPosition(window).y >= player[0].getCard(0).getSprite().getPosition().y &&
						Mouse::getPosition(window).y <= (player[0].getCard(0).getSprite().getGlobalBounds().height + player[0].getCard(0).getSprite().getPosition().y)
						)
					{
						int index = uno.getCardSelectedID(player[0], Mouse::getPosition(window).x, Mouse::getPosition(window).y);
						if (index != -1)
						{
							//If card is special
							if (player[0].getCard(index).getColor() == 'b')
							{
								chooseBarActive = true;
							}
							//Check if valid and display & remove from Player's Cards
							if (
								player[0].getCard(index).getColor() == centerCard->getColor() ||
								player[0].getCard(index).getValue() == centerCard->getValue() ||
								chooseBarActive
								)
							{
								if (centerCard)
									delete centerCard;
								centerCard = player[0].removeCard(index, false);
								if (centerCard)
									centerCard->setPos(567, 237);
								if (!chooseBarActive)
								{
									//									if (centerCard->getValue() == 'S' || centerCard->getValue() == 'R')
									//									{
									//										if (!uno.hasValidMove(player[0], *centerCard))
									//											validCardPick = true;
									//										else
									//											validCardPick = false;
									//									}
									if (!uno.changeTurn(uno.turn, *centerCard, turnChange))
										turnChange = false;
								}
								if (player[0].getNoOfCards() == 1)
									startTimer = true;
								validCardPick = true;
								if (centerCard->getValue() == 'T')
									uno.addCardInPlayer(player[1], 2, true);
								if (centerCard->getValue() == 'F')
									uno.addCardInPlayer(player[1], 4, true);
							}
						}
					}
					//If player wants to add card
					if (
						validCardPick &&
						!chooseBarActive &&
						Mouse::getPosition(window).x >= cardback.getPosition().x &&
						Mouse::getPosition(window).x <= cardback.getPosition().x + cardback.getGlobalBounds().width &&
						Mouse::getPosition(window).y >= cardback.getPosition().y &&
						Mouse::getPosition(window).y <= cardback.getPosition().y + cardback.getGlobalBounds().height
						)
					{
						if (!uno.hasValidMove(player[0], *centerCard))
							noValidCard = true;
						else
							noValidCard = false;
						uno.addCardInPlayer(player[0], 1, false);
						if (!noValidCard)
							uno.changeTurn(uno.turn, *centerCard, false);
						if (noValidCard && !uno.hasValidMove(player[0], *centerCard))
						{
							if (!uno.changeTurn(uno.turn, *centerCard, turnChange))
								turnChange = true;
							else
								turnChange = false;
						}
						if (uno.hasValidMove(player[0], *centerCard))
							validCardPick = false;
					}
					// On special card, color choose bar color selected
					if (
						chooseBarActive &&
						Mouse::getPosition(window).x >= 392 && Mouse::getPosition(window).x <= 711 &&
						Mouse::getPosition(window).y >= 237 && Mouse::getPosition(window).y <= 336
						)
					{
						int index = uno.getColorOfMouseClick(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
						if (index != -1)
						{
							chooseBarActive = false;
							centerCard->setColor(uno.getColorOfIndex(index));
							barIndex = index;
							noValidCard = false;
							uno.changeTurn(uno.turn, *centerCard, false);
						}
					}
				}
			}
		}
		//	PC's Turn
		if (uno.turn == 1)
		{
			bool flag = false;
			int pcIndex = -1;
			std::cout << "PC turn\n";
			for (int i = 0; i < player[1].getNoOfCards(); i++)
				std::cout << i << " : " << player[1].getCard(i).getColor() << " " << player[1].getCard(i).getValue() << '\n';
			pcIndex = uno.pcAutoPlay(player[1], *centerCard);
			srand(time(NULL));
			if (pcIndex == -1)
			{
				uno.addCardInPlayer(player[1], 1, true);
				std::cout << "PC Card Added\n";
				pcIndex = uno.pcAutoPlay(player[1], *centerCard);
				if (pcIndex == -1)
				{
					std::cout << "Turn changed\n";
					uno.turn--;
					std::cout << "Still no card to place\n";
				}
				else
				{
					if (player[1].getCard(pcIndex).getColor() == 'b')
					{
						std::cout << "It is special\n";
						flag = true;
						player[1].setCardColor(pcIndex, uno.getColorOfIndex(rand() % 4));
						std::cout << "Bar Color Selected: " << barIndex << endl;
					}
					std::cout << "Now have a card\n";
					if (centerCard)
						delete centerCard;
					centerCard = player[1].removeCard(pcIndex, true);
					centerCard->setPos(567, 237);
					uno.changeTurn(uno.turn, *centerCard, false);
					std::cout << "Center Card Placed & turn decided\n";
					if (!flag)
					{
						flag = false;
						barIndex = uno.getIndexOfBars(*centerCard);
						std::cout << "Bar Color Selected: " << barIndex << endl;
					}
					if (centerCard->getValue() == 'T')
						uno.addCardInPlayer(player[0], 2, false);
					if (centerCard->getValue() == 'F')
						uno.addCardInPlayer(player[0], 4, false);
				}
			}
			else
			{
				if (player[1].getCard(pcIndex).getColor() == 'b')
				{
					std::cout << "It is special\n";
					flag = true;
					player[1].setCardColor(pcIndex, uno.getColorOfIndex(rand() % 4));
				}
				if (centerCard)
					delete centerCard;
				centerCard = player[1].removeCard(pcIndex, true);
				centerCard->setPos(567, 237);
				uno.changeTurn(uno.turn, *centerCard, false);
				barIndex = uno.getIndexOfBars(*centerCard);
				std::cout << "Center Card Placed and Bar Color Selected: " << barIndex << endl;
				if (centerCard->getValue() == 'T')
					uno.addCardInPlayer(player[0], 2, false);
				if (centerCard->getValue() == 'F')
					uno.addCardInPlayer(player[0], 4, false);
			}
			std::cout << "Decided :" << pcIndex << "> " << centerCard->getColor() << " " << centerCard->getValue() << '\n';
		}
		pcCards = uno.getCardBackArray(cardback, player[1].getNoOfCards());

		window.clear();
		if (main_screen)
		{
			clock.restart();
			window.draw(screen);
			play[buttonIndex].setPosition(Vector2f(475, 310));
			window.draw(play[buttonIndex]);
		}
		else
		{
			window.draw(background);
			window.draw(cardback);
			window.draw(bars[barIndex]);
			if (centerCard)
				window.draw(centerCard->getSprite());
			for (int i = 0; i < player[1].getNoOfCards(); i++)
				window.draw(*pcCards[i]);
			for (int i = 0; i < player[0].getNoOfCards(); i++)
			{
				window.draw(player[0].getCard(i).getSprite());
			}
			if (chooseBarActive)
				window.draw(colorChoose);
			if (resultDeclared)
			{
				result[resultIndex].setPosition(Vector2f(240, 145));
				window.draw(result[resultIndex]);
			}
		}
		window.display();

		delete[] pcCards;

		if (elapsed.asMilliseconds() > 250)
		{
			elapsed = milliseconds(0);
			buttonIndex++;
			clock.restart();
		}
		if (buttonIndex == 4)
			buttonIndex = 0;

		if (uno.announceWinner(player[0].getNoOfCards(), player[1].getNoOfCards()) != 0)
		{
			resultDeclared = true;
			if (uno.announceWinner(player[0].getNoOfCards(), player[1].getNoOfCards()) == 1)
				resultIndex = 0;
			else if (uno.announceWinner(player[0].getNoOfCards(), player[1].getNoOfCards()) == 2)
				resultIndex = 1;
		}
	}
}