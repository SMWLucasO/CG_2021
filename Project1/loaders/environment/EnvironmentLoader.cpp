#include "EnvironmentLoader.h"

#include "../../geometry/geometries/BoxGeometry.h"
#include "../../geometry/geometries/RightAngleGeometry.h"
#include "../../geometry/geometries/SphereGeometry.h"

std::vector<Geometry> EnvironmentLoader::load_environment(std::string filename)
{
    std::vector<Geometry> geometry;
    rapidjson::Document document = this->load_environment_json(filename);

    // JSON object's root MUST be an object.
    assert(document.IsObject());

    // Every JSON file must have a type.
    assert(document.HasMember("type"));
    
    // Document must have data points array.
    assert(document.HasMember("data_points"));
    assert(document["data_points"].IsArray());

    // iterate through the data points.
    for (rapidjson::Value::ConstValueIterator it = document["data_points"].Begin(); it != document["data_points"].End(); ++it) {

        // assertions for things that must exist
        rapidjson::GenericObject object = it->GetObject();

        // assert required elements.
        assert(object.HasMember("position"));
        assert(object.HasMember("transformations"));
        assert(object.HasMember("width"));
        assert(object.HasMember("height"));
        assert(object.HasMember("depth"));

        geometry.push_back(create_geometry_from_document(document["type"].GetString(), object));
    }

    return geometry;
}


rapidjson::Document EnvironmentLoader::load_environment_json(std::string filename) {
    rapidjson::Document document;
    document.Parse(this->get_file_contents(filename).c_str());
    return document;
}


std::string EnvironmentLoader::get_file_contents(std::string filename) {
    std::ifstream file(filename);

    std::stringstream output;

    std::string input;
    while (file >> input) {
        output << input;
    }

    return std::string(output.str());
}

// dirty function to createt a geometry based upon a function, not very clean. Temporary? TODO

static Geometry create_geometry_from_document(std::string type, json_object object) {
    
    rapidjson::GenericObject transformations = get_json_placement_transformations(object),
        position = get_json_placement_position(object);

    // assertions
    assert(transformations.HasMember("rotation"));
    assert(transformations.HasMember("translation"));
    assert(transformations.HasMember("scaling"));

    assert_xyz(transformations["rotation"].GetObject());
    assert_xyz(transformations["translation"].GetObject());
    assert_xyz(transformations["scaling"].GetObject());
    assert_xyz(position);

    if (type == "Box") return create_box_geometry(object);
    if (type == "Sphere") return create_sphere_geometry(object);
    if (type == "RightAngle") return create_right_angle_geometry(object);

    assert(0);
}

static Geometry create_box_geometry(json_object object) {
    BoxGeometry box;

    rapidjson::GenericObject transformations = get_json_placement_transformations(object),
        position = get_json_placement_position(object);

    return box;
}

static Geometry create_sphere_geometry(json_object object) {
    SphereGeometry sphere;

    rapidjson::GenericObject transformations = get_json_placement_transformations(object),
        position = get_json_placement_position(object);

    return sphere;
}

static Geometry create_right_angle_geometry(json_object object) {
    RightAngleGeometry right_angle;

    rapidjson::GenericObject transformations = get_json_placement_transformations(object),
        position = get_json_placement_position(object);

    

    return right_angle;
}

static void set_standard_geometry_data(Geometry &geometry, json_object transformation_obj, json_object position_obj) {
    Transformations transform;
    glm::vec3 position;

    // set rotation
    transform.rotation.x = transformation_obj["rotation"]["x"].GetFloat();
    transform.rotation.y = transformation_obj["rotation"]["y"].GetFloat();
    transform.rotation.z = transformation_obj["rotation"]["z"].GetFloat();

    // set translation
    transform.translation.x = transformation_obj["translation"]["x"].GetFloat();
    transform.translation.y = transformation_obj["translation"]["y"].GetFloat();
    transform.translation.z = transformation_obj["translation"]["z"].GetFloat();

    // set scaling
    transform.scaling.x = transformation_obj["scaling"]["x"].GetFloat();
    transform.scaling.y = transformation_obj["scaling"]["y"].GetFloat();
    transform.scaling.z = transformation_obj["scaling"]["z"].GetFloat();

    // set position
    position.x = position_obj["x"].GetFloat();
    position.y = position_obj["y"].GetFloat();
    position.z = position_obj["z"].GetFloat();

    geometry.set_transformations(
        transform
    );

    geometry.set_position(
        position
    );
}

static json_object get_json_placement_position(json_object object) {
    return object["position"].GetObject();
}

static json_object get_json_placement_transformations(json_object object) {
    return object["transformations"].GetObject();
}

static void assert_xyz(json_object object) {
    assert(object.HasMember("x"));
    assert(object.HasMember("y"));
    assert(object.HasMember("z"));
}
