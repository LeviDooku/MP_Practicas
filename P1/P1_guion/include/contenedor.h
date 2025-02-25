////////////////////////////////
// Práctica 1                 //
// file: include/contenedor.h //
// Pedro Velasco Santana      //
////////////////////////////////

#ifndef CONTENEDOR_H
#define CONTENEDOR_H

#include "paquete.h"

/**
 * @struct Contenedor
 * @brief Contenedor de paquetes con capacidad máxima fija.
 */
struct Contenedor {
    static const int MAX = 100;   /**< Número máximo de paquetes permitidos */
    Paquete lista[MAX];           /**< Lista de paquetes almacenados */
    int utiles = 0;               /**< Número de paquetes actualmente almacenados */
};

/**
 * @brief Agrega un paquete al contenedor si es válido.
 * @param c Referencia al contenedor donde se agregará el paquete.
 * @param p Referencia al paquete a agregar.
 */
void agregaPaquete(Contenedor &c, Paquete &p);

/**
 * @brief Muestra la información de todos los paquetes del contenedor.
 * @param c Contenedor del que se mostrarán los paquetes.
 */
void mostrarContenedor(const Contenedor &c);

/**
 * @brief Calcula el peso total de los paquetes del contenedor en kilogramos.
 * @param c Contenedor del que se calculará el peso.
 * @return Peso total en kilogramos.
 */
float calcularPeso(const Contenedor &c);

/**
 * @brief Construye un contenedor nuevo con los paquetes que provengan de origen
 * @param c Contenedor a analizar.
 * @param origen Origen
 * @return Contenedor nuevo
 */
Contenedor obtienePaquetes(const Contenedor &c, const int origen);

/**
 * @brief Intercambia los paquetes a y b.
 * @param a Paquete a.
 * @param b Paquete b
 */
void intercambiaPaquetes(Paquete &a, Paquete &b);

/**
 * @brief Ordenación personalizada, basada en el método de la burbuja.
 * @param c Contenedor a ordenar.
 */
void bubbleSort_pers(Contenedor &c);

/**
 * @brief Ordena un contenedor teniendo en cuenta el origen (primero) y destino (segundo)
 * @param c Contenedor a ordenar.
 */
void ordenar(Contenedor &c);

/**
 * @brief Obtiene el número de paquetes de un contenedor c que van a un destino, además del total de su peso en kg.
 * @param c Contenedor a analizar.
 * @param destino Destino criterio
 * @param nro Contendrá el número de paquetes de destino <destino>
 * @param peso Contendrá el peso total de los paquetes en kg
 */
void enviosDestino(const Contenedor &c, const int destino, int &nro, float &peso);

/**
 * @brief Analiza y muestra el número de paquetes y el peso total por destino.
 * @param c Contenedor a analizar.
 */
void analisisDestinos(const Contenedor &c);

#endif