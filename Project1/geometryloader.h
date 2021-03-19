#pragma once

#include "jsonloader.h"
#include "geometrymanager.h"

#include <glm/glm.hpp>


class GeometryLoader
{
private:
	static GeometryLoader* instance;

	GeometryLoader();
	~GeometryLoader();
public:
	GeometryLoader(GeometryLoader&) = delete;
	GeometryLoader(const GeometryLoader&) = delete;

	void operator =(const GeometryLoader&) = delete;

	static GeometryLoader* get_instance();


	void load_geometry(GeometryManager& geom_manager, std::string path);
};

