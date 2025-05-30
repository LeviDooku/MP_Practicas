/*
NOMBRE Y APELLIDOS: Pedro Velasco Santana
DNI: 45342754w
GRUPO DE PRÁCTICAS: viernes
*/

#include "../include/proceso.h"
#include <iostream> //Para atoi()
#include <cstring> //Para strcpy()

bool sonIguales(const char cad1[],const char cad2[]){
    int i = 0;
    bool resultado = (longitud(cad1) == longitud(cad2)); //Primera aproximación. Si la longitud es diferente, ya no son iguales

    while(cad1[i] != TERMINADOR && resultado){ //Se recorre mientras no se llegue al final o sean iguales
        resultado &= (cad1[i] == cad2[i]); //Mantiene el resultado a true hasta que encuentre una diferencia
        i++;
    }

    return resultado;
}

int longitud(const char cad[]){
    int longitud = 0;

    while(cad[longitud] != TERMINADOR)
        longitud++;

    return longitud;
}

int carsUnicos(const char cad1[]){
    char aux[longitud(cad1)];
    int i = 0;
    int contador = 0; //Contador global

    while (cad1[i] != TERMINADOR){
        char actual = cad1[i];
        int repeticiones = 0; //Contador de repeticiones de "actual"
        int j = 0;
        
        //Contar cuántas veces aparece "actual" en la cadena
        while(cad1[j] != TERMINADOR){ //! Insostenible en cadenas muy largas, > MAX_SIZE
            if(actual == cad1[j])
                repeticiones++;
            j++;
        }

        if(repeticiones == 1)   //Si el caracter solo aparece 1 vez en la cadena...
            contador++;         //Se actualiza contador "global"
        i++;
    }
    return contador;
}

//Función auxiliar para intercambiar dos caracteres
void intercambiaChar(char &a, char &b){
    char temp = a;
    a = b;
    b = temp;
}

//Función auxiliar para ordenar una cadena de caracteres usando Bubble Sort
//! Insostenible en cadenas muy largas, > MAX_SIZE
void ordenarCadena(char cadena[]) {
    int n = longitud(cadena);

    bool intercambio = true;
    while(intercambio){
        intercambio = false;
        int i = 0;
        while(i < n - 1){
            if(cadena[i] > cadena[i + 1]){  
                intercambiaChar(cadena[i], cadena[i + 1]);
                intercambio = true;
            }
            i++;
        }
    }
}

bool anagrama(const char cad1[],const char cad2[]){
    char cad_aux[longitud(cad1) + 1]; //Copias de las cadenas
    char cad_aux1[longitud(cad2) + 1];

    strcpy(cad_aux, cad1);
    strcpy(cad_aux1, cad2);

    ordenarCadena(cad_aux); //Se ordenan
    ordenarCadena(cad_aux1);
    
    //Comparación caracter a caracter
    int i = 0;
    bool resultado = true; 

    while (cad_aux[i] != TERMINADOR && resultado){
        resultado = (cad_aux[i] == cad_aux1[i]);
        i++;
    }

    return resultado;
}

//Función auxiliar para compress
void int_to_char(int num, char cadena[], int & indice){
    int temp = num;
    int digitos = 0;
    
    //Contar los dígitos de num
    do{
       digitos++;
       temp /= 10; 
    }while(temp > 0);

    //Agregar dígitos a la cadena
    for(int i = digitos - 1; i >= 0; --i){
        cadena[indice + i] = '0' + (num % 10); //Convertir último dígito y agregarlo (en tabla ASCII, los dígitos decimales están ordenados)
        num /= 10; //Eliminar dígito ya agregado
    }
    indice += digitos; //Actualizar el índice después de agregar los dígitos
}

//Se presupone que frase ya está ordenada
void compress(const char frase[], char salida []){
    int i = 0;
    int j = 0;

    while(frase[i] != TERMINADOR){
        int contador = 1; //El caracter actual aparece como mínimo una vez
        while(frase[i] == frase[i + 1] && frase[i + 1] != TERMINADOR){ //Contar la frecuencia de apariciones
            contador++;
            i++;
        }
        salida[j++] = frase[i]; //Agregar el caracter a salida y actualizar índice
        //Traducir contador a char y agregarlo a salida, tras el caracter
        if(contador >= 10)
            int_to_char(contador, salida, j);
        else
            salida[j++] = '0' + contador;
        i++;
    }
    salida[j] = TERMINADOR; //Agregar terminador a salida
}

void decompress(const char frase[], char salida[]){
    int i = 0;
    int j = 0;

    while(frase[i] != TERMINADOR){
        if(frase[i] < '0' || frase[i] > '9'){ //Estamos ante un caracter no numérico
            salida[j] = frase[i];
        }
        else{
            char temp[10] = {0}; //10 posiciones que suponen los dígitos que se necesitan para almacenar el valor max de un signed int
            int k = 0;
            while(frase[i] >= '0' && frase[i] <= '9' && frase[i] != TERMINADOR){ //Almecenar en un array auxiliar los dígitos
                temp[k++] = frase[i];
                i++;
            }
            int repeticiones = atoi(temp); //Convertir a entero
            for(int r = 0; r < repeticiones; ++r){ //Agregarlo a la salida
                salida[j++] = frase[i - k - 1];  
            }
        }
        i++;
    }
    salida[j] = TERMINADOR;
}