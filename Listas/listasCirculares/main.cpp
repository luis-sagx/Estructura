#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct nodo{
    int dato;
    nodo *siguiente;
};

nodo *cabeza = NULL;

void insertarInicio(int dato){
    nodo *nuevoNodo = (nodo*)malloc(sizeof(nodo));
    nuevoNodo->dato = dato;
    if(cabeza == NULL){
        nuevoNodo->siguiente = nuevoNodo;
        cabeza = nuevoNodo;
    } else{
        nodo *actual = cabeza;
        while(actual->siguiente != cabeza){
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo;
        nuevoNodo->siguiente = cabeza;
        cabeza = nuevoNodo;
    }
}

void insertarFinal(int dato){
    nodo *nuevoNodo = (nodo*)malloc(sizeof(nodo));
    nuevoNodo->dato = dato;
    if(cabeza == NULL){
        nuevoNodo->siguiente = nuevoNodo;
        cabeza = nuevoNodo;
    } else{
        nodo *actual = cabeza;
        while(actual->siguiente != cabeza){
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo;
        nuevoNodo->siguiente = cabeza;
    }
}

void insertarMedio(int dato, int datoAnterior){
    nodo *nuevoNodo = (nodo*)malloc(sizeof(nodo));
    nuevoNodo->dato = dato;
    if (cabeza == NULL){
        nuevoNodo->siguiente = cabeza;
    } else{
        nodo *actual = cabeza;
        do{
            actual = actual->siguiente;
        }while(actual->dato != datoAnterior && actual != cabeza);
        if (actual != cabeza){
            nuevoNodo->siguiente = actual->siguiente;
            actual->siguiente = nuevoNodo;
        } else {
            printf("Dato no encontrado");
        }    
    }    
}

void modificar(int nuevoDato, int datoPorModificar){
    if (cabeza == NULL){
        printf("La lista esta vacia");
    } else{
        nodo *actual = cabeza;
        while(actual->dato != datoPorModificar){
            actual = actual->siguiente;
        }
        actual->dato = nuevoDato;
    }
}

void eliminar(int datoPorBuscar){
    if (cabeza == NULL){
        printf("La lista esta vacia");
    } else {
        nodo *actual = cabeza;
        do{
            actual = actual->siguiente;
        }while(actual->siguiente->dato != datoPorBuscar && actual != cabeza);
        if(actual->siguiente->dato == datoPorBuscar){
            actual->siguiente = actual->siguiente->siguiente;
        }
        else{
            printf("dato a eliminar no encontrado");
        }
        
    }
}
    

void imprimir(){
    if (cabeza == NULL){
        printf("La lista esta vacia");
    } else{
        nodo *actual = cabeza;
        printf("lista:\n");
        do{
            printf("%d\n",actual->dato);
            actual = actual->siguiente;
        }while(actual != cabeza);
    }
}

int main(){
    insertarInicio(99);
    insertarInicio(0);
    insertarFinal(55);
    insertarInicio(-11);
    insertarFinal(9);
    insertarFinal(1111);
    insertarMedio(-111111,9);
    imprimir();
    printf("\n");
    modificar(22222,1111);
    eliminar(55);
    imprimir();
    return 0;
}