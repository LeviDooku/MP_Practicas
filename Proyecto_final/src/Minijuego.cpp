/*
NOMBRE Y APELLIDOS: Pedro Velasco Santana
DNI: 45342754w
GRUPO DE PRÁCTICAS: viernes
*/

#include "Minijuego.h"

Minijuego::Minijuego(int numNaves, float radioBase, float radioNave, int vidas) : estado_juego(0){
    num_vidas = (vidas > MAX_VIDAS) ? MAX_VIDAS : vidas;
    numNaves = (numNaves > 15) ? MAX_NAVES : numNaves;  

    //Configurar la base
    float baseX = MAX_X / 2.0;
    float baseY = MAX_Y - 20.0;
    Vector2D posBase(baseX, baseY);
    Vector2D velBase(0, 0);
    Vector2D acelBase(0, 0);

    base = Particula(posBase, acelBase, velBase, radioBase, 2);

    disparos = ConjuntoParticulas();
    
    //Crear naves
    naves = ConjuntoParticulas(numNaves);
    float zonaSegura = MAX_Y - radioBase - 100; //Para evitar spawneo de naves muy cerca de base

    for(int i = 0; i < numNaves; ++i){
        Particula nave = naves.obtener(i);

        //Ajustar valores de cada Partícula

        Vector2D pos = nave.getPos();
        float nuevaY = aleatorio(0, zonaSegura);
        pos.setY(nuevaY);
        nave.setPos(pos);

        nave.setAcel(Vector2D(0, 0));
        nave.setVel(Vector2D(nave.getVel().getX(), 0));
        nave.setRadio(radioNave);

        naves.reemplazar(nave, i);
    }
}

int Minijuego::step(int tecla){
    return 1;
}

bool Minijuego::terminado() const{
    return estado_juego != 0;
}

//Get

int Minijuego::getEstado() const{
    return estado_juego;
}

const ConjuntoParticulas& Minijuego::getNaves() const{
    return naves;
}

const ConjuntoParticulas& Minijuego::getDisparos() const{
    return disparos;
}

const Particula& Minijuego::getBase() const{
    return base;
}
