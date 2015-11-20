#pragma once
#include <SFML/Graphics.hpp>
#include "Clock.h"
struct Application
{
	Application();
	void run();
	void processEvents();
	void update();
	void render();

	sf::RenderWindow window;
	Clock clock;
};