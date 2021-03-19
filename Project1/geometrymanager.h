#pragma once

#include "geometry.h"
#include "loaders/object/objloader.h"

#include <unordered_map>
#include <string>

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

