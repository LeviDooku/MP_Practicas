//La salida esperada es que a es igual a *p

#include<iostream>
using namespace std;

int main(){
    int a = 5;
    int *p = &a; //Declaración de un entero y un puntero a entero

    *p = *p * a; //Se modifica p, equivale a: a = 5 * 5, ya que p -> a
    if(a == *p)
        cout << "a es igual a *p" << endl;
    else
        cout << "a es diferente a *p" << endl;

    cout << "a = :" << a << endl;
    cout << "*p = :" << *p << endl;
}

