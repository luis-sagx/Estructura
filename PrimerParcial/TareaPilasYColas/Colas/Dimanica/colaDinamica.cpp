#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Orden {
    int numeroOrden;              // Numero de orden
    char nombreCliente[50];       // Nombre del cliente
    char platillo[100];           // Nombre del platillo
    struct Orden *siguiente;      // Puntero al siguiente elemento en la cola
} Orden;

typedef struct ColaDinamica {
    Orden *frente;   // Puntero al frente de la cola
    Orden *final;    // Puntero al final de la cola
} ColaDinamica;

void inicializarCola(ColaDinamica *cola) { // Función para inicializar una cola dinámica vacía
    cola->frente = NULL;   // Inicializa el frente de la cola como NULL
    cola->final = NULL;    // Inicializa el final de la cola como NULL
}

int colaVacia(ColaDinamica *cola) { // Función para verificar si la cola está vacía
    return (cola->frente == NULL && cola->final == NULL);
}


void encolar(ColaDinamica *cola, int numeroOrden, const char nombreCliente[], const char platillo[]) { // Insertar una nueva orden a la cola
    Orden *nuevaOrden = (Orden *)malloc(sizeof(Orden));   // Reserva memoria para la nueva orden 
    if (nuevaOrden == NULL) {                               // Verifica si la asignacion de memoria fue exitosa
        printf("Error: Fallo en la asignacion de memoria\n");
        return;
    }

    nuevaOrden->numeroOrden = numeroOrden; // Asigna los valores proporcionados a la nueva orden
    strcpy(nuevaOrden->nombreCliente, nombreCliente);
    strcpy(nuevaOrden->platillo, platillo);
    nuevaOrden->siguiente = NULL;   // Establece el siguiente de la nueva orden como NULL

    if (colaVacia(cola)) { // Si la cola está vacía, la nueva orden será tanto el frente como el final de la cola
        cola->frente = nuevaOrden;
        cola->final = nuevaOrden;
    } else {         // Si la cola no está vacía, enlaza la nueva orden al final de la cola y actualiza el puntero final
        cola->final->siguiente = nuevaOrden;
        cola->final = nuevaOrden;
    }
}

Orden desencolar(ColaDinamica *cola) { // Eliminar la orden del frente de la cola y devolverla
    Orden ordenEliminada;   // Declara una variable para almacenar la orden eliminada
    ordenEliminada.numeroOrden = -1;   // Suponiendo que -1 denota un número de orden inválido

    if (colaVacia(cola)) {   // Verifica si la cola esta vacia
        printf("Error: La cola esta vacía\n");
        return ordenEliminada;
    }

    Orden *temp = cola->frente;   // Guarda el puntero al frente de la cola en una variable temporal
    ordenEliminada = *temp;   // Copia la orden del frente a la variable de orden eliminada
    cola->frente = cola->frente->siguiente;   // Avanza el frente de la cola al siguiente elemento

    if (cola->frente == NULL) {
        cola->final = NULL;   // Si después de desencolar la cola queda vacía, también se actualiza el final
    }

    free(temp);   // Libera la memoria asignada a la orden desencolada
    return ordenEliminada;   // Devuelve la orden eliminada
}


void mostrarCola(ColaDinamica *cola) { // Mostrar todas las ordenes en la cola
    if (colaVacia(cola)) {   // Verifica si la cola esta vacía
        printf("La cola está vacia\n");
        return;
    }

    printf("Ordenes actuales en la cola:\n");
    Orden *actual = cola->frente;   // Inicializa un puntero para recorrer la cola

    while (actual != NULL) {   // Itera sobre todos los elementos de la cola
        printf("Numero de orden: %d, Cliente: %s, Platillo: %s\n",
               actual->numeroOrden, actual->nombreCliente, actual->platillo);
        actual = actual->siguiente;   // Avanza al siguiente elemento en la cola
    }
}
 
void limpiarCola(ColaDinamica *cola) { // Eliminar todos los elementos de la cola
    while (!colaVacia(cola)) {   // Mientras la cola no se encuentre vacia, desencola elementos
        desencolar(cola);
    }
}


int main() {
    ColaDinamica cola;
    inicializarCola(&cola);

    // Simulación de ordenes entrantes
    encolar(&cola, 1, "Javier Vaca", "Pizza");
    encolar(&cola, 2, "Maria Lopez", "Hamburguesa");
    encolar(&cola, 3, "Carlos Zambrano", "Papas fritas");

    mostrarCola(&cola);// Mostrar ordenes actuales
    
    Orden ordenAtendida = desencolar(&cola); // Simulación de finalización de ordenes
    printf("\nOrden %d esta lista para ser servida.\n", ordenAtendida.numeroOrden);

    mostrarCola(&cola); // Mostrar ordenes actualizadas

    return 0;
}
