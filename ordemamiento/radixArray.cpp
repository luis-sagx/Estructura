#include<stdio.h>
#include <iostream>

using namespace std;

int obtenerMaximo(int arr[], int n){
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void ordenarPorConteo(int arr[], int n, int exp){
    int salida[n];
    int i, conteo[10] = { 0 };

    for (i = 0; i < n; i++){
        conteo[(arr[i] / exp) % 10]++;
    }

    for (i = 1; i < 10; i++){
        conteo[i] += conteo[i - 1];
    }

    for (i = n - 1; i >= 0; i--) {
        salida[conteo[(arr[i] / exp) % 10] - 1] = arr[i];
        conteo[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++){
        arr[i] = salida[i];
    }
}

void radixsort(int arr[], int n){
    int maximo = obtenerMaximo(arr, n);

    for (int exp = 1; maximo / exp > 0; exp *= 10)
        ordenarPorConteo(arr, n, exp);
}

void imprimir(int arr[], int n){
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){
    int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
    int n = sizeof(arr) / sizeof(arr[0]);
    imprimir(arr, n);

    radixsort(arr, n);
    imprimir(arr, n);
    return 0;
}