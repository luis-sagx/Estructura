#include<string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct nodo{        // Definición de la estructura nodo de lista circular doblemente enlazada.
    char *premio;   // Cadena de caracteres que almacena el premio.
    nodo *siguiente;
    nodo *anterior;
};

nodo *cabeza = NULL;     // Puntero que apunta a la cabeza de la lista.

void insertarPremio(const char *premio){        // Función para insertar un premio en la lista.
    nodo *nuevoNodo = (nodo*)malloc(sizeof(nodo));      // Asignación de memoria para el nuevo nodo.
    nuevoNodo->premio = (char *)malloc(strlen(premio) + 1); // Asignación de memoria para la cadena de premio.
    if (nuevoNodo->premio == NULL) {
        printf("Error: No se inserto un premio\n");
        return;
    }
    strcpy(nuevoNodo->premio, premio);      // Copia la cadena premio en el nuevo nodo.
    if(cabeza == NULL){
        nuevoNodo->anterior = nuevoNodo;
        nuevoNodo->siguiente = nuevoNodo;
    } else{  // Si la lista no está vacía.
        nodo *actual = cabeza;
        actual->anterior->siguiente = nuevoNodo;  // Enlaza el último nodo con el nuevo nodo.
        nuevoNodo->anterior = actual->anterior;  // Enlaza el nuevo nodo con el último nodo.
        nuevoNodo->siguiente = actual;      // Enlaza el nuevo nodo con la cabeza.
        actual->anterior = nuevoNodo;       
    }
    cabeza = nuevoNodo;         // La cabeza apunta al nuevo nodo
}

void imprimirTodosLosPremios(){
    if (cabeza == NULL){
        printf("No se han agregado premios\n");
    } else{
        nodo *actual = cabeza;
        printf("Todos los premios:\n");
        do{                                 // Recorre la lista para imprimir todos los premios
            printf("%s\n",actual->premio);
            actual = actual->siguiente;
        }while(actual != cabeza);           
    }
}

int generarAvanceRandom(int min, int max) {
  srand(time(NULL));            // Inicializar generador de números aleatorios
  int numero = rand() % (max - min + 1) + min;  // Generar un número aleatorio entre min y max
  printf("El avance fue de: %d posiciones\n",numero);
  return numero;
}

void tomarViada(){
    cabeza = cabeza->anterior;   // Retrocede un nodo en la lista.
}

void girarRuleta(){
    tomarViada();       // Lamar a la funcion para retroceder un nodo.
    int avance = generarAvanceRandom(2,7);  //Llamar a la funcion para el avance random
    for(int i = 0; i < avance; i++){        
        cabeza = cabeza->siguiente;     // Avanza el número de nodos generados aleatoriamente.
    }
}

void imprimirPremio(){
    if(cabeza == NULL){
        printf("No se han ingresado premios\n");
    } else {
        printf("El premio que gano es: %s\n",cabeza->premio);   // Imprime el premio donde apunta la cabeza.
    }}