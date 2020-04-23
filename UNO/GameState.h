#pragma once

#include "State.h"

class GameState : public State
{
private:
	Entity player;
public:
	GameState(RenderWindow *_window);
	virtual ~GameState();
	void end_state();
	void update_keybinds(const float &_dt);
	void update(const float &_dt);
	void render(RenderTarget *_target = nullptr);
private:
};