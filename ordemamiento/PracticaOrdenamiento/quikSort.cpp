#include <iostream>
#include "ListaDoble.h"

using namespace std;

Nodo* particion(Nodo* bajo, Nodo* alto) {
    int aux;
    int pivote = alto->dato;
    Nodo* i = bajo->anterior;

    for (Nodo* j = bajo; j != alto; j = j->siguiente) {
        if (j->dato <= pivote) {
            if (i == NULL) {
                i = bajo;
            } else {
                i = i->siguiente;
            }
            aux = i->dato;
            i->dato = j->dato;
            j->dato = aux;
        }
    }

    if (i == NULL) {
        i = bajo;
    } else {
        i = i->siguiente;
    }
    aux = i->dato;
    i->dato = alto->dato;
    alto->dato = aux;
    return i;
}

void quickSort(Nodo* bajo, Nodo* alto) {
    if (alto != NULL && bajo != alto && bajo != alto->siguiente) {
        Nodo* nodoPivote = particion(bajo, alto);
        quickSort(bajo, nodoPivote->anterior);
        quickSort(nodoPivote->siguiente, alto);
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