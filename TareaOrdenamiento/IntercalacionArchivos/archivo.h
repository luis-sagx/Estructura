#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool leerArchivo(ifstream& archivo, const string& nombreArchivo) { //funcion para abrir un archivo para lectura
    archivo.open(nombreArchivo); // Abre el archivo para lectura
    if (!archivo.is_open()) { // Verifica si el archivo se abrió correctamente
        cout << "Error, NO se abrió el archivo " << nombreArchivo << endl; // imprime un mensaje de error si el archivo no se abrio
        return false;
    }
    return true;
}

bool escribirArchivo(ofstream& archivo, const string& nombreArchivo) { // Función para abrir un archivo para escritura
    archivo.open(nombreArchivo); // Abre el archivo para escritura
    if (!archivo.is_open()) { // Verifica si el archivo se abrió correctamente
        cout << "Error, NO se abrió el archivo " << nombreArchivo << endl; // imprime un mensaje de error si el archivo no se abrio
        return false;
    }
    return true;
}
