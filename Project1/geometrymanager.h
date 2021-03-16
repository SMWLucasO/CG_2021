#pragma once

#include <mutex>	

#include "geometry.h"
#include <map>

enum class GeometryType {
	House,
	Bush,
	Floor,
	Road,
	Tree,
	Lamp,
};

class GeometryManager
{
private:
	std::map<GeometryType, Geometry> geometries;

	static GeometryManager* instance;
	static std::mutex _mutex;

	GeometryManager();
	~GeometryManager();

public:
	
	GeometryManager(GeometryManager& geometry_manager) = delete;
	GeometryManager(const GeometryManager& geometry_manager) = delete;

	void operator =(const GeometryManager &) = delete;
	
	static GeometryManager* get_instance();

	void init(std::string folder_name);
};

