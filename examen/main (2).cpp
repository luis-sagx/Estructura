#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct Nodo {
    int coeficiente;
    int potencia;
    Nodo *siguiente;
} Nodo;

void insertar(Nodo *&cabeza, int coeficiente, int potencia) {
    Nodo *nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->coeficiente = coeficiente;
    nuevoNodo->potencia = potencia;
    nuevoNodo->siguiente = NULL;
    if (cabeza == NULL) {
        cabeza = nuevoNodo;
    } else {
        Nodo *temp = cabeza;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
    }
}

void imprimir(Nodo *cabeza) {
    if (cabeza == NULL) {
        printf("La lista esta vacia\n");
    } else {
        Nodo *actual = cabeza;
        bool primerElemento = true;

        while (actual != NULL) {
            if (actual->coeficiente != 0) {
                if (actual->coeficiente > 0 && !primerElemento) {
                    printf(" + ");
                } else if (actual->coeficiente < 0) {
                    printf(" - ");
                } if(actual->potencia == 0){
                    printf("%d", abs(actual->coeficiente));
                } else{
                    printf("%dx^%d", abs(actual->coeficiente), actual->potencia);
                    primerElemento = false;
                }
            }
            actual = actual->siguiente;
        }
        printf("\n");
    }
}

void sumar(Nodo *polinomio1, Nodo *polinomio2) {
    Nodo *resultado = NULL;
    Nodo *temp1 = polinomio1;
    Nodo *temp2 = polinomio2;

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->potencia > temp2->potencia) {
            insertar(resultado, temp1->coeficiente, temp1->potencia);
            temp1 = temp1->siguiente;
        } else if (temp1->potencia < temp2->potencia) {
            insertar(resultado, temp2->coeficiente, temp2->potencia);
            temp2 = temp2->siguiente;
        } else {
            insertar(resultado, temp1->coeficiente + temp2->coeficiente, temp1->potencia);
            temp1 = temp1->siguiente;
            temp2 = temp2->siguiente;
        }
    }

    while (temp1 != NULL) {
        insertar(resultado, temp1->coeficiente, temp1->potencia);
        temp1 = temp1->siguiente;
    }

    while (temp2 != NULL) {
        insertar(resultado, temp2->coeficiente, temp2->potencia);
        temp2 = temp2->siguiente;
    }

    printf("El resultado es:\n");
    imprimir(resultado);
}

int main() {
    Nodo *polinomio1 = NULL;
    Nodo *polinomio2 = NULL;

    insertar(polinomio1, 3, 12);
    insertar(polinomio1, 2, 8);
    insertar(polinomio1, 1, 0);

    insertar(polinomio2, 8, 12);
    insertar(polinomio2, -3, 10);
    insertar(polinomio2, 10, 6);

    printf("Primer polinomio:\n");
    imprimir(polinomio1);
    printf("Segundo polinomio:\n");
    imprimir(polinomio2);

    sumar(polinomio1, polinomio2);

    return 0;
}
