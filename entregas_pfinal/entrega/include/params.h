/*
NOMBRE Y APELLIDOS: Pedro Velasco Santana
DNI: 45342754w
GRUPO DE PRÁCTICAS: viernes
*/

#ifndef PARAMS_H
#define PARAMS_H

#include "Vector2D.h"

//Límites del juego
const int MAX_X             = 600;
const int MAX_Y             = 600;

//Velocidad y aceleración partículas
const int MAX_VEL           = 7;
const int MAX_VEL_BASE      = 5;
const float MAX_ACC         = 2.0;

//Radios Partículas
const float MIN_R           = 3.0;
const float MAX_R_NAVE      = 9.0;
const float MAX_R_BASE      = 15.0;
const float RADIO_DISPARO   = 10.0; // ! CAMBIAR A GUSTO PARA COMPROBAR COLISIONES
const float MAX_R           = MAX_R_BASE;
const float EPSILON         = 0.01;

//Características minijuego
const int MAX_NAVES         = 15;   // ! CAMBIAR A GUSTO PARA DEBUG
const int MUNICION          = 50;   // ! CAMBIAR A GUSTO PARA DEBUG
const float CADENCIA        = 0.2;

inline float aleatorio(float min, float max){
    float r = rand() / static_cast<float> (RAND_MAX);
    float rango = max - min;
    return (r * rango + min);
}

#endif //PARAMS_H