#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <tuple>

#include <document.h>

#include "../../geometry/Geometry.h"

#define json_object rapidjson::GenericObject<true, rapidjson::Value>

class EnvironmentLoader
{
private:
	rapidjson::Document load_environment_json(std::string filename);
	std::string get_file_contents(std::string filename);
public:
	std::vector<Geometry> load_environment(std::string filename);
};


// The below has been marked as static, so that it is local to this .ccp/.h file.

static Geometry create_geometry_from_document(std::string type, json_object object);
static Geometry create_box_geometry(json_object object);
static Geometry create_sphere_geometry(json_object object);
static Geometry create_right_angle_geometry(json_object object);

static void set_standard_geometry_data(Geometry& geometry, json_object transformation_obj, json_object position_obj);

static json_object get_json_placement_position(json_object object);
static json_object get_json_placement_transformations(json_object object);

static void assert_xyz(json_object object);