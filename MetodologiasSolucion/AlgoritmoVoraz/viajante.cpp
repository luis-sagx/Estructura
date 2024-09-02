#include <iostream>

using namespace std;

class Nodo {
public:
    int id;
    Nodo* siguiente;
    Nodo(int id) : id(id), siguiente(nullptr) {}
};

class Grafo {
private:
    int** matriz;
    int numNodos;
public:
    Grafo(int numNodos) {
        this->numNodos = numNodos;
        matriz = new int*[numNodos];
        for (int i = 0; i < numNodos; i++) {
            matriz[i] = new int[numNodos];
        }
    }

    void agregarArista(int origen, int destino, int costo) {
        matriz[origen][destino] = costo;
        matriz[destino][origen] = costo;
    }

    int obtenerCosto(int origen, int destino) {
        return matriz[origen][destino];
    }

    int getNumNodos() {
        return numNodos;
    }

};

class TSP {
private:
    bool* visitado;
    Nodo* recorrido;
    Grafo* grafo;
    int distanciaTotal;
public:
    TSP(Grafo* grafo) {
        this->grafo = grafo;
        int numNodos = grafo->getNumNodos();
        visitado = new bool[numNodos];
        for (int i = 0; i < numNodos; i++) {
            visitado[i] = false;
        }
        recorrido = nullptr;
        distanciaTotal = 0;
    }

    void resolver(int nodoInicial) {
        Nodo* actual = new Nodo(nodoInicial);
        recorrido = actual;
        visitado[nodoInicial] = true;

        for (int i = 1; i < grafo->getNumNodos(); i++) {
            int siguienteNodo = encontrarNodoMinimo(actual->id);
            distanciaTotal += grafo->obtenerCosto(actual->id, siguienteNodo);
            Nodo* nuevoNodo = new Nodo(siguienteNodo);
            actual->siguiente = nuevoNodo;
            actual = nuevoNodo;
            visitado[siguienteNodo] = true;
        }

        // Cerrar el ciclo regresando al nodo inicial
        distanciaTotal += grafo->obtenerCosto(actual->id, nodoInicial);
        actual->siguiente = new Nodo(nodoInicial);
    }

    int encontrarNodoMinimo(int nodoActual) {
        int minimo = INT_MAX; // Un valor alto como máximo posible
        int nodoMinimo = -1;
        for (int i = 0; i < grafo->getNumNodos(); i++) {
            if (!visitado[i] && grafo->obtenerCosto(nodoActual, i) < minimo) {
                minimo = grafo->obtenerCosto(nodoActual, i);
                nodoMinimo = i;
            }
        }
        return nodoMinimo;
    }

    void imprimirRecorrido() {
        cout << "Recorrido del viajante: ";
        Nodo* actual = recorrido;
        while (actual != nullptr) {
            cout << actual->id << (actual->siguiente != nullptr ? " -> " : "");
            actual = actual->siguiente;
        }
        cout << endl;
        cout << "Distancia total: " << distanciaTotal << endl;
    }

};

int main() {
    Grafo grafo(4);
    grafo.agregarArista(0, 1, 10);
    grafo.agregarArista(0, 2, 15);
    grafo.agregarArista(0, 3, 20);
    grafo.agregarArista(1, 2, 35);
    grafo.agregarArista(1, 3, 25);
    grafo.agregarArista(2, 3, 30);

    TSP tsp(&grafo);
    tsp.resolver(0);
    tsp.imprimirRecorrido();

    return 0;
}
