#include <iostream>
#include "Nodo.h"

using namespace std;

Nodo* insertar(Nodo* raiz, int dato) {
    if (raiz == nullptr) {
        return new Nodo(dato);
    }

    if (dato < raiz->dato) {
        raiz->izquierdo = insertar(raiz->izquierdo, dato);
    } else {
        raiz->derecho = insertar(raiz->derecho, dato);
    }

    return raiz;
}

void recorrerInorden(Nodo* raiz) {
    if (raiz != nullptr) {
        recorrerInorden(raiz->izquierdo);
        cout << raiz->dato << " ";
        recorrerInorden(raiz->derecho);
    }
}

void recorrerPreorden(Nodo* raiz) {
    if (raiz != nullptr) {
        cout << raiz->dato << " ";
        recorrerPreorden(raiz->izquierdo);
        recorrerPreorden(raiz->derecho);
    }
}

void recorrerPostorden(Nodo* raiz) {
    if (raiz != nullptr) {
        recorrerPostorden(raiz->izquierdo);
        recorrerPostorden(raiz->derecho);
        cout << raiz->dato << " ";
    }
}

void eliminarArbol(Nodo* raiz) {
    if (raiz != nullptr) {
        eliminarArbol(raiz->izquierdo);
        eliminarArbol(raiz->derecho);
        delete raiz;
    }
}

int main() {
    Nodo* raiz = nullptr;

    // Insertar algunos valores en el árbol
    raiz = insertar(raiz, 10);
    insertar(raiz, 1);
    insertar(raiz, 2);
    insertar(raiz, 3);
    insertar(raiz, 4);
    insertar(raiz, 5);
    insertar(raiz, 6);

    cout << "Recorrido en inorden del árbol: ";
    recorrerInorden(raiz);
    cout << endl;

    cout << "Recorrido en preorden del árbol: ";
    recorrerPreorden(raiz);
    cout << endl;

    cout << "Recorrido en postorden del árbol: ";
    recorrerPostorden(raiz);
    cout << endl;

    eliminarArbol(raiz);

    return 0;
}