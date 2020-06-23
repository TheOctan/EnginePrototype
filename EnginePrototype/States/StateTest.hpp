#pragma once

#ifndef __STATETEST_HPP__
#define __STATETEST_HPP__

#include "StateMachine/StateBase.hpp"
#include "../GUI.hpp"

class StateTest : public StateBase
{
public:
	StateTest(Game& game);

	void init() override;

	void handleEvent	(sf::Event e)			override;
	void handleInput	()						override;
	void update			(sf::Time deltaTime)	override;
	void render			(const float alpha)		override;

private:

	sf::RectangleShape rect;
	sf::Vector2f size;
	sf::Vector2f prev;
	sf::Vector2f position;
	int dir = 1;

};

#endif // __STATETEST_HPP__




