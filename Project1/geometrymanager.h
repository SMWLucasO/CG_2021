#pragma once

#include <vector>
#include <unordered_map>
#include <string>

#include "geometry.h"

#include "loaders/texture/texture.h"

class GeometryManager
{
private:
	std::unordered_map<std::string, Geometry> geometries;

	static GeometryManager* instance;

	GeometryManager();
	~GeometryManager();

public:
	
	GeometryManager(GeometryManager& geometry_manager) = delete;
	GeometryManager(const GeometryManager& geometry_manager) = delete;

	void operator =(const GeometryManager &) = delete;
	
	static GeometryManager* get_instance();

	Geometry* get_geometry(std::string name);

	void add_geometry(std::string name, Geometry geometry);
	void clear_geoms();
};

