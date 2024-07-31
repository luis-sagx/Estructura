#ifndef _NODO_H
#define _NODO_H
using namespace std;

class Nodo{
    public:
        int dato;
        Nodo* siguiente;
        Nodo* anterior;

    Nodo(int d){
        dato = d;
        siguiente = 0;  //0 es el puntero NULL en c++
        anterior = 0;
    }
    Nodo(int d, Nodo* sig, Nodo* ant){
        dato = d;
        siguiente = sig;
        anterior = ant;
    }
};

#endif 