
#include "raylib.h"
#include "Particula.h"
#include "ConjuntoParticulas.h"
#include "params.h"
#include <iostream>

const int screenWidth = MAX_X;
const int screenHeight = MAX_Y;

using namespace std;

void pintarParticula(const Particula & p, Color c) {
    DrawCircle(p.getPos().getX(), p.getPos().getY(), p.getRadio(), c);
}

const int N_COLOR = 6;
const Color c[N_COLOR] = {RED, BLUE, BLACK, GREEN, YELLOW, MAGENTA};
int main(int argc, char* argv[]) {
    // activación de ventana gráfica
    //---------------------------------------------------------
    int N, modo;
    if (argc < 3){
        cout << "USO: testV <nro particulas> <modo>, donde modo = 1 (rebotar), modo=2 (wrap)" << endl;
        exit(-1);
    }
    else{
        N = atoi(argv[1]);
        modo = atoi(argv[2]);
    }

    InitWindow(screenWidth, screenHeight, "Minijuego");
    int tiempo = 0;
   
    // creación de objetos
    //---------------------------------------------------------
    ConjuntoParticulas nube(N);

    // el agujero negro
    Particula atractor(1);
    Vector2D pos(screenWidth/2.0, screenHeight/2.0);
    atractor.setPos(pos);
    atractor.setRadio(35.0);
    
    
    
    SetTargetFPS(30); // velocidad de la simulación
    //----------------------------------------------------------
    // bucle principal
    //---------------------------------------------------------
    bool fin = false;
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {   nube.mover(modo);
        nube.gestionarColisiones();
        N = nube.getUtiles();
        for(int i = N-1; i >= 0; i-- ){
            if (atractor.colision(nube.obtener(i)))
                nube.borrar(i);
        }
        tiempo++;
        
        //-----------------------------------------------------
        // pintar los objetos
        //-----------------------------------------------------

        BeginDrawing();

         ClearBackground(RAYWHITE);
         N = nube.getUtiles();
         if (N > 0 && !fin){
             for(int i = 0; i < N; i++)
               pintarParticula(nube.obtener(i), c[i%N_COLOR]);
             
             pintarParticula(atractor, BLACK);
             
             string s = "particulas-> " + to_string(N) + " Cap:" + to_string(nube.getCapacidad());
             DrawText("ESC para salir", 10, 10, 20, BLACK);
             DrawText(s.c_str(), 10, 40, 20, BLACK);
             }
         else{
             fin = true;
             DrawText("ESC para salir", 10, 10, 20, BLACK);
             string s = "FIN DE LA EJECUCION";
             DrawText(s.c_str(), 300, 300, 40, BLACK);
         }
             
        
        EndDrawing();
        //-----------------------------------------------------
    }

    // cerrar ventana
    //---------------------------------------------------------
    CloseWindow(); 
    //----------------------------------------------------------

    return 0;
}
