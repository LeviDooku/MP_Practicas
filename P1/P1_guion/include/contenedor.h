////////////////////////////////
// Práctica 1                 //
// file: include/contenedor.h //
// Pedro Velasco Santana      //
////////////////////////////////

// TO DO: mirar parámetros: valor, referencia, referencia constante?

#ifndef CONTENEDOR_H
#define CONTENEDOR_H

struct contenedor;

void agregaPaquete(contenedor c, paquete p);
void mostrarContenedor(const contenedor c); //Evitar, preferible string o algo del estilo 
int calcularPeso(const contenedor c); //devolver en kg!!! Está en gramos
contenedor obtenienePaquetes(const contenedor c, const int origen); //Comprobar que el valor devuelto es correcto
void ordenar(contenedor c);
? enviosDestino(const contenedor c, const int destino); //Devuelve un vector? wtff
void analisisDestinos(const contenedor c); //Not sure lo q devuelve

#endif