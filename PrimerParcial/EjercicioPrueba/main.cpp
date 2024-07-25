#include <stdio.h>
#include <stdlib.h>

struct nodo {
    int dato; 
    struct nodo *siguiente; // Puntero al siguiente nodo
};

void insertarNodo(struct nodo **cabeza, int dato) {
    nodo *nuevoNodo = (struct nodo*)malloc(sizeof(struct nodo)); // Asigna memoria para un nuevo nodo
    nuevoNodo->dato = dato;       // Inicializa el campo dato del nuevo nodo
    nuevoNodo->siguiente = *cabeza; // Enlaza el nuevo nodo con la lista actual
    *cabeza = nuevoNodo;         // Actualiza la cabeza de la lista para que apunte al nuevo nodo
}

void imprimirLista(struct nodo *cabeza) {
    if (cabeza == NULL) {
        printf("La lista esta vacia\n"); // Imprime un mensaje si la lista está vacía
    } else {
        nodo *actual = cabeza;
        while (actual != NULL) { // Recorre la lista y imprime cada elemento
            printf("%d -> ", actual->dato);
            actual = actual->siguiente;
        }
        printf("NULL\n"); // Indica el final de la lista
    }
}

void imprimirEstructura(struct nodo **vector, int tamano) {
    for (int i = 0; i < tamano; i++) { // Recorre cada elemento del vector
        printf("Vector[%d]: ", i);
        imprimirLista(vector[i]); // Imprime la lista almacenada en el vector[i]
    }
}

int main() {
    int tamano = 3; // Define el tamaño del vector de listas
    nodo **vector = (struct nodo**)malloc(tamano * sizeof(struct nodo*)); // Asigna memoria para el vector de punteros a nodos

    vector[0] = NULL; // Inicializa la primera lista como vacía
    insertarNodo(&vector[0], 3); // Insertar datos de la lista 0
    insertarNodo(&vector[0], 2); 
    insertarNodo(&vector[0], 1); 

    vector[1] = NULL; // Inicializa la segunda lista como vacía
    insertarNodo(&vector[1], 4); // Inserta dato de la lista 1
    
    vector[2] = NULL; // Inicializa la tercera lista como vacía
    insertarNodo(&vector[2], 6); // Insertar datos de la lista 2
    insertarNodo(&vector[2], 5); 

    imprimirEstructura(vector, tamano); // Imprime las listas enlazadas del vector
    free(vector); // Libera la memoria asignada para el vector de punteros
    return 0; 
}
