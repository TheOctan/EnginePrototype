#include "StateTest.hpp"
#include<iostream>

#include "../Game.hpp"

StateTest::StateTest(Game& game)
	: StateBase(game)
{
}

void StateTest::init()
{
	size = sf::Vector2f(m_pGame->m_window.getSize());

	rect.setSize(sf::Vector2f(150, 100));
	rect.setFillColor(sf::Color::Green);
	
	position = sf::Vector2f(300, 300);
}

void StateTest::handleEvent(sf::Event e)
{
	if (e.type == sf::Event::Resized)
		size = sf::Vector2f((float)e.size.width, (float)e.size.height);
}

void StateTest::handleInput()
{
}

void StateTest::update(sf::Time deltaTime)
{
	prev = position;
	position.x += dir * 0.0003f*deltaTime.asMicroseconds();

	auto bound = rect.getGlobalBounds();
	if (bound.left + bound.width > size.x)
	{
		dir = -1;
	}
	else if (bound.left < 0)
	{
		dir = 1;
	}
}

void StateTest::render(const float alpha)
{
	rect.setPosition(position * alpha + prev * (1.0f - alpha));
	//rect.setPosition(position);

	m_pGame->m_window.draw(rect);
}
