#include <iostream>
#include "lista.h"

using namespace std;

// Función para fusionar dos listas ordenadas
Nodo* fusionarListas(Nodo* izquierda, Nodo* derecha) {
    if (!izquierda) return derecha;
    if (!derecha) return izquierda;

    if (izquierda->dato <= derecha->dato) {
        izquierda->siguiente = fusionarListas(izquierda->siguiente, derecha);
        return izquierda;
    } else {
        derecha->siguiente = fusionarListas(izquierda, derecha->siguiente);
        return derecha;
    }
}

// Función recursiva para ordenar la lista
Nodo* mergeSort(Nodo* lista) {
    if (!lista || !lista->siguiente) {
        return lista;
    }

    // Dividir la lista en dos mitades
    Nodo* mitadIzquierda = lista;
    Nodo* mitadDerecha = lista->siguiente;
    while (mitadDerecha && mitadDerecha->siguiente) {
        lista = lista->siguiente;
        mitadDerecha = mitadDerecha->siguiente->siguiente;
    }
    mitadDerecha = lista->siguiente;
    lista->siguiente = nullptr;  // Separar las dos mitades

    // Llamadas recursivas para ordenar ambas mitades
    Nodo* izquierdaOrdenada = mergeSort(mitadIzquierda);
    Nodo* derechaOrdenada = mergeSort(mitadDerecha);

    // Fusionar las listas ordenadas
    return fusionarListas(izquierdaOrdenada, derechaOrdenada);
}

int main() {
    Lista lista;

    lista.insertarFinal(170);
    lista.insertarFinal(45);
    lista.insertarFinal(75);
    lista.insertarFinal(90);
    lista.insertarFinal(802);
    lista.insertarFinal(24);
    lista.insertarFinal(2);
    lista.insertarFinal(66);

    cout << "Lista antes de ordenar:" << endl;
    lista.mostrarLista();

    lista.cabeza = mergeSort(lista.cabeza);

    cout << "Lista despues de ordenar:" << endl;
    lista.mostrarLista();

    return 0;
}
