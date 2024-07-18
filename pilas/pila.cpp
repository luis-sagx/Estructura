#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int pila[MAX];
int cima = -1;

int pilaAux[MAX];
int cimaAux = -1;

void insertarPrimero(int valor) {
    if (cima >= MAX - 1) {
        printf("Error: desbordamiento de pila\n");
        return;
    }
    cima++;
    pila[cima] = valor;
}

void insertarAuxiliar(int valor) {
    if (cimaAux >= MAX - 1) {
        printf("Error: desbordamiento de pila auxiliar\n");
        return;
    }
    cimaAux++;
    pilaAux[cimaAux] = valor;
}

int sacarElemento() {
    if (cima == -1) {
        printf("Error: subdesbordamiento de pila\n");
        return -1; 
    }
    int valor = pila[cima];
    cima--;
    return valor;
}

int sacarAuxiliar() {
    if (cimaAux == -1) {
        printf("Error: subdesbordamiento de pila auxiliar\n");
        return -1; 
    }
    int valor = pilaAux[cimaAux];
    cimaAux--;
    return valor;
}

void imprimirPila() {
    if (cima == -1) {
        printf("La pila está vacía\n");
        return;
    }
    while (cima != -1) {
        int valor = sacarElemento();
        printf("%d\n", valor);
        insertarAuxiliar(valor);
    }
    while (cimaAux != -1) {
        insertarPrimero(sacarAuxiliar());
    }
}

void insertarElementos() {
    int valor;
    char continuar;

    do {
        printf("Introduce un valor para apilar: ");
        scanf("%d", &valor);
        insertarPrimero(valor);
        
        printf("¿Deseas insertar otro valor? (s/n): ");
        scanf(" %c", &continuar);
    } while (continuar == 's' || continuar == 'S');
}

int main() {
    insertarElementos();

    printf("Elementos en la pila:\n");
    imprimirPila();

    return 0;
}