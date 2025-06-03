////////////////////////////////
// Proyecto final             //
// file: main.cpp             //
// Pedro Velasco Santana      //
////////////////////////////////

#include <iostream>
#include "Vector2D.h"
#include "Particula.h"
#include "ConjuntoParticulas.h"
#include "params.h"
#include "Minijuego.h"
#include "raylib.h"

using namespace std;

// ! HECHO POR IA CUIDAOOOOOOO

// Función para pintar una partícula
void PintarParticula(const Particula& p) {
    Color color;
    switch(p.getTipo()) {
        case 1: color = RED; break;    // Naves (rojo)
        case 2: color = BLUE; break;   // Base (azul)
        default: color = GREEN; break; // Disparos (verde)
    }
    DrawCircle(p.getPos().getX(), p.getPos().getY(), p.getRadio(), color);
}

int main(void) {
    // Inicializar ventana
    const int screenWidth = MAX_X;
    const int screenHeight = MAX_Y;
    InitWindow(screenWidth, screenHeight, "Prueba Minijuego - Disparos");
    SetTargetFPS(60);

    // Crear instancia del juego
    Minijuego juego(100, 10.0, 8.0, 30); //PARA PROBAR CONSTRUCTOR

    // Bucle principal
    while (!WindowShouldClose()) {
        // Procesar entrada
        int tecla = 0;
        if (IsKeyDown(KEY_LEFT)) tecla = KEY_LEFT;
        else if (IsKeyDown(KEY_RIGHT)) tecla = KEY_RIGHT;
        else if (IsKeyDown(KEY_SPACE)) tecla = KEY_SPACE;

        // Actualizar estado del juego
        //juego.step(tecla);
        juego.step_debug(GetFrameTime());

        // Renderizado
        BeginDrawing();
        ClearBackground(BLACK);
        printf("Limpiando fondo\n");
        DrawText(TextFormat("Disparos: %d", juego.getNumDisparos()), 10, 30, 20, WHITE);
        
        // Pintar todos los elementos del juego
        const ConjuntoParticulas& naves = juego.getNaves();
        for (int i = 0; i < naves.getUtiles(); ++i) {
            PintarParticula(naves.obtener(i));
        }
        
        const ConjuntoParticulas& disparos = juego.getDisparos();
        for (int i = 0; i < disparos.getUtiles(); ++i) {
            PintarParticula(disparos.obtener(i));
        }
        
        PintarParticula(juego.getBase());
        
        // Mostrar información del juego
        DrawText(TextFormat("Naves: %d", juego.getNaves().getUtiles()), 10, 10, 20, WHITE);
        if (juego.terminado()) {
            const char* mensaje = (juego.getEstado() == 1) ? "VICTORIA!" : "DERROTA!";
            DrawText(mensaje, screenWidth/2 - 50, screenHeight/2, 30, YELLOW);
        }
        
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
