////////////////////////////////
// Proyecto final             //
// file: Particula.cpp        //
// Pedro Velasco Santana      //
////////////////////////////////

#include "Particula.h"
#include "params.h"

//Constructores

Particula::Particula(const int tipoPart){
    if(tipoPart != 0){
        radio = 3;
        tipo = tipoPart;
    }
    else{
        pos.setXY(aleatorio(0, MAX_X), aleatorio(0, MAX_Y));
        acel.setXY(aleatorio(-MAX_ACC, MAX_ACC), aleatorio(-MAX_ACC, MAX_ACC));
        veloc.setXY(aleatorio(-MAX_VEL, MAX_VEL), aleatorio(-MAX_VEL, MAX_VEL));
        radio = aleatorio(MIN_R, MAX_R);
        tipo = tipoPart;
    }
}

Particula::Particula(const Vector2D &pos, const Vector2D &acel, const Vector2D &vel, const float radio, const int tipo)
: pos(pos.getX(), pos.getY()), 
  acel(acel.getX(), acel.getY()),
  veloc(vel.getX(), vel.getY()),
  radio(radio),
  tipo(tipo)
{}

//Métodos set y get

void Particula::setPos(const Vector2D &new_pos){
    pos.setXY(new_pos.getX(), new_pos.getY());
}

void Particula::setAcel(const Vector2D &new_acel){
    acel.setXY(new_acel.getX(), new_acel.getY());
}

void Particula::setVel(const Vector2D &new_vel){
    veloc.setXY(new_vel.getX(), new_vel.getY());
}

void Particula::setRadio(const float new_radio){
    radio = new_radio;
}

Vector2D Particula::getPos() const{
    return pos;
}

Vector2D Particula::getAcel() const{
    return acel;
}

Vector2D Particula::getVel() const{
    return veloc;
}

float Particula::getRadio() const{
    return radio;
}

//Otros