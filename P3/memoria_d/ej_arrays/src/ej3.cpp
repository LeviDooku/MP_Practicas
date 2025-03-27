////////////////////////////////
// Práctica 3                 //
// file: ej3.cpp (DP)         //
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
        cout << "Introduzca valor correcto (> 0): ";
        cin >> capacidad;
    }

    v = new int [capacidad];
    rellenar(v, capacidad, 0, 10);
    util = capacidad;

    int nro = 0;
    cout << "Ingrese valor para comprobar múltiplos: ";
    cin >> nro;

    while(nro < 0){
        cout << "Introduzca valor correcto (> 0): ";
        cin >> nro;
    }

    cout << "El array es: " << "(capacidad: " << capacidad << ") ; (utilizados: " << util << ")" << endl;
    mostrar(v, util);

    int *mult; 
    int m_cap = 0;

    multiplos(v, capacidad, nro, mult, m_cap);

    cout << "El array de múltiplos es: " << "(capacidad: " << capacidad << ")" << endl;
    mostrar(mult, m_cap);

    delete [] v;
    delete [] mult;
}