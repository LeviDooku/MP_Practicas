////////////////////////////////
// Práctica 3                 //
// file: ej3.cpp (ptr)        //
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

void params(int *v, int util, int * &menor, int * &mayor){
    int *actual;
    for(int i = 0; i < util; ++i){
        actual = (v + i);
        if(*actual < *menor) 
            menor = actual;
        else if(*actual > *mayor) 
            mayor = actual;
    }
}

int main(){

    const int MAX = 21;
    int vector[MAX];
    int usados = MAX;

    srand(time(0));
    rellenar(vector, MAX, 0, 30);

    int *menor = vector;
    int *mayor = vector;

    mostrar(vector, usados);

    params(vector, usados, menor, mayor);
    
    cout << "Elemento menor: " << *menor << endl;
    cout << "Elemento mayor: " << *mayor << endl;

    usados /= 2;
    menor = vector;
    mayor = vector;

    mostrar(vector, usados);

    params(vector, usados, menor, mayor);

    cout << "Elemento menor (primera mitad): " << *menor << endl;
    cout << "Elemento mayor (primera mitad): " << *mayor << endl;

    usados = MAX / 3; 
    int *tercio = &vector[usados];
    menor = tercio;
    mayor = tercio;

    mostrar(tercio, usados);

    params(tercio, usados, menor, mayor);

    cout << "Elemento menor (segundo tercio): " << *menor << endl;
    cout << "Elemento mayor (segundo tercio): " << *mayor << endl;

    usados = MAX;
    menor = vector;
    mayor = vector;

    params(vector, usados, menor, mayor);

    if(menor < mayor)
        cout << "El valor menor (" << *menor << ") Aparece primero en el array" << endl;
    else
        cout << "El valor mayor (" << *mayor << ") Aparece primero en el array" << endl;

}