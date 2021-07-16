#pragma once

#include <vector>

#include "animation.h"

struct SpikeMovementAnimationData: public AnimationData
{
	bool scale_back_down = false;
};

class SpikeMovementAnimation: public Animation
{
private:
	std::vector<SpikeMovementAnimationData> spike_data;
public:
	void execute();

	/**
	* Register a spike to be animated.
	*
	* @param spike the spike to be animated.
	*/
	void register_spike(Mesh* spike);
};

