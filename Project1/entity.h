#pragma once

#include "transformation.h"

class Entity
{
private:
	Transformations transformations = Transformations();
public:
	virtual void setup() = 0;
	virtual void render() = 0;

	Transformations& get_transformations();
	void set_transformations(Transformations transformations);
};

