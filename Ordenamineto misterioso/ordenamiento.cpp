#include "ordenamiento.h"

Nodo* Ordenamiento::fusionarListas(Nodo* izquierda, Nodo* derecha) { 
    // Si una de las listas es nula, devuelve la otra lista
    if (izquierda == nullptr) 
        return derecha;
    if (derecha == nullptr) 
        return izquierda;

    Nodo* cabeza = nullptr;  // Puntero a la cabeza de la lista fusionada
    Nodo* actual = nullptr;  // Puntero al nodo actual en la lista fusionada

    if (izquierda->registro->dato <= derecha->registro->dato) {    // Inicializar la cabeza de la lista fusionada
        cabeza = izquierda;                 // La cabeza es el primer nodo de la lista izquierda
        izquierda = izquierda->siguiente;   // Avanzar al siguiente nodo en la lista izquierda
    } else {
        cabeza = derecha;                   // La cabeza es el primer nodo de la lista derecha
        derecha = derecha->siguiente;       // Avanzar al siguiente nodo en la lista derecha
    }

    actual = cabeza;  // Inicializar el nodo actual

    while (izquierda != nullptr && derecha != nullptr) {     // Fusionar las listas 
        if (izquierda->registro->dato <= derecha->registro->dato) {
            actual->siguiente = izquierda;          // El siguiente nodo en la lista fusionada es de la lista izquierda
            izquierda = izquierda->siguiente;       // Avanzar al siguiente nodo en la lista izquierda
        } else {
            actual->siguiente = derecha;            // El siguiente nodo en la lista fusionada es de la lista derecha
            derecha = derecha->siguiente;           // Avanzar al siguiente nodo en la lista derecha
        }
        actual = actual->siguiente;             // Avanzar al siguiente nodo en la lista fusionada
    }

    if (izquierda != nullptr) {
        actual->siguiente = izquierda; // Si quedan nodos en la lista izquierda, añadirlos a la lista fusionada
    } else {
        actual->siguiente = derecha;   // Si quedan nodos en la lista derecha, añadirlos a la lista fusionada
    }

    return cabeza;  // Devolver la cabeza de la lista fusionada
}

Nodo* Ordenamiento::ordenamientoMisterio(Nodo* lista) {
    if (lista == nullptr || lista->siguiente == nullptr) {       // Caso base
        return lista;
    }

    // Dividir la lista en dos mitades
    Nodo* mitadIzquierda = lista;
    Nodo* mitadDerecha = lista->siguiente;
    while (mitadDerecha != nullptr && mitadDerecha->siguiente != nullptr) {
        lista = lista->siguiente;
        mitadDerecha = mitadDerecha->siguiente->siguiente;
    }
    mitadDerecha = lista->siguiente;
    lista->siguiente = nullptr;  // Separar las dos mitades

    // Llamadas recursivas para ordenar ambas mitades
    Nodo* izquierdaOrdenada = ordenamientoMisterio(mitadIzquierda);
    Nodo* derechaOrdenada = ordenamientoMisterio(mitadDerecha);

    // Fusionar las listas ordenadas
    return fusionarListas(izquierdaOrdenada, derechaOrdenada);
}
