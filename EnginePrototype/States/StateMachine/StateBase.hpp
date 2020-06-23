#pragma once

#ifndef __STATEBASE_HPP__
#define __STATEBASE_HPP__

#include<SFML/Graphics.hpp>

#include"../../Util/NonCopyable.hpp"

class StateBase : NonCopyable
{
public:
	StateBase(class Game& game)
	:	m_pGame			(&game)
	{}

	virtual ~StateBase() = default;

	virtual void init			() = 0;

	virtual void handleEvent	(sf::Event event) {};
	virtual void handleInput	() = 0;
	virtual void update			(sf::Time deltaTime) {};
	virtual void render			(const float alpha) = 0;

	virtual void pause	() {}
	virtual void resume	() {}

protected:
	Game* m_pGame;

};

#endif // !__STATEBASE_HPP__
