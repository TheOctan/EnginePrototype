#pragma once

#ifndef __GAME_HPP__
#define __GAME_HPP__

#include<memory>
#include<vector>
#include<SFML/Graphics.hpp>

#include "States/StateMachine/StateMachine.hpp"
#include "States/StateTest.hpp"
#include "Util/NonMoveable.hpp"
#include "Util/FPSCounter.hpp"

namespace gm
{
	class VertexArray : public sf::Drawable
	{
	public:

		VertexArray() : VertexArray(sf::PrimitiveType::Points, 0)
		{

		}

		explicit VertexArray(sf::PrimitiveType type, std::size_t vertexCount = 0)
		{
			this->m_primitiveType = type;
			this->m_vertices.reserve(vertexCount);
		}

		void move(float x, float y)
		{
			for (size_t i = 0; i < m_vertices.size(); i++)
			{
				m_vertices[i].position.x += x;
				m_vertices[i].position.y += y;
			}

			if (m_vertices.size() > buffer)
				removeVertex();
		}

		std::size_t getVertexCount() const
		{
			return this->m_vertices.size();
		}

		sf::Vertex& operator [](std::size_t index)
		{
			return this->m_vertices.at(index);
		}

		const sf::Vertex& operator [](std::size_t index) const
		{
			return this->m_vertices.at(index);
		}

		void clear()
		{
			this->m_vertices.clear();
		}

		void removeVertex()
		{
			this->m_vertices.erase(this->m_vertices.begin());
		}

		void resize(std::size_t vertexCount)
		{
			this->m_vertices.resize(vertexCount);
		}

		void append(const sf::Vertex& vertex)
		{
			if (vertex.position != this->top().position)
			{
				this->m_vertices.push_back(vertex);
				this->m_vertices.back().color = sf::Color(136,139,255);
			}
		}

		sf::Vertex top() const
		{
			int count = this->getVertexCount();

			if (count > 0)
				return this->m_vertices.front();

			return sf::Vertex(sf::Vector2f(0, 0));
		}

		void setPrimitiveType(sf::PrimitiveType type)
		{
			this->m_primitiveType = type;
		}

		sf::PrimitiveType getPrimitiveType() const
		{
			return this->m_primitiveType;
		}

	protected:

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
		{
			if (!this->m_vertices.empty())
				target.draw(&this->m_vertices[0], this->m_vertices.size(), this->m_primitiveType, states);
		}

	private:

		std::vector<sf::Vertex> m_vertices;      ///< Vertices contained in the array
		sf::PrimitiveType       m_primitiveType; ///< Type of primitives to draw
		const unsigned buffer = 400;
	};

} // namespace gm

class Game : NonCopyable, NonMovable
{
public:
	Game();
	
	void run();

	sf::RenderWindow	m_window;
	StateMachine		m_machine;

private:
	void handleEvent();	
	
	FPSCounter			counter;
	
	sf::RectangleShape inter;
	sf::RectangleShape invers;

	gm::VertexArray graphic;
};

#endif // !__GAME_HPP__


