#include "shadingmanager.h"

ShadingManager* ShadingManager::instance { nullptr };

ShadingManager::ShadingManager()
{
}

ShadingManager::~ShadingManager()
{
	delete instance;
}

ShadingManager* ShadingManager::get_instance()
{
	if (ShadingManager::instance == nullptr) {
		instance = new ShadingManager();
	}

	return ShadingManager::instance;
}

void ShadingManager::init(std::string folder_name) {
	this->shaders.emplace(ShaderType::Basic, Shader((folder_name + "/basic/")));
	this->shaders.emplace(ShaderType::Lambert, Shader((folder_name + "/lambert/")));
	this->shaders.emplace(ShaderType::Phong, Shader((folder_name + "/phong/")));
}

Shader& ShadingManager::get_shader(ShaderType type)
{
	return shaders[type];
}
