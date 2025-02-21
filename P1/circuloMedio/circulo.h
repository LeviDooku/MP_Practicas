/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   circulo.h
 * Author: david
 *
 * Created on 24 de febrero de 2020, 9:08
 */

#ifndef CIRCULO_H
#define CIRCULO_H

#include "punto2d.h"
#include <string>

class Circulo {
private:
    Punto centro; // Centro del círculo
    double radio; // radio del círculo

public:
    Circulo(); // Constructor: Pone a 0 el punto y el radio
    Circulo(const Punto & centro, double rradio); // Constructor: Inicializa el círculo con un centro y un radio
    void set(const Punto & centro, double rradio); // Asigna el centro y el radio a un circulo
    Punto getCentro() const;
    double getRadio() const;
    string toString() const; // devuelve el contenido del circulo como un string
    double area() const; // Devuelve el �rea de un círculo
    double distancia(const Circulo & c2) const;
    bool interior(const Punto & p) const; // true si p est� contenido en el círculo
};


#endif /* CIRCULO_H */
