/**
  * @file 
  * @brief Fichero con las definiciones para la E/S de imágenes PGM 
  *
  * Permite la E/S de archivos de tipos PGM
  *
  */

#include <fstream>
#include <string>
#include "../include/Imagen.h" // ! NO ENTREGAR ASÍ
#include "../include/pgm.h" // ! NO ENTREGAR ASÍ
using namespace std;


TipoImagen LeerTipo(ifstream& f)
{
  char c1,c2;
  TipoImagen res= IMG_DESCONOCIDO;

  if (f) {
    f >> c1 >> c2;
    if (f && c1=='P')
      switch (c2) {
        case '5': res= IMG_PGM_BINARIO; break;
        case '2': res= IMG_PGM_TEXTO; break;
        default: res= IMG_DESCONOCIDO;
      }
  }
  return res;
}


// _____________________________________________________________________________

char SaltarSeparadores (ifstream& f)
{
  char c;
  do {
    c= f.get();
  } while (isspace(c));
  f.putback(c);
  return c;
}

// _____________________________________________________________________________

bool LeerCabecera (ifstream& f, int& filas, int& columnas)
{
    int maxvalor;

    while (SaltarSeparadores(f)=='#')
      f.ignore(10000,'\n');

    f >> columnas >> filas >> maxvalor;
    
    if (/*str &&*/ f && filas>0 && filas <5000 && columnas >0 && columnas<5000) {
        f.get(); // Saltamos separador
        return true;
    }
    else return false;
}

// _____________________________________________________________________________

TipoImagen infoPGM(const char nombre[], int& filas, int& columnas)
{
  TipoImagen tipo;
  filas=columnas=0;
  ifstream f(nombre);

  tipo=LeerTipo(f);
  if (tipo!=IMG_DESCONOCIDO)
    if (!LeerCabecera(f,filas,columnas)) {
      tipo=IMG_DESCONOCIDO;
    }

  return tipo;
}


bool leerPGMTexto(Imagen & img, string nombre) {
    bool exito = false;
    int filas = 0;
    int columnas = 0;
    ifstream f(nombre);
    int aux;
    if (LeerTipo(f)==IMG_PGM_TEXTO){    
    if (LeerCabecera(f, filas, columnas)) {
        reservaMem(img, filas, columnas);
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                f >> aux; //leer un numero en lugar de un unico caracter
                if ((aux < 256)&&(aux >= 0))
                    img.M[i][j] = aux;

            }
        }
        exito = true;
        f.close();
    }
    }

    return exito;
}



void getMaxMin(const Imagen & img, int & max, int & min){
max = min = img.M[0][0];   
int valor;
   for(int i = 0; i < img.nf; i++){
        for (int j=0; j< img.nc; j++){
            valor = img.M[i][j];
            if (valor < min)
                min = valor;
            
            if (valor > max)
                max = valor;
        }
   }
}

bool escribirPGMTexto(const Imagen & img, std::string nombre) {
        ofstream f(nombre);
        bool res = true;

        int max, min;
        getMaxMin(img, max, min);

        // [a=min, b=max] -> [c=0,d=255]

        // c + (x - a) * (d-c) / (b - a)


        if (f) {
            f << "P2" << endl;
            f << img.nc << ' ' << img.nf << endl;
            f << 255 << endl;
            int valor;
            int pos = 0;
            for (int i = 0; i < img.nf; i++) {
                for (int j = 0; j < img.nc; j++) {
                    valor = ((img.M[i][j] - min) * 254) / (max - min);
                    if (valor >= 0 && valor < 255)
                        img.M[i][j] = valor;
                    else {
                        img.M[i][j] = 0;
                        std::cout << valor << std::endl;
                    }
                    f <<  img.M[i][j] << ' ';
                    if ((pos) % 19 == 0) //para ser mas visible
                        f << endl;
                    pos++;
                }
            }
            f.close();
        }

        return res;
        
 }


