/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   punto2d.h
 * Author: david
 *
 * Created on 24 de febrero de 2020, 9:06
 */

#ifndef PUNTO2D_H
#define PUNTO2D_H

#include <string>
using namespace std;

const double PI = 3.14159265;

class Punto {
private:
    double x; // coordenada x del punto
    double y; // coordenada y del punto

public:
    Punto(); //constructor. Pone a 0 las dos coordenadas
    Punto(double px, double py); // constructor. Inicializa un punto con dos valores x y
    double getX() const;
    double getY() const;
    void setX(double newXValue);
    void setY(double newYValue);
    string toString() const; // devuelve el contenido del punto como un string
    double distancia(const Punto & p2) const; // calcula la distancia a otro punto
    Punto puntoMedio(const Punto & p2) const; //devuelve el punto medio entre el objeto implicito y p2
};

#endif /* PUNTO2D_H */
