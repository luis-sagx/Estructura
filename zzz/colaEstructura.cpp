#include<stdio.h>
#include<stdlib.h>
#define MAX 10

typedef struct Cola{
    int frente;
    int fin;
    int elementos[MAX];
}Cola;

void inicializar(Cola *cola){
    cola->frente = -1;
    cola->fin = -1;
}

int estaLlena(Cola *cola){
    return cola->fin == MAX -1;
}

int estaVacia(Cola *cola){
    return cola->frente == -1;
}    

void encolar(Cola *cola, int elemento){
    if(estaVacia(cola)){
        cola->frente = 0;
        cola->fin = 0;
    } else if(estaLlena(cola)){
        printf("Cola llena\n");
        return;
    } else {
        cola->fin++;
    }
    cola->elementos[cola->fin] = elemento;
}

void desencolar(Cola *cola) {
    if (estaVacia(cola)) {
        printf("La cola se encuentra vacía\n");
        return;
    }
    printf("Elemento desencolado: %d\n", cola->elementos[cola->frente]);
    if (cola->frente == cola->fin) {
        inicializar(cola);
    } else {
        cola->frente++;
    }
}


void mostrarFrente(Cola *cola){
    if(estaVacia(cola)){
        printf("Cola vacia\n");
        return;
    }
    printf("Frente: %d\n", cola->elementos[cola->frente]);
}

void imprimir(Cola *cola){
    if(estaVacia(cola)){
        printf("Cola Vacia\n");
    } else {
        while (cola->fin >= cola->frente){
            printf("%d ",cola->elementos[cola->frente]);
            cola->frente++;
        }
        printf("\n");
    }
}

int main(){
    Cola cola;
    inicializar(&cola);

    encolar(&cola, 10);
    encolar(&cola, 20);
    encolar(&cola, 30);

    desencolar(&cola);
    mostrarFrente(&cola);
    imprimir(&cola);

}