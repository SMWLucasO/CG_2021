#pragma once

#include <vector>
#include <unordered_map>
#include <string>

#include "geometry.h"

#include "loaders/texture/texture.h"

class GeometryManager
{
private:
	// Map containing all the geometries.
	std::unordered_map<std::string, Geometry> geometries;

	// The single geometry manager instance.
	static GeometryManager* instance;

	GeometryManager();

	/**
	* GeometryManager destructor.
	*/
	~GeometryManager();

public:
	
	GeometryManager(GeometryManager& geometry_manager) = delete;
	GeometryManager(const GeometryManager& geometry_manager) = delete;

	void operator =(const GeometryManager &) = delete;
	
	/**
	* Access the GeometryManager singleton.
	*
	* @return GeometryManager*
	*/
	static GeometryManager* get_instance();

	/**
	* Get a specific geometry.
	*
	* @param name the name of the geometry to get.
	*
	* @return Geometry*
	*/
	Geometry* get_geometry(std::string name);

	/**
	* Add a geometry to the geometry manager.
	*
	* @param name the name of the geometry
	* @param geometry the actual geometry containing vertices, etc.
	*/
	void add_geometry(std::string name, Geometry geometry);

	/**
	* Remove all geometries from the geometry manager.
	*/
	void clear_geometries();
};

