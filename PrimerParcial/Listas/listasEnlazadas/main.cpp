#include <stdio.h>
#include <stdlib.h>

struct nodo{
    int dato;
    nodo *siguiente;
};

nodo *cabeza = NULL;

void insertarNodoInicio(int dato){
    nodo *nuevoNodo = (nodo*)malloc(sizeof(nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = cabeza;
    cabeza = nuevoNodo;
}

void insertarNodoFinal(int dato){
    nodo *nuevoNodo = (nodo*)malloc(sizeof(nodo));
    nodo *actual = cabeza;
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;
    if(cabeza == NULL){
        printf("La lista se encontraba vacia\n");
        cabeza = nuevoNodo;
    } else{
        while (actual->siguiente != NULL)
        {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo;
    }
}

void insertarNodosMedio(int dato, int datoAnterior){
    nodo *nuevoNodo = (nodo*)malloc(sizeof(nodo));
    nodo *actual = cabeza;
    nuevoNodo->dato = dato;
    if(cabeza == NULL){
        printf("La lista se encontraba vacia");
        cabeza = nuevoNodo;
    } else{
        while(actual->dato != datoAnterior && actual != NULL){
            actual = actual->siguiente;
        }
        if(actual != NULL){
          nuevoNodo->siguiente = actual->siguiente;
          actual->siguiente = nuevoNodo;
        } else{
            printf("Dato no encontrado");
        }
    }
}

void eliminarNodo(int dato){
    nodo *actual = cabeza;
    nodo *anterior = NULL;
    if(cabeza == NULL){
        printf("Lista vacia");
    } else{
        // Buscar el nodo a eliminar y el nodo anterior a él
        while(actual != NULL && actual->dato != dato){
            anterior = actual;
            actual = actual->siguiente;
        }
        if (actual != NULL){
            // Si el nodo a eliminar es el primero
            if(anterior == NULL){
                cabeza = actual->siguiente;
            } else{
                // Si el nodo a eliminar está en medio o al final
                anterior->siguiente = actual->siguiente;
            }
            free(actual); // Liberar la memoria del nodo eliminado
        } else{
            printf("Dato a eliminar no encontrado");
        }
    }
}


void modificarDato(int dato, int nuevoDato){
    nodo *actual = cabeza;
    if(cabeza == NULL){
        printf("Lista vacia");
    } else{
        while(actual->dato != dato){
            actual = actual->siguiente;
        }
        if(actual != NULL){
            actual->dato = nuevoDato;
        } else{
            printf("Dato no encontrado");
        }
    }    
}

void imprimirLista(){
    nodo *actual = cabeza;
    if (actual == NULL){
        printf("Lista vacia");
    } else{
        printf("Lista: \n");
        while(actual != NULL){
            printf("%d\n",actual->dato);
            actual = actual->siguiente;
        }
    }
}

int main(){
    insertarNodoInicio(33);
    insertarNodoInicio(44);
    insertarNodoFinal(55);
    insertarNodosMedio(1,33);
    insertarNodoInicio(222);
    imprimirLista();
    printf("nuevo\n");
    modificarDato(44,0);
    eliminarNodo(1);
    imprimirLista();
    return 0;
}