#ifndef ALGORITMOFLOYDWARSHALL_H
#define ALGORITMOFLOYDWARSHALL_H
#include "MatrizAdyacencia.h"

// Clase para implementar el algoritmo de Floyd-Warshall
class AlgoritmoFloydWarshall {
protected:
    int **matrizCamino;  // Matriz para almacenar el camino
    int **matrizDistancia;  // Matriz de distancias mínimas
private:
    int numVertices;  // Número de vértices

public:
    // Constructor
    AlgoritmoFloydWarshall(MatrizAdyacencia grafo);

    void calcularDistanciasMinimas();

    void imprimirCaminoMinimo(int origen, int destino);

    int **obtenerMatrizCamino() { return matrizCamino; }
    int **obtenerMatrizDistancia() { return matrizDistancia; }

private:
    // Método recursivo para recuperar el camino mínimo
    void recuperarCamino(int origen, int destino);
};

// Implementación del constructor
AlgoritmoFloydWarshall::AlgoritmoFloydWarshall(MatrizAdyacencia grafo) {
    numVertices = grafo.obtenerNumeroDeVertices();
    typedef int* PunteroEntero;
    matrizDistancia = new PunteroEntero[numVertices];
    matrizCamino = new PunteroEntero[numVertices];
    // Inicialización de matrices
    for (int i = 0; i < numVertices; i++) {
        matrizDistancia[i] = new int[numVertices];
        matrizCamino[i] = new int[numVertices];
        for (int j = 0; j < numVertices; j++) {
            matrizDistancia[i][j] = grafo.obtenerValor(i, j);
            if (i == j || grafo.obtenerValor(i, j) == INT_MAX) {
                matrizCamino[i][j] = -1;  // Inicialización de camino
            } else {
                matrizCamino[i][j] = i;
            }
        }
    }
}

// Implementación del algoritmo de Floyd-Warshall
void AlgoritmoFloydWarshall::calcularDistanciasMinimas() {
    for (int i = 0; i < numVertices; i++) {
        matrizDistancia[i][i] = 0;  // Distancia mínima de un vértice a sí mismo
    }
    for (int k = 0; k < numVertices; k++) {
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                if (matrizDistancia[i][k] != INT_MAX && matrizDistancia[k][j] != INT_MAX &&
                    matrizDistancia[i][k] + matrizDistancia[k][j] < matrizDistancia[i][j]) {
                    matrizDistancia[i][j] = matrizDistancia[i][k] + matrizDistancia[k][j];
                    matrizCamino[i][j] = k;
                }
            }
        }
    }
}

// Método para recuperar e imprimir el camino mínimo
void AlgoritmoFloydWarshall::imprimirCaminoMinimo(int origen, int destino) {
    cout << "Camino para ir de " << origen << " a " << destino << ": ";
    recuperarCamino(origen, destino);
    cout << endl;
}

// Método recursivo para recuperar el camino mínimo
void AlgoritmoFloydWarshall::recuperarCamino(int origen, int destino) {
    if (matrizCamino[origen][destino] == -1) {
        cout << origen;
        if (origen != destino) {
            cout << " -> " << destino;
        }
    } else {
        int intermedio = matrizCamino[origen][destino];
        recuperarCamino(origen, intermedio);
        cout << " -> " << destino;
    }
}

#endif