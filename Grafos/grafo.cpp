#include<iostream>
#define DIM 10 // Dimensión máxima para pila y cola

using namespace std;

// Estructura de nodo para la lista de adyacencia
class Nodo {
public:
    int vertice; // Indica el vértice con que se conecta
    int peso;    // Peso de la arista
    Nodo* sig;
    
    Nodo(int destino, int ponderacion) {
        vertice = destino;
        peso = ponderacion;
        sig = nullptr;
    }
};

// Clase Lista para manejar la lista de adyacencia de un vértice
class Lista {
public:
    Nodo* cabeza;

    Lista() {
        cabeza = nullptr;
    }
    void insertar(Nodo* nodo);
};

void Lista::insertar(Nodo* nodo) {
    if (cabeza == nullptr) {
        cabeza = nodo;
        return;
    }

    // Inserción por orden de valores
    if (nodo->vertice < cabeza->vertice) { // Si es menor a la cabeza, se inserta antes
        nodo->sig = cabeza;
        cabeza = nodo;
        return;
    }

    Nodo* aux = cabeza; // Si no, se inserta al final
    while (aux->sig != nullptr) {
        aux = aux->sig;
    }

    aux->sig = nodo;
}

// Clase Grafo para manejar el grafo completo
class Grafo {
public:
    int n;
    Lista* listady; // Cada vértice tiene su lista de adyacencia

    Grafo(int num_nodos) {
        n = num_nodos;
        listady = new Lista[n]{};
    }

    void agregarArista(int fuente, int destino, int peso);
    void DFS(int vertice_inicial);
    void BFS(int vertice_inicial);
};

// Estructuras de pila y cola
int pila[DIM];
int cima = -1;

// Funciones para manejar la pila
void insertarPila(int valor) {
    if (cima >= DIM - 1) {
        printf("Error: desbordamiento de pila\n");
        return;
    }
    cima++;
    pila[cima] = valor;
}

int sacarPila() {
    if (cima == -1) {
        printf("Error: subdesbordamiento de pila\n");
        return -1;
    }
    int valor = pila[cima];
    cima--;
    return valor;
}

bool pilaVacia() {
    return cima == -1;
}

// Funciones para manejar la cola
int cola[DIM];
int frente = -1;
int final = -1;

void insertarCola(int dato) {
    if (final == DIM - 1) {
        printf("Cola llena\n");
    } else if (frente == -1 && final == -1) {
        frente = final = 0;
    } else {
        final++;
    }
    cola[final] = dato;
}

int quitarCola() {
    if (frente == -1) {
        printf("La cola esta vacia\n");
        return -1;
    } else {
        int valor = cola[frente];
        if (frente == final) {
            frente = final = -1;
        } else {
            frente++;
        }
        return valor;
    }
}

bool colaVacia() {
    return frente == -1;
}

// Implementación de agregar arista
void Grafo::agregarArista(int fuente, int destino, int peso) {
    Nodo* nuevoNodo = new Nodo(destino, peso);
    listady[fuente].insertar(nuevoNodo);
    // Añadir también la arista en la dirección opuesta para hacerlo no dirigido
    Nodo* nodoOpuesto = new Nodo(fuente, peso);
    listady[destino].insertar(nodoOpuesto);
}

// Implementación de DFS usando la pila
void Grafo::DFS(int vertice_inicial) {
    bool visitado[n] = { false };
    insertarPila(vertice_inicial);

    while (!pilaVacia()) {
        int v = sacarPila();

        if (!visitado[v]) {
            cout << v << " ";
            visitado[v] = true;
        }

        Nodo* aux = listady[v].cabeza;
        while (aux != nullptr) {
            if (!visitado[aux->vertice]) {
                insertarPila(aux->vertice);
            }
            aux = aux->sig;
        }
    }
    cout << endl;
}

// Implementación de BFS usando la cola
void Grafo::BFS(int vertice_inicial) {
    bool visitado[n] = { false };
    insertarCola(vertice_inicial);
    visitado[vertice_inicial] = true;

    while (!colaVacia()) {
        int v = quitarCola();
        cout << v << " ";

        Nodo* aux = listady[v].cabeza;
        while (aux != nullptr) {
            if (!visitado[aux->vertice]) {
                insertarCola(aux->vertice);
                visitado[aux->vertice] = true;
            }
            aux = aux->sig;
        }
    }
    cout << endl;
}

// Programa principal para probar el grafo
int main() {
    Grafo grafo(5);

    grafo.agregarArista(0, 1, 2);
    grafo.agregarArista(0, 4, 1);
    grafo.agregarArista(1, 2, 3);
    grafo.agregarArista(1, 3, 1);
    grafo.agregarArista(2, 3, 5);
    grafo.agregarArista(3, 4, 2);

    cout << "Recorrido DFS (Iniciando desde el vértice 0): ";
    grafo.DFS(0);

    cout << "Recorrido BFS (Iniciando desde el vértice 0): ";
    grafo.BFS(0);

    return 0;
}
