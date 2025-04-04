/*
 * File:   Imagen.cpp
 * Author: David Pelta
 *
 * Metodología de la Programación
*/

#include "../include/Imagen.h" // ! NO ENTREGAR ASÍ
#include "../include/pgm.h" // ! NO ENTREGAR ASÍ
 
void cargarImagen(Imagen & img, std::string file){
     int fil, col;
     TipoImagen tipo = infoPGM(file.c_str(), fil, col);
     if (tipo == IMG_PGM_TEXTO){
         liberaMem(img);
         leerPGMTexto(img, file);
         }
     else{
         std::cerr << "Error en la lectura del fichero " << file << std::endl;
         exit(-1);
     }
 }
 
void guardarImagen(Imagen & img, std::string file){
     escribirPGMTexto(img, file);
 }
 
void inicializaFiltro(Imagen & filtro, int opcion) {
     if (filtro.M == nullptr)
         reservaMem(filtro, 3, 3);
 
     switch (opcion){
      case 1:{ // repujado
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
     case 2:{ // deteccion bordes
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
 
     case 3:{ // sharpen
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
 
     case 4:{ // desenfoque
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
 
void reservaMem(Imagen & img, int fil, int col){
    if(img.M != nullptr) liberaMem(img);

    img.M  = new int * [fil];
    for(int i = 0; i < fil; ++i)
        img.M[i] = new int[col];
}

void liberaMem(Imagen & img){
    for(int i = 0; i < img.nf; ++i)
        delete[] img.M[i];
    delete[] img.M;
    img.M = nullptr;
}

// ? COMPLETAR
void copiar(const Imagen & origen, Imagen & destino){
    if(destino.M != nullptr) liberaMem(destino);

    reservaMem(destino, origen.nf, origen.nc);
}

void rotar(Imagen & img){}

void espejoV(const Imagen & origen, Imagen & destino){}

void espejoH(const Imagen & origen, Imagen & destino){}

bool sonIguales(const Imagen & img1, const Imagen & img2){
    bool iguales = (img1.nf == img2.nf && img1.nc == img2.nc);

    for(int i = 0; i < img1.nc && iguales; ++i){
        for(int j = 0; j < img1.nf && iguales; ++j)
            if(img1.M[i][j] != img2.M[i][j]) 
                iguales = false;
    }
    return iguales;
}

void aplicaFiltro(Imagen & img, const Imagen & filtro){}
