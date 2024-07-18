#include<stdio.h>

void seleccion(int a[], int n){
    int minimo, aux;
    for(int i=0; i<n; i++){
        minimo = i;
        for(int j = i+1; j<n; j++){
            if(a[minimo]>a[j]){
                minimo = j;
            }
        }
        aux = a[minimo];
        a[minimo] = a[i];
        a[i] = aux;
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

    seleccion(a, longitud);
    imprimir(a, longitud);

    return 0;
}