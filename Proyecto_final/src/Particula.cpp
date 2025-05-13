/*
NOMBRE Y APELLIDOS: Pedro Velasco Santana
DNI: 45342754w
GRUPO DE PRÁCTICAS: viernes
*/

#include "Particula.h"
#include "params.h"
#include <iostream>

//Constructores

Particula::Particula(const int tipoPart){
    if(tipoPart == 0){
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

//Otros métodos

void Particula::mover(){
    veloc.sumar(acel);

    if(veloc.getX() < -MAX_VEL) veloc.setX(-MAX_VEL);
    if(veloc.getX() > MAX_VEL) veloc.setX(MAX_VEL);

    if(veloc.getY() < -MAX_VEL) veloc.setY(-MAX_VEL);
    if(veloc.getY() > MAX_VEL) veloc.setY(MAX_VEL);

    pos.sumar(veloc);

    if(pos.getX() < 0) pos.setX(0);
    if(pos.getX() > MAX_X) pos.setX(MAX_X - radio);
    
    if(pos.getY() < 0) pos.setY(0);
    if(pos.getY() > MAX_Y) pos.setY(MAX_Y - radio);
}

void Particula::rebotar(){
    if(pos.getX() + radio >= MAX_X || pos.getX() - radio <= 0){
        veloc.setX(-veloc.getX());
        acel.setX(-acel.getX());
    }
    else if(pos.getY() + radio >= MAX_Y || pos.getY() - radio <= 0){
        veloc.setY(-veloc.getY());
        acel.setY(-acel.getY());
    }
}

bool Particula::colision(const Particula &otra) const{
    return pos.distancia(otra.getPos()) <= radio + otra.getRadio();
}

void Particula::choque(Particula &otra){
    Vector2D aux_vel = getVel();
    Vector2D aux_acel = getAcel();

    setVel(otra.getVel());
    setAcel(otra.getAcel());

    otra.setVel(aux_vel);
    otra.setAcel(aux_acel);
}

void Particula::wrap(){
    if(pos.getX() - radio <= 0) pos.setX(MAX_X - radio - 1);
    if(pos.getX() + radio >= MAX_X) pos.setX(radio + 1);

    if(pos.getY() - radio <= 0) pos.setY(MAX_Y - radio - 1); 
    if(pos.getY() + radio >= MAX_Y) pos.setY(radio + 1);
}

std::string Particula::toString() const{
    return "{ " + pos.toString() + ", " + veloc.toString() + ", " + acel.toString() + ", " + std::to_string(radio) + ", " + std::to_string(tipo) + " }";
}