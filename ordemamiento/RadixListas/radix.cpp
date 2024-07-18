#include "lista.h"
using namespace std;

// Función para obtener el dígito en una posición específica
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
        // Crear 10 listas enlazadas separadas para los dígitos 0-9
        Lista listas[10];
        
        Nodo* temp = lista.cabeza;
        while (temp != NULL) {
            int digito = obtenerDigito(temp->dato, exp);
            listas[digito].insertar(temp->dato);
            temp = temp->siguiente;
        }

        // Concatenar las listas de nuevo en la lista principal
        lista.limpiar();
        for (int i = 0; i < 10; i++) {
            if (!lista.cabeza) {
                lista.cabeza = listas[i].cabeza;
            } else {
                Nodo* temp = lista.cabeza;
                while (temp->siguiente != NULL) {
                    temp = temp->siguiente;
                }
                temp->siguiente = listas[i].cabeza;
            }
            listas[i].cabeza = NULL;
        }
        
    }
}

int main() {
    Lista lista;
    lista.insertar(170);
    lista.insertar(45);
    lista.insertar(75);
    lista.insertar(90);
    lista.insertar(802);
    lista.insertar(24);
    lista.insertar(2);
    lista.insertar(66);

    cout << "Lista original: ";
    lista.mostrarLista();
    radixSort(lista);

    cout << "Lista ordenada: ";
    lista.mostrarLista();

    return 0;
}
