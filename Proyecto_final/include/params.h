////////////////////////////////
// Proyecto final             //
// file: params.h             //
// Pedro Velasco Santana      //
////////////////////////////////

#ifndef PARAMS_H
#define PARAMS_H

#include "Vector2D.h"

const int MAX_X = 600;
const int MAX_Y = 600;

const int MAX_VEL = 7;
const float MAX_ACC = 2.0;

const float RADIO = 3.0;
const float MIN_R = 3.0;
const float MAX_R = 7.0;
const float EPSILON = 0.01;

float aleatorio(float min, float max);

#endif //PARAMS_H