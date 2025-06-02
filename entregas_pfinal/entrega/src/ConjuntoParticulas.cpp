/*
NOMBRE Y APELLIDOS: Pedro Velasco Santana
DNI: 45342754w
GRUPO DE PRÁCTICAS: viernes
*/

#include "ConjuntoParticulas.h"

ConjuntoParticulas::ConjuntoParticulas(int n){
    if(n > 0){
        set = new Particula[n];
        capacidad = n;
        utiles = n;

        for(int i = 0; i < n; ++i)
            set[i] = Particula(1);
    }
}

ConjuntoParticulas::ConjuntoParticulas(const ConjuntoParticulas &otro){
    capacidad = otro.capacidad;
    utiles = otro.utiles;
    set = new Particula[capacidad];

    for(int i = 0; i < capacidad; ++i)
        set[i] = otro.set[i];
}

ConjuntoParticulas::~ConjuntoParticulas(){
    libera();
}

int ConjuntoParticulas::getUtiles() const{
    return utiles;
}

int ConjuntoParticulas::getCapacidad() const{
    return capacidad;
}

void ConjuntoParticulas::redimensiona(const int new_cap){
    Particula *set_amplido = new Particula[new_cap];

    for(int i = 0; i < utiles; ++i)
        set_amplido[i] = set[i];

    delete [] set;
    set = set_amplido;
    capacidad = new_cap;
}

void ConjuntoParticulas::libera(){
    delete [] set;
    set = nullptr;
    capacidad = 0;
    utiles = 0;
}

void ConjuntoParticulas::agregar(const Particula &a_agregar){
    if(capacidad == utiles)
        redimensiona(capacidad + TAM_BLOQUE);
    set[utiles++] = a_agregar;        
}

void ConjuntoParticulas::borrar(int pos){
    if(pos >= 0 && pos < utiles){
        set[pos] = set[--utiles];
        if((capacidad - utiles) >= TAM_BLOQUE)
            redimensiona(utiles);
    }
}

const Particula& ConjuntoParticulas::obtener(int pos) const{
    assert(pos >= 0 && pos < utiles && "Índice fuera de rango en obtener()");
    return set[pos];
}

void ConjuntoParticulas::reemplazar(const Particula &sustituta, int pos){
    if(pos >= 0 && pos < utiles)
        set[pos] = sustituta;
}

void ConjuntoParticulas::mover(int tipo){
    for(int i = 0; i < utiles; ++i){
        if(tipo == 0 || tipo != 1 || tipo != 2)
            set[i].mover();
        else if(tipo == 1){
            set[i].mover();
            set[i].rebotar();
        }
        else if(tipo == 2){
            set[i].mover();
            set[i].wrap();
        }

    }
}

void ConjuntoParticulas::gestionarColisiones(){
    for(int i = 0; i < utiles; ++i){
        bool colisionan = false;
        for(int j = i + 1; j < utiles && !colisionan; ++j){
            if(set[i].colision(set[j])){
                set[i].choque(set[j]);
                colisionan = true;
            }
        }
    }
}

std::string ConjuntoParticulas::toString() const{
    std::string result = "";

    result += "Capacidad: " + std::to_string(capacidad) + "\n";
    result += "Número de partículas: " + std::to_string(utiles) + "\n";

    for (int i = 0; i < utiles; ++i) {
        result += set[i].toString() + "\n";
    }
    
    return result;
}

//Sobrecarga de operadores

ConjuntoParticulas& ConjuntoParticulas::operator=(const ConjuntoParticulas &otro){
    if(this != &otro){
        delete [] set;

        capacidad = otro.getCapacidad();
        utiles = otro.getUtiles();
        set = new Particula[capacidad];

        for(int i = 0; i < utiles; ++i)
            set[i] = otro.set[i];
    }

    return *this;
}

ConjuntoParticulas& ConjuntoParticulas::operator+=(const Particula &p){
    agregar(p);
    return *this;
}

ConjuntoParticulas& ConjuntoParticulas::operator+=(const ConjuntoParticulas &cp){
    for(int i = 0; i < cp.getUtiles(); ++i)
        agregar(cp.obtener(i));
    
    return *this;
}

bool ConjuntoParticulas::operator==(const ConjuntoParticulas &cp) const{
    bool iguales = utiles == cp.getUtiles();

    if(iguales){
        bool *p_usadas = new bool[utiles];
        for(int i = 0; i < utiles; ++i)
            p_usadas[i] = false; 
        
        for(int i = 0; i < utiles; ++i){
            bool encontrado = false;
            for(int j = 0; j < utiles && !encontrado; ++j){
                if(!p_usadas[j] && obtener(i) == cp.obtener(j)){
                    p_usadas[j] = true;
                    encontrado = true;
                }
            }
            if(!encontrado){
                iguales = false;
            }
        }
        delete [] p_usadas;
    }
    return iguales;
}

std::ostream& operator<<(std::ostream &flujo, const ConjuntoParticulas &cp){
    flujo << "@Particula: " << cp.getUtiles() << '\n';

    for(int i = 0; i < cp.getUtiles(); ++i)
        flujo << "p" << (i + 1) << ": " <<  cp.obtener(i) << "\n";
    
    return flujo;
}

std::istream& operator>>(std::istream &flujo, ConjuntoParticulas &cp){
    std::string cabecera;
    int numParticulas; 

    flujo >> cabecera >> numParticulas;

    while(cp.getUtiles() > 0)
        cp.borrar(0);

    for(int i = 0; i < numParticulas; ++i){
        std::string etiqueta;
        flujo >> etiqueta;
        
        Particula p;
        flujo >> p;

        cp.agregar(p);
    }

    return flujo;
}

