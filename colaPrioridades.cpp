#include <stdio.h>
#include <stdlib.h>

struct nodo {
    int dato;
    struct nodo *siguiente; // Puntero al siguiente nodo
};

void insertarPrioridad(nodo **vector, int prioridad, int dato) {
    nodo *nuevoNodo = (nodo*)malloc(sizeof(nodo)); // Asigna memoria para un nuevo nodo
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;

    if (vector[prioridad] == NULL) {
        vector[prioridad] = nuevoNodo;
    } else {
        nodo *actual = vector[prioridad];
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo;
    }
}

int desencolar(nodo **vector, int prioridad) {
    if (vector[prioridad] == NULL) {
        printf("Error: La lista de prioridad %d esta vacia\n", prioridad);
        return -1;
    }

    nodo *primerNodo = vector[prioridad]; 
    int dato = primerNodo->dato; 

    vector[prioridad] = primerNodo->siguiente; 

    free(primerNodo); 
    return dato; 
}

void imprimirLista(nodo *cabeza) {
    if (cabeza == NULL) {
        printf("La lista esta vacia\n"); // Imprime un mensaje si la lista está vacía
    } else {
        nodo *actual = cabeza;
        while (actual != NULL) { // Recorre la lista y imprime cada elemento
            printf("%d  ", actual->dato);
            actual = actual->siguiente;
        }
        printf("\n"); // Indica el final de la lista
    }
}

void imprimirEstructura(nodo **vector, int tamano) {
    for (int i = 0; i < tamano; i++) { // Recorre cada elemento del vector
        printf("Vector[%d]: ", i);
        imprimirLista(vector[i]); // Imprime la lista almacenada en el vector[i]
    }
}

void imprimirListaPrioridad(nodo *cabeza) {
    if (cabeza == NULL) {
        printf("La lista esta vacia\n");
    } else {
        nodo *actual = cabeza;
        while (actual != NULL) {
            printf("%d  ", actual->dato);
            actual = actual->siguiente;
        }
        printf("\n");
    }
}

int main() {
    int prioridad = 3; // Define el tamaño del vector de listas
    nodo **vector = (nodo**)malloc(prioridad * sizeof(nodo*)); // Asigna memoria para el vector de punteros a nodos

    for (int i = 0; i < prioridad; i++) {
        vector[i] = NULL; 
    }

    insertarPrioridad(vector, 0, 0); 
    insertarPrioridad(vector, 1, 1); 
    insertarPrioridad(vector, 2, 2); 
    insertarPrioridad(vector, 2, 3);

    imprimirEstructura(vector, prioridad); // Imprime todas las listas en el vector

    printf("Elementos con prioridad 2: ");
    imprimirListaPrioridad(vector[2]); // Imprime los elementos con prioridad 2

    int datoDesencolado = desencolar(vector, 2);
    if (datoDesencolado != -1) {
        printf("Elemento desencolado con prioridad 2: %d\n", datoDesencolado);
    }

    free(vector); 

    return 0;
}
