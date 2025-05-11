/*
 * File:   main.cpp
 * Author: David A. Pelta
 *
 */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
#include "Particula.h"
#include "Vector2D.h"
#include "ConjuntoParticulas.h"
#include <cstring>

using namespace std;

const float EPS = 10e-5;
// comprueba si las particulas (en orden) son iguales, usando distancia
/*bool igualesEnPosicion(const ConjuntoParticulas & c1, const ConjuntoParticulas & c2){
	bool rta = c1.getUtiles() == c2.getUtiles();
	
	for(int i = 0; i < c1.getUtiles() && rta; i++){
		rta = (c1.obtener(i)).distancia(c2.obtener(i)) <= EPS;
	}
	
	return rta;
	
}*/

void agregaPart(ConjuntoParticulas & c1, int n){

	for(int i = 0; i < n; i++){
		Particula p(1);
		c1.agregar(p);
	}
}


TEST_CASE("Constructores") {

    SUBCASE("Prueba constructores 1") {
	ConjuntoParticulas c1;
	CHECK(c1.getCapacidad() == c1.getUtiles());
	ConjuntoParticulas c2(10);
	CHECK(c2.getUtiles() == 10);
	CHECK(c2.getCapacidad() >= c2.getUtiles());
    }

    SUBCASE("Prueba constructores 2") {
	ConjuntoParticulas c1(4);
	ConjuntoParticulas c2(c1);
	
    CHECK(c1.getCapacidad() == c2.getCapacidad());
	CHECK(c1.getUtiles() == c2.getUtiles());
	
	
	Particula p1, p2;
	for(int i = 0; i < c1.getUtiles(); i++){
		p1 = c1.obtener(i);
		p2 = c2.obtener(i);
		CHECK(p1.distancia(p2) == 0);
	}
    }
	 
}

TEST_CASE("Pruebas agregar/borrar") {

    SUBCASE("Agregar") {
	ConjuntoParticulas c1;
	Particula p; // se crea al azar
	for(int i = 0; i < TAM_BLOQUE;i++)
		c1.agregar(p);
		
	
	CHECK(c1.getCapacidad() == TAM_BLOQUE);
	CHECK(c1.getUtiles() == TAM_BLOQUE);
	
	// fuerzo redimension
	c1.agregar(p);
	CHECK(c1.getCapacidad() == 2*TAM_BLOQUE);
	CHECK(c1.getUtiles() == TAM_BLOQUE+1);
    }

  SUBCASE("Borrar") {
	const float EPS = 10e-5;
	ConjuntoParticulas c1(6);
	int cap = c1.getCapacidad();
	int util = c1.getUtiles();
	
	c1.borrar(-1);
	c1.borrar(7);
	CHECK(c1.getCapacidad() == cap);
	CHECK(c1.getUtiles() == util);
	
	// guardo la ultima particula
	Particula p = c1.obtener(5);
	c1.borrar(0);
	// ahora en la pos 0 debería estar p
	CHECK(p.distancia(c1.obtener(0)) < EPS);
	
	// fuerzo redimension
	for(int i = 0; i < TAM_BLOQUE; i++)
		c1.borrar(0);	
	
	CHECK(c1.getCapacidad() == cap - TAM_BLOQUE);
	CHECK(c1.getUtiles() == (util - TAM_BLOQUE - 1));
    }
       
  SUBCASE("combinados"){
	  ConjuntoParticulas origen(7);
	  ConjuntoParticulas otro = origen;
	  for(int i = 0; i < 10; i++){
		  Particula p;
		  otro.agregar(p);
	  }
	  
	  CHECK(otro.getUtiles() == 17);
	  int aux = otro.getUtiles() - 1;
	  
	  for(int i = 0; i < 10; i++)
		  otro.borrar(7);
	  
	  // otro y origen deberian ser iguales
	  CHECK(otro.getUtiles() == origen.getUtiles());
	  // la distancia entre las particulas debería ser cero
	  // todavia no hemos implementado == entre particulas
	
	
	CHECK(igualesEnPosicion(origen,otro) == true);
	  
  }
}


TEST_CASE("Varios") {
	const int N = 10;
	ConjuntoParticulas *v = new ConjuntoParticulas[N];

	for(int i = 0; i < N; i++)
		agregaPart(v[i],i);

	for(int i = 0; i < N; i++){
		CHECK(v[i].getUtiles() == i);
	}

	for(int i = 0; i < N-1; i++){
		CHECK(v[i].getCapacidad() <= v[i+1].getCapacidad());
	}

	delete [] v;
}