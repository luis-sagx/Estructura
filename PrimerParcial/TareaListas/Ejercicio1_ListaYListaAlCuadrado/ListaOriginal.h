#include <stdio.h>
#include <stdlib.h>

struct nodo {       //Estructura nodo
    int dato;           
    nodo *siguiente;    
    nodo *anterior;     
};

nodo *cabeza = NULL;                   // Puntero al primer nodo de la lista original
nodo *cabezaListaCuadrados = NULL;     // Puntero al primer nodo de la lista de cuadrados

void insertar(int dato) { 
    nodo *nuevoNodo = (nodo*)malloc(sizeof(nodo)); // Crear un nuevo nodo asignando espacio de memoria
    nuevoNodo->dato = dato;             // Asignar el dato al nuevo nodo
    nuevoNodo->anterior = NULL;         
    nuevoNodo->siguiente = cabeza;      
    if (cabeza != NULL) {
        cabeza->anterior = nuevoNodo;   
    }
    cabeza = nuevoNodo;                 // Establecer el nodo nuevo como la nueva cabeza de la lista
}

void eliminar() {
    if (cabeza == NULL) {
        printf("La lista esta vacia\n");  // Imprimir un mensaje si la lista está vacía
        return;                           // Salir de la función
    }
    nodo *actual = cabeza;               // Inicializar un puntero al nodo actual que apunte al primer nodo de la lista

    while (actual != NULL) {             // Iterar sobre la lista hasta llegar al final de la lista
        nodo *posterior = actual->siguiente;  // Guardar el siguiente nodo en la lista
        while (posterior != NULL) {      // Iterar el puntero posteriores mientras no sea nulo
            if (actual->dato == posterior->dato) { 
                // Eliminar el nodo donde apunta posterior
                nodo *temp = posterior;  
                posterior = posterior->siguiente;  // Avanzar al siguiente puntero posterior
                if (temp->anterior != NULL) {  
                    temp->anterior->siguiente = temp->siguiente;  //Quitar el elace siguiente que apunta al nodo donde apunta temporal
                }
                if (temp->siguiente != NULL) { 
                    temp->siguiente->anterior = temp->anterior;  //Quitar el elace anterior que apunta al nodo donde apunta temporal
                }
                free(temp);                // Liberar la memoria del nodo temporal
            } else {
                posterior = posterior->siguiente;  // Avanzar al siguiente nodo 
            }
        }
        actual = actual->siguiente;      // Avanzar al siguiente nodo en la lista
    }
}

void sumarLista() {
    int suma = 0;                        
    nodo *actual = cabeza;               // Inicializar un puntero actual que apunte al inicio de la lista
    while (actual != NULL) {             
        suma += actual->dato;            // Sumar el dato del nodo actual a la suma total
        actual = actual->siguiente;      // Avanzar al siguiente nodo en la lista
    }
    printf("La suma de los elementos de la lista es: %d\n", suma);  // Imprimir la suma total
}

void imprimir() {
    if (cabeza == NULL) {
        printf("La lista esta vacia\n");  // Imprimir un mensaje si la lista está vacía
    } else {
        nodo *actual = cabeza;           // Inicializar un puntero actual que apunte al inicio de la lista
        //printf("La lista es:\n");
        while (actual != NULL) {         
            printf("%d\n", actual->dato);  // Imprimir el dato del nodo actual
            actual = actual->siguiente;  // Avanzar al siguiente nodo en la lista
        }
    }
}

