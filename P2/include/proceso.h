/* 
 * File:   proceso.h
 * Author: David A. Pelta
 * Asignatura: Metodologías de la Programación
 * Created on 18 de febrero de 2025, 10:38
 */

#ifndef PROCESO_H
#define PROCESO_H

const int MAX_SIZE = 50;
const char TERMINADOR = '\0';


/**
 * @brief Compara si dos cadenas son iguales. Es decir, tienen exactamente los mismos caracteres en la misma posición
 * @param cad1 primera cadena tipo C
 * @param cad2 segunda cadena tipo C
 * @return verdadero (las cadenas son iguales) o falso (caso contrario)
 */
bool sonIguales(const char cad1[],const char cad2[]);

/**
 * @brief Calcula la longitud de la cadena (sin contar el terminador)
 * @param cad cadena tipo C
 * @return un valor entero;
 */
int longitud(const char cad[]);



/**
 * @brief Calcula el número de caracteres que aparecen una sola vez en la cadena
 * @param cad1 cadena tipo C
 * @return un valor entero
 */
int carsUnicos(const char cad1[]);


/**
 * @brief Comprueba si dos cadenas son anagramas. Es decir, tienen exactamente los mismos caracteres pero en cualquier posición.
 * Por ejemplo abcabc y aaccbb son anagramas. En cambio abcd y abde, no lo son.
 * @param cad1 primera cadena tipo C
 * @param cad2 segunda cadena tipo C
 * @return Verdadero (si son anagramas) o Falso (en caso contrario) 
 */
bool anagrama(const char cad1[],const char cad2[]);


/**
 * @brief Recibe una cadena y devuelve otra “comprimida”
de la siguiente forma. Si frase = {aaaBBeeekhh} entonces salida = {a3B2e3k1h2}
 * @param frase cadena tipo C a comprimir
 * @param salida cadena tipo C con la frase comprimida
 */
void compress(const char frase[], char salida []);


/**
 * @brief Descomprime una cadena dada.  Recibe una cadena y devuelve otra “expandida”
de la siguiente forma. Si frase = {a3B2e3k1h2} entonces salida = {aaaBBeeekhh}. 
 * Suponemos que el número de repeticiones de un símbolo es 9 como máximo y que la cadena de salida tiene 
 * espacio suficiente.
 * @param frase cadena tipo C que representa una cadena comprimida
 * @param salida cadena tipo C con la frase expandida
 */

void decompress(const char frase[], char salida[]);



#endif /* PROCESO_H */

