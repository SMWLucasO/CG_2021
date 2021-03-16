#pragma once

#include <mutex>
#include <vector>

#include "environment_entity.h"

class EnvironmentManager {
private:
	std::vector<EnvironmentEntity> entities;

	static EnvironmentManager* instance;
	static std::mutex _mutex;

	EnvironmentManager();
	~EnvironmentManager();
public:

	EnvironmentManager(EnvironmentManager& environment_manager) = delete;
	EnvironmentManager(const EnvironmentManager& environment_manager) = delete;

	void operator =(const EnvironmentManager&) = delete;

	static EnvironmentManager* get_instance();

};