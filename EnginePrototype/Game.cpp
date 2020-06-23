#include "Game.hpp"

#include "States/StatePlaying.hpp"

#include <iostream>

Game::Game()
:	m_window(sf::VideoMode(1300, 650), "Gravity Engine V_0.0.5"),
	graphic(sf::PrimitiveType::LinesStrip)
{
	m_window.setFramerateLimit(60);
	m_machine.pushState<StatePlaying>(*this);

	invers.setSize(sf::Vector2f(200, 5));
	inter.setSize(sf::Vector2f(200, 5));
	invers.setFillColor(sf::Color::Green);
	inter.setFillColor(sf::Color::Red);
	invers.setPosition(5, 125);
	inter.setPosition(5, 125);
}

void Game::run()
{
	constexpr unsigned	TPS = 60;								// ticks per seconds
	const sf::Time		dt = sf::seconds(1.0f / float(TPS));
	unsigned			ticks = 0;

	sf::Clock timer;
	auto lastTime		= sf::Time::Zero;
	auto accumulator	= sf::Time::Zero;

	while (m_window.isOpen() && !m_machine.empty())
	{
		auto& state = m_machine.getCurrentState();

		// get times
		auto time		= timer.getElapsedTime();
		auto frameTime	= time - lastTime;
		if (frameTime > sf::seconds(0.25f))
			frameTime = sf::seconds(0.25f);

		lastTime = time;
		accumulator += frameTime;

		// real time update
		state.handleInput();
		counter.update();

		// fixed time update
		while (accumulator >= dt)
		{
			//ticks++;
			// updating with fixed time
			state.update(dt);
			accumulator -= dt;
		}

		const auto interpolation = accumulator / dt;

		inter.setSize(sf::Vector2f(invers.getGlobalBounds().width * interpolation, inter.getSize().y));
		counter.setText("interpolation: 0." + std::to_string(int(interpolation*10)) + "\ninvers: 0." + std::to_string(int((1 - interpolation)*10)));

		auto bound = inter.getGlobalBounds();
		graphic.append(sf::Vertex(sf::Vector2f(5, 120.f - (bound.left + bound.width)*0.3f)));

		graphic.move(0.5, 0);

		//State state = currentState * interpolation + previousState * (1.0 - interpolation);

		// render
		m_window.clear(sf::Color(52, 37, 239));
		//m_window.clear();
		state.render(interpolation);
		m_window.draw(counter);
		m_window.draw(graphic);
		//m_window.draw(invers);
		//m_window.draw(inter);
		m_window.display();

		// handle window events
		handleEvent();
		m_machine.tryPop();
	}
}

void Game::handleEvent()
{
	sf::Event event;

	while (m_window.pollEvent(event))
	{
		m_machine.getCurrentState().handleEvent(event);

		switch (event.type)
		{
		case sf::Event::Closed:
			m_window.close();
			break;

		case sf::Event::Resized:
			m_window.setView(sf::View(sf::FloatRect(0, 0, (float)event.size.width, (float)event.size.height)));
			break;

		case sf::Event::MouseMoved:
			//std::cout << event.mouseMove.x << " " << event.mouseMove.y << std::endl;
			break;

		default:
			break;
		}
	}
}
