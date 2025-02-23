////////////////////////////////
// Práctica 1                 //
// file: src/contenedor.cpp   //
// Pedro Velasco Santana      //
////////////////////////////////

#include "../include/contenedor.h"

void agregarPaquete(Contenedor &c, Paquete &p){
        if(c.utiles < Contenedor::MAX && esValido(p))
                c.lista[c.utiles++] = p;
}

void mostrarContenedor(const Contenedor c){}

int calcularPeso(const Contenedor c){}

Contenedor obtenienePaquetes(const Contenedor c, const int origen){}

void ordear(Contenedor c){}

//? enviosDestino(const Contenedor c, const int destino){}

void analisisDestinos(const Contenedor c){}
