#pragma once

#include <unordered_map>
#include <string>

#include "shader.h"

class ShadingManager
{
private:

	// The single instance for the shading manager.
	static ShadingManager* instance;

	// The collection of shaders
	std::unordered_map<ShaderType, Shader> shaders;

	/**
	* ShadingManager constructor.
	*/
	ShadingManager();

	/**
	* ShadingManager destructor.
	*/
	~ShadingManager();
public:
	
	// remove copy-constructors
	ShadingManager(ShadingManager& other) = delete;
	ShadingManager(const ShadingManager& other) = delete;

	// no setting objects.
	void operator =(const ShadingManager&) = delete;

	/**
	* Get access to the ShadingManager Singleton.
	*
	* @return ShadingManager*
	*/
	static ShadingManager* get_instance();

	/**
	* Initiate the shading manager's shaders.
	*
	* @param folder_name the folder location wherein the different shader folders are located.
	*/
	void init(std::string folder_name);

	/**
	* Get the shader based upon the give from the given string.
	*
	* @param name the name of the shader, e.g. "lambert" or "basic".
	*
	* @return ShaderType
	*/
	ShaderType get_shader_type_from_string(std::string name);

	/**
	* Get the shader program by its type.
	*
	* @param type the shader type, e.g. Lambert or Phong.
	*
	* @return Shader&
	*/
	Shader& get_shader(ShaderType type);
};	

