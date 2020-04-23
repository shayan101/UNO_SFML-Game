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
	
	if (Keyboard::isKeyPressed(Keyboard::A)) {
		cout << "A\n";
	}
}

void GameState::render(const RenderTarget *_target)
{
}
