////////////////////////////////
// Práctica 3                 //
// file: funcArrays.cpp (DP)  //
// Pedro Velasco Santana      //
////////////////////////////////

#include <iostream>
#include <cstdlib>
#include "../include/funcArrays.h" // ! NO INCLUIR EN LA ENTREGA ASINNNN

using namespace std;

//Función que recibe un puntero a entero (array) y un tamaño
//Muestra los elementos del array, o los primeros k-elementos
void mostrar(const int *v, int k){
    for(int i = 0; i < k; i++)
       cout << v[i] << " ";
    cout << endl;
}
  
//Función que recibe un puntero a entero, un tamaño y unos umbrales
//Rellena los primeros k elementos con números aleatorios entre min y max
void rellenar(int *v, int k, int min, int max){
    for(int i = 0; i < k; i++)
        v[i] = (random()% (max - min)) + min;
    cout << endl;
}

void Redimensiona(int * &p, int util, int tipo, int &cap){
    int new_size;

    switch (tipo){
        case 1:
        new_size = cap + 1;
        break;

        case 2:
        new_size = cap + TAM_BLOQUE;
        break;

        case 3: 
        new_size = cap * 2; 
        break;
        
        default:
        new_size = 1;
        break;
    }
    
    if(new_size > cap){
        int *v_ampliado = new int[new_size];
        for(int i = 0; i < cap; ++i)
            v_ampliado[i] = p[i];
        delete [] p;
        p = v_ampliado;
    }

    cap = new_size;
}

int * Union(const int * v1, const int * v2, const int n1, const int n2, int &res_cap){
    int *v;
    int cap = TAM_BLOQUE;
    v = new int [cap];
    int util = 0;

    for(int i = 0; i < n1; ++i){
        if(util == cap) Redimensiona(v, util, 1, cap);
        bool repe = false;
        for(int j = 0; j < util && !repe; ++j){
            repe = (v1[i] == v[j]) ? true : false;
        }
        
        if(!repe){
            v[util] = v1[i];
            util++;
        }
    }

    for(int i = 0; i < n2; ++i){
        if(util == cap) Redimensiona(v, util, 1, cap);
        bool repe = false;
        for(int j = 0; j < util && !repe; ++j){
            repe = (v2[i] == v[j]) ? true : false;
        }
        
        if(!repe){
            v[util] = v2[i];
            util++;
        }
    }

    res_cap = util;
    return v;
}

bool en_ambos(const int *v1, const int *v2, const int util1, const int util2, const int buscar){
    bool en_ambos = false;

    for(int i = 0; i < util1; ++i){
        if(v1[i] == buscar){
            for(int j = 0; j < util2; ++j)
                if(v2[j] == buscar) en_ambos = true;
        } 
    }

    return en_ambos;
}

int * Interseccion(const int * v1, const int * v2, const int n1, const int n2, int &res_cap){
    int *v;
    int cap = TAM_BLOQUE;
    v = new int [cap];
    int util = 0;

    for(int i = 0; i < n1; ++i){
        if(en_ambos(v1, v2, n1, n2, v1[i])){
            if(util == cap) Redimensiona(v, util, 1, cap);
            
            bool repe = false;
            for(int j = 0; j < util && !repe; ++j){
                repe = (v1[i] == v[j]) ? true : false;
            }
            
            if(!repe && en_ambos){
                v[util] = v1[i];
                util++;
            }
        }
    }

    res_cap = util;
    return v;
}

void multiplos(const int * v, const int cap, const int nro, int * &mult, int &m_cap){
    m_cap = TAM_BLOQUE;
    mult = new int [TAM_BLOQUE];
    int util = 0;

    for(int i = 0; i < cap; ++i){
        bool repe = false;
        for(int j = 0; j < util; ++j)
            if(mult[j] == v[i]) repe = true;

        if(v[i] % nro == 0 && !repe){
            if(util == m_cap) Redimensiona(mult, util, 1, m_cap);
            mult[util] = v[i];
            util++;
        }
    }

    m_cap = util;
}