#include<iostream>
#include "../include/pgm.h" // ! NO ENTREGAR ASÍ
#include "../include/Imagen.h" // ! NO ENTREGAR ASÍ
#include "../include/pruebas.h" // ! NO ENTREGAR ASÍ

using namespace std;

int main(int argc, char*argv[]){

    if (argc < 2){
        cerr << "Uso: pruebas <nro funcion: 0..7> <nombre fichero> \n El nombre de fichero es obligatorio si el nro de funcion es mayor que 3" << endl;
        exit(-1);
    }
    
    // suponemos parametros correctos
    int nro = atoi(argv[1]);
    string fich;
    if(nro > 4){
        if (argc > 2)
             fich = argv[2];
        else {
            cerr << "Para el test " << nro << " hace falta indicar el nombre del fichero con la imagen a procesar." << endl;
            exit(-1);
        }
    }



    switch(nro){
    case 1:{test1(); break;}
    case 2:{test2(); break;}
    case 3:{test3(); break;}
    case 4:{test4(); break;}
    case 5:{test5(fich); break;}    
    case 6:{test6(fich); break;}    
    case 7:{test7(fich); break;}    
    case 8:{test8(fich); break;}    
    }
 
return 0;
}
