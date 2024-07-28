#include <stdio.h>
#include <stdlib.h>

// Estructura para el nodo de la lista enlazada
typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;

Nodo* insertarNodo(int dato) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

// Función para insertar un elemento en la cola de prioridades
void encolar(Nodo* colaPrioridades[], int dato, int prioridad) {
    Nodo* nuevoNodo = insertarNodo(dato);
    if (colaPrioridades[prioridad] == NULL) {
        colaPrioridades[prioridad] = nuevoNodo;
    } else {
        Nodo* temp = colaPrioridades[prioridad];
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
    }
}

// Función para eliminar y devolver el elemento de mayor prioridad
int desencolar(Nodo* colaPrioridades[], int maxPrioridad) {
    for (int i = 0; i <= maxPrioridad; i++) {
        if (colaPrioridades[i] != NULL) {
            Nodo* temp = colaPrioridades[i];
            int dato = temp->dato;
            colaPrioridades[i] = colaPrioridades[i]->siguiente;
            free(temp);
            return dato;
        }
    }
    printf("La cola está vacía\n");
    return -1;
}

// Función para verificar si la cola de prioridades está vacía
int estaVacia(Nodo* colaPrioridades[], int maxPrioridad) {
    for (int i = 0; i <= maxPrioridad; i++) {
        if (colaPrioridades[i] != NULL) {
            return 0;
        }
    }
    return 1;
}

// Función para liberar la memoria de la cola de prioridades
void liberarColaPrioridades(Nodo* colaPrioridades[], int maxPrioridad) {
    for (int i = 0; i <= maxPrioridad; i++) {
        Nodo* temp = colaPrioridades[i];
        while (temp != NULL) {
            Nodo* porLiberar = temp;
            temp = temp->siguiente;
            free(porLiberar);
        }
    }
}

// Función principal para demostrar el uso de la cola de prioridades
int main() {
    int maxPrioridad = 5;
    Nodo* colaPrioridades[maxPrioridad + 1];
    for (int i = 0; i <= maxPrioridad; i++) {
        colaPrioridades[i] = NULL;
    }

    encolar(colaPrioridades, 10, 2);
    encolar(colaPrioridades, 20, 1);
    encolar(colaPrioridades, 30, 3);
    encolar(colaPrioridades, 40, 0);

    while (!estaVacia(colaPrioridades, maxPrioridad)) {
        printf("Desencolar: %d\n", desencolar(colaPrioridades, maxPrioridad));
    }

    liberarColaPrioridades(colaPrioridades, maxPrioridad);
    return 0;
}
