////////////////////////////////
// Proyecto final             //
// file: main.cpp             //
// Pedro Velasco Santana      //
////////////////////////////////

#include <iostream>
#include "Vector2D.h"
#include "Particula.h"
#include "ConjuntoParticula.h"
#include "params.h"

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

// === Funciones de prueba ===

// Prueba de toString()
void testToString_P() {
    cout << "\n=== Prueba toString() ===" << endl;
    Particula p;
    cout << "Particula creada: " << p.toString() << endl;
    cout << "=== Fin prueba toString ===\n" << endl;
}

// Prueba de mover()
void testMover() {
    cout << "\n=== Prueba mover() ===" << endl;
    Particula p(Vector2D(1, 1), Vector2D(0.5, 0.5), Vector2D(2, 2), 1, 0);
    cout << "Antes de mover: " << p.toString() << endl;
    p.mover();
    cout << "Después de mover: " << p.toString() << endl;
    cout << "=== Fin prueba mover ===\n" << endl;
}

// Prueba de rebotar()
void testRebotar() {
    cout << "\n=== Prueba rebotar() ===" << endl;
    Particula p(Vector2D(MAX_X, MAX_Y), Vector2D(0, 0), Vector2D(5, 5), 1, 0);
    cout << "Antes de rebotar: " << p.toString() << endl;
    p.rebotar();
    cout << "Después de rebotar: " << p.toString() << endl;
    cout << "=== Fin prueba rebotar ===\n" << endl;
}

// Prueba de colision()
void testColision() {
    cout << "\n=== Prueba colision() ===" << endl;
    Particula p1(Vector2D(5, 5), Vector2D(0, 0), Vector2D(0, 0), 2, 0);
    Particula p2(Vector2D(6, 5), Vector2D(0, 0), Vector2D(0, 0), 2, 0);

    cout << "Partícula 1: " << p1.toString() << endl;
    cout << "Partícula 2: " << p2.toString() << endl;

    if (p1.colision(p2))
        cout << "-> Colisionan!" << endl;
    else
        cout << "-> No colisionan." << endl;
        
    cout << "=== Fin prueba colision ===\n" << endl;
}

// Prueba de choque()
void testChoque() {
    cout << "\n=== Prueba choque() ===" << endl;
    Particula p1(Vector2D(2, 2), Vector2D(0.1, 0.1), Vector2D(1, 1), 1, 0);
    Particula p2(Vector2D(5, 5), Vector2D(-0.2, -0.2), Vector2D(-1, -1), 1, 0);

    cout << "Antes del choque:" << endl;
    cout << "p1: " << p1.toString() << endl;
    cout << "p2: " << p2.toString() << endl;

    p1.choque(p2);

    cout << "Después del choque:" << endl;
    cout << "p1: " << p1.toString() << endl;
    cout << "p2: " << p2.toString() << endl;

    cout << "=== Fin prueba choque ===\n" << endl;
}

// Prueba general
void testCompleto_P() {
    cout << "\n=== Prueba completa ===" << endl;
    Particula p(Vector2D(1, 1), Vector2D(0.5, 0.5), Vector2D(2, 2), 1, 0);
    cout << "Estado inicial: " << p.toString() << endl;

    p.mover();
    cout << "Tras mover: " << p.toString() << endl;

    p.rebotar();
    cout << "Tras rebotar: " << p.toString() << endl;
    
    cout << "=== Fin prueba completa ===\n" << endl;
}

// Prueba de toString()
void testToString_C() {
    cout << "\n=== Prueba toString() ===" << endl;
    ConjuntoParticulas c(3);
    cout << c.toString();
    cout << "=== Fin prueba toString ===\n" << endl;
}

// Prueba de agregar()
void testAgregar() {
    cout << "\n=== Prueba agregar() ===" << endl;
    ConjuntoParticulas c;
    Particula p;
    c.agregar(p);
    c.agregar(p);
    c.agregar(p);
    c.agregar(p); // debería forzar una redimensión
    cout << c.toString();
    cout << "=== Fin prueba agrega ===\n" << endl;
}

// Prueba de borrar()
void testBorrar() {
    cout << "\n=== Prueba borrar() ===" << endl;
    ConjuntoParticulas c(4);
    cout << "Antes de borrar:\n" << c.toString();
    c.borrar(1);
    cout << "Después de borrar la posición 1:\n" << c.toString();
    cout << "=== Fin prueba borrar ===\n" << endl;
}

// Prueba de obtener()
void testObtener() {
    cout << "\n=== Prueba obtener() ===" << endl;
    ConjuntoParticulas c(1);
    Particula &p = c.obtener(0);
    cout << "Partícula obtenida: " << p.toString() << endl;
    cout << "=== Fin prueba obtener ===\n" << endl;
}

// Prueba de reemplazar()
void testReemplazar() {
    cout << "\n=== Prueba reemplazar() ===" << endl;
    ConjuntoParticulas c(2);
    Particula nueva(Vector2D(9, 9), Vector2D(0, 0), Vector2D(0, 0), 3, 1);
    cout << "Antes de reemplazar:\n" << c.toString();
    c.reemplazar(nueva, 0);
    cout << "Después de reemplazar la posición 0:\n" << c.toString();
    cout << "=== Fin prueba reemplazar ===\n" << endl;
}

// Prueba de mover()
void testMoverConjunto() {
    cout << "\n=== Prueba mover() con tipo 2 (wrap) ===" << endl;
    ConjuntoParticulas c(3);
    cout << "Antes de mover:\n" << c.toString();
    c.mover(2);
    cout << "Después de mover:\n" << c.toString();
    cout << "=== Fin prueba mover ===\n" << endl;
}

// Prueba de gestionarColisiones()
void testGestionarColisiones() {
    cout << "\n=== Prueba gestionarColisiones() ===" << endl;
    ConjuntoParticulas c;
    // Crear dos partículas que colisionan
    Particula p1(Vector2D(5, 5), Vector2D(0, 0), Vector2D(1, 1), 2, 0);
    Particula p2(Vector2D(6, 5), Vector2D(0, 0), Vector2D(-1, -1), 2, 0);
    c.agregar(p1);
    c.agregar(p2);
    cout << "Antes de gestionar colisiones:\n" << c.toString();
    c.gestionarColisiones();
    cout << "Después de gestionar colisiones:\n" << c.toString();
    cout << "=== Fin prueba gestionarColisiones ===\n" << endl;
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

    cout << "=== Inicio de pruebas de la clase Particula ===\n" << endl;

    testToString_P();
    testMover();
    testRebotar();
    testColision();
    testChoque();
    testCompleto_P();

    cout << "\n=== Fin de todas las pruebas ===" << endl;

    cout << "=== Inicio de pruebas de la clase ConjuntoParticulas ===\n" << endl;

    testToString_C();
    testAgregar();
    testBorrar();
    testObtener();
    testReemplazar();
    testMoverConjunto();
    testGestionarColisiones();

    cout << "\n=== Fin de todas las pruebas ===" << endl;

    return 0;
}

