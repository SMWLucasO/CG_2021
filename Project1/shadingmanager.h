#pragma once

#include <map>
#include <mutex>

#include "shader.h"

class ShadingManager
{
private:
	static ShadingManager* instance;
	static std::mutex _mutex;

	std::map<ShaderType, Shader> shaders;

	ShadingManager();
	~ShadingManager();
public:
	
	// remove copy-constructors
	ShadingManager(ShadingManager& other) = delete;
	ShadingManager(const ShadingManager& other) = delete;

	// no setting objects.
	void operator =(const ShadingManager&) = delete;

	// initiate the shadingmanager, must be called once from main.

	static ShadingManager* get_instance();

	Shader& get_shader(ShaderType type);
	void init(std::string folder_name);
};	

