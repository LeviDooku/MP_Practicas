////////////////////////////////
// Práctica 1                 //
// file: include/paquete.h    //
// Pedro Velasco Santana      //
////////////////////////////////

// TO DO: mirar parámetros: valor, referencia, referencia constante?

#ifndef PAQUETE_H
#define PAQUETE_H

#include <string>
using namespace std;

struct Paquete{
    int origen;
    int destino;
    int peso;
};

int gTokg(int p);
string toString(const Paquete p); //Por q da error el string. Mirar formato en pdf
Paquete creaPaquete(const int origen, const int destino, const int peso);
bool esValido(const Paquete p);

#endif