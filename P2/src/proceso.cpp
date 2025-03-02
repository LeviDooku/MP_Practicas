////////////////////////////////
// Práctica 1                 //
// file: src/contenedor.cpp   //
// Pedro Velasco Santana      //
////////////////////////////////

#include "../include/proceso.h"

bool sonIguales(const char cad1[],const char cad2[]){
    int i = 0;
    bool resultado = (longitud(cad1) == longitud(cad2)) ? true : false;

    do{
        resultado = (cad1[i] == cad2[i]) ? true : false;
        i++;
    }while(cad1[i] != TERMINADOR && resultado);

    return resultado;
}

int longitud(const char cad[]){
    int longitud = 0;

    while(cad[longitud] != TERMINADOR)
        longitud++;

    return longitud;
}

int carsUnicos(const char cad1[]){
    char aux[longitud(cad1)];
    int i = 0;
    int contador = 0;

    while (cad1[i] != TERMINADOR){
        char actual = cad1[i];
        bool encontrado = false;
        int j = 0;

        while (aux[j] != TERMINADOR && !encontrado){
            encontrado = (aux[j] == actual);
            j++;
        }

        if (!encontrado){
            aux[j] = actual;
            aux[j + 1] = TERMINADOR;
            contador++;
        }
        i++;
    }

    return contador;
}

bool anagrama(const char cad1[],const char cad2[]){
    bool resultado = false;
    return resultado;   
}

void compress(const char frase[], char salida []){}

void decompress(const char frase[], char salida[]){}

