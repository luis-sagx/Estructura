#include<stdio.h>
void quicksort(int a[], int bajo, int alto) {
    if (bajo < alto) {
        int pivote = a[(bajo + alto) / 2];
        int i = bajo;
        int j = alto;

        while (i <= j) {
            while (a[i] < pivote)
                i++;
            while (a[j] > pivote)
                j--;
            if (i <= j) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                i++;
                j--;
            }
        }

        if (bajo < j)
            quicksort(a, bajo, j);
        if (i < alto)
            quicksort(a, i, alto);
    }
}

void imprimir(int a[], int n){
    for(int i = 0; i<n; i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

int main(){
    int a[] = {2,4,6,1,9,4,2,0,-3,5};
    int longitud = sizeof(a)/sizeof(a[0]);
    imprimir(a, longitud);

    quicksort(a,0,longitud-1);
    imprimir(a,longitud);

}