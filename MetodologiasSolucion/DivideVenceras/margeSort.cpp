#include <iostream>
#include <cstdlib>  // Para usar rand()
#include <ctime>    // Para usar time()
#include "lista.h"

using namespace std;

// Variable global para contar el número de iteraciones
int contadorIteraciones = 0;

// Función para fusionar dos listas ordenadas
Nodo* fusionarListas(Nodo* izquierda, Nodo* derecha) {
    if (!izquierda) return derecha;
    if (!derecha) return izquierda;

    // Incrementar el contador de iteraciones
    contadorIteraciones++;

    if (izquierda->dato <= derecha->dato) {
        izquierda->siguiente = fusionarListas(izquierda->siguiente, derecha);
        return izquierda;
    } else {
        derecha->siguiente = fusionarListas(izquierda, derecha->siguiente);
        return derecha;
    }
}

// Función recursiva para ordenar la lista
Nodo* mergeSort(Nodo* lista) {
    if (!lista || !lista->siguiente) {
        return lista;
    }

    // Dividir la lista en dos mitades
    Nodo* mitadIzquierda = lista;
    Nodo* mitadDerecha = lista->siguiente;
    while (mitadDerecha && mitadDerecha->siguiente) {
        lista = lista->siguiente;
        mitadDerecha = mitadDerecha->siguiente->siguiente;
    }
    mitadDerecha = lista->siguiente;
    lista->siguiente = nullptr;  // Separar las dos mitades

    // Llamadas recursivas para ordenar ambas mitades
    Nodo* izquierdaOrdenada = mergeSort(mitadIzquierda);
    Nodo* derechaOrdenada = mergeSort(mitadDerecha);

    // Fusionar las listas ordenadas
    return fusionarListas(izquierdaOrdenada, derechaOrdenada);
}

int main() {
    Lista lista;
    int numeroDatos;

    cout << "Ingrese el numero de datos a generar: ";
    cin >> numeroDatos;

    // Inicializar la semilla para generar números aleatorios
    srand(time(0));

    // Insertar números aleatorios en la lista
    for (int i = 0; i < numeroDatos; i++) {
        int numeroAleatorio = rand() % 1000;  // Generar número aleatorio entre 0 y 999
        lista.insertarFinal(numeroAleatorio);
    }

    cout << "Lista antes de ordenar:" << endl;
    lista.mostrarLista();

    lista.cabeza = mergeSort(lista.cabeza);

    cout << "Lista despues de ordenar:" << endl;
    lista.mostrarLista();

    // Mostrar el número de iteraciones realizadas
    cout << "Numero de iteraciones: " << contadorIteraciones << endl;

    return 0;
}
