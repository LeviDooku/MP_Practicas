///////////////////////////////////
// Proyecto final                //
// file: ConjuntoParticulas.cpp  //
// Pedro Velasco Santana         //
///////////////////////////////////

#include <iostream>
#include "ConjuntoParticulas.h"
//#include "Particula.h"

ConjuntoParticulas::ConjuntoParticulas(const int n){
    if(n > 0){
        set = new Particula[n];
        capacidad = n;
        utiles = n;

        for(int i = 0; i < n; ++i)
            set[i] = Particula(1);
    }
}

ConjuntoParticulas::ConjuntoParticulas(const ConjuntoParticulas &otro){ // ? No deberían tmb copiarse la cap??
    capacidad = otro.capacidad;
    utiles = otro.utiles;
    set = new Particula[capacidad];

    for(int i = 0; i < capacidad; ++i)
        set[i] = otro.set[i];
}

ConjuntoParticulas::~ConjuntoParticulas(){

}

int ConjuntoParticulas::getUtiles() const{
    return utiles;
}

void ConjuntoParticulas::agrega(const Particula &a_agregar){

}

void ConjuntoParticulas::borrar(const int pos){

}

Particula& ConjuntoParticulas::obtener(const int pos){
    return set[pos]; 
}

void ConjuntoParticulas::reemplazar(const Particula &sustituta, const int pos){

}

void ConjuntoParticulas::mover(int tipo){

}

void ConjuntoParticulas::gestionarColisiones(){

}

std::string ConjuntoParticulas::toString() const{

}