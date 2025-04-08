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

    img.nf = fil;
    img.nc = col;
}

void liberaMem(Imagen & img){
    for(int i = 0; i < img.nf; ++i)
        delete[] img.M[i];
    delete[] img.M;

    img.M = nullptr;
    img.nf = 0;
    img.nc = 0;

}

void copiar(const Imagen & origen, Imagen & destino){
    if(destino.M != nullptr) liberaMem(destino); //Liberar mem destino

    reservaMem(destino, origen.nf, origen.nc); //Reservar con tam origen

    //Copia
    for(int i = 0; i < origen.nf; ++i){
        for(int j = 0; j < origen.nc; ++j)
            destino.M[i][j] = origen.M[i][j];
    }
}

void rotar(Imagen & img){
    //Imagen auxiliar rotada
    Imagen rotada;
    reservaMem(rotada, img.nc, img.nf); 

    //Rotación
    for(int i = 0; i < img.nf; ++i){
        for(int j = 0; j < img.nc; ++j){
            rotada.M[j][img.nf - 1 - i] = img.M[i][j];
        }
    }

    liberaMem(img);
    copiar(rotada, img); //Copiar imagen rotada a original
    liberaMem(rotada); //Liberar mem de la imagen rotada
}

void espejoV(const Imagen & origen, Imagen & destino){
    if(destino.M != nullptr) liberaMem(destino); //Liberar mem destino
    reservaMem(destino, origen.nf * 2, origen.nc); //La imagen tendrá el doble de filas

    for(int i = 0; i < origen.nf; ++i){
        for(int j = 0; j < origen.nc; ++j){
            destino.M[i][j] = origen.M[i][j]; //Se copia la mitad superior
            destino.M[destino.nf - 1 - i][j] = origen.M[i][j]; //Se copia la mitad inferior al revés
        }
    }
}

void espejoH(const Imagen & origen, Imagen & destino){
    if(destino.M != nullptr) liberaMem(destino); //Liberar mem destino
    reservaMem(destino, origen.nf, origen.nc * 2); //La imagen tendrá el doble de columnas

    for(int i = 0; i < origen.nf; ++i){
        for(int j = 0; j < origen.nc; ++j){
            destino.M[i][j] = origen.M[i][j]; 
            destino.M[i][destino.nc - 1 - j] = origen.M[i][j];
        }
    }
}

bool sonIguales(const Imagen & img1, const Imagen & img2){
    bool iguales = (img1.nf == img2.nf && img1.nc == img2.nc);

    //Se recorre pixel a pixel mientras tengan el mismo valor
    for(int i = 0; i < img1.nf && iguales; ++i){
        for(int j = 0; j < img1.nc && iguales; ++j)
            if(img1.M[i][j] != img2.M[i][j]) 
                iguales = false;
    }
    return iguales;
}

int valorPixel(const Imagen & img, const Imagen & filtro, int i, int j){
    int valor = 0;

    //Se recorre el filtro
    for(int k = 0; k < filtro.nf; ++k){
        for(int l = 0; l < filtro.nc; ++l)
            valor += img.M[i + k - 1][j + l - 1] * filtro.M[k][l]; //Calcular el valor correctamente
    }

    return valor;
}

void aplicaFiltro(Imagen & img, const Imagen & filtro){
    Imagen aux;
    copiar(img, aux);

    //Se recorre aux evitando bordes
    for(int i = 1; i < aux.nf - 1; ++i){
        for(int j = 1; j < aux.nc - 1; ++j){
            aux.M[i][j] = valorPixel(img, filtro, i, j); //Modificar valor
        }
    }

    copiar(aux, img);
    liberaMem(aux); //Liberar memoria de aux
}
