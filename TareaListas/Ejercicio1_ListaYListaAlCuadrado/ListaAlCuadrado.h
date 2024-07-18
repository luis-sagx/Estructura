#include "ListaOriginal.h"

void insertarCuadrados(){
    if(cabeza == NULL){
        printf("La lista esta vacia\n");
    } else{
        nodo *actual = cabeza;
        while(actual != NULL) {              // Iterar sobre la lista mientras actual no sea nulo
            nodo *nuevoNodo = (nodo*)malloc(sizeof(nodo));  // Crear un nuevo nodo para almacenar el cuadrado del dato
            nuevoNodo->dato = actual->dato * actual->dato;  // Calcular y almacenar el cuadrado del dato de la lista original
            nuevoNodo->siguiente = NULL;
            if(cabezaListaCuadrados == NULL){   // Si la lista esta vacia el puntero cabeza apunta al nuevo nodo
                nuevoNodo->anterior = NULL;
                cabezaListaCuadrados = nuevoNodo;
            } else {
                nodo *temporal = cabezaListaCuadrados;    // Crear un puntero tamporal para iterar la lista de los elementos al cuadrado
                while (temporal->siguiente != NULL){
                    temporal = temporal->siguiente;       // Avanzar al siguiente nodo de la lista de cuadrados
                }
                nuevoNodo->anterior = temporal;           // Apuntar el enlace anterior del nuevo nodo al ultimo nodo
                temporal->siguiente = nuevoNodo;          // Apuntar el enlace siguiente al nuevo nodo
            }
            actual = actual->siguiente;             // Avanzar al siguiente nodo en la lista original
        }
    }             
}

void imprimirListaCuadrados() {            
    if (cabezaListaCuadrados == NULL) {
        printf("La lista esta vacia\n");  // Imprimir un mensaje si la lista de cuadrados está vacía
    } else {
        nodo *temporal = cabezaListaCuadrados;  // Inicializar un puntero al nodo actual con la cabeza de la lista de cuadrados
        printf("Lista de los numeros al cuadrado:\n");
        while (temporal != NULL) {           // Iterar sobre la lista de cuadrados mientras el nodo actual no sea nulo
            printf("%d\n",temporal->dato);   // Imprimir el cuadrado del dato original
            temporal = temporal->siguiente;    // Avanzar al siguiente nodo en la lista de cuadrados
        }
    }
}
