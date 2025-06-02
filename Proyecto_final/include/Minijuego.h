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
    int num_vidas;                  ///< Número de vidas del jugador

    /**
     * @brief Mueve las naves según su patrón de movimiento
     */
    //void moverNaves();

    /**
     * @brief Mueve los disparos hacia arriba de la pantalla
     */
    //void moverDisparos();

    /**
     * @brief Gestiona las colisiones entre elementos del juego
     * @return True si se produjo colisión, false en caso contrario
     */
    //bool gestionaColisiones();

    /**
     * @brief Crea un nuevo disparo en la base de la nave
     */
    //void crearDisparo();
public:
    
    /**
     * @brief Constructor
     */
    Minijuego(int numNaves = MAX_NAVES, float radioBase = 10.0f, float radioNave = 8.0, int vidas = MAX_VIDAS);

    /**
     * @brief Avanza el estado del juego un paso
     * @param tecla Código de la tecla pulsada
     * @return Código del estado del juego
     */
    int step(int tecla);

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
    //int getNumNaves() const;

    /**
     * @brief Devuelve la cantidad de disparos restantes
     * @return El número de disparos restantes
     */
    //int getNumDisparos() const;

    /**
     * @brief Reinicia el juego a su estado inicial
     */
    //void reiniciar();
};

#endif //MINIJUEGO_H