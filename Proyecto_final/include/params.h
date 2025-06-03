/*
NOMBRE Y APELLIDOS: Pedro Velasco Santana
DNI: 45342754w
GRUPO DE PRÁCTICAS: viernes
*/

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

const int MAX_NAVES = 15;
const int MAX_VIDAS = 5;
const int MAX_DISPAROS = 100;
const float RADIO_DISPARO = 5.0; // ! CAMBIAR A GUSTO

inline float aleatorio(float min, float max){
    float r = rand() / static_cast<float> (RAND_MAX);
    float rango = max - min;
    return (r * rango + min);
}

#endif //PARAMS_H