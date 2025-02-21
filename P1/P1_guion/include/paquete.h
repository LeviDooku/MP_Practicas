////////////////////////////////
// Práctica 1                 //
// file: include/paquete.h    //
// Pedro Velasco Santana      //
////////////////////////////////

// TO DO: mirar parámetros: valor, referencia, referencia constante?

#ifndef PAQUETE_H
#define PAQUETE_H

struct paquete;

String toString(const paquete p); //Por q da error el string. Mirar formato en pdf
paquete creaPaquete(const int origen, const int destino, const int peso);
bool esValido(const paquete p);

#endif