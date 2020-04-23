#include "State.h"

State::State(RenderWindow * _window)
{
	window = _window;
	shoud_end = false;
}

State::~State()
{
}

const bool & State::get_end()
{
	return shoud_end;
}

void State::check_for_end()
{
	if (Keyboard::isKeyPressed(Keyboard::Escape)) {
		shoud_end = true;
	}
}
