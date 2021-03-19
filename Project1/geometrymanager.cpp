#include "geometrymanager.h"

GeometryManager* GeometryManager::instance{ nullptr };

GeometryManager::GeometryManager()
{
}

GeometryManager::~GeometryManager()
{
	delete instance;
}


GeometryManager* GeometryManager::get_instance()
{
	if (GeometryManager::instance == nullptr) {
		instance = new GeometryManager();
	}

	return GeometryManager::instance;
}

Geometry* GeometryManager::get_geometry(std::string name)
{
	// since the address doesn't change in here, we can return a pointer to the geom's address.
	Geometry* geom = &this->geometries[name];
	return geom;
}

void GeometryManager::add_geometry(std::string name, Geometry geometry)
{
	this->geometries.emplace(name, geometry);
}

void GeometryManager::clear_geoms()
{
	this->geometries.clear();
}


