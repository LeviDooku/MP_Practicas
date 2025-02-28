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

    while(cad1[i != '\0']){
        char actual = cad1[i];
        for(int j = 0; j < longitud(cad1); ++j){
            if(aux[j] != actual){
                aux[j] = actual;
                contador++;
            }
        }
    }
    return contador;
}

bool anagrama(const char cad1[],const char cad2[]){
    return false;
}

void compress(const char frase[], char salida []){}

void decompress(const char frase[], char salida[]){}

