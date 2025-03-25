////////////////////////////////
// Práctica 3                 //
// file: ej1.cpp (DP)         //
// Pedro Velasco Santana      //
////////////////////////////////

#include <iostream>
#include <cstdlib>
#include "../include/funcArrays.h" // ! NO INCLUIR EN LA ENTREGA ASINNNN

using namespace std;

int main(){
    int *v;
    int util = 0;
    int capacidad = 0;
    
    cout << "Introduzca tamaño del vector: ";
    cin >> capacidad;

    while(capacidad < 0){
        cout << "Introduzca tamaño del vector: ";
        cin >> capacidad;
    }

    v = new int [capacidad];

    int valor;
    cout << "Introduzca valores: (-1 para terminar) " << endl;

    while(valor != -1){
        cout << "VALOR: ";
        cin >> valor;

        if(util == capacidad){
            int tipo;
            cout << endl << "Se requiere redimensión. Elija forma: " << endl;
            cout << "1) Una casilla" << endl << "2) Un bloque" << endl << "3) Duplicar tamaño" << endl;
            cin >> tipo;
            Redimensiona(v, util, tipo, capacidad);
        }

        v[util] = valor;
        util++;

        cout << "El array actual es: " << "(capacidad: " << capacidad << ") ; (utilizados: " << util << ")" << endl;
        mostrar(v, util);
    }  
    
    delete [] v;
}