#include <iostream>
#include "intercalacion.h"

using namespace std;

int main() {
    const string archivo1 = "archivos/datos1.txt";
    const string archivo2 = "archivos/datos2.txt";
    const string archivoOrdenado = "archivos/datosIntercalados.txt";

    intercalarArchivos(archivo1, archivo2, archivoOrdenado);

    cout << "Se ordenaron los datos de los dos archivos en " << archivoOrdenado << endl;

    return 0;
}
