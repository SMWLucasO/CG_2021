#include "couch_wave_animation.h"

void CouchWaveAnimation::execute()
{
}

void CouchWaveAnimation::register_couch_seat(Mesh* couch_seat)
{
	this->couch_seats.push_back(couch_seat);
}
