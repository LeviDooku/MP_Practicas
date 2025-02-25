////////////////////////////////
// Práctica 1                 //
// file: include/contenedor.h //
// Pedro Velasco Santana      //
////////////////////////////////

// TO DO: mirar parámetros: valor, referencia, referencia constante?

#ifndef CONTENEDOR_H
#define CONTENEDOR_H

#include "paquete.h"

struct Contenedor{
    static const int MAX = 100;
    Paquete lista[MAX];
    int utiles = 0;
};

void agregaPaquete(Contenedor &c, Paquete &p);
void mostrarContenedor(const Contenedor &c);
float calcularPeso(const Contenedor &c);
Contenedor obtienePaquetes(const Contenedor &c, const int origen);
void intercambiaPaquetes(Paquete &a, Paquete &b);
void bubbleSort_pers(Contenedor &c);
void ordenar(Contenedor &c);
void enviosDestino(const Contenedor &c, const int destino, int &nro, float &peso);
void analisisDestinos(const Contenedor &c);

#endif