#include <iostream>

using namespace std;

const int TAM_BLOQUE = 5;

void mostrar_array(const int * v, int n, int util){
    cout << endl << "Usados: " << util << "; Capacidad: " << n << endl;
    for(int i = 0; i < util; ++i)
        cout << v[i] << " ";
    cout << endl << endl;
}

void Redimensiona(int * &p, int util, int &cap){
    int new_size = cap + TAM_BLOQUE;
    
    if(new_size > cap){
        int *v_ampliado = new int[new_size];
        for(int i = 0; i < util; ++i)
            v_ampliado[i] = p[i];
        delete [] p;
        p = v_ampliado;
    }
    cap = new_size;
}

bool YaIncluido(const int *v, const int cap, const int a_buscar){
    bool incluido = false;

    for(int i = 0; i < cap && !incluido; ++i)
        if(v[i] == a_buscar) incluido = true;
    
    return incluido;
}

int * EliminaDuplicados(const int * v, int n, int & res_cap){
    int *res;
    res = new int[n];
    int util_res = 0;
    res_cap = util_res;

    for(int i = 0; i < n; ++i){
        if(!YaIncluido(res, res_cap, v[i])){
            res[util_res++] = v[i];
            res_cap = util_res;
        } 
    }

    return res;
}

int * EliminaConsecutivos(const int * v, int n, int & res_cap){
    int *res;
    res = new int[n];
    int util_res = 0;
    res_cap = util_res;

    if(n > 0) res[util_res++] = v[0];

    for(int i = 1; i < n; ++i){
        if(v[i] != v[i - 1]){
            res[util_res++] = v[i];
            res_cap = util_res;
        }
    }

    return res;
}

int * FiltrarMayores(const int *v, int n, int umbral, int &res_cap){
    int *res;
    res = new int[n];
    int util_res = 0;
    res_cap = util_res;

    for(int i = 0; i < n; ++i){
        if(v[i] > umbral){
            res[util_res++] = v[i];
            res_cap = util_res;
        }
    }
    return res;
}

void Intercambia(int &a, int &b){
    int aux = a;
    a = b;
    b = aux;
}

void RotarIzq(int * v, const int capacidad){
    v[capacidad] = v[0];
    for(int i = 0; i < capacidad - 1; ++i){
        Intercambia(v[i], v[i + 1]);
    }
}

void test_repe_simple(const int * v, int n, int util){
    cout << "Array sin aplicar función:" << endl;
    mostrar_array(v, n, util);

    int res_cap;
    int *resultado = EliminaDuplicados(v, util, res_cap);

    cout << "Array después de EliminaDuplicados:" << endl;
    mostrar_array(resultado, res_cap, res_cap);

    delete [] resultado;
}

void test_consecutivo(const int * v, int n, int util){
    cout << "Array sin aplicar función:" << endl;
    mostrar_array(v, n, util);

    int res_cap;
    int *resultado = EliminaConsecutivos(v, util, res_cap);

    cout << "Array después de EliminaDuplicados:" << endl;
    mostrar_array(resultado, res_cap, res_cap);

    delete [] resultado;
}

void test_filtrar_mayores(const int * v, int n, int util){
    cout << "Array sin aplicar función:" << endl;
    mostrar_array(v, n, util);

    int res_cap;
    int *resultado = FiltrarMayores(v, util, 2, res_cap);

    cout << "Array después de FiltrarMayores:" << endl;
    mostrar_array(resultado, res_cap, res_cap);

    delete [] resultado;
}

void test_rotar_izq(const int * v, int n, int util){
    cout << "Array sin aplicar función:" << endl;
    mostrar_array(v, n, util);

    int res_cap = n, res_util = 0;
    int *resultado = new int[res_cap];
    for(int i = 0; i < util; ++i)
        resultado[res_util++] = v[i];

    RotarIzq(resultado, res_cap);

    cout << "Array después de FiltrarMayores:" << endl;
    mostrar_array(resultado, res_cap, res_cap);

    delete [] resultado;
}

int main(){
    int *v;
    int util = 0, capacidad = 0;

    cout << "Introduzca capacidad del vector: ";
    cin >> capacidad;

    while(capacidad <= 0){
        cout << "Valor no válido. Capacidad > 0: ";
        cin >> capacidad;
    }

    v = new int[capacidad];
    
    int elem = 0;
    cout << "Introduzca los elementos del vector (-1 para terminar): " << endl;
    cout << "Pos " << util << ": ";
    cin >> elem;

    while(elem != -1){
        if(util == capacidad) Redimensiona(v, util, capacidad);

        v[util] = elem;
        util++;

        mostrar_array(v, capacidad, util);

        cout << "Pos " << util << ": ";
        cin >> elem;
    }
    
    cout << endl << "TEST: " << endl;

    test_repe_simple(v, capacidad, util);
    test_consecutivo(v, capacidad, util);
    test_filtrar_mayores(v, capacidad, util);
    test_rotar_izq(v, capacidad, util);

    delete [] v;
}