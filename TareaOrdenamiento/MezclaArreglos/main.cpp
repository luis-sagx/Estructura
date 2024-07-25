#include "ordenamiento.h"

void imprimir(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int a[] = {1, 2, 3, 5, 7, 2, 3, 4, 9, 10, -1};
    int size = sizeof(a) / sizeof(a[0]);
    printf("Arreglo desordenado: ");
    imprimir(a, size);
    mergeSortArreglos(a, 0, size - 1);
    printf("Arreglo desordenado: ");
    imprimir(a, size);

    return 0;
}
