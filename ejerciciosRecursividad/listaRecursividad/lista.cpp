#include <stdio.h>
#include <stdlib.h>

struct nodo{
    int id;
    int dato;
    nodo *siguiente;
};

nodo *cabeza = NULL;

void insertarNodo(int dato){
    nodo *nuevoNodo = (nodo*)malloc(sizeof(nodo));
    nuevoNodo->id = 1;
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = cabeza;
    cabeza = nuevoNodo;
}

void imprimir(nodo *actual){
    if(actual == NULL)
        return;
    printf("Id: %d, Dato: %d\n", actual->id, actual->dato);
    imprimir(actual->siguiente);
}

int main(){
    insertarNodo(300);
    insertarNodo(200);
    insertarNodo(100);
    imprimir(cabeza);
    return 0;
}