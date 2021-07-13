#pragma once

#include "animation.h"
#include "mesh.h"

struct CouchWaveAnimationData: public AnimationData
{
	bool move_position_back = false;
	bool may_go_up = true;
};

class CouchWaveAnimation: public Animation
{
private:
	// data for the animation to work.
	std::vector<CouchWaveAnimationData> couch_seats;

	// The amount of calls that have been done for this animation.
	// gets reset every 10 calls.
	int execution_calls = 0;
	
	// The amount of seats we need to move.
	int couch_seats_to_animate = 1;

public:
	void execute();
	
	/**
	* Register a couch seat to be animated.
	* 
	* @param couch_seat the seat to be animated.
	*/
	void register_couch_seat(Mesh* couch_seat);
};

