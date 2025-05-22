/*
NOMBRE Y APELLIDOS: Pedro Velasco Santana
DNI: 45342754w
GRUPO DE PRÁCTICAS: viernes
*/

#include <cmath>
#include "Vector2D.h"

//Constructor

Vector2D::Vector2D(float x, float y) : x(x), y(y) {}

//Métodos set y get

void Vector2D::setX(float new_x){
    x = new_x;
}

void Vector2D::setY(float new_y){
    y = new_y;
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

//Sobrecarga de operadores

std::ostream& operator<<(std::ostream &flujo, const Vector2D &v){
    flujo << v.toString(); // ? Está bien usar toString()?
    return flujo;
}

std::istream& operator>>(std::istream &flujo, Vector2D &v){
    char p1, coma, p2;
    float x, y;

    flujo >> p1 >> x >> coma >> y >> p2;

    if(p1 == '(' && coma == ',' && p2 == ')') // ? Comprobar coordenadas?
        v.setXY(x, y);
    
    return flujo;
}

bool operator==(const Vector2D &v1, const Vector2D &v2){
    return std::fabs(v1.getX() - v2.getX()) < EPSILON &&
            std::fabs(v1.getY() - v2.getY()) < EPSILON;
}

