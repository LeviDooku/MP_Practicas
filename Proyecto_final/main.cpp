////////////////////////////////
// Proyecto final             //
// file: main.cpp             //
// Pedro Velasco Santana      //
////////////////////////////////

#include <iostream>
#include "Vector2D.h"
#include "Particula.h"

using namespace std;

// === Funciones de prueba ===

// Prueba de toString()
void testToString(){
    cout << "\n=== Prueba toString() ===" << endl;
    Vector2D v(3, 4);
    cout << "Vector: " << v.toString() << endl;
    cout << "=== Fin prueba toString ===\n" << endl;
}

// Prueba de modulo()
void testModulo(){
    cout << "\n=== Prueba modulo() ===" << endl;
    Vector2D v(3, 4);
    cout << "Modulo: " << v.modulo() << endl; // Debería ser 5
    cout << "=== Fin prueba modulo ===\n" << endl;
}

// Prueba de normalizar()
void testNormalizar(){
    cout << "\n=== Prueba normalizar() ===" << endl;
    Vector2D v(3, 4);
    cout << "Antes de normalizar: " << v.toString() << endl;
    v.normalizar();
    cout << "Después de normalizar: " << v.toString() << endl;
    cout << "Modulo tras normalizar: " << v.modulo() << endl; // Debería ser aproximadamente 1
    cout << "=== Fin prueba normalizar ===\n" << endl;
}

// Prueba de sumar()
void testSumar(){
    cout << "\n=== Prueba sumar() ===" << endl;
    Vector2D v1(1, 2);
    Vector2D v2(3, 4);
    cout << "v1 antes de sumar: " << v1.toString() << endl;
    v1.sumar(v2);
    cout << "v1 después de sumar v2: " << v1.toString() << endl;
    cout << "=== Fin prueba sumar ===\n" << endl;
}

// Prueba de escalar()
void testEscalar(){
    cout << "\n=== Prueba escalar() ===" << endl;
    Vector2D v(1, 2);
    cout << "Antes de escalar: " << v.toString() << endl;
    v.escalar(2);
    cout << "Después de escalar por 2: " << v.toString() << endl;
    cout << "=== Fin prueba escalar ===\n" << endl;
}

// Prueba de distancia()
void testDistancia(){
    cout << "\n=== Prueba distancia() ===" << endl;
    Vector2D v1(1, 2);
    Vector2D v2(4, 6);
    cout << "Distancia entre v1 y v2: " << v1.distancia(v2) << endl;
    cout << "=== Fin prueba distancia ===\n" << endl;
}

// Prueba general de todo
void testCompleto(){
    cout << "\n=== Prueba completa ===" << endl;
    Vector2D v1(3, 4);
    Vector2D v2(1, 2);
    cout << "v1 inicial: " << v1.toString() << endl;
    cout << "v2 inicial: " << v2.toString() << endl;

    cout << "- Módulo de v1: " << v1.modulo() << endl;
    v1.normalizar();
    cout << "- v1 normalizado: " << v1.toString() << endl;
    v2.sumar(v1);
    cout << "- v2 tras sumar v1: " << v2.toString() << endl;
    v2.escalar(2);
    cout << "- v2 tras escalar: " << v2.toString() << endl;
    cout << "- Distancia entre v1 y v2: " << v1.distancia(v2) << endl;
    cout << "=== Fin prueba completa ===\n" << endl;
}

int main(){
    cout << "=== Inicio de pruebas de la clase Vector2D ===\n" << endl;

    testToString();
    testModulo();
    testNormalizar();
    testSumar();
    testEscalar();
    testDistancia();
    testCompleto();

    cout << "\n=== Fin de todas las pruebas ===" << endl;
    return 0;
}

