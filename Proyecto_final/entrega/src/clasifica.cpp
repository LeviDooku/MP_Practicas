/* 
 * File:   clasifica.cpp
 * Author: David Pelta
 *
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
    
    
    /********************************
     *        LECTURA DE DATOS
     *******************************/

    // ..........................

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

    for(int i = 0; i < k; i++)
        grupos[i] += centros[i];
    
    
    cout << "ESTADO INICIAL DE LOS GRUPOS" << endl;
    for(int i = 0; i < k; i++){
        cout << "Grupo " << i+1 << endl;
        cout << grupos[i] << endl;   
    }
    
    
     /********************************************
     *     PROCESAMIENTO DE LOS DATOS
     ********************************************/
     //......................................



    /********************************
     *     MOSTRAR RESULTADOS
     *******************************/

    cout << "ESTADO FINAL DE LOS GRUPOS" << endl;    
    for(int i = 0; i < k; i++){
        cout << "Grupo " << i+1 << endl;
        cout << grupos[i] << endl;   
    }
    

    return 0;
}

