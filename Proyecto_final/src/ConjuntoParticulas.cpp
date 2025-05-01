///////////////////////////////////
// Proyecto final                //
// file: ConjuntoParticulas.cpp  //
// Pedro Velasco Santana         //
///////////////////////////////////

#include <iostream>
#include "ConjuntoParticulas.h"

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
    delete [] set;
    set = nullptr;
}

int ConjuntoParticulas::getUtiles() const{
    return utiles;
}

void ConjuntoParticulas::redimensiona(const int new_cap){
    Particula *set_amplido = new Particula[new_cap];

    for(int i = 0; i < utiles; ++i)
        set_amplido[i] = set[i];

    delete [] set;
    set = set_amplido;
    capacidad = new_cap;
}

void ConjuntoParticulas::agrega(const Particula &a_agregar){
    if(capacidad == utiles){
        redimensiona(capacidad + TAM_BLOQUE);
    }
    set[utiles++] = a_agregar;        
}

void ConjuntoParticulas::borrar(const int pos){
    if(pos >= 0 && pos < utiles){
        set[pos] = set[--utiles];
        if((capacidad - utiles) > TAM_BLOQUE)
            redimensiona(utiles);
    }
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