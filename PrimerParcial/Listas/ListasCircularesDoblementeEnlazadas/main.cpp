#include <stdio.h>
#include<stdlib.h>
#include<string.h>

struct nodo{
    char *palabra;
    nodo *siguiente;
    nodo *anterior;
};

nodo *cabeza = NULL;

void insertarInicio(const char *palabra){
    nodo *nuevoNodo = (nodo*)malloc(sizeof(nodo));
    nuevoNodo->palabra = (char*)malloc(strlen(palabra) + 1);
    strcpy(nuevoNodo->palabra, palabra);
    if(cabeza == NULL){
        nuevoNodo->anterior = nuevoNodo;
        nuevoNodo->siguiente = nuevoNodo;
    } else{
        nodo *ultimo = cabeza->anterior;
        nuevoNodo->siguiente = cabeza;
        nuevoNodo->anterior = ultimo;
        cabeza->anterior = nuevoNodo;
        ultimo->siguiente = nuevoNodo;
    }
    cabeza = nuevoNodo;
}

void insertarMedio(const char *palabra, const char *palabraAnterior){
    nodo *nuevoNodo = (nodo*)malloc(sizeof(nodo));
    nuevoNodo->palabra = (char*)malloc(strlen(palabra)+1);
    strcpy(nuevoNodo->palabra,palabra);
    if (cabeza == NULL){
        nuevoNodo->anterior = nuevoNodo;
        nuevoNodo->siguiente = nuevoNodo;
        cabeza = nuevoNodo;
    } else{
        nodo *actual = cabeza;
        do {
            if (strcmp(actual->palabra, palabraAnterior) == 0) {
                nuevoNodo->siguiente = actual->siguiente;
                nuevoNodo->anterior = actual;
                actual->siguiente->anterior = nuevoNodo;
                actual->siguiente = nuevoNodo;
                return;
            }
            actual = actual->siguiente;
        } while (actual != cabeza);
    }
}

void imprimir(){
    if(cabeza == 0){
        printf("La lista esta vacia");
    } else{
        nodo *actual = cabeza;
        do{
            printf("%s\n",actual->palabra);
            actual = actual->siguiente;
        } while (actual != cabeza); 
    }
}

int main(){
    insertarInicio("Hola");
    insertarInicio("Mundo");
    insertarInicio("Klk");
    insertarMedio("444","Mundo");
    imprimir();
    return 0;
}