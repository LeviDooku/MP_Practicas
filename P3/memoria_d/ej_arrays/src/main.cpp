/*
NOMBRE Y APELLIDOS: Pedro Velasco Santana
DNI: 45342754w
GRUPO DE PRÁCTICAS: viernes
*/

#include <iostream>
#include <cstdlib>
#include "../include/funcArrays.h" //! NO ENTREGAR ASINN

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

    cout << "VALOR: ";
    cin >> valor;

    while(valor != -1){

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

        cout << "VALOR: ";
        cin >> valor;
    }  
    
    int *v1;
    int util1 = 0;
    int capacidad1 = 0;

    cout << endl << "Introduzca tamaño del segundo vector: ";
    cin >> capacidad1;

    while(capacidad < 0){
        cout << "Introduzca tamaño del vector: ";
        cin >> capacidad1;
    }

    v1 = new int [capacidad1];
    util1 = capacidad1;

    rellenar(v1, capacidad1, 0, 10);

    cout << endl << "[+] ARRAYS GENERADOS (1 TERMINAL, 2 ALEATORIO EN RANGO 0 - 10)" << endl << endl;

    cout << "El array 1 es: " << "(capacidad: " << capacidad << ") ; (utilizados: " << util << ")" << endl;
    mostrar(v, util);

    cout << "El array 2 es: " << "(capacidad: " << capacidad1 << ") ; (utilizados: " << util1 << ")" << endl;
    mostrar(v1, util1);
    
    cout << endl << "[+] PRUEBA UNION E INTERSECCIÓN CON ARRAYS ANTERIORES" << endl << endl;

    int u_cap = 0; 
    int *resultado_u = Union(v, v1, util, util1, u_cap);

    cout << "El array union es: " << "(capacidad: " << u_cap << ")" << endl;
    mostrar(resultado_u, u_cap);

    int i_cap = 0;
    int *resultado_i = Interseccion(v, v1, util, util1, i_cap);

    cout << "El array intersección es: " << "(capacidad: " << i_cap << ")" << endl;
    mostrar(resultado_i, i_cap);

    cout << endl << "[+] PRUEBA MULTIPLOS MODIFICANDO ARRAYS ANTERIORES" << endl << endl;

    int nro = 0;
    cout << "Ingrese valor para comprobar múltiplos: ";
    cin >> nro;

    while(nro < 0){
        cout << "Introduzca valor correcto (> 0): ";
        cin >> nro;
    }

    int *mult, *mult1; 
    int m_cap = 0, m_cap1 = 0;

    multiplos(v, capacidad, nro, mult, m_cap);
    multiplos(v1, capacidad1, nro, mult1, m_cap1);

    cout << "El array de múltiplos de vector 1: " << "(capacidad: " << capacidad << ")" << endl;
    mostrar(mult, m_cap);

    cout << "El array de múltiplos de vector 2: " << "(capacidad: " << capacidad << ")" << endl;
    mostrar(mult1, m_cap1);

    delete [] v;
    delete [] v1;
    delete [] resultado_u;
    delete [] resultado_i;
    delete [] mult;
    delete [] mult1;
}