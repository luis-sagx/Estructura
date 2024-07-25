#include "archivo.h"

void intercalarArchivos(const string& archivo1, const string& archivo2, const string& archivoOrdenado) {
    ifstream archivoA, archivoB;    // Archivo de entrada
    ofstream archivoC;      // Archivo de salida

    if (!leerArchivo(archivoA, archivo1) || !leerArchivo(archivoB, archivo2) || !escribirArchivo(archivoC, archivoOrdenado)) {
        return;     // Si algún archivo no se puede abrir, se sale de la función
    } 

    int datoA, datoB;
    // Leer el primer dato de cada archivo
    bool hayDatoA = bool (archivoA >> datoA);
    bool hayDatoB = bool (archivoB >> datoB);

    while (hayDatoA && hayDatoB) {     // Intercala los datos mientras haya datos en ambos archivos
        if (datoA < datoB) {        // Compara los datos actuales de ambos archivos
            archivoC << datoA << endl;  // Escribe el dato más pequeño en el archivo de salida
            hayDatoA = bool (archivoA >> datoA);    // Lee el siguiente dato del archivoA
        } else {
            archivoC << datoB << endl;  // Escribir el dato más pequeño en el archivo de salida
            hayDatoB = bool (archivoB >> datoB);    // Lee el siguiente dato del archivoB
        }
    }

    while (hayDatoA) {  // Mientas aun queden datos en archivoA
        archivoC << datoA << endl;  // Escribe el dato más pequeño en el archivo de salida
        hayDatoA = bool (archivoA >> datoA);    // Lee el siguiente dato del archivoA
    }

    while (hayDatoB) {  // Mientas aun queden datos en archivoB
        archivoC << datoB << endl;  // Escribir el dato más pequeño en el archivo de salida
        hayDatoB = bool (archivoB >> datoB);    // Lee el siguiente dato del archivoB
    }

    archivoA.close();
    archivoB.close();
    archivoC.close();
}
