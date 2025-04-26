////////////////////////////////
// Proyecto final             //
// file: Particula.h          //
// Pedro Velasco Santana      //
////////////////////////////////

#include "Vector2D.h"

//Constructores

Vector2D::Vector2D() : x(0), y(0) {}

Vector2D::Vector2D(float x, float y) : x(x), y(y) {}

//Métodos set y get

void Vector2D::setX(float new_x){
    this->x = new_x;
}

void Vector2D::setY(float new_y){
    this->y = new_y;
}

void Vector2D::setXY(float new_x, float new_y){
    setX(new_x);
    setY(new_y);
}

float Vector2D::getX() const{
    return this->x;
}

float Vector2D::getY() const{
    return this->y;
}

//Otros métodos

void Vector2D::sumar(const Vector2D &a_sumar){}

void Vector2D::escalar(const float valor){}

float Vector2D::modulo() const{
    return 0.0;
}

void Vector2D::normalizar(){}

float Vector2D::distancia(const Vector2D &v2) const{
    return 0.0;
}

std::string Vector2D::toString() const{
    return " ";
}