/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   circulo.cpp
 * Author: david
 * 
 * Created on 24 de febrero de 2020, 9:08
 */

#include "circulo.h"
#include <string>

using namespace std;

Circulo::Circulo() : centro(0, 0), radio(0) {
}

Circulo::Circulo(const Punto & p, double rradio) : centro(p), radio(rradio) {
}

void Circulo::set(const Punto & p, double rradio) {
    radio = rradio;
    centro = p;
}

Punto Circulo::getCentro() const {
    return centro;
}

double Circulo::getRadio() const {
    return radio;
}

string Circulo::toString() const {
    // // devuelve un string con el formato (x,y) radio-(x,y)

    string rta = to_string(radio) + "-" + centro.toString();
    return rta;
}

double Circulo::Circulo::area() const {
    return PI * radio * radio;
}

double Circulo::distancia(const Circulo & c2) const {
    // calcula la distancia entre los dos centros
    double dist = centro.distancia(c2.getCentro());
    return dist;
}

//Comprueba si un punto es interior al círculo

bool Circulo::interior(const Punto & p) const {
    bool rta = p.distancia(centro) <= getRadio();
    return rta;
}
