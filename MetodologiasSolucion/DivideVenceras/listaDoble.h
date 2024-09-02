#ifndef LISTADOBLE_H
#define LISTADOBLE_H

#include "Nodo.h"
#include <iostream>
using namespace std;

class ListaDoble {
public:
    Nodo* cabeza;
public:
    ListaDoble() {
        cabeza = NULL;
    }
    void insertarInicio(int dato);
    void mostrarLista();
    void insertarFinal(int dato);
};

void ListaDoble::insertarInicio(int dato) {
    Nodo* nuevoNodo = new Nodo(dato);
    nuevoNodo->siguiente = cabeza;
    if (cabeza != NULL) {
        cabeza->anterior = nuevoNodo;
    }
    cabeza = nuevoNodo;
}

void ListaDoble::insertarFinal(int dato) {
    Nodo* nuevoNodo = new Nodo(dato);
    if (cabeza == NULL) {
        printf("La lista se encontraba vacia \n");
        cabeza = nuevoNodo;
    } else {
        Nodo* actual = cabeza;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo;
        nuevoNodo->anterior = actual;
    }
}

void ListaDoble::mostrarLista() {
    Nodo* actual = cabeza;
    if (cabeza == NULL) {
        printf("La lista esta vacia");
    } else {
        while (actual != NULL) {
            printf("%d ", actual->dato);
            actual = actual->siguiente;
        }
    }
}

#endif
