#include<stdio.h>

int sumar(int n){
    if(n == 1)
        return 1;
    return n + sumar(n-1); 

}

int factorial(int n){
    if(n==0)
        return 1;
    return n * factorial(n-1);
}    

void imprimirMenorAMayor(int n) {
    if (n == 0)
        return;
    imprimirMenorAMayor(n - 1); 
    printf("%d ", n); 
}

void imprimirMayorAMenor(int n){
    if (n == 0)
        return;
    printf("%d ", n);
    imprimirMayorAMenor(n-1);
}

int fibonacci(int n){
    if(n == 0 || n == 1)
        return n;
    return (fibonacci(n-1) + fibonacci(n-2));
}

void imprimirFibonacci(int n){
    for (int i = 0; i <= n; i++){
        printf("%d ",fibonacci(i));
    }
}

int main(){
    int suma;
    suma = sumar(3);
    printf("suma: %d\n", suma);
    int res;
    res = factorial(5);
    printf("factorial: %d\n", res);
    imprimirMenorAMayor(10);
    printf("\n");
    imprimirMayorAMenor(10);
    printf("\n");
    int numerosFibonacci;
    numerosFibonacci = fibonacci(10);
    printf("fibonacci: %d\n", numerosFibonacci);
    imprimirFibonacci(10);
}