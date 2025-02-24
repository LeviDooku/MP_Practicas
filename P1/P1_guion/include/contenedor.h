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
void mostrarContenedor(const Contenedor &c); //Evitar, preferible string o algo del estilo 
float calcularPeso(const Contenedor &c); //devolver en kg!!! Está en gramos
Contenedor obtienePaquetes(const Contenedor &c, const int origen); //Comprobar que el valor devuelto es correcto
void intercambiaPaquetes(Paquete &a, Paquete &b);
void bubbleSort_pers(Contenedor &c);
void ordenar(Contenedor &c);
void enviosDestino(const Contenedor &c, const int destino, int &nro, float &peso); //Devuelve un vector? wtff
void analisisDestinos(const Contenedor &c); //Not sure lo q devuelve

#endif