#include "geometrymanager.h"

// The single geometry manager instance.
GeometryManager* GeometryManager::instance{ nullptr };

GeometryManager::GeometryManager()
{
}

GeometryManager::~GeometryManager()
{
	// clear memory.
	delete instance;
}

GeometryManager* GeometryManager::get_instance()
{
	if (GeometryManager::instance == nullptr) // create a geometry manager instance if none is available yet.
		instance = new GeometryManager();
	

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

void GeometryManager::clear_geometries()
{
	this->geometries.clear();
}


