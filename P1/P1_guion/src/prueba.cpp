#include <iostream>
#include <string>
#include "../include/contenedor.h"
#include "../include/paquete.h"

using namespace std;

int main() {
    Paquete actual;
    Contenedor c1, otro;
    int origen, destino, cant;
    float peso;

    // lectura de datos
    cin >> cant;

    c1.utiles = 0;
    for (int i = 0; i < cant; i++) {
        cin >> origen >> destino >> peso;
        actual = creaPaquete(origen, destino, peso);
        agregaPaquete(c1, actual);
    }

    cout << "\n ******** Prueba mostrarContenedor ******** \n";
    mostrarContenedor(c1);
    
    cout << "\n ******** Prueba ordenar ******** \n";
    ordenar(c1);
    mostrarContenedor(c1);

    cout << "\n ******** Prueba enviosDestino ******** \n";
    cout << "Datos de envios a los destinos 1 y 4\n";
    int nro;
    enviosDestino(c1, 1, nro, peso);
    cout << "Destino: " << 1 << " Paquetes: " << nro << " Peso: " << peso << endl;
    enviosDestino(c1, 4, nro, peso);
    cout << "Destino: " << 4 << " Paquetes: " << nro << " Peso: " << peso << endl;

    cout << "\n ******** Prueba obtienePaquetes ******** \n";
    cout << "Paquetes con origen = 4\n";
    otro = obtienePaquetes(c1, 4);
    mostrarContenedor(otro);

    cout << "\n ******** Prueba analisisDestinos ******** \n";
    analisisDestinos(c1);
    

    return (0);
}

