#include "FPSCounter.hpp"

#include "../ResourceManager/ResourceHolder.hpp"

FPSCounter::FPSCounter()
{
	m_text.move(5, 5);
	m_text.setFillColor(sf::Color(255, 255, 255));
	m_text.setFont(ResourceHolder::get().fonts.get("arial"));
	m_text.setCharacterSize(15);
}

void FPSCounter::update()
{
	m_frameCount++;

	if (m_delayTimer.getElapsedTime().asSeconds() > 0.2)
	{
		m_fps = m_frameCount / m_fpsTimer.restart().asSeconds();
		m_frameCount = 0;
		m_delayTimer.restart();
	}

	m_text.setString("FPS " + std::to_string((int)m_fps) + "\tgravity engine v_0.0.5\n" + str);
}

int FPSCounter::count() const
{
	return (int)m_fps;
}

void FPSCounter::setText(sf::String str)
{
	this->str = str;
}

void FPSCounter::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(m_text, states);
}
