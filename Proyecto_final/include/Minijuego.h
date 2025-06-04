/*
NOMBRE Y APELLIDOS: Pedro Velasco Santana
DNI: 45342754w
GRUPO DE PRÁCTICAS: viernes
*/

#ifndef MINIJUEGO_H
#define MINIJUEGO_H

#include "ConjuntoParticulas.h"
#include "Particula.h"
#include "params.h"

/**
 * @class Minijuego
 * @brief Usa clases anteriores para montar un juego básico de disparos.
 */
class Minijuego{
private: 
    ConjuntoParticulas naves;       ///< Naves que recibirán los disparos
    ConjuntoParticulas disparos;    ///< Disparos que saldrán desde la base
    Particula base;                 ///< Base que se moverá en horizontal y disparará
    int estado_juego;               ///< 0: jugando, 1: victoria, -1: derrota
    int num_naves;                  ///< Número inicial de naves
    float radio_base;               ///< Radio de la base
    float radio_nave;               ///< Radio de las naves    
    int municion;                   ///< Munición disponible
    float tiempo_ultimo_disparo;    ///< Tiempo desde que se realizó el último disparo
          
    
    /**
     * @brief Mueve las naves según su patrón de movimiento
     */
    void moverNaves();

    /**
     * @brief Mueve los disparos hacia arriba de la pantalla y los elimina del conjunto
     */
    void moverDisparos();

    /**
     * @brief Crea un nuevo disparo en la base de la nave y lo agrega al conjunto disparos
     */
    void crearDisparo();

    /**
     * @brief Gestiona las colisiones entre elementos del juego
     * @return True si se produjo colisión, false en caso contrario
     */
    bool gestionaColisiones();

    /**
     * @brief Método para crear las partículas del conjunto Naves
     */
    void inicializarNaves();

    /**
     * @brief Actualizar los atributos de la base, en función de la tecla pulsada
     * @param tecla Código de la tecla que define el movimiento de la base
     */
    void moverBase(int tecla);

public:
    
    /**
     * @brief Constructor
     */
    Minijuego(int numNaves = MAX_NAVES, float radioBase = MAX_R_BASE, float radioNave = MAX_R_NAVE);

    /**
     * @brief Avanza el estado del juego un paso
     * @param tecla Código de la tecla pulsada
     * @return Código del estado del juego
     */
    int step(int tecla, float dt);

    /**
     * @brief Comprueba si el juego ha termiado
     * @return True si el juego ha finalizado, false en otro caso
     */
    bool terminado() const;

    /**
     * @brief Devuelve el estao del juego
     * @return 0: jugando, 1: victoria, -1: derrota
     */
    int getEstado() const;

    /**
     * @brief Devuelve una referencia constante al conjunto de naves
     * @return Referencia constante al ConjuntoParticulas de naves
     */
    const ConjuntoParticulas& getNaves() const;
    
    /**
     * @brief Devuelve una referencia constante al conjunto de disparos
     * @return Referencia constante al ConjuntoParticulas de disparos
     */
    const ConjuntoParticulas& getDisparos() const;

    /**
     * @brief Devuelve una referencia constante a la base del jugador
     * @return Referencia constante a la Particula que representa la base
     */
    const Particula& getBase() const;

    /**
     * @brief Devuelve el número de naves restantes
     * @return El número de naves restantes
     */
    int getNumNaves() const;

    /**
     * @brief Devuelve la cantidad de disparos restantes
     * @return El número de disparos restantes
     */
    int getNumDisparos() const;

    /**
     * @brief Devuelve el radio de la nave
     * @return Radio de la nave
     */
    float getRadioNave() const;

    /**
     * @brief Devuelve el radio de la base
     * @return Radio de la base
     */
    float getRadioBase() const;

    /**
     * @brief Reinicia el juego a su estado inicial
     */
    void reiniciar(int num_naves); 
};

#endif //MINIJUEGO_H