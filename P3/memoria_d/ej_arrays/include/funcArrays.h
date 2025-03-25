////////////////////////////////
// Práctica 3                 //
// file: funcArrays.h (DP)    //
// Pedro Velasco Santana      //
////////////////////////////////

#ifndef PROCESO_H
#define PROCESO_H

const int TAM_BLOQUE = 5;

/**
 * @brief Función para mostrar k posiciones de un array
 * @param v Puntero entero, posición inicial sobre la que se itera
 * @param k Número de posiciones a mostrar
 */
void mostrar(const int *v, int k);

/** 
 * @brief Función para rellenar k posiciones de un array, con valores aleatorios entre un umbral
 * @param v Puntero entero, posición inicial sobre la que se itera
 * @param k Número de posiciones a rellenar
 * @param min Valor menor
 * @param max Valor mayor
 */
void rellenar(int *v, int k, int min, int max);

/**
 * @brief Redimensiona un array dinámico
 * @param p Puntero a entero, posición inicial del array
 * @param util Cantidad de posiciones usadas
 * @param tipo Tipo de redimensión escogida
 * @param cap Capacidad total del array (puede ser o no ser = a util)
 */
void Redimensiona(int * &p, int util, int tipo, int &cap);

#endif