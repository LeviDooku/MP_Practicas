/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   punto2d.cpp
 * Author: david
 * 
 * Created on 24 de febrero de 2020, 9:06
 */

#include "punto2d.h"
#include <cmath>

Punto::Punto() : x(0), y(0) {
}

Punto::Punto(double px, double py) : x(px), y(py) {
}

double Punto::getX() const{
    return x;
}

double Punto::getY() const{
    return y;
}

void Punto::setX(double px) {
    x = px;
}

void Punto::setY(double py) {
    y = py;
}

string Punto::toString() const {
    // devuelve un string con el formato (x,y)
    string rta = "(" + to_string(x) + "," + to_string(y) + ")";
    return rta;
}

double Punto::distancia(const Punto & p2) const{
    double dx = p2.getX() - getX();
    double dy = p2.getY() - getY();
    return sqrt(dx * dx + dy * dy);
}

Punto Punto::puntoMedio(const Punto & p2) const {
    Punto pMedio;
    pMedio.setX((getX() + p2.getX()) / 2.0);
    pMedio.setY((getY() + p2.getY()) / 2.0);
    return pMedio;
}