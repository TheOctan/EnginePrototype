#include "StatePlaying.hpp"

#include "../Game.hpp"
#include "StateTest.hpp"

#include <iostream>

StatePlaying::StatePlaying(Game& game)
:	StateBase	(game)
{
	
}

void StatePlaying::init()
{
	menuTexture.loadFromFile("Textures/demo_background.png");
	buttonTexture.loadFromFile("Textures/button.png");
	scrollBarTexture.loadFromFile("Textures/scrollBar.png");
	textBoxTexture.loadFromFile("Textures/textBox.png");
	lockTexture.loadFromFile("Textures/lock.png");

	m_menu.setTitle("Main Menu");

#pragma region Adding widgets

	m_menu.addWidget(new gui::Lock("Full Screen Mode"));
	m_menu.addWidget(new gui::ScrollBar("Sound", 1, 10), true);
	m_menu.addWidget(new gui::Button("Button 1", gui::Button::Small), true);
	
	m_menu.addWidget(new gui::TextBox("Text_0"));
	m_menu.addWidget(new gui::Button("Button 2", gui::Button::Small), true);
	m_menu.addWidget(new gui::Button("Button 3"), true);
	
	m_menu.addWidget(new gui::ScrollBar("Music"));
	m_menu.addWidget(new gui::Button("Button 4"), true);
	m_menu.addWidget(new gui::Button("Button 5", gui::Button::Small), true);
	
	m_menu.addWidget(new gui::Lock("Text", gui::Lock::Small));
	m_menu.addWidget(new gui::Button("Button 6", gui::Button::Small), true);
	m_menu.addWidget(new gui::Button("Button 7", gui::Button::Small), true);
	m_menu.addWidget(new gui::Lock("A", gui::Lock::Narrow), true);
	m_menu.addWidget(new gui::Button("Button 8", gui::Button::Small), true);
	m_menu.addWidget(new gui::Button("A", gui::Button::Narrow), true);
	
	m_menu.addWidget(new gui::Lock("B", gui::Lock::Narrow));
	m_menu.addWidget(new gui::Button("Button 9"), true);
	m_menu.addWidget(new gui::TextBox("Text_1"), true);
	m_menu.addWidget(new gui::Button("B", gui::Button::Narrow), true);

#pragma endregion

#pragma region Subscribing

	m_menu[0].subscribe(this, &StatePlaying::button_1);
	m_menu[2].subscribe(this, &StatePlaying::button_3);
	m_menu[3].subscribe(this, &StatePlaying::button_2);
	m_menu[2].subscribe(this, &StatePlaying::button_3);
	m_menu[15].setActive(false);

#pragma endregion
	
#pragma region Texturing

	m_menu.setTexture(menuTexture);

	for (size_t i = 0; i < 19; i++)
	{
		if (i == 2 || i == 4 || i == 5 || i == 7 || i == 8 || i == 10 || i == 11 || i == 13 || i == 14 || i == 16 || i == 18)
		{
			m_menu[i].setTexture(buttonTexture);
		}
		else if (i == 1 || i == 6)
		{
			m_menu[i].setTexture(scrollBarTexture);
		}
		else if (i == 3 || i == 17)
		{
			m_menu[i].setTexture(textBoxTexture);
		}
		else if (i == 0 || i == 9 || i == 12 || i == 15)
		{
			m_menu[i].setTexture(lockTexture);
		}
	}

#pragma endregion
	
	m_menu.setOrigin(m_menu.getSize() / 2.f);
	m_menu.setPosition(sf::Vector2f(m_pGame->m_window.getSize()) / 2.f);
}

void StatePlaying::handleEvent(sf::Event e)
{
	m_menu.handleEvent(e);

	if (e.type == sf::Event::Resized)
	{
		m_menu.setPosition(sf::Vector2f(m_pGame->m_window.getSize()) / 2.f);
	}
}

void StatePlaying::handleInput()
{

}

void StatePlaying::update(sf::Time deltaTime)
{
	
}

void StatePlaying::render(const float alpha)
{
	m_pGame->m_window.draw(m_menu);
}

void StatePlaying::button_1(gui::Widget* sender, const WidgetEventArgs& e)
{
	sender->setActive(false);
}

void StatePlaying::button_2(gui::Widget* sender, const WidgetEventArgs& e)
{
	sender->setActive(false);
}

void StatePlaying::button_3(gui::Widget* sender, const WidgetEventArgs& e)
{
	this->m_pGame->m_machine.changeState<StateTest>(*m_pGame);
}

void StatePlaying::button_4(gui::Widget* sender, const WidgetEventArgs& e)
{
	
}


