////////////////////////////////
// Práctica 1                 //
// file: include/Contenedor.h //
// Pedro Velasco Santana      //
////////////////////////////////

// TO DO: mirar parámetros: valor, referencia, referencia constante?

#ifndef CONTENEDOR_H
#define CONTENEDOR_H

struct Contenedor;

void agregaPaquete(Contenedor c, Paquete p);
void mostrarContenedor(const Contenedor c); //Evitar, preferible string o algo del estilo 
int calcularPeso(const Contenedor c); //devolver en kg!!! Está en gramos
Contenedor obtenienePaquetes(const Contenedor c, const int origen); //Comprobar que el valor devuelto es correcto
void ordenar(Contenedor c);
? enviosDestino(const Contenedor c, const int destino); //Devuelve un vector? wtff
void analisisDestinos(const Contenedor c); //Not sure lo q devuelve

#endif