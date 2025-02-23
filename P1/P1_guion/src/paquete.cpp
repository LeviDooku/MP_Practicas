////////////////////////////////
// Práctica 1                 //
// file: src/paquete.cpp      //
// Pedro Velasco Santana      //
////////////////////////////////

#include "../include/paquete.h"

//Recibe un paquete y devuelve una cadena con información sobre el mismo

string toString(const Paquete &p){
    return "O: <" + to_string(p.origen) + "> D: <" + to_string(p.destino) + "> P: <" + to_string(p.peso);
}

//Crear paquete a partir de unos parámetros

Paquete creaPaquete(const int origen, const int destino, const int peso){
    Paquete nuevo = {origen, destino, peso};
    return nuevo;
}

//Comprobar la validez de los datos de un objeto Paquete

bool esValido(const Paquete &p){
    return p.origen > 0 && p.destino > 0 && p.peso > 0;
}

