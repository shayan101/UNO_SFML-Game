#pragma once

#include "GameState.h"

class Game
{
private:
	RenderWindow *window = nullptr;
	Event event;
	Clock dt_clock;
	float dt;
	stack<State *> states;
public:
	Game();
	virtual ~Game();
	void update_events();
	void update_dt();
	void update();
	void render();
	void run();
private:
	void init_window();
	void init_states();
};