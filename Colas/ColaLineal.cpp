#include<iostream>
#include<stdio.h>
#define DIM 10

int colaLineal[DIM];
int frente = -1;
int final = -1;

void insertar(int dato){
    if(final == DIM -1){             // Verificar si la cola esta llena
        printf("Cola llena\n");
    } else if(frente == -1 && final == -1){     // Verificar si la cola esta vacia
        frente = final = 0;     // Asignar el indice 0
    } else{
        final++;        // El final ir al siguiente indice
    }
    colaLineal[final] = dato; // Asignar el dato
}

void quitar(){
    if(frente == -1){
        printf("La cola esta vacia\n");       // Verificar si la cola esta vacia
    } else {
        printf("Elemento: %d quitado\n",colaLineal[frente]);
        if(frente == final){
            frente = final = -1;        //Vaciar la cola
        } else {
            frente ++;      // Frente se recorre al siguiente dato
        }
    }
}

bool colaVacia(){
    if(frente == -1)
        return true;
    return false;
}

bool colaLlena(){
    if(final == DIM -1)
        return true;
    return false;
}

void mostrarFrente(){
    if(frente == -1){
        printf("La cola esta vacia\n");       // Verificar si la cola esta vacia
    } else {
        int temp = colaLineal[frente];
        printf("Elemento en el frente: %d\n", temp);
        quitar();
        insertar(temp);
        printf("Elemento: %d insertado\n",temp);
    }
}

void maxElementos() {
    if (frente == -1 && final == -1) {
        printf("Numero maximo de elementos que se pueden ingresar: %d\n", DIM);
    } else {
        int elementos_actuales = final - frente + 1;
        int espacios_disponibles = DIM - elementos_actuales;
        printf("Numero maximo de elementos que se pueden ingresar: %d\n", espacios_disponibles);
    }
}

void mostrarCola() {
    if (frente == -1) {
        printf("La cola está vacía\n");
    } else {
        printf("Elementos en la cola:\n");
        for (int i = frente; i <= final; i++) {
            printf("%d\n", colaLineal[i]);
        }
    }
}

int main() {
    insertar(1);
    insertar(2);
    insertar(3);
    insertar(4);
    insertar(5);

    mostrarCola();

    mostrarFrente();
    mostrarCola();
    
    quitar();
    mostrarCola();
    
    maxElementos();
    return 0;
}

