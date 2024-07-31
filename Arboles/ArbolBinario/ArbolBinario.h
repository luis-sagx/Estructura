#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H

#include "Nodo.h"
#include <iostream>

using namespace std;

class ArbolBinario {
public:
    Nodo* raiz;

    ArbolBinario(int valorRaiz){
        raiz = new Nodo(valorRaiz);
    }

    void insertar(int dato);
    void recorrerInorden(Nodo* raiz);
    void recorrerPostorden(Nodo* raiz);
    void recorrerPreorden(Nodo* raiz);
};

void ArbolBinario::insertar(int dato) {
    if (raiz == nullptr) {
        raiz = new Nodo(dato);
    } else {
        Nodo* actual = raiz;
        Nodo* padre = nullptr;
        while (actual != nullptr) {
            padre = actual;
            if (dato == actual->dato) {
                cout << "El dato " << dato << " se encuentra repetido, ingrese otro dato" << endl;
                return;
            }
            if (dato < actual->dato) {
                actual = actual->izquierdo;
            } else {
                actual = actual->derecho;
            }
        }
        if (dato < padre->dato) {
            padre->izquierdo = new Nodo(dato);
        } else {
            padre->derecho = new Nodo(dato);
        }
    }
}

void ArbolBinario::recorrerInorden(Nodo* nodo) {    //IRD
    if (nodo != nullptr) {
        recorrerInorden(nodo->izquierdo);
        cout << nodo->dato << " ";
        recorrerInorden(nodo->derecho);
    }
}

void ArbolBinario::recorrerPreorden(Nodo* nodo) {   //RID
    if (nodo != nullptr) {
        cout << nodo->dato << " ";
        recorrerPreorden(nodo->izquierdo);
        recorrerPreorden(nodo->derecho);
    }
}

void ArbolBinario::recorrerPostorden(Nodo* nodo) {  //IDR
    if (nodo != nullptr) {
        recorrerPostorden(nodo->izquierdo);
        recorrerPostorden(nodo->derecho);
        cout << nodo->dato << " ";
    }
}


#endif