#pragma once

#include "State.h"

class GameState : public State
{
private:
public:
	GameState(RenderWindow *_window);
	virtual ~GameState();
	void end_state();
	void update_keybinds(const float &_dt);
	void update(const float &_dt);
	void render(const RenderTarget *_target = nullptr);
private:
};