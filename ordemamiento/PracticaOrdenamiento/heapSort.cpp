#include <iostream>
#include "lista.h"

using namespace std;

Nodo* obtenerNodoEnPosicion(Nodo* cabeza, int posicion) {
    Nodo* actual = cabeza;
    for (int i = 0; actual != NULL && i < posicion; i++) {
        actual = actual->siguiente;
    }
    return actual;
}

void heapify(Nodo* cabeza, int n, int i) {
    int mayor = i;
    int izquierda = 2 * i + 1;
    int derecha = 2 * i + 2;

    Nodo* nodoMayor = obtenerNodoEnPosicion(cabeza, mayor);
    Nodo* nodoIzquierda = obtenerNodoEnPosicion(cabeza, izquierda);
    Nodo* nodoDerecha = obtenerNodoEnPosicion(cabeza, derecha);

    if (izquierda < n && nodoIzquierda->dato > nodoMayor->dato) {
        mayor = izquierda;
        nodoMayor = nodoIzquierda;
    }

    if (derecha < n && nodoDerecha->dato > nodoMayor->dato) {
        mayor = derecha;
        nodoMayor = nodoDerecha;
    }

    if (mayor != i) {
        Nodo* nodoActual = obtenerNodoEnPosicion(cabeza, i);
        int temp = nodoActual->dato;
        nodoActual->dato = nodoMayor->dato;
        nodoMayor->dato = temp;
        heapify(cabeza, n, mayor);
    }
}

void heapSort(Nodo* cabeza) {
    if (cabeza == NULL) return;

    int n = 0;
    Nodo* actual = cabeza;
    while (actual != NULL) {
        n++;
        actual = actual->siguiente;
    }

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(cabeza, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        Nodo* nodoInicial = obtenerNodoEnPosicion(cabeza, 0);
        Nodo* nodoFinal = obtenerNodoEnPosicion(cabeza, i);
        int temp = nodoInicial->dato;
        nodoInicial->dato = nodoFinal->dato;
        nodoFinal->dato = temp;
        heapify(cabeza, i, 0);
    }
}

int main() {
    Lista lista;

    lista.insertarFinal(5);
    lista.insertarFinal(1);
    lista.insertarFinal(8);
    lista.insertarFinal(3);
    lista.insertarFinal(7);

    cout << "Lista antes de ordenar:" << endl;
    lista.mostrarLista();

    heapSort(lista.cabeza);

    cout << "Lista despues de ordenar:" << endl;
    lista.mostrarLista();

    return 0;
}
