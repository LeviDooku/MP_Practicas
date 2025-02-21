/**
   @file central.cpp
   @brief Calcula crculo con centro en medio de dos círculos y radio la mitad de la distancia
   

// si quieres utilizar la funcion to_string(), debes agregar -std=c++14 a las opciones del compilador

 **/

#include <iostream>
#include <cmath> 
#include <string>
#include "punto2d.h"
#include "circulo.h"

using namespace std;

int main() {
    int x, y, radio;

    // leer datos para circulo 1
    cin >> x >> y >> radio;
    Punto centro1(x, y);
    Circulo c1(centro1, radio);

    // leer datos para circulo 2
    cin >> x >> y >> radio;
    Punto centro2(x, y);
    Circulo c2(centro2, radio);

    // realizar los calculos
    Punto aux = c1.getCentro();
    Punto centroNuevo;
    double radioNuevo;

    centroNuevo = aux.puntoMedio(c2.getCentro());
    radioNuevo = aux.distancia(c2.getCentro()) / 2.0;
    Circulo c3(centroNuevo, radioNuevo);

    // mostrar resultados
    cout << "\nLos circulos son\n";
    cout << "Circulo 1 -> " << c1.toString() << ", area: " << c1.area() << endl;
    cout << "Circulo 2 -> " << c2.toString() << ", area: " << c2.area() << endl;
    cout << "Circulo 3 -> " << c3.toString() << ", area: " << c3.area() << endl;
}

/* Fin: central.cpp */
