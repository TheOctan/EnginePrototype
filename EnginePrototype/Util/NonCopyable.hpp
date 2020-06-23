#pragma once

#ifndef __NONCOPYABLE_HPP__
#define __NONCOPYABLE_HPP__

struct NonCopyable
{
	NonCopyable()									= default;
	NonCopyable& operator = (const NonCopyable&)	= delete;
	NonCopyable(const NonCopyable&)					= delete;
};

#endif // !__NONCOPYABLE_HPP__
