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

Geometry* GeometryManager::get_geometry(GeometryType geometry_type)
{
	// since the address doesn't change in here, we can return a pointer to the geom's address.
	Geometry* geom = &this->geometries[geometry_type];
	return geom;
}

Geometry* GeometryManager::get_geometry_by_name(std::string name)
{
	if (name == "box") return &geometries[GeometryType::Box]; // add more here & replace this one.

	return &geometries[GeometryType::Box]; // this is actually the default.
}

void GeometryManager::init(std::string folder_name)
{
	// text for loading geoms for now.
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals;
	bool res = false;

	res = loadOBJ((folder_name + "/box.obj").c_str(), vertices, uvs, normals);
	this->geometries.emplace(GeometryType::Box, Geometry(vertices, uvs, normals));
}
