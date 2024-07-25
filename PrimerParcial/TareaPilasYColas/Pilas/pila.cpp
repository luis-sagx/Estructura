#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MAX 20 // Definimos el tamaño máximo de las pilas

// Definición de pilas y sus respectivas variables para seguir la cima
int original[MAX];
int copiaOriginal[MAX]; // Pila para almacenar una copia de la original
int cimaOriginal = -1;
int cimaCopiaOriginal = -1;

int primos[MAX];
int cimaPrimos = -1;

int pares[MAX];
int cimaPares = -1;

int impares[MAX];
int cimaImpares = -1;

bool estaVacia(int cima) { // Verificar si la pila está vacía
    return cima == -1;
}

bool estaLlena(int cima) { // Verificar si la pila está llena
    return cima == MAX - 1;
}

void insertar(int pila[], int *cima, int valor) { // Insertar un elemento a la pila
    if (estaLlena(*cima)) { // Verificar si la pila está llena
        printf("Pila llena, no se puede empujar el valor %d\n", valor);
        return;
    }
    pila[++(*cima)] = valor; // Incrementar la cima y agregar el valor
}

int quitar(int pila[], int *cima) { // Sacar un elemento de la pila
    if (estaVacia(*cima)) { // Verificar si la pila está vacía
        printf("Pila vacía, no se puede sacar un valor\n");
        return -1; // Valor de error
    }
    return pila[(*cima)--]; // Devolver el valor de la cima y decrementar la cima
}

bool esPrimo(int num) { // Verificar si un número es primo
    if (num <= 1) return false; // Los números menores o iguales a 1 no son primos
    if (num == 2) return true; // El 2 es primo
    if (num % 2 == 0) return false; // Los números pares mayores que 2 no son primos
    for (int i = 3; i <= sqrt(num); i += 2) { // Verificar divisibilidad por números impares
        if (num % i == 0) return false;
    }
    return true; // Si no es divisible por ningún número, es primo
}

void imprimirPila(int pila[], int cima) { // Imprimir el contenido de la pila
    for (int i = 0; i <= cima; i++) { // Iterar desde el inicio hasta la cima de la pila
        printf("%d ", pila[i]); // Imprimir cada elemento
    }
    printf("\n");
}

void clasificarNumeros() { // Clasificación de los números en pilas de primos, pares e impares
    while (!estaVacia(cimaOriginal)) { // Continuar mientras la pila original no esté vacía
        int valor = quitar(original, &cimaOriginal); // Quitar un valor de la pila original
        if (esPrimo(valor)) {           // Si el valor es primo agregarlo a la pila de primos
            insertar(primos, &cimaPrimos, valor); 
        } else if (valor % 2 == 0) {    // Si el valor es par agregarlo a la pila de pares
            insertar(pares, &cimaPares, valor); 
        } else {                        // Si el valor es impar no primo agregarlo a la pila de impares
            insertar(impares, &cimaImpares, valor); 
        }
    }
}

int main() {
    int num = 0;
    printf("Ingrese numeros (ingrese -1 para terminar):\n");
    while(num != -1){           // Salir del bucle si el usuario ingresa -1
        printf("Numero: ");
        scanf("%d", &num);
        if (num != -1) { // Solo insertar si el número no es -1
            insertar(original, &cimaOriginal, num); // Agregar el número a la pila original
            insertar(copiaOriginal, &cimaCopiaOriginal, num); // Agregar el número a la copia de la pila original
        }
    }

    // Clasificar los números en pilas de primos, pares e impares
    clasificarNumeros();

    // Imprimir el contenido de las pilas
    printf("Pila original: ");
    imprimirPila(copiaOriginal, cimaCopiaOriginal); // Imprimir la copia de la pila original

    printf("Pila de numeros primos: ");
    imprimirPila(primos, cimaPrimos);

    printf("Pila de numeros pares: ");
    imprimirPila(pares, cimaPares);

    printf("Pila de numeros impares: ");
    imprimirPila(impares, cimaImpares);

    return 0;
}
