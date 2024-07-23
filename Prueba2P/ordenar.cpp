#include <stdio.h>
#include <iostream>
#include "lista.h"

void obtenerIndice(float a[], int size, int b[]) {
    for (int i = 0; i < size; i++) {
        b[i] = a[i] * size;
    }
}

void ordenar(float a[], int size, int b[]) {
    Lista listas[10];
    int j = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == b[j]) {
                listas[i].insertarFinal(a[j]);
            }
        }
    }

    for (int i = 0; i < size; i++) {
        Nodo* actual = listas[i].cabeza;
        while (actual != nullptr) {
            Nodo* siguiente = actual->siguiente; 
            while (siguiente != nullptr) { 
                if (actual->dato > siguiente->dato) {
                    float aux = actual->dato;
                    actual->dato = siguiente->dato;
                    siguiente->dato = aux;
                }
                siguiente = siguiente->siguiente; 
            }
            actual = actual->siguiente; 
        }
    }

    for (int i = 0; i < size; i++) {
        Nodo* actual = listas[i].cabeza;
        while (actual != nullptr) {
            a[j++] = actual->dato;
            actual = actual->siguiente;
            if (actual == nullptr){
                break;
            }
        }
    }
}

void imprimir(float a[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%f ", a[i]);
    }
    printf("\n");
}

int main() {
    float a[] = {0.28, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    int size = sizeof(a) / sizeof(a[0]);
    int b[size];
    printf("Arreglo desordenado: ");
    imprimir(a, size);
    obtenerIndice(a, size, b);
    ordenar(a, size, b);
    printf("Arreglo ordenado: ");
    imprimir(a, size);
    return 0;
}
