
#include<iostream>
#include "pgm.h"
#include "Imagen.h"

using namespace std;

void rellena(Imagen & img){
    for(int i = 0; i < img.nf; i++){
        for (int j=0; j< img.nc; j++){
            img.M[i][j] = i * img.nc + j;
        }
    }
}

void test0(){
    Imagen img1, img2;
    reservaMem(img1, 20, 20);
    reservaMem(img2, 10, 20); 
    rellena(img1);
    copiar(img2, img1);
    
    bool igual = sonIguales(img1, img2);
    
    if (!igual){
        cout << "ERROR" << endl;
    }
    
    liberaMem(img1);
    liberaMem(img2);
    
}

void test1(string file) {
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

void test2(string file, int opc) {
    Imagen img, filtro;
    cargarImagen(img, file);

    string cad = file.substr(0, file.length() - 4);

    inicializaFiltro(filtro, opc);
    aplicaFiltro(img, filtro);
    guardarImagen(img, cad + "_filtro_" + to_string(opc) + ".pgm");
    liberaMem(img);
    liberaMem(filtro);
}

// espejos

void test3(string file) {
    Imagen img, imgV, imgH;
    cargarImagen(img, file);

    string cad = file.substr(0, file.length() - 4);
    espejoV(img, imgV);
    guardarImagen(imgV, cad + "_espejoV1" + ".pgm");
    espejoH(img, imgH);
    guardarImagen(imgH, cad + "_espejoH1" + ".pgm");

    liberaMem(img);
    liberaMem(imgV);
    liberaMem(imgH);

}

void test4(string file) {
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


//int main(int argc, char*argv[]){
int main(){

    //string fich = argv[1];

    Imagen i1, i2;
    
    cout << sonIguales(i1,i2);
    
    //test0();
//    test1(fich);
/*    
    for(int i = 1; i <= 4; i++){
        test2(fich,i);
    }
*/
 //   test3(fich);
 //   test4(fich);
return 0;
}
