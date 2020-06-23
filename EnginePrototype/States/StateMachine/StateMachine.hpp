#pragma once

#ifndef __STATEMACHINE_HPP__
#define __STATEMACHINE_HPP__

#include<memory>
#include<stack>

#include"StateBase.hpp"

class StateMachine : NonCopyable
{
public:
	StateMachine();

	template<class State, typename... Args>
	void pushState(Args&&... args);
	void pushState(std::unique_ptr<StateBase> state);

	void popState();

	template<class State, typename... Args>
	void changeState(Args&&... args);
	void changeState(std::unique_ptr<StateBase> state);

	StateBase& getCurrentState();

	bool empty() const;
	void reset();
	void tryPop();

private:

	std::stack<std::unique_ptr<StateBase>>	m_states;
	std::unique_ptr<StateBase>				m_change;

	bool m_shouldReset	= false;
	bool m_shouldPop	= false;
	bool m_shouldChage	= false;
};

#include"StateMachine.inl"

#endif // !__STATEMACHINE_HPP__


