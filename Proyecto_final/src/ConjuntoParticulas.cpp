///////////////////////////////////
// Proyecto final                //
// file: ConjuntoParticulas.cpp  //
// Pedro Velasco Santana         //
///////////////////////////////////

#include <iostream>
#include <sstream>
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
    if(pos >= 0 && pos < utiles)
        return set[pos]; 
}

void ConjuntoParticulas::reemplazar(const Particula &sustituta, const int pos){
    if(pos >= 0 && pos < utiles)
        set[pos] = sustituta;
}

void ConjuntoParticulas::mover(int tipo){
    switch(tipo){
        default:
        case 0:
            for(int i = 0; i < utiles; ++i)
                set[i].mover();
            break;
        case 1:
            for(int i = 0; i < utiles; ++i){
                set[i].mover();
                set[i].rebotar();
            }
            break;
        case 2:
            for(int i = 0; i < utiles; ++i){
                set[i].mover();
                set[i].wrap();
            }
            break;
    }
}

void ConjuntoParticulas::gestionarColisiones(){
    for(int i = 0; i < utiles; ++i){
        for(int j = i + 1; j < utiles; ++j){
            if(set[i].colision(set[j]))
                set[i].choque(set[j]);
        }
    }

}

// ! NO SÉ Si ESTÁ BIEN; PREGUNTAR PROFE
std::string ConjuntoParticulas::toString() const{
    std::ostringstream oss;

    oss << "Capacidad: " << capacidad << "\n";
    oss << "Número de partículas: " << utiles << "\n";

    for (int i = 0; i < utiles; ++i)
        oss << set[i].toString() << "\n";

    return oss.str();
}