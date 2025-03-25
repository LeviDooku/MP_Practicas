////////////////////////////////
// Práctica 3                 //
// file: funcArrays.h (DP)    //
// Pedro Velasco Santana      //
////////////////////////////////

#ifndef PROCESO_H
#define PROCESO_H

const int TAM_BLOQUE = 5;

void mostrar(const int *v, int k);

void rellenar(int *v, int k, int min, int max);

void Redimensiona(int * &p, int util, int tipo, int &cap);

#endif