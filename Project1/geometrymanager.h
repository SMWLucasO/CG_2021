#pragma once

#include "geometry.h"
#include "loaders/object/objloader.h"


#include <unordered_map>
#include <string>

enum class GeometryType {
	House,
	Bush,
	Floor,
	Road,
	Tree,
	Lamp,
	Box,
};

class GeometryManager
{
private:
	std::unordered_map<GeometryType, Geometry> geometries;

	static GeometryManager* instance;

	GeometryManager();
	~GeometryManager();

public:
	
	GeometryManager(GeometryManager& geometry_manager) = delete;
	GeometryManager(const GeometryManager& geometry_manager) = delete;

	void operator =(const GeometryManager &) = delete;
	
	static GeometryManager* get_instance();

	Geometry* get_geometry(GeometryType geometry_type);

	void init(std::string folder_name);
};

