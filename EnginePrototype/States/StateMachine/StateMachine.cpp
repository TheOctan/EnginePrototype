#include"StateMachine.hpp"

StateMachine::StateMachine()
{
}

void StateMachine::pushState(std::unique_ptr<StateBase> state)
{
	if (!m_states.empty())
		m_states.top()->pause();
	
	m_states.push(std::move(state));
	m_states.top()->init();
}

void StateMachine::popState()
{
	m_shouldPop = true;
}

void StateMachine::changeState(std::unique_ptr<StateBase> state)
{
	m_change = std::move(state);
	m_shouldChage = true;
}

StateBase& StateMachine::getCurrentState()
{
	return *m_states.top();
}

bool StateMachine::empty() const
{
	return m_states.empty();
}

void StateMachine::reset()
{
	m_shouldReset = true;
}

void StateMachine::tryPop()
{
	if (m_shouldReset)
	{
		while (!m_states.empty())
			m_states.pop();		
		m_shouldReset = false;

		return;
	}
	if (m_shouldPop && !m_states.empty())
	{
		m_states.pop();
		if (!m_states.empty())
			m_states.top()->resume();
		
		m_shouldPop = false;
	}
	if (m_shouldChage && !m_states.empty())
	{
		m_states.pop();
		m_states.push(std::move(m_change));
		m_states.top()->init();

		m_shouldChage = false;
	}
}
