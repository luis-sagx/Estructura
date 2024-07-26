#include "archivo.h"

void intercalarArchivos(const string& archivo1, const string& archivo2, const string& archivoOrdenado) {
    ifstream archivoA, archivoB;    // Archivo de entrada
    ofstream archivoSalida;      // Archivo de salida

    if (!leerArchivo(archivoA, archivo1) || !leerArchivo(archivoB, archivo2) || !escribirArchivo(archivoSalida, archivoOrdenado)) {
        return;     // Si algún archivo no se puede abrir, se sale de la función
    } 

    int datoA, datoB;
    // Leer el primer dato de cada archivo
    bool hayDatoA = bool (archivoA >> datoA);
    bool hayDatoB = bool (archivoB >> datoB);

    while (hayDatoA && hayDatoB) {     // Intercala los datos mientras haya datos en ambos archivos
        if (datoA < datoB) {        // Compara los datos actuales de ambos archivos
            archivoSalida << datoA << endl;  // Escribe el dato más pequeño en el archivo de salida
            hayDatoA = bool (archivoA >> datoA);    // Lee el siguiente dato del archivoA
        } else {
            archivoSalida << datoB << endl;  // Escribir el dato más pequeño en el archivo de salida
            hayDatoB = bool (archivoB >> datoB);    // Lee el siguiente dato del archivoB
        }
    }

    while (hayDatoA) {  // Mientas aun queden datos en archivoA
        archivoSalida << datoA << endl;  // Escribe el dato más pequeño en el archivo de salida
        hayDatoA = bool (archivoA >> datoA);    // Lee el siguiente dato del archivoA
    }

    while (hayDatoB) {  // Mientas aun queden datos en archivoB
        archivoSalida << datoB << endl;  // Escribir el dato más pequeño en el archivo de salida
        hayDatoB = bool (archivoB >> datoB);    // Lee el siguiente dato del archivoB
    }

    archivoA.close();
    archivoB.close();
    archivoSalida.close();
}
