/* 
 * File:   pruebas.h
 * Author: David A. Pelta
 *
 */

#ifndef PRUEBAS_H
#define PRUEBAS_H

#include <iostream>

/*
 CONJUNTO BASICO DE PRUEBAS PARA EL MODULO Imagen
 */

void test1();
void test2();
void test3();
void test4();
void test5(std::string);
void test6(std::string);
void test7(std::string);
void test8(std::string);

#endif /* PRUEBAS_H */


// COPIA LA SIGUIENTE FUNCION EN TU FICHERO Imagen.cpp
/*
 void inicializaFiltro(Imagen & filtro, int opcion) {
    if (filtro.M == nullptr)
        reservaMem(filtro, 3, 3);

    switch (opcion)
    {
    case 1: // repujado
    {
        filtro.M[0][0] = 2;
        filtro.M[0][1] = -1;
        filtro.M[0][2] = 0;

        filtro.M[1][0] = -1;
        filtro.M[1][1] = 1;
        filtro.M[1][2] = 1;

        filtro.M[2][0] = 0;
        filtro.M[2][1] = 1;
        filtro.M[2][2] = 2;
        break;
    }
    case 2: // deteccion bordes
    {
        filtro.M[0][0] = -1;
        filtro.M[0][1] = 0;
        filtro.M[0][2] = 1;

        filtro.M[1][0] = -2;
        filtro.M[1][1] = 0;
        filtro.M[1][2] = 2;

        filtro.M[2][0] = -1;
        filtro.M[2][1] = 0;
        filtro.M[2][2] = 1;
        break;
    }


    case 3: // sharpen
    {
        filtro.M[0][0] = 1;
        filtro.M[0][1] = -2;
        filtro.M[0][2] = 1;

        filtro.M[1][0] = -2;
        filtro.M[1][1] = 5;
        filtro.M[1][2] = -2;

        filtro.M[2][0] = 1;
        filtro.M[2][1] = -2;
        filtro.M[2][2] = 1;
        break;
    }


    case 4: // desenfoque
    {
        filtro.M[0][0] = 1;
        filtro.M[0][1] = 1;
        filtro.M[0][2] = 1;

        filtro.M[1][0] = 1;
        filtro.M[1][1] = 1;
        filtro.M[1][2] = 1;

        filtro.M[2][0] = 1;
        filtro.M[2][1] = 1;
        filtro.M[2][2] = 1;
        break;
    }
    }
}

 
 */