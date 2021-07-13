#include "flower_animation.h"

#include <iostream>

void FlowerAnimation::execute()
{
	for (auto it = flower_piece_data.begin(); it != flower_piece_data.end(); ++it)
	{
		// we need a reference, otherwise the struct will not be updated :p
		FlowerAnimationData& data = *it;

		// update the rotations of the flower piece.
		update_flower_piece_rotations(data);

		// update the position of the flower piece.
		update_flower_piece_position(data);
	}
}

void FlowerAnimation::update_flower_piece_rotations(FlowerAnimationData& data)
{
	// current rotations of the flower piece.
	glm::vec3 rotations = data.animation_entity->get_rotations();

	// toggle between rotating Z in [initial, initial + 5]
	if (data.initial_transformations.rotations.z + 5 <= rotations.z)
		data.rotate_z_back = true;
	else if (data.initial_transformations.rotations.z + 0.1 >= rotations.z)
		data.rotate_z_back = false;

	// apply the Z-axis rotation.
	if (data.rotate_z_back)
		rotations.z -= 0.5;
	else
		rotations.z += 0.5;

	rotations.y += 5;

	// clamp rotation between [0, 359], 360* = 0*
	if (rotations.y >= 360)
		rotations.y = 0;

	data.animation_entity->set_rotations(rotations);
}

void FlowerAnimation::update_flower_piece_position(FlowerAnimationData& data)
{
	// current position of the flower piece.
	glm::vec3 position = data.animation_entity->get_position();

	// make the flower pieces move up and down from [initial, initial + 1]
	if (data.initial_transformations.position.y + 1 <= position.y)
		data.move_position_back = true;
	else if (data.initial_transformations.position.y + 0.02 >= position.y)
		data.move_position_back = false;

	// apply the y-axis position changes.
	if (data.move_position_back)
		position.y -= 0.01;
	else
		position.y += 0.01;

	data.animation_entity->set_position(position);
}

void FlowerAnimation::register_flower_piece(Mesh* flower_piece)
{
	FlowerAnimationData data;

	// make a copy of the transformations
	Transformations transformations = Animation::extract_transformation_data(flower_piece);
	

	// store the necessary data in the flower animation data struct.
	data.animation_entity = flower_piece;
	data.initial_transformations = transformations;

	this->flower_piece_data.push_back(data);
}
