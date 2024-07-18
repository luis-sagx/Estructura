#ifndef LISTA
#define LISTA_H

#include <iostream>
#include "nodo.h"
using namespace std;

class Lista{
    public:
        Nodo* cabeza;
    public:
        Lista(){
            cabeza = NULL;
        }
    void insertar(int dato);
    void mostrarLista();
    int obtenerMaximo();
    void limpiar();
    void concatenar(Lista& otraLista);
};

void Lista::insertar(int dato){
    Nodo* nuevoNodo = new Nodo(dato);
        if (!cabeza) {
            cabeza = nuevoNodo;
        } else {
            Nodo* temp = cabeza;
            while (temp->siguiente) {
                temp = temp->siguiente;
            }
            temp->siguiente = nuevoNodo;
        }
}

void Lista::mostrarLista(){
    Nodo* temp = cabeza;
        while (temp) {
            cout << temp->dato << " ";
            temp = temp->siguiente;
        }
        cout << endl;
}

int Lista::obtenerMaximo() {
    if (!cabeza) return 0;
    int maxVal = cabeza->dato;
    Nodo* temp = cabeza->siguiente;
    while (temp) {
        if (temp->dato > maxVal) {
            maxVal = temp->dato;
        }
        temp = temp->siguiente;
    }
    return maxVal;
}

void Lista::limpiar() {
    while (cabeza) {
        Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }
}

void Lista:: concatenar(Lista& otraLista) {
    if (!cabeza) {
        cabeza = otraLista.cabeza;
    } else {
        Nodo* temp = cabeza;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        temp->siguiente = otraLista.cabeza;
    }
    otraLista.cabeza = NULL;
}

#endif
