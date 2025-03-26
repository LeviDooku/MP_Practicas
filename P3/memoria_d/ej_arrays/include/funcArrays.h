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

/**
 * @brief Realiza la unión de dos arrays dinámicos
 * @param v1 Puntero a entero, posición inicial del primer array
 * @param v2 Puntero a entero, posición inicial del segundo array
 * @param n1 Tamaño de v1
 * @param n2 Tamaño de v2
 * @return Array dinámico resultante de la unión de v1 y v2
 */
int * Union(const int * v1, const int * v2, const int n1, const int n2, int &res_cap, int &res_util);

/**
 * @brief Función auxliar para determinar si un elemento está presente en dos arrays
 * @param v1 Puntero a entero, posición inicial del primer array
 * @param v2 Puntero a entero, posición inicial del segundo array
 * @param n1 Tamaño de v1
 * @param n2 Tamaño de v2
 * @param buscar Elemento a comprobar
 * @return True si está en ambos, false en caso contrario
 */
bool en_ambos(const int *v1, const int *v2, const int util1, const int util2, const int buscar);

/**
 * @brief Realiza la interseccion de dos arrays dinámicos
 * @param v1 Puntero a entero, posición inicial del primer array
 * @param v2 Puntero a entero, posición inicial del segundo array
 * @param n1 Tamaño de v1
 * @param n2 Tamaño de v2
 * @return Array dinámico resultante de la intersección de v1 y v2
 */
int * Interseccion(const int * v1, const int * v2, const int n1, const int n2, int &res_cap, int &res_util);

#endif