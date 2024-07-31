#include "lista.h"

void seleccion(Lista lista){
    if (lista.cabeza == nullptr){
        cout << "La lista esta vacia";
        return;
    }

    Nodo *actual = lista.cabeza;
    
    while(actual != nullptr){
        Nodo *temp = actual->siguiente;
        Nodo *min = actual;
        while(temp != nullptr){
            if (min->dato > temp->dato){
                min = temp;
            }
            temp = temp->siguiente;
        }

        if(min != actual){
            int aux = actual->dato;
            actual->dato = min->dato;
            min->dato = aux;
        }

        actual = actual->siguiente;
    }
}

int main(){
    Lista lista;
    
    lista.insertarFinal(1);
    lista.insertarFinal(55);
    lista.insertarFinal(33);
    lista.insertarFinal(12);
    lista.insertarFinal(0);
    lista.insertarFinal(69); 
    lista.insertarFinal(2);
    lista.insertarFinal(-11);

    cout << "Lista desordenada: ";
    lista.imprimir();
    cout << "Lista ordenada: ";
    seleccion(lista);
    lista.imprimir();

    return 0;
}