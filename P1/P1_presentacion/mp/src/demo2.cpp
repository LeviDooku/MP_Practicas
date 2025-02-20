////////////////////////////////
// Práctica 1                 //
// file: src/demo2.cpp        //
// Pedro Velasco Santana      //
////////////////////////////////

#include <iostream>
#include "../include/oper2.h"

using namespace std;
int main (int argc, char *argv[]){
	
  double a, b;
  cout << "Introduce el primer valor: ";
  cin >> a;
  cout << "Introduce el segundo valor: ";
  cin >> b;
  cout << "suma(" << a << ", " << b << ") = " << suma(a,b) << endl;
  cout << "resta(" << a << ", " << b << ") = " << resta(a,b) << endl;
  cout << "multiplica(" << a << ", " << b << ") = " << multiplica(a,b) << endl;
  cout << "divide(" << a << ", " << b << ") = " << divide(a,b) << endl;

  return 0;
}