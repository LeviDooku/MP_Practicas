////////////////////////////////
// Práctica 1                 //
// file: include/paquete.h    //
// Pedro Velasco Santana      //
////////////////////////////////

#ifndef PAQUETE_H
#define PAQUETE_H

#include <string>
using namespace std;

/**
 * @struct Paquete
 * @brief Representa un paquete con origen, destino y peso en gramos.
 */
struct Paquete{
    int origen;     /**< Origen del paquete */
    int destino;    /**< Destino del paquete */
    float peso;     /**< Peso del paquete en gramos */
};

/**
 * @brief Convierte gramos a kilogramos. (NO especificada en guion)
 * @param p Peso en gramos.
 * @return Peso en kilogramos (float).
 */
float gTokg(float p);

/**
 * @brief Genera una cadena con la información de un paquete.
 * @param p Paquete a describir.
 * @return Cadena formateada con la información del paquete.
 */
string toString(const Paquete &p);

/**
 * @brief Crea un paquete a partir de los parámetros especificados.
 * @param origen Origen del paquete.
 * @param destino Destino del paquete.
 * @param peso Peso del paquete en gramos.
 * @return El paquete creado.
 */
Paquete creaPaquete(const int origen, const int destino, const float peso);

/**
 * @brief Comprueba la validez de un paquete.
 * @param p Paquete a comprobar.
 * @return true si es válido, false en caso contrario.
 */
bool esValido(const Paquete &p);

#endif