#pragma once

#ifndef __EVENTARGS_HPP__
#define __EVENTARGS_HPP__

#include "../System/Delegate.hpp"

class EventArgs
{
public:
	EventArgs();

	static EventArgs Empty;
};

template<class Sender, class EventArgs_t = EventArgs>
using EventHandler = Action<Sender*, const EventArgs_t&>;

#endif // !__EVENTARGS_HPP__
