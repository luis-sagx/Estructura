#include <iostream>

using namespace std;

#define MAX 100 // Máximo número de aristas y vértices

// Clase para representar una arista en el grafo
class Arista {
public:
    int origen, destino, peso;

    Arista() : origen(0), destino(0), peso(0) {}
};

// Función para encontrar el conjunto al que pertenece un elemento (con path compression)
int encontrarConjunto(int padre[], int i) {
    if (padre[i] != i)
        padre[i] = encontrarConjunto(padre, padre[i]);
    return padre[i];
}

// Función para unir dos subconjuntos diferentes (con union by rank)
void unionConjuntos(int padre[], int rango[], int x, int y) {
    int raizX = encontrarConjunto(padre, x);
    int raizY = encontrarConjunto(padre, y);

    if (rango[raizX] < rango[raizY]) {
        padre[raizX] = raizY;
    } else if (rango[raizX] > rango[raizY]) {
        padre[raizY] = raizX;
    } else {
        padre[raizY] = raizX;
        rango[raizX]++;
    }
}

// Función para ordenar las aristas según su peso usando el método de burbuja
void ordenarAristas(Arista aristas[], int E) {
    for (int i = 0; i < E - 1; i++) {
        for (int j = 0; j < E - i - 1; j++) {
            if (aristas[j].peso > aristas[j + 1].peso) {
                // Intercambiar aristas[j] y aristas[j + 1]
                Arista temp = aristas[j];
                aristas[j] = aristas[j + 1];
                aristas[j + 1] = temp;
            }
        }
    }
}

// Función que implementa el algoritmo de Kruskal
void kruskal(Arista aristas[], int V, int E) {
    // Ordenar las aristas por su peso
    ordenarAristas(aristas, E);

    int padre[MAX], rango[MAX];
    Arista mst[MAX]; // Para almacenar las aristas del MST
    int aristasIncluidas = 0;

    // Inicializar los conjuntos para cada vértice
    for (int i = 0; i < V; i++) {
        padre[i] = i;
        rango[i] = 0;
    }

    int i = 0; // Índice para recorrer aristas
    while (aristasIncluidas < V - 1 && i < E) {
        Arista siguienteArista = aristas[i++];

        int x = encontrarConjunto(padre, siguienteArista.origen);
        int y = encontrarConjunto(padre, siguienteArista.destino);

        // Si incluir esta arista no causa un ciclo
        if (x != y) {
            mst[aristasIncluidas++] = siguienteArista;
            unionConjuntos(padre, rango, x, y);
        }
    }

    // Imprimir las aristas del MST
    cout << "Aristas en el árbol de expansión mínima:" << endl;
    for (int i = 0; i < aristasIncluidas; i++) {
        cout << mst[i].origen << " -- " << mst[i].destino << " == " << mst[i].peso << endl;
    }
}

int main() {
    int V, E;
    Arista aristas[MAX];

    cout << "Ingrese las aristas (origen destino peso):" << endl;
    for (int i = 0; i < E; i++) {
        cin >> aristas[i].origen >> aristas[i].destino >> aristas[i].peso;
    }

    kruskal(aristas, V, E);

    return 0;
}