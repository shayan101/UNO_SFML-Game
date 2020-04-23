#pragma once

#include "Entity.h"

class State
{
protected:
	RenderWindow *window;
	vector<Texture> textures;
	bool shoud_end;
public:
	State(RenderWindow *_window);
	virtual ~State();
	const bool &get_end();
	virtual void check_for_end();
	virtual void end_state() = 0;
	virtual void update_keybinds(const float &_dt) = 0;
	virtual void update(const float &_dt) = 0;
	virtual void render(RenderTarget *_target = nullptr) = 0;
private:
};

