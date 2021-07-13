#pragma once

#include <vector>

#include "transformation.h"
#include "mesh.h"
#include "animation.h"

struct FlowerAnimationData
{
	Mesh* flower_piece;
	Transformations initial_transformations;
	bool move_position_back = false;
	bool rotate_z_back = false;
};

class FlowerAnimation: public Animation
{
private:
	std::vector<FlowerAnimationData> flower_piece_data;

	/**
	* Update the position of the flower piece.
	* 
	* @param data the flower piece's information.
	*/
	void update_flower_piece_position(FlowerAnimationData& data);

	/**
	* Update the rotations of the flower piece.
	* 
	* @param data the flower piece's information.
	*/
	void update_flower_piece_rotations(FlowerAnimationData& data);
public:
	void execute();

	/**
	* Register a flower piece to be animated.
	* 
	* @param flower_piece the part of the flower to be animated.
	*/
	void register_flower_piece(Mesh* flower_piece);
};

