#include <iostream>
#include <fstream>
#include <cstdio> // Para remove()

using namespace std;

void dividirArchivo(const string& nombreArchivo, const string& archivoSalida1, const string& archivoSalida2) { // Divide el archivo en dos archivos temporales
    ifstream archivoEntrada(nombreArchivo);  // Se abre el archivo de entrada para lectura
    ofstream salida1(archivoSalida1);        // Se abre los archivos de salida para escritura
    ofstream salida2(archivoSalida2);        

    if (!archivoEntrada.is_open()) {        // Verifica si el archivo de entrada se abrió correctamente
        cout << "Error, NO se abrió el archivo: " << nombreArchivo << endl;
        return;     // Si no se abrio sale de la funcion 
    }

    int dato;
    bool escribirEnPrimero = true; // Para alternar la escritura entre los dos archivos de salida
    while (archivoEntrada >> dato) {     //Lee cada dato del archivo de entrada
        if (escribirEnPrimero)
            salida1 << dato << endl;    // Escribe el dato en el archivo de salida 1
        else
            salida2 << dato << endl;    // Escribe el dato en el archivo de salida 2
        escribirEnPrimero = !escribirEnPrimero; // Se alterna el archivo de salida 2
    }
    archivoEntrada.close();     // Se cierran los archivos
    salida1.close();
    salida2.close();
}

void mezclarArchivos(const string& archivoEntrada1, const string& archivoEntrada2, const string& archivoSalida) { //Mezclar dos archivos ordenados en uno solo
    ifstream entrada1(archivoEntrada1);  // Abre los archivos de entrada para lectura
    ifstream entrada2(archivoEntrada2);
    ofstream salida(archivoSalida);      // Abre el archivo de salida para escritura

    if (!entrada1.is_open() || !entrada2.is_open()) {     // Se verifica si los archivos de entrada se abrieron correctamente
        cout << "Error, NO se abrieron los archivos de entrada." << endl;
        return;
    }

    int dato1, dato2;
    bool hayDato1 = bool(entrada1 >> dato1);     // Se lee el primer dato del archivo 1
    bool hayDato2 = bool(entrada2 >> dato2);     // Se lee el primer dato del archivo 1

    while (hayDato1 && hayDato2) {     // Se mezcla los datos de los dos archivos de entrada en el archivo de salida
        if (dato1 < dato2) {
            salida << dato1 << endl;
            hayDato1 = bool(entrada1 >> dato1); // Lee el siguiente dato del archivo de entrada 1
        } else {
            salida << dato2 << endl;
            hayDato2 = bool(entrada2 >> dato2); // Lee el siguiente dato del archivo de entrada 2
        }
    }

    while (hayDato1) {  // Mientas haya datos restantes en el archivo 1 se pone en el archivo de salida
        salida << dato1 << endl;
        hayDato1 = bool(entrada1 >> dato1);     
    }

    while (hayDato2) {  // Mientas haya datos restantes en el archivo 1 se pone en el archivo de salida
        salida << dato2 << endl;
        hayDato2 = bool(entrada2 >> dato2);
    }

    entrada1.close();       // Se cierran los archivos
    entrada2.close();
    salida.close();
}

void mergeSort(const string& nombreArchivo) {   // Se aplica mezcla directa con 2 archivos temporales
    const string archivoTemporal1 = "archivos/datosTemp1.txt";
    const string archivoTemporal2 = "archivos/datosTemp2.txt";

    bool ordenado = false;

    while (!ordenado) {     //Mientras el archivo no este ordenado se divide y se mezcla
        dividirArchivo(nombreArchivo, archivoTemporal1, archivoTemporal2);  // Se llama a la funcion que divide el archivo original en dos archivos temporales
        mezclarArchivos(archivoTemporal1, archivoTemporal2, nombreArchivo);  // Se llama a la funcion que mezcla los archivos temporales en el archivo original


        // Comprobar si el archivo está ordenado
        ifstream archivoComprobacion(nombreArchivo);
        int datoActual, datoAnterior;
        bool estaOrdenado = true;
        archivoComprobacion >> datoAnterior;
        while (archivoComprobacion >> datoActual) {  // Se recorre el archivo y se lee los datos para verificar si esta ordenado
            if (datoActual < datoAnterior) {
                estaOrdenado = false;   //Si algun dato no esta ordenado se establece al booleano como falso
                break;
            }
            datoAnterior = datoActual;
        }
        archivoComprobacion.close();

        ordenado = estaOrdenado;   // Se le asigna el valor del booleano del bucle interno 
    }

    remove(archivoTemporal1.c_str());     // Se eliminan los archivos temporales
    remove(archivoTemporal2.c_str());
}
