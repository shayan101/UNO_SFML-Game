#pragma once

#include <map>
#include <ctime>
#include <stack>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Entity
{
protected:
	RectangleShape shape;
	float movement_speed;
public:
	Entity();
	virtual ~Entity();
	virtual void move(const float &_dt, const float &_x_direction, const float &_y_direction);
	virtual void update(const float &_dt);
	virtual void render(RenderTarget *_target);
private:
};