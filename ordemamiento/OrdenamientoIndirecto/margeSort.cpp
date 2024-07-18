#include <stdio.h>

void merge(int a[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int izquierda[n1], derecha[n2];

    for (i = 0; i < n1; i++)
        izquierda[i] = a[l + i];
    for (j = 0; j < n2; j++)
        derecha[j] = a[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (izquierda[i] <= derecha[j]) {
            a[k] = izquierda[i];
            i++;
        } else {
            a[k] = derecha[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        a[k] = izquierda[i];
        i++;
        k++;
    }

    while (j < n2) {
        a[k] = derecha[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);

        merge(a, l, m, r);
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
    mergeSort(a, 0, longitud - 1);
    imprimir(a, longitud);

    return 0;
}
