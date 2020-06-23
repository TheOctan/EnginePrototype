#pragma once

#ifndef __RESOURCEMANAGER_HPP__
#define __RESOURCEMANAGER_HPP__

#include <unordered_map>
#include <string>

template <typename Resource>
class ResourceManager
{
public:
	ResourceManager(const std::string& folder, const std::string& extension);

	const Resource& get	(const std::string& name);
	bool exists			(const std::string& name) const;
	void add			(const std::string& name);

private:
	std::string getFullFilename(const std::string& name) const;

	const std::string m_folder;
	const std::string m_extension;

	std::unordered_map<std::string, Resource> m_resources;
};

#include"ResourceManager.inl"

#endif // !__RESOURCEMANAGER__


