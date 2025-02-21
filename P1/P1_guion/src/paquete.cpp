////////////////////////////////
// Práctica 1                 //
// file: src/paquete.cpp      //
// Pedro Velasco Santana      //
////////////////////////////////

#include "../include/paquete.h"
#include "contenedor.cpp"

#include <string>

struct Paquete{
    int origen;
    int destino;
    int peso;
};

string toString(const Paquete p){}
Paquete creaPaquete(const int origen, const int destino, const int peso){}
bool esValido(const Paquete p);

