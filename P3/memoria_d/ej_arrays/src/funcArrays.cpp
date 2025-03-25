////////////////////////////////
// Práctica 3                 //
// file: funcArrays.cpp (DP)  //
// Pedro Velasco Santana      //
////////////////////////////////

#include <iostream>
#include <cstdlib>
#include "../include/funcArrays.h" // ! NO INCLUIR EN LA ENTREGA ASINNNN

using namespace std;

//Función que recibe un puntero a entero (array) y un tamaño
//Muestra los elementos del array, o los primeros k-elementos
void mostrar(const int *v, int k){
    for(int i = 0; i < k; i++)
       cout << v[i] << " ";
    cout << endl;
}
  
//Función que recibe un puntero a entero, un tamaño y unos umbrales
//Rellena los primeros k elementos con números aleatorios entre min y max
void rellenar(int *v, int k, int min, int max){
    for(int i = 0; i < k; i++)
        v[i] = (random()% (max - min)) + min;
    cout << endl;
}

void Redimensiona(int * &p, int util, int tipo, int &cap){
    int new_size;

    switch (tipo){
        case 1:
        new_size = cap + 1;
        break;

        case 2:
        new_size = cap + TAM_BLOQUE;
        break;

        case 3: 
        new_size = cap * 2; 
        break;
        
        default:
        new_size = 1;
        break;
    }
    
    if(new_size > cap){
        int *v_ampliado = new int[new_size];
        for(int i = 0; i < cap; ++i)
            v_ampliado[i] = p[i];
        delete [] p;
        p = v_ampliado;
    }

    cap = new_size;
}