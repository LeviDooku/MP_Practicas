////////////////////////////////
// Proyecto final             //
// file: Vector2D.cpp         //
// Pedro Velasco Santana      //
////////////////////////////////

#include <cmath>
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
    return x;
}

float Vector2D::getY() const{
    return y;
}

//Otros métodos

void Vector2D::sumar(const Vector2D &a_sumar){
    setXY((x + a_sumar.getX()), (y + a_sumar.getY()));
}

void Vector2D::escalar(const float valor){
    setXY((x * valor), (y * valor));
}

float Vector2D::modulo() const{
    return sqrt((x * x) + (y * y));
}

void Vector2D::normalizar(){
    float m = modulo();
   
    if(m != 0)
        setXY((x/m), (y/m));
}

float Vector2D::distancia(const Vector2D &v2) const{
    return sqrt(((v2.getX() - x) * (v2.getX() - x)) + ((v2.getY() - y) * (v2.getY() - y)));
}

std::string Vector2D::toString() const{
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}