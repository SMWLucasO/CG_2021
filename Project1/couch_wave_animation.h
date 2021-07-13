#pragma once

#include "animation.h"
#include "mesh.h"


class CouchWaveAnimation: public Animation
{
private:
	// the meshes to animate.
	std::vector<Mesh*> couch_seats;
public:

	void enter();
	void process();
	void exit();
	
	void register_couch_seat(Mesh* couch_seat);
};

