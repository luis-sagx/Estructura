#include "lista.h"

void insercion(Lista& lista){
    if(lista.cabeza == nullptr){
        cout << "La lsita esta vacia"<< endl;
        return;
    }

    Nodo* ordenado = nullptr;
    Nodo* actual = lista.cabeza;

    while(actual != nullptr){
        Nodo* temp1 = actual->siguiente;
        if(ordenado == nullptr || ordenado->dato >= actual->dato){
            actual->siguiente = ordenado;
            ordenado = actual;
        } else {
            Nodo* temp2 = ordenado;
            while(temp2->siguiente != nullptr && temp2->siguiente->dato < actual->dato){
                temp2 = temp2->siguiente;
            }
            actual->siguiente = temp2->siguiente;
            temp2->siguiente = actual;
        }
        actual = temp1;
    }
    lista.cabeza = ordenado;
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
    insercion(lista);
    lista.imprimir();

    return 0;
}
