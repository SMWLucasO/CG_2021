#include "geometrymanager.h"

GeometryManager* GeometryManager::instance{ nullptr };
std::mutex GeometryManager::_mutex;


GeometryManager::GeometryManager()
{
}

GeometryManager::~GeometryManager()
{
	delete instance;
}


GeometryManager* GeometryManager::get_instance() {

	std::lock_guard<std::mutex> lock(_mutex);

	if (GeometryManager::instance == nullptr) {
		instance = new GeometryManager();
	}

	return GeometryManager::instance;
}

void GeometryManager::init(std::string folder_name)
{
	this->geometries.emplace(GeometryType::Floor, ...);
}
