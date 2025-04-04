/*
NOMBRE Y APELLIDOS: Pedro Velasco Santana
DNI: 45342754w
GRUPO DE PRÁCTICAS: viernes
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
 * @brief Intercambia dos caracteres
 * @param a caracter a intercambiar con b
 * @param b caracter a intercambiar con a
 */
void intercambiaCadena(char &a, char &b);

/**
 * @brief Ordena una cadena de caracteres 
 * @param cadena cadena tipo C a ordenar
 */
void ordenarCadena(char cadena[]);

/**
 * @brief Comprueba si dos cadenas son anagramas. Es decir, tienen exactamente los mismos caracteres pero en cualquier posición.
 * Por ejemplo abcabc y aaccbb son anagramas. En cambio abcd y abde, no lo son.
 * @param cad1 primera cadena tipo C
 * @param cad2 segunda cadena tipo C
 * @return Verdadero (si son anagramas) o Falso (en caso contrario) 
 */
bool anagrama(const char cad1[],const char cad2[]);

/**
 * @brief Convierte un entero a caracteres y los agrega a "cadena" a partir de "indice"
 * @param num entero a convertir 
 * @param cadena cadena en la que se incluirá
 * @param indice posición a partir de la que se incluirá el entero
 */
void int_to_char(int num, char cadena[], int & indice);

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

