#include<stdio.h>

void burbuja(int a[], int n){
    int aux;
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            if(a[i] > a[j]){
                aux = a[i];
                a[i] = a[j];
                a[j] = aux;
            }
        }
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
    burbuja(a,longitud);
    imprimir(a, longitud);

    return 0;
}