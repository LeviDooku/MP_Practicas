#include<iostream>
using namespace std;

int main(){
    int a = 5;
    int *p = &a; //Declaración de un puntero a entero
    int **p2 = &p; //Declaración de un puntero a puntero a entero

    cout<< "Inicialización: " << endl << "a = :" << a << endl << "*p = :" << *p << endl << "**p2 = :" <<  **p2 << endl;
    
    **p2 = *p + (**p2 / a); // 5 + (5/5) = 6 

    cout << endl << "Primera operación: " << endl << "a = :" << a << endl << "*p = :" << *p << endl << "**p2 = :" <<  **p2 << endl;

    *p = a + 1; // (6 + 1) = 7
    
    cout << endl << "Segunda operación: " << endl << "a = :" << a << endl << "*p = :" << *p << endl << "**p2 = :" <<  **p2 << endl;

    a = **p2 / 2; // 7 / 2 = 3 (enteros)
    
    cout << endl << "Tercera operación (RESULTADOS): " << endl << "a = :" << a << endl << "*p = :" << *p << endl << "**p2 = :" <<  **p2 << endl;
}