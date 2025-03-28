/**
  * @file 
  * @brief Fichero cabecera para la E/S de imágenes PGM 
  *
  * Permite la E/S de archivos de tipos PGM
  *
  */
  
#ifndef _PGM_H_
#define _PGM_H_

#include "Imagen.h"
#include <iostream>
/**
  * @brief Tipo de imagen
  *
  * Declara una serie de constantes para representar los distintos tipos
  * de imágenes que se pueden manejar.
  *
  * @see LeerTipoImagen
  */
enum TipoImagen {
  IMG_DESCONOCIDO,	///< Tipo de imagen desconocido
  IMG_PGM_BINARIO,	///< Imagen tipo PGM Binario
  IMG_PGM_TEXTO		///< Imagen tipo PGM Texto
};


/**
  * @brief Consulta el tipo de imagen del archivo y sus dimensiones
  *
  * @param nombre indica el nombre del archivo de disco a consultar
  * @param filas Parámetro de salida con las filas de la imagen.
  * @param columnas Parámetro de salida con las columnas de la imagen.
  * @return Devuelve el tipo de la imagen en el archivo 
  *
  * @see TipoImagen
  */
TipoImagen infoPGM(const char nombre[], int& filas, int& columnas);


/**
  * @brief Lee una imagen de tipo PGM texto
  *
  * @param nombre 	nombre del archivo a leer
  * @param filas 	Parámetro de salida con las filas de la imagen.
  * @param columnas Parámetro de salida con las columnas de la imagen.
  * @param datos 	vector para obtener el valor de cada uno de los píxeles
  *        desde la esquina superior izqda a la inferior dcha. 
  * @retval true 	si ha tenido éxito en la lectura.
  * @retval false 	si se ha producido algún error en la lectura.
  * @pre datos 		debe tener tamaño suficiente para almacenar
  *      @a filas x @a columnas bytes de datos de la imagen.
  */

bool leerPGMTexto(Imagen & img, std::string nombre);


bool escribirPGMTexto(const Imagen & img, std::string nombre);

#endif

