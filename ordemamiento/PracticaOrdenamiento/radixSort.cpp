#include <iostream>
#include "lista.h"
using namespace std;

int obtenerDigito(int numero, int exp) {
    return (numero / exp) % 10;
}

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
            int digito = obtenerDigito(actual->dato, exp);
            listas[digito].insertarFinal(actual->dato);
            actual = actual->siguiente;
        }

        lista.limpiar();
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
    lista.mostrarLista();
    radixSort(lista);

    cout << "Lista ordenada: ";
    lista.mostrarLista();

    return 0;
}
