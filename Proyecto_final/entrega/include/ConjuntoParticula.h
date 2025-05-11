///////////////////////////////////
// Proyecto final                //
// file: ConjuntoParticula.h    //
// Pedro Velasco Santana         //
///////////////////////////////////

#ifndef CONJUNTOPARTICULAS_H
#define CONJUNTOPARTICULAS_H

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

public:
    
    /**
     * @brief Constructor por defecto. 
     * @param n Define la cantidad de particulas del conjunto. Se generan de forma aleatoria.
     */
    ConjuntoParticulas(const int n = 0);
    
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
     * @brief Redimensiona el array dinámico de Partícula
     * @param new_cap Nueva capacidad del array
     */
    void redimensiona(const int new_cap);
    
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
    Particula& obtener(int pos); 

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
    void mover(const int tipo = 0);

    /**
     * @brief Evalúa si las partículas han chocado
     */
    void gestionarColisiones();

    /**
     * @brief Devuelve los datos del objeto actual como string
     * @return Cadena con los datos formateados
     */
    std::string toString() const;
};

#endif //CONJUNTOPARTICULAS_H