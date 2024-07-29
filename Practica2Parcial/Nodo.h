#ifndef NODO_H
#define NODO_H

class Nodo {
    public:
        int dato;
        Nodo* siguiente;

        Nodo(int d){
            dato = d;
        }
};

#endif