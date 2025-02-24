////////////////////////////////
// Práctica 1                 //
// file: src/paquete.cpp      //
// Pedro Velasco Santana      //
////////////////////////////////

#include "../include/paquete.h"

float gTokg(float peso){
    return peso / 1000.0f;
}

//Recibe un paquete y devuelve una cadena con información sobre el mismo

string toString(const Paquete &p){
    return "Origen: " + to_string(p.origen) + " | Destino: " + to_string(p.destino) + " | Peso: " + to_string(gTokg(p.peso));
}

//Crear paquete a partir de unos parámetros

Paquete creaPaquete(const int origen, const int destino, const float peso){
    Paquete nuevo = {origen, destino, peso};
    return nuevo;
}

//Comprobar la validez de los datos de un objeto Paquete

bool esValido(const Paquete &p){
    return p.origen > 0 && p.destino > 0 && p.peso > 0;
}

