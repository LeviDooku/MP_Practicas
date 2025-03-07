////////////////////////////////
// Práctica 2                 //
// file: src/proceso.cpp      //
// Pedro Velasco Santana      //
////////////////////////////////

#include "../include/proceso.h"
#include <iostream>

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
    int i = 0;
    int contador = 0;

    while(cad1[i] != TERMINADOR){
        char actual = cad1[i];
        int j = 0;

        while (cad2[j] != TERMINADOR){
            if(actual == cad2[j])
                contador++;
            j++;
        }
        i++;
    }
    return (contador == longitud(cad1)) ? true : false;
}

//Función auxiliar para compress y decompress
void int_to_char(int num, char cadena[], int & indice){
    int temp = num;
    int digitos = 0;
    
    //Contar los dígitos de num
    do{
       digitos++;
       temp /= 10; 
    }while(temp > 0);

    //Agregar dígitos a la cadena
    for(int i = digitos - 1; i >= 0; --i){
        cadena[indice + i] = '0' + (num % 10); //Convertir último dígito y agregarlo (en tabla ASCII, los dígitos decimales están ordenados)
        num /= 10; //Eliminar dígito ya agregado
    }
    indice += digitos; //Actualizar el índice después de agregar los dígitos
}

//Se presupone que frase ya está ordenada
void compress(const char frase[], char salida []){
    int i = 0;
    int j = 0;

    while(frase[i] != TERMINADOR){
        int contador = 1;
        while(frase[i] == frase[i + 1] && frase[i + 1] != TERMINADOR){
            contador++;
            i++;
        }
        salida[j++] = frase[i];
        if(contador >= 10)
            int_to_char(contador, salida, j);
        else
            salida[j++] = '0' + contador;
        i++;
    }
    salida[j] = TERMINADOR;
}

void decompress(const char frase[], char salida[]){}