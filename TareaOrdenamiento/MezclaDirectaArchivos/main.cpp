#include "mezcla.h"
#include <iostream>

using namespace std;

int main() {
    const string archivoDatos = "archivos/datos.txt";

    mergeSort(archivoDatos);
    cout << "Ordenado por mezcla directa en el archivo: " << archivoDatos << endl;
    
    return 0;
}
