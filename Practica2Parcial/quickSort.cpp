#include <iostream>
#include "ListaDoble.h"

using namespace std;

Nodo* particion(Nodo* primero, Nodo* ultimo) {
    int aux;
    int pivote = ultimo->dato;
    Nodo* i = primero->anterior;

    for (Nodo* j = primero; j != ultimo; j = j->siguiente) {
        if (j->dato <= pivote) {
            if (i == NULL) {
                i = primero;
            } else {
                i = i->siguiente;
            }
            aux = i->dato;
            i->dato = j->dato;
            j->dato = aux;
        }
    }

    if (i == NULL) {
        i = primero;
    } else {
        i = i->siguiente;
    }
    aux = i->dato;
    i->dato = ultimo->dato;
    ultimo->dato = aux;
    return i;
}

void quickSort(Nodo* primero, Nodo* ultimo) {
    if (ultimo != NULL && primero != ultimo && primero != ultimo->siguiente) {
        Nodo* nodoPivote = particion(primero, ultimo);
        quickSort(primero, nodoPivote->anterior);
        quickSort(nodoPivote->siguiente, ultimo);
    }
}

Nodo* encontrarUltimo(Nodo* cabeza) {
    while (cabeza != NULL && cabeza->siguiente != NULL) {
        cabeza = cabeza->siguiente;
    }
    return cabeza;
}

int main() {
    ListaDoble lista;

    lista.insertarFinal(5);  
    lista.insertarFinal(1); 
    lista.insertarFinal(8);  
    lista.insertarFinal(3);  
    lista.insertarFinal(7);  

    cout << "Lista antes de ordenar:" << endl;
    lista.mostrarLista();

    Nodo* ultimo = encontrarUltimo(lista.cabeza);
    quickSort(lista.cabeza, ultimo);

    cout << "Lista despues de ordenar:" << endl;
    lista.mostrarLista();

    return 0;
}