#pragma once

#ifndef __NONMOVEABLE_HPP__
#define __NONMOVEABLE_HPP__

struct NonMovable
{
	NonMovable()							= default;
	NonMovable& operator = (NonMovable&&)	= delete;
	NonMovable(NonMovable&&)				= delete;
};

#endif // !__NONMOVEABLE_HPP__

