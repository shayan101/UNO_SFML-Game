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

class State
{
private:
	RenderWindow * window;
public:
	State(RenderWindow *_window);
	virtual ~State();
	virtual void end_state() = 0;
	virtual void update(const float &_dt) = 0;
	virtual void render(const RenderTarget *_target = nullptr) = 0;
private:
};

