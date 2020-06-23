#pragma once

#ifndef __FPSCOUNTER_HPP__
#define __FPSCOUNTER_HPP__

#include <SFML/Graphics.hpp>

class FPSCounter : public sf::Drawable
{
public:
	FPSCounter();

	void update();

	int count() const;
	void setText(sf::String str);

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	sf::Text m_text;
	sf::String str;

	sf::Clock m_delayTimer;
	sf::Clock m_fpsTimer;

	float m_fps = 0;

	int m_frameCount = 0;
};

#endif // !__FPSCOUNTER_HPP__

