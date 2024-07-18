#include<stdio.h>
#include<stdlib.h>

#define MAX 10

typedef struct Pila
{
    int cima;
    int elementos[MAX];
}Pila;

void inicializarPila(Pila *pila){
    pila->cima = -1;
}

int estaVacia(Pila *pila){
    return pila->cima == -1;
}

int estaLlena(Pila *pila){
    return pila->cima == MAX-1;
}

void apilar(Pila *pila, int elemento){
    if(estaLlena(pila)){
        printf("La pila esta llena\n");
    } else{
        pila->elementos[++pila->cima] = elemento;
    }
}

void desapilar(Pila *pila){
    if(estaVacia(pila)){
        printf("La pila esta vacia, no hay elementos que desapilar");
    } else{
        pila->elementos[pila->cima--];
    }
}

void cima(Pila *pila){
    if(estaVacia(pila)){
        printf("La pila esta vacia\n");
    } else{
        printf("%d\n",pila->elementos[pila->cima]);
    }
}

void imprimir(Pila *pila){
    if(estaVacia(pila)){
        printf("La pila esta vacia\n");
    } else{
        while (pila->cima != -1){
            printf("%d ",pila->elementos[pila->cima]);
            pila->cima--;
        }
        printf("\n");
    }
}

int main(){
    Pila pila;
    inicializarPila(&pila);
    apilar(&pila, 10);
    apilar(&pila, 5);
    apilar(&pila, 23);
    //imprimir(&pila);

    cima(&pila);
    desapilar(&pila);

    imprimir(&pila);
}