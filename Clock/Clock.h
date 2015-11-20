#pragma once
#include <SFML/Graphics.hpp>
#include <windows.h>

const sf::Vector2f SEC_HAND_SIZE = { 80, 3 };
const sf::Vector2f MIN_HAND_SIZE = { 80, 1 };
const sf::Vector2f HOUR_HAND_SIZE = { 50, 1 };
const float CLOCK_RADIUS = 100;
const float MID_CLOCK_RADIUS = 6;
const float MIN_HAND_QUTLINE_WIDTH = 2;
const float HOUR_HAND_QUTLINE_WIDTH = 3;
const float FULL_CRL_DEGREES = 360;
const int CRL_QUARTER = 90;
const int SEC_HAND_POS = 60;
const int HOUR_HAND_POS = 12;
const float PI = 3.14;
const float CHARACTER_SIZE = 20;


struct Clock
{
	Clock(sf::RenderWindow& window);

	void update();
	void initHands();
	void initCircles();
	void initNumbers();
	void draw(sf::RenderWindow& window);

	sf::Vector2u clock_position;
	float second_angle;
	float minute_angle;
	float hour_angle;

	sf::RectangleShape min_hand;
	sf::RectangleShape hour_hand;
	sf::RectangleShape sec_hand;

	sf::CircleShape clock_crl;
	sf::CircleShape middle_crl;

	sf::Font font;
	sf::Text text[HOUR_HAND_POS];

	SYSTEMTIME t;
};