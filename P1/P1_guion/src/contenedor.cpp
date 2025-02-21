////////////////////////////////
// Práctica 1                 //
// file: src/contenedor.cpp   //
// Pedro Velasco Santana      //
////////////////////////////////

#include "../include/contenedor.h"
#include "paquete.cpp"

struct Contenedor{
        static const int MAX = 100;
        Paquete lista[MAX];
        int utiles = 0;
};

void agregarPaquete(Contenedor c, Paquete p){}
void mostrarContenedor(const Contenedor c){}
int calcularPeso(const Contenedor c){}
Contenedor obtenienePaquetes(const Contenedor c, const int origen){}
void ordear(Contenedor c){}
? enviosDestino(const Contenedor c, const int destino){}
void analisisDestinos(const Contenedor c){}
