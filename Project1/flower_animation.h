#pragma once

#include <vector>

#include "mesh.h"
#include "animation.h"

class FlowerAnimation: public Animation
{
private:
	std::vector<Mesh*> flower_pieces;
public:
	void execute();

	/**
	* Register a flower piece to be animated.
	* 
	* @param flower_piece the part of the flower to be animated.
	*/
	void register_flower_piece(Mesh* flower_piece);
};

