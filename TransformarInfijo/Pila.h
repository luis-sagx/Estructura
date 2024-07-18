#include<iostream>
#include<stdlib.h>
#include "Nodo.h"
using namespace std;

class Pila{
    private:
        Nodo* cima;
    public:
        Pila(){
            cima = 0;
        }
    bool estaVacia();
    void apilar(char simbolo);
    char desapilar();
    char obtenerCima();
};

bool Pila::estaVacia(){
    return cima == NULL;
}

void Pila::apilar(char simbolo){
    Nodo* nuevoNodo = new Nodo(simbolo);
    nuevoNodo->siguiente = cima;
    cima = nuevoNodo;
}

char Pila::desapilar(){
    if(estaVacia()){
        printf("La pila esta vacia");
        exit(EXIT_FAILURE);
    } else{
        Nodo* actual = cima;
        char simbolo = actual->simbolo;
        cima = cima->siguiente;
        delete(actual);
        return simbolo;
    }
}

char Pila::obtenerCima(){
    if(estaVacia()){
        printf("La pila esta vacia");
        exit(EXIT_FAILURE);
    } else{
        return cima->simbolo;
    }
}

