//La salida esperada es que a es diferente a *p

#include<iostream>
using namespace std;

int main(){
    int a = 5, *p; //Declaración de un entero y un puntero a entero

    a = *p * a; //Se modifica a, equivale a: a = (valor intedeterminado) * 5
    if(a == *p)
        cout << "a es igual a *p" << endl;
    else
        cout << "a es diferente a *p" << endl;

    cout << "a = :" << a << endl;
    cout << "*p = :" << *p << endl;

}