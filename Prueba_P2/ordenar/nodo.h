#ifndef NODO_H
#define NODO_H

class Nodo {
public:
    float dato;
    Nodo* siguiente;

    Nodo(float d) {
        dato = d;
        siguiente = nullptr;
    }
};

#endif
