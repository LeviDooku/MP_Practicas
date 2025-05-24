/*
NOMBRE Y APELLIDOS: Pedro Velasco Santana
DNI: 45342754w
GRUPO DE PRÁCTICAS: viernes
*/

#ifndef CONJUNTOPARTICULAS_H
#define CONJUNTOPARTICULAS_H

#include <iostream>
#include <cassert>
#include "Particula.h"

const int TAM_BLOQUE = 3;

/**
 * @class ConjuntoParticulas
 * @brief Almacena un conjunto de objetos del tipo Particula
 */
class ConjuntoParticulas{
private:
    Particula *set = nullptr; ///< Array de Particulas
    int capacidad = 0; ///< Capacidad del array
    int utiles  = 0; ///< Posiciones ocupadas

    /**
     * @brief Redimensiona el array dinámico de Partícula
     * @param new_cap Nueva capacidad del array
     */
    void redimensiona(const int new_cap);

    /**
     * @brief Libera la memoria del array dinámico de Partícula
     */
    void libera();

public:
    
    /**
     * @brief Constructor por defecto. 
     * @param n Define la cantidad de particulas del conjunto. Se generan de forma aleatoria.
     */
    ConjuntoParticulas(int n = 0);
    
    /**
     * @brief Constructor de copia
     * @param otro Conjunto a copiar
     */
    ConjuntoParticulas(const ConjuntoParticulas &otro);

    /**
     * @brief Destructor, libera la memoria reservada
     */
    ~ConjuntoParticulas();

    /**
     * @brief Devuelve la cantidad de Partículas en el conjunto
     * @return Cantidad de partículas del conjunto
     */
    int getUtiles() const;

    /**
     * @brief Devuelve la capacidad del array Partículas en el conjunto
     * @return Capacidad de partículas del conjunto
     */    
    int getCapacidad() const;
    
    /**
     * @brief Agrega una partícula al conjunto. Si no hay hueco, redimensiona la capacidad
     * @param a_agregar Particula a añadir
     */
    void agregar(const Particula &a_agregar);

    /**
     * @brief Borra la particula de una posición concreta
     * @param pos Posición del array en el que se realiza el borrado
     */
    void borrar(int pos);

    /**
     * @brief Devuelve una referencia al elemento de una posición concreta
     * @param pos Posición del elemento
     * @return Referencia al elemento pos
     */
    const Particula& obtener(int pos) const; 

    /**
     * @brief Reemplaza un elemento concreto de un array con otro
     * @param sustituta Elemento a reemplazar
     * @param pos Posición en la que se realiza el reemplazo
     */
    void reemplazar(const Particula &sustituta, int pos);

    /**
     * @brief Mueve las Partículas del conjunto en base a un tipo
     * @param tipo Tipo de movimiento de las partículas
     */
    void mover(int tipo = 0);

    /**
     * @brief Evalúa si las partículas han chocado
     */
    void gestionarColisiones();

    /**
     * @brief Devuelve los datos del objeto actual como string
     * @return Cadena con los datos formateados
     */
    std::string toString() const;
    
//Sobrecarga de operadores // ? Está correcto??

    /**
     * @brief Sobrecarga del operador de asignación
     * @param otro Objeto que se quiere copiar
     * @return Referencia al objeto actual
     */
    ConjuntoParticulas& operator=(const ConjuntoParticulas &otro);

    /**
     * @brief Sobrecarga del operador de suma y asignación
     * @param p Particula que se quiere agregar al conjunto
     * @return Referencia al objeto actual
     */
    ConjuntoParticulas& operator+=(const Particula &p);

    /**
     * @brief Sobrecarga del operador de suma y asignación
     * @param cp ConjuntoParticula que se quiere agregar al conjunto actual
     * @return Referencia al objeto actual
     */
    ConjuntoParticulas& operator+=(const ConjuntoParticulas &cp);

    /**
     * @brief Compara si dos conjuntos contienen las mismas partículas (sin importar el orden)
     * @param cp Conjunto a comparar
     * @return True si ambos conjuntos son iguales, false en otro caso
     */
    bool operator==(const ConjuntoParticulas &cp) const;
};

//Sobrecarga de operadores

// Se implementan como funciones externas porque los métodos públicos de la clase
// son suficientes para mostrar la información de un Conjunto con el formato que 
// se pide.

/**
 * @brief Sobrecarga del operador << para mostrar un objeto de la clase Particula
 * @param flujo Flujo de salida
 * @param cp Objeto ConjuntoParticula que se desea mostrar
 * @return Referencia al flujo de salida
 */
std::ostream& operator<<(std::ostream &flujo, const ConjuntoParticulas &cp);

/**
 * @brief Sobrecarga del operador >> para leer un objeto de la clase Particula
 * @param flujo Flujo de entrada
 * @param cp Objeto ConjuntoParticulas que se desea leer
 * @return Referencia al flujo de entrada
 */
std::istream& operator>>(std::istream &flujo, ConjuntoParticulas &cp);

#endif //CONJUNTOPARTICULAS_H