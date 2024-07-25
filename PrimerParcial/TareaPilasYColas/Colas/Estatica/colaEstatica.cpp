#include <stdio.h>
#include <string.h>

#define MAX_ORDENES 50

int numerosOrden[MAX_ORDENES];
char nombresClientes[MAX_ORDENES][50];  // Arreglo bidimensional para nombres de clientes
char platillos[MAX_ORDENES][100];       // Arreglo bidimensional para nombres de platillos
int frente = -1;  // Variable para indicar el frente de la cola
int final = -1;   // Variable para indicar el final de la cola

int colaVacia() { // Función para verificar si la cola está vacía
    return (frente == -1 && final == -1);
}

int colaLlena() { // Función para verificar si la cola está llena
    return final == MAX_ORDENES - 1;
}

void encolar(int numeroOrden, const char nombreCliente[], const char platillo[]) { // Insertar una nueva orden
    if (colaLlena()) {  // Verifica si la cola esta llena
        printf("Error: La cola esta llena\n");
        return;
    }
    if (colaVacia()) {  // Si la cola está vacia, inicializa el frente y el final
        frente = 0;
        final = 0;
    } else {
        final++;  // Avanza el índice del final de la cola
    }
    // Almacena los datos de la nueva orden en los arreglos correspondientes
    numerosOrden[final] = numeroOrden;
    strcpy(nombresClientes[final], nombreCliente);
    strcpy(platillos[final], platillo);
}

void desencolar() { // Eliminar la orden del frente de la cola
    if (colaVacia()) {  // Verifica si la cola está vacia
        printf("Error: La cola esta vacia\n");
        return;
    }
    if (frente == final) {  // Si solo hay un elemento en la cola
        frente = -1;
        final = -1;
    } else {
        frente++;  // Avanza el indice del frente de la cola
    }
}

void mostrarCola() { // Mostrar todas las ordenes en la cola
    if (colaVacia()) {  // Verifica si la cola está vacía
        printf("La cola esta vacia\n");
        return;
    }
    printf("Ordenes actuales en la cola:\n");
    int i = frente;
    while (i != final) {  // Itera desde el frente hasta el final de la cola
        printf("Numero de Orden: %d, Cliente: %s, Platillo: %s\n",
               numerosOrden[i], nombresClientes[i], platillos[i]);
        i++;  // Avanza al siguiente elemento en la cola
    }
    // Imprime el último elemento en la cola (cuando frente y final son iguales)
    printf("Numero de orden: %d, Cliente: %s, Platillo: %s\n", numerosOrden[final], nombresClientes[final], platillos[final]);
}

int main() {
    // Simulación de ordenes entrantes
    encolar(1, "Juan Heredia", "Pizza");
    encolar(2, "Maria Lopez", "Hamburguesa");
    encolar(3, "Carlos Zambrano", "Papas fritas");

    mostrarCola(); // Mostrar ordenes actuales

    desencolar(); // Simulacion de finalización de ordenes
    printf("\nOrden 1 esta lista para ser servida.\n");

    mostrarCola(); // Mostrar ordenes actualizadas

    return 0;
}
