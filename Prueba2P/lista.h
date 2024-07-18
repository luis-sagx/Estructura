#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include "nodo.h"

class Lista {
public:
    Nodo* cabeza;
public:
    Lista() {
        cabeza = nullptr;
    }

    void insertarInicio(float dato);
    void insertarFinal(float dato);
    void mostrarLista();
    void limpiar();
};

void Lista::insertarInicio(float dato) {
    Nodo* nuevoNodo = new Nodo(dato);
    nuevoNodo->siguiente = cabeza;
    cabeza = nuevoNodo;
}

void Lista::insertarFinal(float dato) {
    Nodo* nuevoNodo = new Nodo(dato);
    if (cabeza == nullptr) {
        cabeza = nuevoNodo;
    } else {
        Nodo* actual = cabeza;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo;
    }
}

void Lista::mostrarLista() {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        printf("%f ", actual->dato);
        actual = actual->siguiente;
    }
    printf("\n");
}

void Lista::limpiar() {
    while (cabeza) {
        Nodo* actual = cabeza;
        cabeza = cabeza->siguiente;
        delete actual;
    }
}

#endif
