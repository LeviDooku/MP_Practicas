/*
NOMBRE Y APELLIDOS: Pedro Velasco Santana
DNI: 45342754w
GRUPO DE PRÁCTICAS: viernes
*/

#include <iostream>
#include "Particula.h"
#include "Vector2D.h"
#include "ConjuntoParticulas.h"

using namespace std;

int main() {
    ConjuntoParticulas parts;
    Particula* centros;
    ConjuntoParticulas* grupos;
    int k = 0; //Número de Partículas en centros
    
    /********************************
     *        LECTURA DE DATOS
     *******************************/

    cin >> parts;

    string cabecera;
    cin >> cabecera;

    if (cabecera != "@Centros:") {
        cerr << "Error: Se esperaba '@Centros:', se encontró: '" << cabecera << "'" << endl;
        return 1;
    }

    cin >> k;

    centros = new Particula[k];
    for(int i = 0; i < k; ++i){
        string etiqueta;
        cin >> etiqueta >> centros[i];
    }

    /********************************
     *        MOSTRAR DATOS LEIDOS
     *******************************/

    cout << "PARTICULAS LEIDAS" << endl;
    cout << parts << endl;
    
    cout << "CENTROS LEIDOS" << endl;
    for(int i = 0; i < k; i++)
        cout << centros[i] << endl;
    
     /********************************************
     *     SE AGREGAN LOS CENTROS A CADA GRUPO
     ********************************************/

    grupos = new ConjuntoParticulas[k];
    for(int i = 0; i < k; i++)
        grupos[i] += centros[i];
    
    
    cout << endl << "ESTADO INICIAL DE LOS GRUPOS" << endl;
    for(int i = 0; i < k; i++){
        cout << "Grupo " << i+1 << endl;
        cout << grupos[i] << endl;   
    }
    
     /********************************************
     *     PROCESAMIENTO DE LOS DATOS
     ********************************************/

    for(int i = 0; i < parts.getUtiles(); ++i){
        Particula p = parts.obtener(i);
        int indice_centro_cercano = 0;
        float distancia_min = p.distancia(centros[0]);

        for(int j = 1; j < k; ++j){
            float dist_actual = p.distancia(centros[j]);
            if(distancia_min > dist_actual){
                distancia_min = dist_actual;
                indice_centro_cercano = j;
            }
        }
        grupos[indice_centro_cercano].agregar(p);
    }

    /********************************
     *     MOSTRAR RESULTADOS
     *******************************/

    cout << "ESTADO FINAL DE LOS GRUPOS" << endl;    
    for(int i = 0; i < k; i++){
        cout << "Grupo " << i+1 << endl;
        cout << grupos[i] << endl;   
    }

    delete [] centros;
    delete [] grupos;

    return 0;
}

