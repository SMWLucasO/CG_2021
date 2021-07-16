#include "spike_movement_animation.h"

void SpikeMovementAnimation::execute()
{
	for (auto it = this->spike_data.begin(); it != this->spike_data.end(); ++it)
	{
		// we need a reference, otherwise the struct will not be updated :p
		SpikeMovementAnimationData& data = *it;

		glm::vec3 scaling = data.animation_entity->get_scaling();

		// determine whether we should scale the spikes up or down.
		if (scaling.y > data.initial_transformations.scaling.y + 5)
			data.scale_back_down = true;
		else if (scaling.y <= data.initial_transformations.scaling.y)
			data.scale_back_down = false;

		// scale up or down.
		if (data.scale_back_down)
			scaling.y -= 0.5;
		else
			scaling.y += 0.5;

		// update scaling of spike.
		data.animation_entity->set_scaling(scaling);
	}
}

void SpikeMovementAnimation::register_spike(Mesh* spike)
{
	SpikeMovementAnimationData data;
	data.animation_entity = spike;
	data.initial_transformations = Animation::extract_transformation_data(spike);

	this->spike_data.push_back(data);
}
