
/* 
 * File:   Imagen.h
 * Author: David Pelta
 *
 * Metodología de la Programación
 */

#ifndef IMAGEN_H
#define IMAGEN_H

#include <iostream>

struct Imagen{
    int **M = nullptr;
    int nc=0, nf=0;
};


// funciones provistas para la lectura/escritura de imagenes en formato PGM, modo texto.

/// @brief Carga en img los datos de la imagen almacenada en el fichero file. 
/// \param img dato de tipo Imagen
/// \param file nombre del fichero
void cargarImagen(Imagen & img, std::string file);


/// @brief Guarda en el fichero file, los datos de la Imagen img en formato PGM
/// \param img dato de tipo Imagen
/// \param file nombre del fichero

void guardarImagen(Imagen & img, std::string file);


/// @brief Reserva memoria para una matriz de fil filas y col columnas. Asigna nc y nf.
/// Si img.M es distinto del puntero nulo, entonces primero libera la memoria reservada.
/// \param img dato de tipo Imagen
/// \param fil número de filas de la matriz
/// \param col número de columnas de la matriz

void reservaMem(Imagen & img, int fil, int col);



/// @brief Libera la memoria de la matriz. Asigna cero a nc y nf.
/// Solo se libera si img.M es distinto del puntero nulo, entonces primero libera la memoria reservada.
/// \param img dato de tipo Imagen

void liberaMem(Imagen & img);

/// @brief copia "profunda" de origen a destino. Requiere (posiblemente)liberar, reservar y copiar
/// Sería el equivalente a la operación destino = origen 
/// \param origen dato de tipo Imagen
/// \param destino dato de tipo Imagen
void copiar(const Imagen & rvalue, Imagen & );


/// @brief aplica el filtro sobre la Imagen img, calculando el nuevo valor para cada pixel. 
/// Se asume que filtro es una matriz de 3 x 3
/// \param img dato de tipo Imagen a procesar
/// \param filtro dato de tipo Imagen de 3x3 que representa el filtro a aplicar
void aplicaFiltro(Imagen & img, const Imagen & filtro); 

/// @brief rota la imagen 90º grados en sentido horario. Se modifica la imagen original
/// \param img dato de tipo Imagen

void rotar(Imagen & img);


/// @brief Dada una imagen, crea una imagen especular vertical
/// \param origen datos de tipo Imagen de f x c
/// \param destino datos de tipo Imagen de (2*f) x c
void espejoV(const Imagen & origen, Imagen & destino);



/// @brief Dada una imagen, crea una imagen especular horizontal
/// \param origen datos de tipo Imagen de f x c
/// \param destino datos de tipo Imagen de f x (2*c)
void espejoH(const Imagen & origen, Imagen & destino);

/// @brief Compara si dos datos de tipo Imagen son iguales
/// \param img1 dato de tipo Imagen
/// \param img2 dato de tipo Imagen
/// \return true, si son iguales. False en caso contrario
bool sonIguales(const Imagen & img1, const Imagen & img2);


/// @brief Inicializa el dato filtro con parametros predeterminados
/// \param filtro dato de tipo Imagen
/// \param opcion valores válidos:1,2,3,4
void inicializaFiltro(Imagen & filtro, int opcion);


#endif /* IMAGENPGM_H */

