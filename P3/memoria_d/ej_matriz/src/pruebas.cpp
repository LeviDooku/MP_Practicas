/* 
 * File:   pruebas.cpp
 * Author: David A. Pelta
 *
*/

#include <iostream>
#include "../include/pruebas.h" // ! NO ENTREGAR ASÍ
#include "../include/Imagen.h" // ! NO ENTREGAR ASÍ
#include "../include/pgm.h" // ! NO ENTREGAR ASÍ

using namespace std;

void rellena(Imagen & img){
    for(int i = 0; i < img.nf; i++){
        for (int j=0; j< img.nc; j++){
            img.M[i][j] = i * img.nc + j;
        }
    }
}

void cartel(string msg){
    cout << "*****************************************" << endl;
    cout << "    " << msg << endl;
    cout << "*****************************************" << endl;
}

void test1(){
    cartel("test1: Memoria basica 1 ");
    Imagen img1;
    reservaMem(img1, 5, 5);
    rellena(img1);
    liberaMem(img1);
}

void test2(){
    cartel("test2: Memoria basica 2 ");
    Imagen img1;
    reservaMem(img1, 5, 5);
    rellena(img1);
    reservaMem(img1, 4, 3);
    rellena(img1);
    liberaMem(img1);
}

void test3(){
    cartel("test3: Memoria basica 3");
    Imagen img1;
    liberaMem(img1);
    reservaMem(img1, 5, 5);
    liberaMem(img1);
    liberaMem(img1);
}

void test4(){
    cartel("test4: Memoria basica 4");
    Imagen img1, img2;
    reservaMem(img1, 4, 3);
    reservaMem(img2, 3, 4);
    rellena(img1);
    rellena(img2);
    copiar(img2, img1);
    
    bool igual = sonIguales(img1, img2);
    
    if (!igual){
        cout << "ERROR" << endl;
    }
        
    liberaMem(img1);
    liberaMem(img2);   
}

void test5(string file) {
    cartel("test5: rotacion");
    Imagen img;
    cargarImagen(img, file);
    string cad = file.substr(0, file.length() - 4);

    rotar(img);
    guardarImagen(img, cad + "_rota45.pgm");
    rotar(img);
    guardarImagen(img, cad + "_rota90.pgm");
    rotar(img);
    guardarImagen(img, cad + "_rota180.pgm");

    liberaMem(img);
}

void test6(string file) {
    cartel("test6: aplicacion filtros");
    Imagen img, aux, filtro;
    cargarImagen(img, file);
    string cad = file.substr(0, file.length() - 4);

    for(int i = 1; i <= 4;i++){
        inicializaFiltro(filtro, i);
        copiar(img, aux);
        aplicaFiltro(aux, filtro);
        guardarImagen(aux, cad + "_F_" + to_string(i) + ".pgm");
    }
        
    liberaMem(img);
    liberaMem(filtro);
    liberaMem(aux);
}

// espejos

void test7(string file) {
    cartel("test7: aplicacion espejos");
    Imagen img, imgV, imgH;
    cargarImagen(img, file);

    string cad = file.substr(0, file.length() - 4);
    espejoV(img, imgV);
    guardarImagen(imgV, cad + "_espejoV" + ".pgm");
    espejoH(img, imgH);
    guardarImagen(imgH, cad + "_espejoH" + ".pgm");

    liberaMem(img);
    liberaMem(imgV);
    liberaMem(imgH);

}

void test8(string file) {
    cartel("test8: aplicacion espejos combinados");
    Imagen img, imgV, imgH;
    cargarImagen(img, file);

    string cad = file.substr(0, file.length() - 4);
    espejoV(img, imgV);
    guardarImagen(imgV, cad + "_espejoV1" + ".pgm");
    espejoV(imgV, img);
    guardarImagen(img, cad + "_espejoV2" + ".pgm");

    espejoH(img, imgH);
    guardarImagen(imgH, cad + "_espejoH1" + ".pgm");
    espejoH(imgH, img);
    guardarImagen(img, cad + "_espejoH2" + ".pgm");

    liberaMem(img);
    liberaMem(imgV);
    liberaMem(imgH);
}


