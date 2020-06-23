template<class Engine>
inline Randomizer<Engine>::Randomizer(int seed)
:	m_prng(seed)
{
}

template<class Engine>
template<typename _Ty>
_int<_Ty> Randomizer<Engine>::Range(_Ty low, _Ty high)
{
	return Range<UniformIntDist<_Ty>>(low, high);
}

template<class Engine>
template<typename _Ty>
inline _real<_Ty> Randomizer<Engine>::Range(_Ty low, _Ty high)
{
	return Range<UniformFloatDist<_Ty>>(low, high);
}

template<class Engine>
template<class Dist, typename _Ty>
inline _Ty Randomizer<Engine>::Range(_Ty low, _Ty high)
{
	Dist dist(low, high);
	return dist(m_prng);
}

template<typename Engine>
Randomizer<Engine> Randomizer<Engine>::Rand;
