//La salida esperada es que a es diferente a *p

#include<iostream>
using namespace std;

int main(){
    int a = 5, *p; //Declaración de un entero y un puntero a entero

    *p = *p * a; //Se modifica p, equivale a: *p = 5 * (valor intedeterminado)
    if(a == *p)
        cout << "a es igual a *p" << endl;
    else
        cout << "a es diferente a *p" << endl;

    cout << "a = :" << a << endl;
    cout << "*p = :" << *p << endl;

}