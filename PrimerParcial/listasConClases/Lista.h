#include<stdio.h>
#include<stdlib.h>
#include "Nodo.h"
using namespace std;

class Lista{
    public:
        Nodo* cabeza;
    public:
        Lista(){
            cabeza = NULL;
        }
    void insertarInicio(int dato);
    void mostrarLista();
    void insetarFinal(int dato);
};

void Lista::insertarInicio(int dato){
    Nodo* nuevoNodo = new Nodo(dato);
    nuevoNodo->siguiente = cabeza;
    nuevoNodo->anterior = NULL;
    cabeza = nuevoNodo;
}

void Lista::insetarFinal(int dato){
    Nodo* nuevoNodo = new Nodo(dato);
    Nodo* actual = cabeza;
    nuevoNodo->dato = dato;
    if(cabeza == NULL){
        printf("La lista se encontraba vacia \n");
        nuevoNodo->siguiente = cabeza;
        nuevoNodo->anterior = NULL;
        cabeza = nuevoNodo;
    } else{
        while(actual->siguiente != NULL){
            actual = actual->siguiente;
        }
        if(actual != NULL){
            nuevoNodo->siguiente = actual->siguiente;
            nuevoNodo->anterior = actual;
            actual->siguiente = nuevoNodo;
        }
    }
}

void Lista::mostrarLista(){
    Nodo* actual = cabeza;
    if (cabeza == NULL){
        printf("La lista esta vacia");
    } else {
        while(actual != NULL){
            printf("%d\n", actual->dato);
            actual = actual->siguiente; 
        }
    }
}