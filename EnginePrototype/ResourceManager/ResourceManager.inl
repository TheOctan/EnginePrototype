#include "ResourceManager.hpp"

template<typename Resource>
inline ResourceManager<Resource>::ResourceManager(const std::string& folder, const std::string& extension)
:	m_folder("res/" + folder + "/"),
	m_extension("." + extension)
{
}

template<typename Resource>
inline const Resource& ResourceManager<Resource>::get(const std::string & name)
{
	if (!exists(name))
	{
		add(name);
	}

	return m_resources.at(name);
}

template<typename Resource>
inline bool ResourceManager<Resource>::exists(const std::string & name) const
{
	return m_resources.find(name) != m_resources.end();
}

template<typename Resource>
inline void ResourceManager<Resource>::add(const std::string & name)
{
	Resource r;

	//if the resource fails to load, then it adds a default "fail" resource
	if (!r.loadFromFile(getFullFilename(name)))
	{
		Resource fail;
		fail.loadFromFile(getFullFilename("_fail_"));
		m_resources.insert(std::make_pair(name, fail));
	}
	else
	{
		m_resources.insert(std::make_pair(name, r));
	}
}

template<typename Resource>
inline std::string ResourceManager<Resource>::getFullFilename(const std::string & name) const
{
	return m_folder + name + m_extension;
}