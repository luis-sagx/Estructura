#include <iostream>
using namespace std;

#define MAX_SIZE 100  // Define el tamaño máximo del arreglo

// Función para realizar búsqueda lineal
int busquedaLineal(int arr[], int n, int valor) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == valor) {
            return i; // Retorna el índice donde se encontró el valor
        }
    }
    return -1; // Retorna -1 si el valor no se encuentra en el arreglo
}

int main() {
    int arr[MAX_SIZE]; // Arreglo de tamaño máximo
    int n; // Tamaño real del arreglo
    int valor;

    cout << "Ingrese el tamaño del arreglo: ";
    cin >> n;
    
    // Ingreso de elementos del arreglo
    cout << "Ingrese los elementos del arreglo:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Ingresar el valor a buscar
    cout << "Ingrese el valor a buscar: ";
    cin >> valor;

    // Llamada a la función de búsqueda lineal
    int resultado = busquedaLineal(arr, n, valor);

    // Mostrar el resultado
    if (resultado != -1) {
        cout << "Valor encontrado en el índice: " << resultado << endl;
    } else {
        cout << "Valor no encontrado en el arreglo." << endl;
    }

    return 0;
}
