////////////////////////////////
// Práctica 3                 //
// file: ej1.cpp (DP)         //
// Pedro Velasco Santana      //
////////////////////////////////

#include <iostream>
#include <cstdlib>

using namespace std;

//Función que recibe un puntero a entero (array) y un tamaño
//Muestra los elementos del array, o los primeros k-elementos
void mostrar(const int *v, int k){
    for(int i = 0; i < k; i++)
       cout << v[i] << ", ";
    cout << endl;
  }
  
//Función que recibe un puntero a entero, un tamaño y unos umbrales
//Rellena los primeros k elementos con números aleatorios entre min y max
void rellenar(int *v, int k, int min, int max){
    for(int i = 0; i < k; i++)
        v[i] = (random()% (max - min)) + min;
}

void Redimensiona(int * &p, int util, int tipo, int &cap){ //Ni idea a qué se refiere con la capacidad

}

int main(){
    const int TAM_BLOQUE = 5;
    int *v;
    int util;
    
    while(util > 0){
        cout << "Introduzca tamaño del vector: ";
        cin >> util;
    }

    v = new int [util];

    rellenar(v, util, 0, 30);

    cout << "El array actual es: " << endl;
    mostrar(v, util);
    
    int opcion;

    cout << "Elija forma de redimensión: " << endl;
    cout << "1) Una casilla" << endl << "2) Un bloque" << endl << "3) Duplicar tamaño" << endl;
    cin >> opcion;

    Redimensiona(v, util, opcion,);
    
    
}