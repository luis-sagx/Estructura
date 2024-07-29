#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"
#include <iostream>

using namespace std;

class Lista{
    public: 
    Nodo* cabeza;

    Lista(){
        cabeza = nullptr;
    }

    void insertarInicio(int dato);
    void insertarFinal(int dato);
    void imprimir();

};

void Lista::insertarInicio(int dato){
    Nodo* nuevoNodo = new Nodo(dato);
    nuevoNodo->siguiente = cabeza;
    cabeza = nuevoNodo;
}

void Lista::insertarFinal(int dato){
    Nodo* nuevoNodo = new Nodo(dato);
    if (cabeza == nullptr){
        nuevoNodo->siguiente = cabeza;
        cabeza = nuevoNodo;
    } else {
        Nodo* actual = cabeza; 
        while(actual->siguiente != nullptr){
            actual = actual->siguiente;
        }
        nuevoNodo->siguiente = nullptr;
        actual->siguiente = nuevoNodo;
    }
}

void Lista::imprimir(){
    Nodo* actual = cabeza;
    while (actual != nullptr){
        cout << actual->dato << " ";
        actual = actual->siguiente;
    }

    cout << endl;
}

#endif