#include "mezcla.h"
#include <iostream>

int main() {
    string archivoEntrada = "archivos/datos.txt";

    ordenarArchivoExterno(archivoEntrada);

    cout << "Archivo ordenado en archivos/datosOrdenados.txt";
    return 0;
}