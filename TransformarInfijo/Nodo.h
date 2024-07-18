#ifndef _NODO_H
#define _NODO_H

class Nodo{
    public:
        char simbolo;
        Nodo* siguiente;
    Nodo(char s){
        simbolo = s;
        siguiente = 0;
    }
    Nodo(char s, Nodo* sig){
        simbolo = s;
        siguiente = sig;
    }
};

#endif 