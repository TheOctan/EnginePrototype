template<class State, typename ...Args>
inline void StateMachine::pushState(Args&& ...args)
{
	if (!m_states.empty())
		m_states.top()->pause();
	m_states.push(std::make_unique<State>(std::forward<Args>(args)...));
	m_states.top()->init();
}

template<class State, typename ...Args>
inline void StateMachine::changeState(Args&& ...args)
{
	m_change = std::make_unique<State>(std::forward<Args>(args)...);
	m_shouldChage = true;
}