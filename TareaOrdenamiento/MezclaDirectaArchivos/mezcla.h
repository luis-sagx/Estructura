#include <iostream>
#include <fstream>
#include <string>

#define MAX_SIZE 100

using namespace std;

void ordenamientoInsercion(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int clave = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > clave) {
            arr[j + 1] = arr[j];        // Se mueven los elementos que son mayores que la clave a una posición adelante de su posición actual
            j--;
        }
        arr[j + 1] = clave;
    }
}

void dividirYOrdenar(const string& nombreArchivoEntrada) {    // Dividir el archivo en fragmentos más pequeños y ordenarlos
    ifstream archivoEntrada(nombreArchivoEntrada); // Se abre el archivo de entrada
    if (!archivoEntrada.is_open()) {
        cout << "Error al abrir el archivo de entrada." << endl;
        return;
    }

    int fragmento[MAX_SIZE]; // Arreglo para almacenar el fragmento
    int numero, contador = 0, indiceFragmento = 0;

    while (archivoEntrada >> numero) {  // Se leen números y se escriben fragmentos ordenados en archivos temporales
        fragmento[contador++] = numero; // Se lee el número y se almacena en el fragmento
        if (contador == MAX_SIZE) { // Se verifica si el fragmento está lleno
            ordenamientoInsercion(fragmento, contador); // Se ordena el fragmento
            ofstream archivoSalida("temp" + to_string(indiceFragmento++) + ".txt"); // Se crea el archivo temporal
            for (int i = 0; i < contador; ++i) {
                archivoSalida << fragmento[i] << endl; // Se escribe el fragmento ordenado en el archivo temporal
            }
            contador = 0; // Se reinicia el contador
        }
    }

    if (contador > 0) {
        ordenamientoInsercion(fragmento, contador); // Se ordena el fragmento restante
        ofstream archivoSalida("temp" + to_string(indiceFragmento) + ".txt"); // Se crea el archivo temporal
        for (int i = 0; i < contador; ++i) {
            archivoSalida << fragmento[i] << endl; // Se escribe el fragmento ordenado en el archivo temporal
        }
    }

    archivoEntrada.close(); // Se cierra el archivo de entrada
}

// Función para mezclar dos archivos ordenados
void mezclarArchivos(const string& archivo1, const string& archivo2, const string& nombreArchivoSalida) {
    ifstream archivoA(archivo1), archivoB(archivo2); // Se abren los archivos de entrada
    ofstream archivoSalida(nombreArchivoSalida); // Se abre el archivo de salida

    if (!archivoA.is_open() || !archivoB.is_open() || !archivoSalida.is_open()) {
        cout << "Error al abrir uno de los archivos durante la mezcla." << endl;
        return;     //Se verifica que se hayan abierto los arcchivos, de no ser asi sale de la funcion
    }

    int num1, num2;
    bool hayDato1 = bool(archivoA >> num1); // Se lee el primer número del primer archivo
    bool hayDato2 = bool(archivoB >> num2); // Se lee el primer número del segundo archivo

    while (hayDato1 && hayDato2) {      // Mientras haya datos en los dos archivos, se mezclan los datos
        if (num1 < num2) {
            archivoSalida << num1 << endl; // Se escribe el numero menor en el archivo de salida
            hayDato1 = bool(archivoA >> num1); // Se lee el siguiente numero del primer archivo
        } else {
            archivoSalida << num2 << endl; // Se escribe el numero menor en el archivo de salida
            hayDato2 = bool(archivoB >> num2); // Se lee el siguiente numero del segundo archivo
        }
    }

    while (hayDato1) {      //Si hay datos en el archivo1, estos se ponen en el archivo de salida
        archivoSalida << num1 << endl;
        hayDato1 = bool(archivoA >> num1);
    }
    while (hayDato2) {      //Si hay datos en el archivo2, estos se ponen en el archivo de salida
        archivoSalida << num2 << endl;
        hayDato2 = bool(archivoB >> num2);
    }

    archivoA.close(); // Se cierran los archivos
    archivoB.close(); 
    archivoSalida.close(); 
}

void ordenarArchivoExterno(const string& nombreArchivoEntrada) {
    dividirYOrdenar(nombreArchivoEntrada); // Se divide y se ordena el archivo de entrada

    int numFragmentos = 0;
    while (true) {
        string archivoTemp = "temp" + to_string(numFragmentos) + ".txt";
        ifstream archivo(archivoTemp);
        if (!archivo.is_open()){        // Se cuenta el número de fragmentos
            break;
        } 
        archivo.close();
        numFragmentos++;
    }

    // Se mezclan los archivos temporales
    for (int i = 0; i < numFragmentos - 1; ++i) {
        string archivo1 = "temp" + to_string(i) + ".txt";
        string archivo2 = "temp" + to_string(i + 1) + ".txt";
        string nombreArchivoSalida = "temp" + to_string(i + 1) + ".txt";
        mezclarArchivos(archivo1, archivo2, nombreArchivoSalida); // Se mezclan dos fragmentos
    }

    // Se renombra el último archivo temporal a "datosOrdenados.txt"
    rename(("temp" + to_string(numFragmentos - 1) + ".txt").c_str(), "archivos/datosOrdenados.txt");
}
