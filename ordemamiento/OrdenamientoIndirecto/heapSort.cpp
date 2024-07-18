#include <stdio.h>

void heapify(int a[], int n, int i) {
    int mayor = i;
    int izquierda = 2 * i + 1;
    int derecha = 2 * i + 2;
    int aux;

    if (izquierda < n && a[izquierda] > a[mayor])
        mayor = izquierda;

    if (derecha < n && a[derecha] > a[mayor])
        mayor = derecha;

    if (mayor != i) {
        aux = a[i];
        a[i] = a[mayor];
        a[mayor] = aux;
        heapify(a, n, mayor);
    }
}

void heapSort(int a[], int n) {
    int aux;
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    for (int i = n - 1; i > 0; i--) {
        aux = a[0];
        a[0] = a [i];
        a[i] = aux;
        heapify(a, i, 0);
    }
}

void imprimir(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int a[] = {1, 2, 3, 5, 7, 2, 3, 4, 9, 10, -1};
    int longitud = sizeof(a) / sizeof(a[0]);
    printf("Longitud: %d\n", longitud);
    imprimir(a, longitud);
    heapSort(a, longitud);
    imprimir(a, longitud);

    return 0;
}
