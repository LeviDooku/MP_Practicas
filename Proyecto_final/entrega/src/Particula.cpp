/*
NOMBRE Y APELLIDOS: Pedro Velasco Santana
DNI: 45342754w
GRUPO DE PRÁCTICAS: viernes
*/

#include "Particula.h"
#include "params.h"
#include <iostream>

//Métodos privados

bool Particula::lim_izq(const float epsilon){
    return pos.getX() - epsilon <= 0;
}

bool Particula::lim_dcha(const float epsilon){
    return pos.getX() + epsilon >= MAX_X;
}

bool Particula::lim_arriba(const float epsilon){
    return pos.getY() + epsilon >= MAX_Y;
}

bool Particula::lim_abajo(const float epsilon){
    return pos.getY() - epsilon <= 0;
}

void Particula::corregir_pos(){
    if(lim_izq()) pos.setX(0);
    if(lim_dcha()) pos.setX(MAX_X - radio);
    
    if(lim_abajo()) pos.setY(0);
    if(lim_arriba()) pos.setY(MAX_Y - radio);   
}

void Particula::limitar_velocidad(){
    if(veloc.getX() < -MAX_VEL) veloc.setX(-MAX_VEL);
    if(veloc.getX() > MAX_VEL) veloc.setX(MAX_VEL);

    if(veloc.getY() < -MAX_VEL) veloc.setY(-MAX_VEL);
    if(veloc.getY() > MAX_VEL) veloc.setY(MAX_VEL);
}

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

    limitar_velocidad();

    pos.sumar(veloc);

    corregir_pos();
}

void Particula::rebotar(){
    if(lim_izq(radio) || lim_dcha(radio)){
        veloc.setX(-veloc.getX());
        acel.setX(-acel.getX());
    }
    else if(lim_abajo(radio) || lim_arriba(radio)){
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
    const int epsilon = 1;
    if(lim_izq(radio)) pos.setX(MAX_X - radio - epsilon);
    if(lim_dcha(radio)) pos.setX(radio + epsilon);

    if(lim_abajo(radio)) pos.setY(MAX_Y - radio - epsilon); 
    if(lim_arriba(radio)) pos.setY(radio + epsilon);
}

std::string Particula::toString() const{
    return "{ " + pos.toString() + ", " + veloc.toString() + ", " + acel.toString() + ", " + std::to_string(radio) + ", " + std::to_string(tipo) + " }";
}