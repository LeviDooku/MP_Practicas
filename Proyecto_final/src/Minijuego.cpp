/*
NOMBRE Y APELLIDOS: Pedro Velasco Santana
DNI: 45342754w
GRUPO DE PRÁCTICAS: viernes
*/

#include "Minijuego.h"

//Constructor

Minijuego::Minijuego(int numNaves, float radioBase, float radioNave, int vidas) : estado_juego(0), tiempoUltimoDisparo(0.0), modoGeneracionDisparosActivo(true), disparosGeneradosDebug(0){
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
    bool colision_producida = false; // Bandera para saber si hubo alguna colisión

    // Iteramos sobre todos los disparos (desde el final hacia el principio)
    for (int i = disparos.getUtiles() - 1; i >= 0; --i) {
        // Obtenemos el disparo actual
        const Particula& disparo_actual = disparos.obtener(i);

        // Iteramos sobre todas las naves (desde el final hacia el principio)
        // Para evitar 'break', usaremos una bandera local.
        bool disparo_colisiono_con_nave = false; // Bandera para el bucle interno

        for (int j = naves.getUtiles() - 1; j >= 0 && !disparo_colisiono_con_nave; --j) {
            const Particula& nave_actual = naves.obtener(j);

            // Usamos el método colision de la clase Particula
            if (disparo_actual.colision(nave_actual)) {
                // ¡COLISIÓN DETECTADA!

                // 1. Eliminar el disparo
                disparos.borrar(i);

                // 2. Eliminar la nave
                naves.borrar(j);

                colision_producida = true;         // Marcamos que hubo una colisión general
                disparo_colisiono_con_nave = true; // Marcamos que este disparo ya colisionó
                                                   // Esto hará que el bucle interno (de naves) termine
                                                   // en la siguiente iteración para este disparo.
            }
        }
    }

    return colision_producida;
}

//Otros métodos

int Minijuego::step(int tecla){
    moverNaves();
    
    return estado_juego;
}

////////////////////////////////////////////////////

int Minijuego::step_debug(float dt){
    moverNaves();
    moverDisparos();

    // Lógica para disparar automáticamente basada en el tiempo
    tiempoUltimoDisparo += dt;
    const float CADENCIA_DISPARO_DEBUG = 0.1f; // Más rápido para generar un buen volumen de prueba
    const int MAX_DISPAROS_GENERADOS_DEBUG = 50; // Limite de disparos a generar para la prueba

    // Solo genera disparos si estamos en modo de generación activa y no hemos alcanzado el límite
    if (modoGeneracionDisparosActivo && disparosGeneradosDebug < MAX_DISPAROS_GENERADOS_DEBUG) {
        if (tiempoUltimoDisparo >= CADENCIA_DISPARO_DEBUG) {
            crearDisparo();
            tiempoUltimoDisparo = 0.0f; 
            disparosGeneradosDebug++; // Incrementa el contador de disparos generados para depuración
            gestionaColisiones();
        }
    } else if (modoGeneracionDisparosActivo && disparosGeneradosDebug >= MAX_DISPAROS_GENERADOS_DEBUG) {
        // Una vez alcanzado el límite, desactiva la generación
        modoGeneracionDisparosActivo = false;
        // Opcional: Puedes imprimir un mensaje para saber cuándo se detiene la generación
        // std::cout << "DEBUG: Generación de disparos detenida. Total generados: " << disparosGeneradosDebug << std::endl;
    }


    return estado_juego;
}

////////////////////////////////////////////////////

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

int Minijuego::getNumNaves() const{
    return naves.getUtiles();
}

int Minijuego::getNumDisparos() const{
    return disparos.getUtiles();
}

