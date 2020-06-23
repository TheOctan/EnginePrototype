#pragma once

#ifndef __RANDOM_HPP__
#define __RANDOM_HPP__

#include <random>
#include <ctime>

template<typename _Ty>
using UniformIntDist = std::uniform_int_distribution<_Ty>;
template<typename _Ty>
using UniformFloatDist = std::uniform_real_distribution<_Ty>;

template<typename _Ty>
using _int = std::enable_if_t<std::is_integral<_Ty>::value, _Ty>;
template<typename _Ty>
using _real = std::enable_if_t<std::is_floating_point<_Ty>::value, _Ty>;


template <class Engine = std::mt19937>
class Randomizer
{
public:
	static Randomizer Rand;
	
	Randomizer(int seed = std::time(nullptr));

	template<typename _Ty>
	_int<_Ty> Range(_Ty low, _Ty high);

	template<typename _Ty>
	_real<_Ty> Range(_Ty low, _Ty high);

	template<class Dist, typename _Ty>
	_Ty Range(_Ty low, _Ty high);

private:
	Engine m_prng;
};

#include"Random.inl"

typedef Randomizer<std::mt19937> Random;

#endif // !__RANDOM_HPP__


