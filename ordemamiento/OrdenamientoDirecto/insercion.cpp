#include<stdio.h>

void insercion(int a[], int n){
    for(int i = 1; i<n; i++){
        int aux = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > aux){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = aux;
    }
}

void imprimir(int a[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(){
    int a[] = {1,2,3,5,7,2,3,4,9,10,-1};
    int longitud = sizeof(a)/sizeof(a[0]);
    printf("%d\n", longitud);
    imprimir(a, longitud);
    insercion(a, longitud);
    imprimir(a, longitud);

    return 0;
}