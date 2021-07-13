#pragma once

#include "animation.h"
#include "mesh.h"


class CouchWaveAnimation: public Animation
{
private:
	// the meshes to animate.
	std::vector<Mesh*> couch_seats;
public:
	void execute();
	
	/**
	* Register a couch seat to be animated.
	* 
	* @param couch_seat the seat to be animated.
	*/
	void register_couch_seat(Mesh* couch_seat);
};

