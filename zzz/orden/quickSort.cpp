#include <stdio.h>

void intercambiar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particion(int arr[], int izquierda, int derecha) {
    int pivote = arr[(izquierda + derecha) / 2];
    int i = izquierda - 1;
    int j = derecha + 1;

    while (1) {
        do {
            i++;
        } while (arr[i] < pivote);

        do {
            j--;
        } while (arr[j] > pivote);

        if (i >= j)
            return j;

        intercambiar(&arr[i], &arr[j]);
    }
}

void quickSort(int arr[], int izquierda, int derecha) {
    if (izquierda < derecha) {
        int indice_particion = particion(arr, izquierda, derecha);
        quickSort(arr, izquierda, indice_particion);
        quickSort(arr, indice_particion + 1, derecha);
    }
}

void imprimir(int arr[], int tamaño) {
    for (int i = 0; i < tamaño; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int tamaño = sizeof(arr) / sizeof(arr[0]);
    printf("Arreglo original:\n");
    imprimir(arr, tamaño);
    quickSort(arr, 0, tamaño - 1);
    printf("Arreglo ordenado con Quicksort:\n");
    imprimir(arr, tamaño);
    return 0;
}
