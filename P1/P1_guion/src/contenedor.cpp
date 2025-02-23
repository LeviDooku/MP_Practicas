////////////////////////////////
// Práctica 1                 //
// file: src/contenedor.cpp   //
// Pedro Velasco Santana      //
////////////////////////////////

#include "../include/contenedor.h"

#include <iostream>

//Agregar un paquete al contenedor, si este es válido

void agregarPaquete(Contenedor &c, Paquete &p){
        if(c.utiles < Contenedor::MAX && esValido(p))
                c.lista[c.utiles++] = p;
}

//Mostrar el contenido del contenedor c, para ello se usa toString()

void mostrarContenedor(const Contenedor &c){
        for(int i = 0; i < c.utiles; ++i)
                std::cout << toString(c.lista[i]) << std::endl;
}

//Calcular el peso total de un contenedor en kg

int calcularPeso(const Contenedor &c){
        int peso_total = 0;
        for(int i = 0; i < c.utiles; ++i)
                peso_total += c.lista[i].peso;
        return gTokg(peso_total);
}

//Crear un objeto contenedor nuevo a partir de otro contenedor. El nuevo contendrá solo los paquetes con el origen indicado por parámetro

Contenedor obtenienePaquetes(const Contenedor &c, const int origen){
        Contenedor nuevo;
        for(int i = 0; i < c.utiles; ++i){
                if(c.lista[i].origen == origen)
                        nuevo.lista[nuevo.utiles++] = c.lista[i];
        }
        return nuevo;
}

void bubbleSort(){}

void ordear(Contenedor &c){

}

//? enviosDestino(const Contenedor c, const int destino){}

void analisisDestinos(const Contenedor c){}
