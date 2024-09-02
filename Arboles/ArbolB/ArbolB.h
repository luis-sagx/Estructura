#ifndef ARBOLB_H
#define ARBOLB_H

#include "Nodo.h"

class ArbolB{
    private:
    Nodo* raiz;   // Puntero a la raíz del árbol B
    int grado;    // Grado mínimo del árbol B

    public:
    ArbolB(int grado) {
        this->grado = grado;
        raiz = nullptr;
    }

    void insertar(int k);
    void recorrer() {
        if (raiz != nullptr) recorrer(raiz);
    }

    void eliminar(int k);

    private:
    void recorrer(Nodo* nodo) {
        int i;
        for (i = 0; i < nodo->numClaves; i++) {
            if (!nodo->esHoja)
                recorrer(nodo->hijos[i]);
            cout << " " << nodo->claves[i];
        }

        if (!nodo->esHoja)
            recorrer(nodo->hijos[i]);
    }
};

void ArbolB::insertar(int k) {
    if (raiz == nullptr) {
        raiz = new Nodo(grado, true);
        raiz->claves[0] = k;
        raiz->numClaves = 1;
    } else {
        if (raiz->numClaves == 2 * grado) {
            Nodo* s = new Nodo(grado, false);  // Corregido: se crea el nodo con el grado y especificando si es hoja
            s->hijos[0] = raiz;

            s->dividirHijo(0, raiz, grado);

            int i = 0;
            if (s->claves[0] < k)
                i++;
            s->hijos[i]->insertarNoLleno(k, grado);

            raiz = s;
        } else {
            raiz->insertarNoLleno(k, grado);
        }
    }
}

void ArbolB::eliminar(int k) {
    if (!raiz) {
        cout << "El árbol está vacío.\n";
        return;
    }

    raiz->eliminar(k, grado);

    if (raiz->numClaves == 0) {
        Nodo* tmp = raiz;
        if (raiz->esHoja)
            raiz = nullptr;
        else
            raiz = raiz->hijos[0];

        delete tmp;
    }
}

#endif