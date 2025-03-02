/*
 * File:   main.cpp
 * Author: David A. Pelta
 *
 * Programa básico para utilizar las funciones del módulo "proceso".
 */

#include <iostream>
#include <cstring>
#include "../include/proceso.h"

using namespace std;

int main() {
    
    char cad1[MAX_SIZE];
    char cad2[MAX_SIZE];
    char cad3[MAX_SIZE];
    
    strcpy(cad1, "123456789"); 
    strcpy(cad2, "123456789");
    cout << "La longitud de la cadena " << cad1 << " es: " << longitud(cad1) << endl;
    
    cout << "----------------------------------------------------" << endl;
    cout << "Las cadenas\n" << cad1 << endl << cad2 << endl << " son iguales? " << (sonIguales(cad1, cad2)?"SI":"NO") << endl;
    cad2[5] = TERMINADOR;
    cout << "Las cadenas\n" << cad1 << endl << cad2 << endl << " son iguales? " << (sonIguales(cad1, cad2)?"SI":"NO") << endl;
    
    cout << "----------------------------------------------------" << endl;
    
    cout << "Caracteres unicos en " << cad1 << " -> " << carsUnicos(cad1) << endl;
    strcpy(cad1, "123445566789");
    cout << "Caracteres unicos en " << cad1 << " -> " << carsUnicos(cad1) << endl;
    
    cout << "----------------------------------------------------" << endl;
    
    strcpy(cad1, "123456789");
    strcpy(cad2, "432198765");
    cout << "Las cadenas\n" << cad1 << endl << cad2 << endl << " son anagramas? " << (anagrama(cad1, cad2)?"SI":"NO") << endl;
    
    cad1[0] = 'a';
    cout << "Las cadenas\n" << cad1 << endl << cad2 << endl << " son anagramas? " << (anagrama(cad1, cad2)?"SI":"NO") << endl;
    
    //cout << "Son Iguales : " << sonIguales(frase, salida) << endl;
    cout << "----------------------------------------------------" << endl;
    strcpy(cad1, "aaaabbbccd");
    compress(cad1, cad2);
    cout << "Cadena original: " << cad1 << " Comprimida: " << cad2 << endl;
    
    strcpy(cad1, "ABC!!DE");
    compress(cad1, cad2);
    cout << "Cadena original: " << cad1 << " Comprimida: " << cad2 << endl;
    
    
    strcpy(cad1, "aaaabbbccd");
    compress(cad1, cad2);
    decompress(cad2, cad3);
    cout << "Cadena comprimida: " << cad2 << " Descomprimida: " << cad3 << endl;
    
    cout << "Las cadenas\n" << cad1 << endl << cad3 << endl << "son iguales? " << (sonIguales(cad1, cad3)?"SI":"NO") << endl;
    
    return (0);
}









