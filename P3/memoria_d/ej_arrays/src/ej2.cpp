////////////////////////////////
// Práctica 3                 //
// file: ej2.cpp (DP)         //
// Pedro Velasco Santana      //
////////////////////////////////

#include <iostream>
#include <cstdlib>
#include "../include/funcArrays.h" // ! NO INCLUIR EN LA ENTREGA ASINNNN

using namespace std;

int main(){
    int *v, *v1;
    int util = 0, util1 = 0;
    int capacidad = 0, capacidad1 = 0;
    
    cout << "Introduzca tamaño del vector 1: ";
    cin >> capacidad;

    while(capacidad < 0){
        cout << "Introduzca tamaño del vector: ";
        cin >> capacidad;
    }

    v = new int [capacidad];
    util = capacidad;

    cout << "Introduzca tamaño del vector 2: ";
    cin >> capacidad1;

    while(capacidad1 < 0){
        cout << "Introduzca tamaño del vector: ";
        cin >> capacidad1;
    }

    v1 = new int [capacidad1];
    util1 = capacidad1;

    rellenar(v, capacidad, 0, 10);
    rellenar(v1, capacidad1, 0, 10);

    cout << "El array 1 es: " << "(capacidad: " << capacidad << ") ; (utilizados: " << util << ")" << endl;
    mostrar(v, util);

    cout << "El array 2 es: " << "(capacidad: " << capacidad1 << ") ; (utilizados: " << util1 << ")" << endl;
    mostrar(v1, util1);

    int u_cap = 0; 
    int *resultado_u = Union(v, v1, util, util1, u_cap);

    cout << "El array union es: " << "(capacidad: " << u_cap << ")" << endl;
    mostrar(resultado_u, u_cap);

    int i_cap = 0;
    int *resultado_i = Interseccion(v, v1, util, util1, i_cap);

    cout << "El array intersección es: " << "(capacidad: " << i_cap << ")" << endl;
    mostrar(resultado_i, i_cap);

    delete [] v;
    delete [] v1;
    delete [] resultado_u;
    delete [] resultado_i;
}