#include "GameState.h"

GameState::GameState(RenderWindow *_window) : State(_window)
{
}

GameState::~GameState()
{
}

void GameState::end_state()
{
	cout << "ending game state\n";
}

void GameState::update_keybinds(const float & _dt)
{
	check_for_end();
}

void GameState::update(const float &_dt)
{
	update_keybinds(_dt);
	player.update(_dt);
}

void GameState::render(RenderTarget *_target)
{
	if (_target) {

	}
	else {
		player.render(window);
	}
}