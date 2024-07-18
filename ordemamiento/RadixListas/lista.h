#ifndef LISTA
#define LISTA_H

#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
    Nodo(int val) : dato(val), siguiente(nullptr) {}
};

class Lista{
    public:
        Nodo* cabeza;
    public:
        Lista(){
            cabeza = NULL;
        }
    void insertar(int dato);
    void mostrarLista();
    void limpiar();
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

void Lista::limpiar() {
    while (cabeza) {
        Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }
}
#endif
