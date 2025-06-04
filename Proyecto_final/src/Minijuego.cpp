/*
NOMBRE Y APELLIDOS: Pedro Velasco Santana
DNI: 45342754w
GRUPO DE PRÁCTICAS: viernes
*/

#include "Minijuego.h"
#include "raylib.h"

//Constructor

Minijuego::Minijuego(int numNaves, float radioBase, float radioNave) : estado_juego(0), municion(MUNICION){
    num_naves = (numNaves > 15) ? MAX_NAVES : numNaves;
    radio_base = (radioBase > MAX_R_BASE) ? MAX_R_BASE : radioBase;
    radio_nave = (radioNave > MAX_R_NAVE) ? MAX_R_NAVE : radioNave;

    //Configurar la base
    float baseX = MAX_X / 2.0;
    float baseY = MAX_Y - 20.0;
    Vector2D posBase(baseX, baseY);
    Vector2D velBase(0, 0);
    Vector2D acelBase(0, 0);

    base = Particula(posBase, acelBase, velBase, radio_base, 2);

    disparos = ConjuntoParticulas();
    
    //Crear naves
    inicializarNaves();
}

//Métodos privados

void Minijuego::moverNaves(){
    naves.mover(1); //Mover + rebotar
}

void Minijuego::moverDisparos(){
    disparos.mover(0); //Simplemente mueve partícula
    for(int i = disparos.getUtiles() - 1; i >= 0; --i){
        const Particula &p = disparos.obtener(i);
        //Si la partícula ya salió del eje Y
        if(p.getPos().getY() - p.getRadio() <= 0)
            disparos.borrar(i);
    }
}

void Minijuego::crearDisparo(){
    Vector2D posDisparo = base.getPos(); //Posición de la base, origen de los disparos
    Vector2D velDisparo(0.0, -MAX_VEL);
    Vector2D acelDisparo(0.0, 0.0); //Los disparos tendrán velocidad constante
    float radioDisparo = RADIO_DISPARO;

    Particula nuevoDisparo(posDisparo, acelDisparo, velDisparo, radioDisparo, 0);
    disparos.agregar(nuevoDisparo);
}

bool Minijuego::gestionaColisiones(){
    bool colision_producida = false;
    for(int i = disparos.getUtiles() - 1; i >= 0; --i){
        const Particula& disparo_actual = disparos.obtener(i);

        bool disparo_colisiono_con_nave = false;

        for(int j = naves.getUtiles() - 1; j >= 0 && !disparo_colisiono_con_nave; --j){
            const Particula& nave_actual = naves.obtener(j);
            if(disparo_actual.colision(nave_actual)) {
                disparos.borrar(i);
                naves.borrar(j);

                colision_producida = true;
                disparo_colisiono_con_nave = true;
            }
        }
    }
    return colision_producida;
}

void Minijuego::inicializarNaves(){
    naves = ConjuntoParticulas(getNumNaves());
    float zonaSegura = MAX_Y - base.getRadio() - 100; //Para evitar spawneo de naves muy cerca de base

    for(int i = 0; i < getNumNaves(); ++i){
        Particula nave = naves.obtener(i);

        //Ajustar valores de cada Partícula

        Vector2D pos = nave.getPos();
        float nuevaY = aleatorio(0, zonaSegura);
        pos.setY(nuevaY);
        nave.setPos(pos);

        nave.setAcel(Vector2D(0, 0));
        nave.setVel(Vector2D(nave.getVel().getX(), 0));
        nave.setRadio(getRadioNave());

        naves.reemplazar(nave, i);
    }
}

void Minijuego::moverBase(int tecla){
    float nuevaVel = 0.0;

    if(tecla == KEY_LEFT)
        nuevaVel = -MAX_VEL_BASE;
    else if(tecla == KEY_RIGHT)
        nuevaVel = MAX_VEL_BASE;

    base.setVel(Vector2D(nuevaVel, 0.0));

    //Tener en cuenta los límites
    Vector2D posBase = base.getPos();
    float radioBase = base.getRadio();

    if(posBase.getX() - radioBase < 0){
        base.setPos(Vector2D(radioBase, posBase.getY()));
        base.setVel(Vector2D(0.0, 0.0));
    }else if(posBase.getX() + radioBase > MAX_X){
        base.setPos(Vector2D(MAX_X - radioBase, posBase.getY()));
        base.setVel(Vector2D(0.0, 0.0));
    }
}

//Otros métodos

int Minijuego::step(int tecla, float dt){
    //Mover la base en función de la tecla
    moverBase(tecla); 
    base.mover();   

    //Lógica de disparos
    tiempo_ultimo_disparo += dt; 
    if(tecla == KEY_SPACE && tiempo_ultimo_disparo >= CADENCIA){ //Limitar la velocidad entre disparos
        if(municion > 0 && disparos.getUtiles() < MAX_DISPAROS_SIMUL){ //Si hay munición y no se supera la cantidad máxima simultánea
            crearDisparo();        
            municion--;                 
            tiempo_ultimo_disparo = 0.0f; //Reiniciar
        }
    }

    //Movimiento de las partículas (naves y disparos)
    moverNaves();
    moverDisparos();
    gestionaColisiones();

    //Todas las naves destruidas
    if(naves.getUtiles() == 0) 
        estado_juego = 1; //Gana
    //No hay munición y aún quedan naves
    else if(municion <= 0)
        estado_juego = -1; //Pierde

    return estado_juego; 
}

bool Minijuego::terminado() const{
    return estado_juego != 0;
}

void Minijuego::reiniciar(int num_naves){
    estado_juego = 0;
    num_naves = (num_naves > 15) ? MAX_NAVES : num_naves;

    float baseX = MAX_X / 2.0;
    float baseY = MAX_Y - 20.0;
    Vector2D posBase(baseX, baseY);
    Vector2D velBase(0, 0);
    Vector2D acelBase(0, 0);

    disparos.vaciar();
    municion = MUNICION;
    tiempo_ultimo_disparo = 0.0f;

    //Crear naves
    inicializarNaves();
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

int Minijuego::getNumNaves() const{
    return num_naves;
}

int Minijuego::getNumDisparos() const{
    return municion;
}

float Minijuego::getRadioNave() const{
    return radio_nave;
}

float Minijuego::getRadioBase() const{
    return radio_base;
}