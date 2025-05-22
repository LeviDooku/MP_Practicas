/*
NOMBRE Y APELLIDOS: Pedro Velasco Santana
DNI: 45342754w
GRUPO DE PRÁCTICAS: viernes
*/

#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <iostream>
#include <string>
#include <cmath> // ? Se puede?

const float EPSILON = 1e-5; // ? Buen epsilon?

/**
 * @class Vector2D
 * @brief Representar un vector en dos dimensiones.
 */
class Vector2D{
private:
    float x, y; ///< Componentes x e y del vector.

public:

    /**
     * @brief Constructor con parámetros
     * @param x Componente x del vector, por defecto = 0
     * @param y Componente y del vector, por defecto = 0
     */
    Vector2D(float x = 0, float y = 0);

    /**
     * @brief Setea componente x del vector
     * @param new_x Nuevo valor de la componente
     */
    void setX(float new_x);
    
    /**
     * @brief Setea componente y del vector
     * @param new_y Nuevo valor de la componente
     */
    void setY(float new_y);

    /**
     * @brief Setea componente x e y del vector
     * @param new_x Nuevo valor de la componente x
     * @param new_y Nuevo valor de la componente y
     */
    void setXY(float new_x, float new_y);

    /**
     * @brief Devuelve componente x del vector
     * @return Valor de la componente x
     */
    float getX() const;

    /**
     * @brief Devuelve componente y del vector
     * @return Valor de la componente y
     */
    float getY() const;

    /**
     * @brief Suma un nuevo vector al objeto actual
     * @param a_sumar Objeto Vector2D a sumar al objeto actual
     */
    void sumar(const Vector2D &a_sumar);
    
    /**
     * @brief Multiplica el objeto actual por un valor
     * @param valor Valor usado para multiplicar
     */
    void escalar(const float valor);

    /**
     * @brief Devuelve el módulo del vector aplicando la fórmula
     * @return Módulo del vector
     */
    float modulo() const;

    /**
     * @brief Normaliza un vector, convirtiéndolo en vector unitario
     */
    void normalizar();

    /**
     * @brief Calcula la distancia entre el objeto actual y otro objeto
     * @param v2 Objeto Vector2D con el que calcular la distancia
     * @return Distancia entre los dos objetos
     */
    float distancia(const Vector2D &v2) const;

    /**
     * @brief Devuelve los datos del objeto actual como string
     * @return Datos del vector como string
     */
    std::string toString() const;
};

//Sobrecarga de operadores

// ? Funciones amiga??

/**
 * @brief Sobrecarga del operador << para mostrar un objeto de la clase Vector2D
 * @param flujo Flujo de salida
 * @param v Objeto Vector2D que se desea mostrar
 * @return Referencia al flujo de salida
 */
std::ostream& operator<<(std::ostream &flujo, const Vector2D &v);

/**
 * @brief Sobrecarga del operador >> para mostrar un objeto de la clase Vector2D
 * @param flujo Flujo de entrada
 * @param v Objeto Vector2D que se desea leer
 * @return Referencia al flujo de entrada
 */
std::istream& operator>>(std::istream &flujo, Vector2D &v);

/**
 * @brief Comparar si dos objetos de Vector2D son iguales
 * @param v1 Primer objeto de Vector2D
 * @param v2 Segundo objeto de Vector2D
 * @return true si son iguales, false en caso contrario
 */
bool operator==(const Vector2D &v1, const Vector2D &v2);

#endif //VECTOR2D_H