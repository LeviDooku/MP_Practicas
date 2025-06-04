/*
NOMBRE Y APELLIDOS: Pedro Velasco Santana
DNI: 45342754w
GRUPO DE PRÁCTICAS: viernes
*/

#include <iostream>
#include "Vector2D.h"
#include "Particula.h"
#include "ConjuntoParticulas.h"
#include "params.h"
#include "Minijuego.h"
#include "raylib.h"
#include <cstdlib> //Para srand
#include <ctime>   //Para time

//Función para pintar una partícula
void PintarParticula(const Particula& p) { 
    Color color; 
    
    // Utilizaremos las coordenadas X e Y y el radio de la Particula
    // para dibujar la forma y el tamaño apropiados.
    float posX = p.getPos().getX();
    float posY = p.getPos().getY();
    float radio = p.getRadio();

    switch(p.getTipo()) { 
        case 1: // Naves (enemigos)
            color = MAROON; // Rojo oscuro (según tu última elección)
            // Dibujar un triángulo apuntando hacia abajo
            DrawTriangle(
                (Vector2){posX, posY - radio},                  // Vértice superior (punta)
                (Vector2){posX - radio, posY + radio},          // Vértice inferior izquierdo
                (Vector2){posX + radio, posY + radio},          // Vértice inferior derecho
                color
            );
            break;
        case 2: // Base (jugador)
            color = DARKGREEN; // Verde oscuro (según tu elección)
            // Dibujar un rectángulo para la base (centrado en la posición de la partícula)
            DrawRectangle(
                posX - radio,   // Esquina superior izquierda X
                posY - radio,   // Esquina superior izquierda Y
                radio * 2,      // Ancho (2 veces el radio para simular un cuadrado si el radio es el lado)
                radio * 2,      // Alto (2 veces el radio)
                color
            );
            break;            
        default: 
            color = GOLD; // Dorado/Amarillo (según tu última elección)
            // Dibujar un pequeño y delgado rectángulo vertical para el proyectil
            DrawRectangle(
                posX - (radio / 2.0f),    // Esquina superior izquierda X (para centrarlo y hacerlo más delgado)
                posY - (radio * 1.5f),    // Esquina superior izquierda Y (para que parezca que sale desde un punto)
                radio,                    // Ancho (el radio de la partícula)
                radio * 3.0f,             // Alto (hacerlo más alto para un efecto de "rayo")
                color
            );
            break;
    } 
} 

int main(void) {
    //Inicializar ventana
    const int screenWidth = MAX_X;
    const int screenHeight = MAX_Y;
    InitWindow(screenWidth, screenHeight, "Prueba Minijuego - Disparos");
    SetTargetFPS(60);
    const float INTRO_DURACION = 5.0; 

    srand(time(NULL)); 

    //Crear instancia del juego
    Minijuego juego(15, 10.0, 10.0); 

    //Bucle principal
    while(!WindowShouldClose()){
        if(IsKeyPressed(KEY_R))
            //Reinicia con 15 naves (valor con el que se inicia el minijuego)
            juego.reiniciar(15);

        int tecla_movimiento_disparo = 0;

        //Solo procesar teclas de juego si no estamos en un estado final de "victoria/derrota"
        if(!juego.terminado()){ 
            if(IsKeyDown(KEY_LEFT)) tecla_movimiento_disparo = KEY_LEFT;
            else if(IsKeyDown(KEY_RIGHT)) tecla_movimiento_disparo = KEY_RIGHT;
            else if(IsKeyDown(KEY_SPACE)) tecla_movimiento_disparo = KEY_SPACE;
        }

        //Se llama al método step
        juego.step(tecla_movimiento_disparo, GetFrameTime());

        BeginDrawing();
        ClearBackground(GRAY);

        //Mostrar contadores
        DrawText(TextFormat("Naves activas: %d", juego.getNaves().getUtiles()), 10, 10, 20, WHITE);
        DrawText(TextFormat("Municion: %d", juego.getNumDisparos()), 10, 30, 20, WHITE);

        //Pintar todos los elementos del juego
        const ConjuntoParticulas& naves = juego.getNaves();
        for(int i = 0; i < naves.getUtiles(); ++i)
            PintarParticula(naves.obtener(i));
        
        const ConjuntoParticulas& disparos = juego.getDisparos();
        for(int i = 0; i < disparos.getUtiles(); ++i)
            PintarParticula(disparos.obtener(i));
        
        PintarParticula(juego.getBase());

        //Mensaje de intro con instrucciones
        if(juego.getEstado() == 0 && GetTime() < INTRO_DURACION){
            DrawText("CONTROLES:", screenWidth/2 - MeasureText("CONTROLES:", 25)/2, screenHeight/2 - 100, 25, YELLOW);
            DrawText("ESC - Salir", screenWidth/2 - MeasureText("ESC - Salir", 20)/2, screenHeight/2 - 60, 20, RAYWHITE);
            DrawText("R - Reiniciar", screenWidth/2 - MeasureText("R - Reiniciar", 20)/2, screenHeight/2 - 30, 20, RAYWHITE);
            DrawText("F. izq / F. dcha - Mover Base", screenWidth/2 - MeasureText("F. izq / F. dcha - Mover Base", 20)/2, screenHeight/2, 20, RAYWHITE);
            DrawText("SPACE - Disparar", screenWidth/2 - MeasureText("SPACE - Disparar", 20)/2, screenHeight/2 + 30, 20, RAYWHITE);
        }
        
        //Mostrar mensaje de victoria/derrota si el juego ha terminado
        if(juego.terminado()){
            const char* mensaje = (juego.getEstado() == 1) ? "VICTORIA!" : "DERROTA!";
            DrawText(mensaje, screenWidth/2 - MeasureText(mensaje, 30)/2, screenHeight/2, 30, YELLOW);
            DrawText("Presiona 'R' para reiniciar", screenWidth/2 - MeasureText("Presiona 'R' para reiniciar", 20)/2, screenHeight/2 + 40, 20, WHITE);
            DrawText("Presiona 'ESC' para salir", screenWidth/2 - MeasureText("Presiona 'ESC' para salir", 20)/2, screenHeight/2 + 65, 20, WHITE); 
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
