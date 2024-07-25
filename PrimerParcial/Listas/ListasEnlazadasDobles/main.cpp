#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct nodo{
    int dato;
    nodo *siguiente;
    nodo *anterior;
};

nodo *cabeza = NULL;

void insertarInicio(int dato){
    nodo *nuevoNodo = (nodo*)malloc(sizeof(nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->anterior = NULL;
    nuevoNodo->siguiente = cabeza;
    cabeza = nuevoNodo;
}

void insertarFinal(int dato){
    nodo *nuevoNodo = (nodo*)malloc(sizeof(nodo));
    nodo *actual = cabeza;
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;
    if (cabeza == NULL){
        nuevoNodo->anterior = NULL;
        cabeza = nuevoNodo;
    } else{
        while(actual->siguiente != NULL){
            actual = actual->siguiente;
        }
        nuevoNodo->anterior = actual;
        actual->siguiente = nuevoNodo;
    }
}

void insertarMedio(int dato, int datoAnterior){
    nodo *nuevoNodo = (nodo*)malloc(sizeof(nodo));
    nuevoNodo->dato = dato;
    if(cabeza == NULL){
        nuevoNodo->anterior = NULL;
        nuevoNodo->siguiente = NULL;
        cabeza = nuevoNodo;
    } else {
        nodo *actual = cabeza;
        while(actual->dato != datoAnterior && actual != NULL){
            actual = actual->siguiente;
        }
        if(actual != NULL){
            nuevoNodo->siguiente = actual->siguiente;
            nuevoNodo->anterior = actual;
            if (actual->siguiente != NULL) {
                actual->siguiente->anterior = nuevoNodo;
            }
            actual->siguiente = nuevoNodo;
        }
    }
}

void eliminar(int datoPorEliminar){
    if(cabeza == NULL){
        printf("La lista esta vacia");
    } else {
        nodo *actual = cabeza;
        while(actual->dato != datoPorEliminar && actual != NULL){
            actual = actual->siguiente;
        }
        if (actual != NULL){
            if(actual == cabeza){
                cabeza = actual->siguiente;
            } else {
                if(actual->anterior != NULL){
                    actual->anterior->siguiente = actual->siguiente;
                }
                if(actual->siguiente != NULL){
                    actual->siguiente->anterior = actual->anterior;
                }
            }
            free(actual); 

        } else{
            printf("no se encontro el dato");
        }
    }
}

void modificar(int nuevoDato, int datoPorModificar){
    if (cabeza == NULL){
        printf("La lista esta vacia");
    } else{
        nodo *actual = cabeza;
        while(actual->dato != datoPorModificar && actual != NULL){
            actual = actual->siguiente;
        }
        if(actual != NULL){
            actual->dato = nuevoDato;
        } else {
            printf("No se encontro el dato");
        }
    }
}
    

void imprimir(){
    if (cabeza == NULL){
        printf("La lista esta vacia");
    } else{
        nodo *actual = cabeza;
        while(actual != NULL){
            printf("%d\n",actual->dato);
            actual = actual->siguiente;
        }
    }
}

int main(){
    insertarFinal(22);
    insertarInicio(99);
    insertarFinal(333);
    insertarMedio(1111,99);
    insertarInicio(0);
    insertarFinal(11);
    insertarMedio(8888,1111);
    insertarFinal(2222);
    imprimir();
    printf("\n");
    eliminar(22);
    eliminar(0);
    eliminar(2222);
    modificar(66666,11);
    imprimir();
    return 0;
}