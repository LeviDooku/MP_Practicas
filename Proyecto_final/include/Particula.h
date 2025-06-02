/*
NOMBRE Y APELLIDOS: Pedro Velasco Santana
DNI: 45342754w
GRUPO DE PRÁCTICAS: viernes
*/

#ifndef PARTICULA_H
#define PARTICULA_H

#include <cstdlib>
#include "Vector2D.h"

/**
 * @class Particula
 * @brief Objeto que se mueve en un plano bidimensional finito
 */
class Particula{
private:
    Vector2D pos;   ///< Posición de la particula
    Vector2D acel;  ///< Aceleración de la particula
    Vector2D veloc; ///< Velocidad de la particula
    float radio;    ///< Radio de la particula
    int tipo;       ///< tipo de la particula

    /**
     * @brief Comprueba si la posición de la partícula supera el límite izquierdo
     * @param epsilon Resta un valor determinado al cálculo
     * @return True si pasa el límite, false en caso contrario
     */
    bool lim_izq(const float epsilon = 0);

    /**
     * @brief Comprueba si la posición de la partícula supera el límite derecho
     * @param epsilon Suma un valor determinado al cálculo
     * @return True si pasa el límite, false en caso contrario
     */
    bool lim_dcha(const float epsilon = 0);

    /**
     * @brief Comprueba si la posición de la partícula supera el límite superior
     * @param epsilon Suma un valor determinado al cálculo
     * @return True si pasa el límite, false en caso contrario
     */
    bool lim_arriba(const float epsilon = 0);

    /**
     * @brief Comprueba si la posición de la partícula supera el límite inferior
     * @param epsilon Resta un valor determinado al cálculo
     * @return True si pasa el límite, false en caso contrario
     */
    bool lim_abajo(const float epsilon = 0);

    /**
     * @brief Corrige la posición de una partícula
     */
    void corregir_pos();

    /**
     * @brief Limita la velocidad de una párticula en base a su velocidad actual
     */
    void limitar_velocidad();

public:

    /**
     * @brief Constructor con un parámetro
     * @param tipoPart Dependiendo del valor de este, se crea un tipo de partícula u otra
     */
    Particula(const int tipoPart = 0);

    /**
     * @brief Constructor con todos los parámetros
     * @param pos Posición de la partícula a construir
     * @param acel Aceleración de la partícula a construir
     * @param vel Velocidad de la partícula a construir
     * @param radio Radio de la partícula a construir
     * @param tipo Tipo de la partícula a construir
     */
    Particula(const Vector2D &pos, const Vector2D &acel, const Vector2D &vel, const float radio, const int tipo);

    /**
     * @brief Setea una nueva posición para el objeto actual
     * @param new_pos Nueva posición de la partícula
     */
    void setPos(const Vector2D &new_pos);

    /**
     * @brief Setea una nueva aceleración para el objeto actual
     * @param new_acel Nueva aceleración de la partícula
     */
    void setAcel(const Vector2D &new_acel);

    /**
     * @brief Setea una nueva velocidad para el objeto actual
     * @param new_vel Nueva velocidad de la partícula
     */
    void setVel(const Vector2D &new_vel);

    /**
     * @brief Setea un nuevo radio para el objeto actual
     * @param new_radio Nuevo valor para el radio
     */
    void setRadio(const float new_radio);

    /**
     * @brief Devuelve la posición del objeto actual
     * @return La posición del objeto actual
     */
    Vector2D getPos() const;

    /**
     * @brief Devuelve la aceleración del objeto actual
     * @return La aceleración del objeto actual
     */
    Vector2D getAcel() const; 

    /**
     * @brief Devuelve la aceleración del objeto actual
     * @return La aceleración del objeto actual
     */
    Vector2D getVel() const;

    /**
     * @brief Devuelve el radio del objeto actual
     * @return El radio del objeto actual
     */
    float getRadio() const;

    /**
     * @brief Devuelve el tipo del objeto actual
     * @return El tipo del objeto actual
     */
    int getTipo() const;

    /**
     * @brief Actualiza la posición de la partícula en base a unas operaciones
     */
    void mover();

    /**
     * @brief Actualiza los atributos necesarios cuando el objeto "choca" con un borde del mapa
     */
    void rebotar();

    /**
     * @brief Calcula si la partícula ha colisionado con otra pasada como parámetro
     * @param otra Partícula con la que se comprueba la colisión
     * @return True si han colisionado, false en caso contrario
     */
    bool colision(const Particula &otra) const; 

    /**
     * @brief Implementa un choque elástico entre el objeto actual y otra pasada como parámetro 
     * @param otra Partícula con la que choca
     */
    void choque(Particula &otra);

    /**
     * @brief Cambiar la posición de una partícula de forma que al llegar a uno de los lados, sale por el otro.
     */
    void wrap();

    /**
     * @brief Devuelve los datos del objeto actual como string
     * @return Cadena con los datos formateados
     */
    std::string toString() const;

    /**
     * @brief Comparar si dos objetos de Particula son iguales
     * @param p1 Primer objeto de Particula
     * @param p2 Segundo objeto de Particula
     * @return true si son iguales, false en caso contrario
     */
    bool operator==(const Particula &p2) const;
};

//Sobrecarga de operadores

/**
 * @brief Sobrecarga del operador << para mostrar un objeto de la clase Particula
 * @param flujo Flujo de salida
 * @param p Objeto Particula que se desea mostrar
 * @return Referencia al flujo de salida
 */
std::ostream& operator<<(std::ostream &flujo, const Particula &p);

/**
 * @brief Sobrecarga del operador >> para leer un objeto de la clase Particula
 * @param flujo Flujo de entrada
 * @param v Objeto Particula que se desea leer
 * @return Referencia al flujo de entrada
 */
std::istream& operator>>(std::istream &flujo, Particula &p);

#endif //PARTICULA_H