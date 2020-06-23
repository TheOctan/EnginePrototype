#pragma once

#ifndef __STATEPLAYING_HPP__
#define __STATEPLAYING_HPP__

#include "StateMachine/StateBase.hpp"
#include "../GUI.hpp"

class StatePlaying : public StateBase
{
public:
	StatePlaying(Game& game);

	void init() override;

	void handleEvent	(sf::Event e)			override;
	void handleInput	()						override;
	void update			(sf::Time deltaTime)	override;
	void render			(const float alpha)		override;

private:
	void button_1(gui::Widget* sender, const WidgetEventArgs& e);
	void button_2(gui::Widget* sender, const WidgetEventArgs& e);
	void button_3(gui::Widget* sender, const WidgetEventArgs& e);
	void button_4(gui::Widget* sender, const WidgetEventArgs& e);

private:
	gui::StackMenu m_menu;

	sf::Texture menuTexture;
	sf::Texture buttonTexture;
	sf::Texture scrollBarTexture;
	sf::Texture textBoxTexture;
	sf::Texture lockTexture;
};

#endif // !__STATEPLAYING_HPP__


