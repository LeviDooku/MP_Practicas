////////////////////////////////
// Proyecto final             //
// file: Vector2D.h           //
// Pedro Velasco Santana      //
////////////////////////////////

#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <string>

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

#endif //VECTOR2D_H