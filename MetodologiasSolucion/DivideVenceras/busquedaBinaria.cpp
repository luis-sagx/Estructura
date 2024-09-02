#include <iostream>
using namespace std;

int busquedaBinaria(int arr[], int n, int valor) {
    int izquierda = 0;
    int derecha = n - 1;

    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;

        if (arr[medio] == valor) {
            return medio; // Retorna el índice donde se encontró el valor
        }
        if (arr[medio] < valor) {
            izquierda = medio + 1; // Ignorar la mitad izquierda
        } else {
            derecha = medio - 1; // Ignorar la mitad derecha
        }
    }

    return -1; // Retorna -1 si el valor no se encuentra en el arreglo
}

int main(){
    int a[] = {1,2,3,4,5,6,7,8,9,22,44,66};
    int size = sizeof(a)/sizeof(a[0]);
    int clave = 8;
    int resultado = busquedaBinaria(a, size, clave);

    // Mostrar el resultado
    if (resultado != -1) {
        cout << "Valor encontrado en el índice: " << resultado << endl;
    } else {
        cout << "Valor no encontrado en el arreglo." << endl;
    }

}