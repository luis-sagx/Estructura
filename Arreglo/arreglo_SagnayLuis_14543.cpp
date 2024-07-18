#include <iostream>

using namespace std;

void imprimirArreglo(int arreglo[], int longitud) {
    for (int i = 0; i < longitud; ++i) {
        cout << arreglo[i] << " ";
    }
    cout << endl;
}

int buscarNumeroEnArreglo(int arreglo[], int longitud, int numero) {
    for (int i = 0; i < longitud; ++i) {
        if (arreglo[i] == numero) {
            return i;
        }
    }
    return -1;
}

int validarIndiceModificar(int indice){
    while(indice < 1 || indice > 3){
        cout << "Indice invalido \nIngresar un indice valido: ";
        cin >> indice;
    }
    return indice;
}

int validarIndiceEliminar(int indice){
    while(indice < 0 || indice > 4){
        cout << "Indice invalido \nIngresar un indice valido: ";
        cin >> indice;
    }
    return indice;
}

int main() {
    int arreglo[5] = {1, 2, 3, 4, 5};
    int indice;

    cout << "Arreglo Inicial:" << endl;
    imprimirArreglo(arreglo, 5);

    cout << "Ingrese un numero para la primera posicion del arreglo: ";
    cin >> arreglo[0];

    cout << "Ingrese un indice para modificar [1-3]: ";
    cin >> indice;
    indice = validarIndiceModificar(indice);

    cout << "Ingrese un numero para colocar en el indice [" << indice << "] : ";
    cin >> arreglo[indice];

    cout << "Ingrese un numero para colocar en el indice [" << (indice + 1) << "] : ";
    cin >> arreglo[indice + 1];

    cout << "Ingrese un numero para colocar en el indice [" << (indice - 1) << "] : ";
    cin >> arreglo[indice - 1];

    cout << "Ingrese el indice que desea eliminar [0-4]: ";
    cin >> indice;
    indice = validarIndiceEliminar(indice);

    for (int i = indice; i < 4; ++i) {
        arreglo[i] = arreglo[i + 1];
    }

    int buscarNumero;
    cout << "Ingrese el numero que desea buscar: ";
    cin >> buscarNumero;
    int indiceEncontrado = buscarNumeroEnArreglo(arreglo, 4, buscarNumero);
    if (indiceEncontrado != -1) {
        cout << "El numero " << buscarNumero;
        cout << " se encuentra en el indice " << indiceEncontrado << endl;
    } else {
        cout << "El numero " << buscarNumero;
        cout << "\bno se encuentra en el arreglo" << endl;
    }

    cout << "Arreglo Final:" << endl;
    imprimirArreglo(arreglo, 4);

    return 0;
}
