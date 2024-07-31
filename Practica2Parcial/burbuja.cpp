#include "Lista.h"

void burbuja(Lista& lista){
    if (lista.cabeza == nullptr){
        return;
    }

    bool intercambiado;
    Nodo* actual;
    

    do{
        intercambiado = false;
        actual = lista.cabeza;
        while (actual->siguiente != nullptr){
            if (actual->dato > actual->siguiente->dato) {
                int aux = actual->dato;
                actual->dato = actual->siguiente->dato;
                actual->siguiente->dato = aux;
                intercambiado = true;
            }
            actual = actual->siguiente;
        }
        

    }while(intercambiado);

}


int main() {
    Lista lista;
    lista.insertarFinal(21);
    lista.insertarFinal(11);
    lista.insertarInicio(99);
    lista.insertarFinal(22);
    lista.insertarInicio(47);
    lista.insertarFinal(44);
    lista.insertarFinal(-1);
    lista.insertarFinal(0);
    lista.insertarFinal(25);
    lista.insertarFinal(14);

    cout << "Lista antes de ordenar: ";
    lista.imprimir();

    burbuja(lista);

    cout << "Lista después de ordenar: ";
    lista.imprimir();

    return 0;
}