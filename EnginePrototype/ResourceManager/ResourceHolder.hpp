#pragma once

#ifndef __RESOURCEHOLDER_HPP__
#define __RESOURCEHOLDER_HPP__

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include"ResourceManager.hpp"
#include"../Util/NonCopyable.hpp"
#include"../Util/NonMoveable.hpp"

class ResourceHolder : NonCopyable, NonMovable
{
public:
	static ResourceHolder& get();

	ResourceManager<sf::Font>           fonts;
	ResourceManager<sf::Texture>        textures;
	ResourceManager<sf::SoundBuffer>    soundBuffers;

private:
	ResourceHolder();
};

#endif // !__RESOURCEHOLDER_HPP__
