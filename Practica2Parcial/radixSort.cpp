#include <iostream>
#include "lista.h"
using namespace std;

int obtenerMaximo(Lista& lista) {
    Nodo* actual = lista.cabeza;
    int maximo = actual->dato;
    while (actual != NULL) {
        if (actual->dato > maximo) {
            maximo = actual->dato;
        }
        actual = actual->siguiente;
    }
    return maximo;
}

void radixSort(Lista& lista) {
    int maxNumero = obtenerMaximo(lista);
    for (int exp = 1; maxNumero / exp > 0; exp *= 10) {
        Lista listas[10];
        
        Nodo* actual = lista.cabeza;
        while (actual != NULL) {
            int digito = (actual->dato / exp) % 10;
            listas[digito].insertarFinal(actual->dato);
            actual = actual->siguiente;
        }

        while (lista.cabeza) {
            Nodo* actual = lista.cabeza;
            lista.cabeza = lista.cabeza->siguiente;
            delete actual;
        }

        for (int i = 0; i < 10; i++) {
            if (!lista.cabeza) {
                lista.cabeza = listas[i].cabeza;
            } else {
                Nodo* actual = lista.cabeza;
                while (actual->siguiente != NULL) {
                    actual = actual->siguiente;
                }
                actual->siguiente = listas[i].cabeza;
            }
            listas[i].cabeza = NULL;
        }
        
    }
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

    cout << "Lista original: ";
    lista.imprimir();
    radixSort(lista);

    cout << "Lista ordenada: ";
    lista.imprimir();

    return 0;
}
