#include "Clock.h"

Clock::Clock(sf::RenderWindow& window)
:clock_position(window.getSize().x / 2, window.getSize().y / 2)
,second_angle(FULL_CRL_DEGREES / SEC_HAND_POS)
,minute_angle(second_angle * 5)
,hour_angle(FULL_CRL_DEGREES / HOUR_HAND_POS)
,sec_hand(SEC_HAND_SIZE)
,min_hand(MIN_HAND_SIZE)
,hour_hand(HOUR_HAND_SIZE)
,clock_crl(CLOCK_RADIUS)
,middle_crl(MID_CLOCK_RADIUS)
{
	initCircles();
	initHands();
	initNumbers();
}
void Clock::update()
{
	GetLocalTime(&time);
	sec_hand.setRotation((second_angle * float(time.wSecond)) - CRL_QUARTER);
	min_hand.setRotation((second_angle * float(time.wSecond)) / SEC_HAND_POS + float(time.wMinute) * second_angle - CRL_QUARTER);
	hour_hand.setRotation((minute_angle * float(time.wMinute)) / SEC_HAND_POS + float(time.wHour) * hour_angle - CRL_QUARTER);
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
	float angle = -M_PI/2 + M_PI/6;
	for (int i = 0; i < HOUR_HAND_POS; ++i)
	{
		text[i].setFont(font);
		text[i].setString(std::to_string(i + 1));
		text[i].setColor(sf::Color::Black);
		text[i].setCharacterSize(CHARACTER_SIZE);
		text[i].setOrigin(text[i].getGlobalBounds().width / 2, text[i].getGlobalBounds().height / 2);
		text[i].setPosition(textPositionOnClock(angle));
		angle = angle + (M_PI/6);
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

sf::Vector2f Clock::textPositionOnClock(float angle)
{
	sf::Vector2f text_position = {(clock_crl.getRadius() - RANGE_FROM__CLOCK_BORDER) * cos(angle) + clock_crl.getPosition().x ,
		(clock_crl.getRadius() - RANGE_FROM__CLOCK_BORDER) * sin(angle) + clock_crl.getPosition().y};
	return text_position;
}