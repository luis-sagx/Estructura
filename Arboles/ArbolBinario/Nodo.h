#ifndef NODO_H
#define NODO_H

class Nodo {
public:
    int dato;
    Nodo* izquierdo;
    Nodo* derecho;

    Nodo(int datoNodo){
        dato = datoNodo;
        izquierdo = 0;
        derecho = 0;
    } 
};

#endif