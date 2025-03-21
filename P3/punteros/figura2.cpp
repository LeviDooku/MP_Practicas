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

int main()
{ 
  const int N = 10;
  int datos[N]; //Array de enteros tamaño 10

  // para rellenar el array con valores al azar entre [min, max]
  // utiliza las dos instrucciones siguientes

  srand(time(0));
  rellenar(datos, N, -10, 10);  //Se rellena usando función rellenar

  // ? Modifica los valores del array. Poniendo a 0 el primer elemento y signo cambiado a los demás
  int signo = 1;
  for(int i = 0; i < N; i++){
    datos[i] = i * signo;
    signo = signo * -1;
   }

  mostrar(datos, N); //Muestra los valores del vector

  int *p = &datos[2]; //Declarar un puntero a entero que contiene la dirección de memoria del tercer elemento
  mostrar(p, 5); //Se muestran los elementos del 2 - 7

  p = &datos[4]; //Se reasigna el puntero al quinto elemento
  mostrar(p, 5); //Se muestran los últimos elemetos del array
  
  //Se asignan dos nuevos punteros a enteros y se asignan a la cuarta y novena posición del array
  int *p1, *p2;
  p1 = &datos[3];   
  p2 = &datos[8];
  cout << "Salida 1: " << p2 - p1 << endl; // ? Salida 1: 5

  p1 = &datos[0];
  cout << "Salida 2: " << p2 - p1 << endl; // ? Salida 2: 8

  p1 = datos;
  cout << "Salida 3: " << p2 - p1 << endl; // ? Salida 3: 8

  p1 = &datos[5];
  cout << "Salida 4: " << *p2 << " - " << *p1
       << " = " << *p2 - *p1 << endl;      // ? Salida 4: (valor pos 6) - (valor pos 3) = diferencia
}