#pragma once

#include <string>
#include <fstream>
#include <sstream>

#include "../vendor/rapidjson/document.h"

#define json_object rapidjson::GenericObj<true, rapidjson::Value>

class JsonLoader
{
private:
	static JsonLoader* instance;

	JsonLoader();
	~JsonLoader();
public:
	JsonLoader(JsonLoader&) = delete;
	JsonLoader(const JsonLoader&) = delete;

	void operator =(const JsonLoader&) = delete;

	static JsonLoader* get_instance();

	rapidjson::Document load_json_from_file(std::string path);
};

