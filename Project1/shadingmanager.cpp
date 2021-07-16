#include "shadingmanager.h"

// the shading manager instance.
ShadingManager* ShadingManager::instance { nullptr };

ShadingManager::ShadingManager()
{
}

ShadingManager::~ShadingManager()
{
	// delete the instance of the shading manager.
	delete instance;
}

ShadingManager* ShadingManager::get_instance()
{
	if (ShadingManager::instance == nullptr) // create the single instance of the shading manager if there is none yet.
		instance = new ShadingManager();
	

	return ShadingManager::instance;
}

void ShadingManager::init(std::string folder_name) {
	this->shaders.emplace(ShaderType::Lambert, Shader((folder_name + "/lambert/")));
	this->shaders.emplace(ShaderType::Phong, Shader((folder_name + "/phong/")));
	this->shaders.emplace(ShaderType::Basic, Shader((folder_name + "/basic/")));
}

ShaderType ShadingManager::get_shader_type_from_string(std::string name)
{
	if (name == "lambert") 
		return ShaderType::Lambert;
	
	if (name == "basic")
		return ShaderType::Basic;

	return ShaderType::Phong;
}

Shader& ShadingManager::get_shader(ShaderType type)
{
	return shaders[type];
}
