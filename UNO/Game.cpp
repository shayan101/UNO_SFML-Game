#include "Game.h"

void Game::init_window()
{
	ifstream file("Config/window.ini");

	VideoMode window_bounce(800, 600);
	string title = "None";
	unsigned fps = 60;
	bool vertical_sync_enabled = false;

	if (file.is_open()) {
		getline(file, title);
		file >> window_bounce.width;
		file >> window_bounce.height;
		file >> fps;
		file >> vertical_sync_enabled;

		file.close();
	}

	window = new RenderWindow(window_bounce,title);
	window->setFramerateLimit(fps);
	window->setVerticalSyncEnabled(vertical_sync_enabled);
}

void Game::init_states()
{
	states.push(new GameState(window));
}

Game::Game()
{
	init_window();
	init_states();
}

Game::~Game()
{
	if (window) {
		delete window;
		window = nullptr;
	}

	while (!states.empty()) {
		delete states.top();
		states.pop();
	}
}

void Game::update_events()
{
	while (window->pollEvent(event)) {
		if (event.type == Event::Closed)
			window->close();

	}
}

void Game::update_dt()
{
	dt = dt_clock.restart().asSeconds();
}

void Game::update()
{
	update_events();

	if (!states.empty()) {
		states.top()->update(dt);
	}
}

void Game::render()
{
	window->clear();

	if (!states.empty()) {
		states.top()->render(window);
	}

	window->display();
}

void Game::run()
{
	while (window->isOpen()) {
		update_dt();
		update();
		render();
	}
}