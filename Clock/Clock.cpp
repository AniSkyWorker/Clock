#include "Clock.h"
#include <iostream>

Clock::Clock(sf::RenderWindow& window)
:clock_position(window.getSize().x / 2, window.getSize().y / 2)
, second_angle(FULL_CRL_DEGREES / SEC_HAND_POS)
, hour_angle(FULL_CRL_DEGREES / HOUR_HAND_POS)
, sec_hand(SEC_HAND_SIZE)
, min_hand(MIN_HAND_SIZE)
, hour_hand(HOUR_HAND_SIZE)
, clock_crl(CLOCK_RADIUS)
,middle_crl(MID_CLOCK_RADIUS)
{
	initCircles();
	initHands();
	initNumbers();
}
void Clock::update()
{
	GetLocalTime(&t);
	sec_hand.setRotation((second_angle * float(t.wSecond)) - CRL_QUARTER);
	min_hand.setRotation((second_angle * float(t.wSecond)) / SEC_HAND_POS + float(t.wMinute) * second_angle - CRL_QUARTER);
	hour_hand.setRotation((5 *second_angle * float(t.wMinute)) / SEC_HAND_POS + float(t.wHour) * hour_angle - CRL_QUARTER);
}
void Clock::initHands()
{
	sec_hand.setPosition(clock_position.x, clock_position.y);
	sec_hand.setFillColor(sf::Color::Red);
	sec_hand.setOrigin(0, sec_hand.getSize().y / 2);

	min_hand.setPosition(clock_position.x, clock_position.y);
	min_hand.setFillColor(sf::Color::Green);
	min_hand.setOutlineThickness(MIN_HAND_QUTLINE_WIDTH);
	min_hand.setOutlineColor(sf::Color::Black);
	min_hand.setOrigin(0, min_hand.getSize().y / 2);

	hour_hand.setPosition(clock_position.x, clock_position.y);
	hour_hand.setFillColor(sf::Color::Red);
	hour_hand.setOutlineThickness(HOUR_HAND_QUTLINE_WIDTH);
	hour_hand.setOutlineColor(sf::Color::Black);
	hour_hand.setOrigin(0, hour_hand.getSize().y / 2);
}
void Clock::initCircles()
{
	clock_crl.setPosition(clock_position.x, clock_position.y);
	clock_crl.setFillColor(sf::Color::White);
	clock_crl.setOrigin(clock_crl.getRadius(), clock_crl.getRadius());
	clock_crl.setOutlineThickness(MIN_HAND_QUTLINE_WIDTH);
	clock_crl.setOutlineColor(sf::Color::Black);

	middle_crl.setPosition(clock_position.x, clock_position.y);
	middle_crl.setFillColor(sf::Color::Black);
	middle_crl.setOrigin(middle_crl.getRadius(), middle_crl.getRadius());
}
void Clock::initNumbers()
{
	font.loadFromFile("sansation.ttf");
	float angle = -PI/2 + PI/6;
	for (int i = 0; i < HOUR_HAND_POS; ++i)
	{
		text[i].setFont(font);
		text[i].setOrigin(CHARACTER_SIZE / 2, CHARACTER_SIZE / 2);
		text[i].setPosition(((clock_crl.getRadius()) - 10)* cos(angle) + clock_crl.getPosition().x,
			((clock_crl.getRadius()) - 10)* sin(angle) + clock_crl.getPosition().y);
		text[i].setString(std::to_string(i + 1));
		text[i].setColor(sf::Color::Black);
		text[i].setCharacterSize(CHARACTER_SIZE);
		angle = angle + (PI/6);
	}
}
void Clock::draw(sf::RenderWindow& window)
{
	window.draw(clock_crl);
	window.draw(sec_hand);
	window.draw(min_hand);
	window.draw(hour_hand);
	window.draw(middle_crl);
	for (int i = 0; i < HOUR_HAND_POS; ++i)
	{
		window.draw(text[i]);
	}
}