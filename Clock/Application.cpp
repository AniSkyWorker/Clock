#include "Application.h"
#include <iostream>


Application::Application() 
:window(sf::VideoMode(240,240), "Clock", sf::Style::Close, sf::ContextSettings(0,0, ANTIALIASING))
,clock(window)
{
}
void Application::run()
{
	while (window.isOpen())
	{
		update();
		processEvents();
		render();
	}
}
void Application::processEvents()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			break;
		}
	}

}
void Application::update()
{
	clock.update();
}
void Application::render()
{
	window.clear(sf::Color::Cyan);
	clock.draw(window);
	window.display();
}