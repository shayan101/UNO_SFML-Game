#include "GameState.h"

GameState::GameState(RenderWindow *_window) : State(_window)
{
}

GameState::~GameState()
{
}

void GameState::end_state()
{
}

void GameState::update(const float &_dt)
{
	cout << "hell from GameState::update()\n";
}

void GameState::render(const RenderTarget *_target)
{
}
