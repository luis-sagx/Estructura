#ifndef NODO
#define NODO_H

#include <iostream>

class Nodo{
    public:
        int dato;
        Nodo* siguiente;
        Nodo(int d){
            dato = d;
            siguiente = 0;
        }
};

#endif // NODO
