#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <tuple>

#include "../../world/camera/Camera.h"
#include "../../world/light/Light.h"

#include "../../geometry/materials/BasicMaterial.h"
#include "../../geometry/materials/reflexive/LambertMaterial.h"
#include "../../geometry/materials/reflexive/PhongMaterial.h"

#include "../../geometry/Geometry.h"

#include "../../geometry/geometries/BoxGeometry.h"
#include "../../geometry/geometries/RightAngleGeometry.h"
#include "../../geometry/geometries/SphereGeometry.h"

#include <document.h>

#define json_object rapidjson::GenericObj<true, rapidjson::Value>

class EnvironmentLoader
{
private:
	rapidjson::Document load_environment_json(std::string filename);
	std::string get_file_contents(std::string filename);
public:
	std::vector<Geometry> load_environment(std::string filename, Camera& camera, float screen_width, float screen_height, Light& light);
};


// The below has been marked as static, so that it is local to this .ccp/.h file.

static Geometry create_geometry_from_document(std::string type, json_object object, Camera& camera, float screen_width, float screen_height, Light& light);
static void setup_geometry(Geometry& geometry, json_object object, Camera& camera, float screen_width, float screen_height, Light& light);

static void set_standard_geometry_data(Geometry& geometry, json_object transformation_obj, json_object position_obj);
static void set_material_from_json(Geometry& geometry, json_object object, Light& light);

static json_object get_json_placement_position(json_object object);
static json_object get_json_placement_transformations(json_object object);

static void assert_xyz(json_object object);