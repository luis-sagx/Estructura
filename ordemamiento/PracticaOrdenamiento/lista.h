#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>

struct Nodo {
    int dato;
    Nodo* siguiente;
    Nodo(int d) {
        dato = d;
        siguiente = 0;
    }
};

class Lista {
public:
    Nodo* cabeza;
public:
    Lista() {
        cabeza = NULL;
    }

    void insertarInicio(int dato);
    void insertarFinal(int dato);
    void mostrarLista();
    void limpiar();
};

void Lista::insertarInicio(int dato) {
    Nodo* nuevoNodo = new Nodo(dato);
    nuevoNodo->siguiente = cabeza;
    cabeza = nuevoNodo;
}

void Lista::insertarFinal(int dato) {
    Nodo* nuevoNodo = new Nodo(dato);
    if (cabeza == NULL) {
        cabeza = nuevoNodo;
    } else {
        Nodo* actual = cabeza;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo;
    }
}

void Lista::mostrarLista() {
    Nodo* actual = cabeza;
    while (actual != NULL) {
        printf("%d ", actual->dato);
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
