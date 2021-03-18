#include "environment.h"

void Environment::init(EnvironmentManager& env_manager)
{
	EnvironmentEntity tmp1 = EnvironmentEntity(
		GeometryManager::get_instance()->get_geometry(GeometryType::Box),
		glm::vec3(0, 0, 0)
	);

	env_manager.add(tmp1);

}
