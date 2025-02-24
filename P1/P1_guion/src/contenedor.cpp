////////////////////////////////
// Práctica 1                 //
// file: src/contenedor.cpp   //
// Pedro Velasco Santana      //
////////////////////////////////

#include "../include/contenedor.h"

#include <iostream>

//Agregar un paquete al contenedor, si este es válido

void agregaPaquete(Contenedor &c, Paquete &p){
        if(c.utiles < Contenedor::MAX && esValido(p))
                c.lista[c.utiles++] = p;
}

//Mostrar el contenido del contenedor c, para ello se usa toString()

void mostrarContenedor(const Contenedor &c){
        for(int i = 0; i < c.utiles; ++i)
                std::cout << toString(c.lista[i]) << std::endl;
}

//Calcular el peso total de un contenedor en kg

float calcularPeso(const Contenedor &c){
        float peso_total = 0;
        for(int i = 0; i < c.utiles; ++i)
                peso_total += c.lista[i].peso;
        return gTokg(peso_total);
}

//Crear un objeto contenedor nuevo a partir de otro contenedor. El nuevo contendrá solo los paquetes con el origen indicado por parámetro

Contenedor obtienePaquetes(const Contenedor &c, const int origen){
        Contenedor nuevo;
        for(int i = 0; i < c.utiles; ++i){
                if(c.lista[i].origen == origen)
                        nuevo.lista[nuevo.utiles++] = c.lista[i];
        }
        return nuevo;
}

//Función auxiliar de intercambio de paquetes

void intercambiaPaquetes(Paquete &a, Paquete &b){
        Paquete aux = a;
        a = b;
        b = aux;
}

//Ordenar un contenedor con el criterio indicado en el guion. Es una modificación del bubble sort

void bubbleSort_pers(Contenedor &c){
        for(int i = 0; i < c.utiles - 1; ++i){
                for(int j = 0; j < c.utiles - i - 1; ++j){
                        if(c.lista[j].origen > c.lista[j + 1].origen || 
                        c.lista[j].origen == c.lista[j + 1].origen &&
                        c.lista[j].destino > c.lista[j + 1].destino)
                                intercambiaPaquetes(c.lista[j], c.lista[j + 1]);
                }
        }
}

//Llama a bubbleSort_pers (se hace así para hacer el código más modular)

void ordenar(Contenedor &c){
        bubbleSort_pers(c);
}

void enviosDestino(const Contenedor &c, const int destino, int &nro, float &peso){
        nro = 0; 
        peso = 0.0;
        for(int i = 0; i < c.utiles; ++i){
                if(c.lista[i].destino == destino){
                        peso += gTokg(c.lista[i].peso);
                        nro++;
                }
        }
}

void analisisDestinos(const Contenedor &c){
        cout << "NADA";
}
