#ifndef NODO_H
#define NODO_H

#include <iostream>
using namespace std;

class Nodo {
public:
    int* claves;    // Array de claves
    Nodo** hijos;   // Array de punteros a hijos
    int numClaves;          // Número actual de claves
    bool esHoja;    // Indica si es un nodo hoja
    Nodo* siguiente;    // Puntero al nodo siguiente (usado solo en hojas)

    Nodo(int grado, bool hoja) {
        claves = new int[2 * grado];  // Máximo número de claves
        hijos = new Nodo*[2 * grado + 1];     // Máximo número de hijos
        numClaves = 0;
        siguiente = nullptr;
        esHoja = hoja;
    }

    void insertarNoLleno(int k, int grado);
    void dividirHijo(int i, Nodo* y, int grado);
    void eliminar(int k, int grado);

private:
    int obtenerPredecesor(int idx);
    int obtenerSucesor(int idx);
    void fusionar(int idx, int grado);
    void llenar(int idx, int grado);
    void eliminarDeHoja(int idx);
    void eliminarDeNoHoja(int idx, int grado);
    void prestarDeAnterior(int idx);
    void prestarDeSiguiente(int idx);
};

void Nodo::insertarNoLleno(int k, int grado) {
    int i = numClaves - 1;

    // Si es una hoja, insertar directamente
    if (esHoja) {
        while (i >= 0 && claves[i] > k) {
            claves[i + 1] = claves[i];
            i--;
        }

        claves[i + 1] = k;
        numClaves = numClaves + 1;
    } else {
        while (i >= 0 && claves[i] > k)
            i--;

        if (hijos[i + 1]->numClaves == 2 * grado - 1) {
            dividirHijo(i + 1, hijos[i + 1], grado);

            if (claves[i + 1] < k)
                i++;
        }
        hijos[i + 1]->insertarNoLleno(k, grado);
    }
}

void Nodo::dividirHijo(int i, Nodo* y, int grado) {
    Nodo* z = new Nodo(grado, y->esHoja);
    z->numClaves = grado - 1;

    for (int j = 0; j < grado - 1; j++)
        z->claves[j] = y->claves[j + grado];

    if (!y->esHoja) {
        for (int j = 0; j < grado; j++)
            z->hijos[j] = y->hijos[j + grado];
    } else {
        z->siguiente = y->siguiente;
        y->siguiente = z;
    }

    y->numClaves = grado - 1;

    for (int j = numClaves; j >= i + 1; j--)
        hijos[j + 1] = hijos[j];

    hijos[i + 1] = z;

    for (int j = numClaves - 1; j >= i; j--)
        claves[j + 1] = claves[j];

    claves[i] = y->claves[grado - 1];
    numClaves = numClaves + 1;
}

// Función para eliminar una clave en un nodo B+
void Nodo::eliminar(int k, int grado) {
    int idx = 0;
    while (idx < numClaves && claves[idx] < k)
        idx++;

    if (idx < numClaves && claves[idx] == k) {
        if (esHoja)
            eliminarDeHoja(idx);
        else
            eliminarDeNoHoja(idx, grado);
    } else {
        if (esHoja) {
            cout << "La clave " << k << " no está en el árbol.\n";
            return;
        }

        bool esUltimoHijo = (idx == numClaves);

        if (hijos[idx]->numClaves < grado)
            llenar(idx, grado);

        if (esUltimoHijo && idx > numClaves)
            hijos[idx - 1]->eliminar(k, grado);
        else
            hijos[idx]->eliminar(k, grado);
    }
}

void Nodo::eliminarDeHoja(int idx) {
    for (int i = idx + 1; i < numClaves; ++i)
        claves[i - 1] = claves[i];

    numClaves--;
}

void Nodo::eliminarDeNoHoja(int idx, int grado) {
    int k = claves[idx];

    if (hijos[idx]->numClaves >= grado) {
        int pred = obtenerPredecesor(idx);
        claves[idx] = pred;
        hijos[idx]->eliminar(pred, grado);
    } else if (hijos[idx + 1]->numClaves >= grado) {
        int succ = obtenerSucesor(idx);
        claves[idx] = succ;
        hijos[idx + 1]->eliminar(succ, grado);
    } else {
        fusionar(idx, grado);
        hijos[idx]->eliminar(k, grado);
    }
}

int Nodo::obtenerPredecesor(int idx) {
    Nodo* cur = hijos[idx];
    while (!cur->esHoja)
        cur = cur->hijos[cur->numClaves];

    return cur->claves[cur->numClaves - 1];
}

int Nodo::obtenerSucesor(int idx) {
    Nodo* cur = hijos[idx + 1];
    while (!cur->esHoja)
        cur = cur->hijos[0];

    return cur->claves[0];
}

void Nodo::llenar(int idx, int grado) {
    if (idx != 0 && hijos[idx - 1]->numClaves >= grado)
        prestarDeAnterior(idx);
    else if (idx != numClaves && hijos[idx + 1]->numClaves >= grado)
        prestarDeSiguiente(idx);
    else {
        if (idx != numClaves)
            fusionar(idx, grado);
        else
            fusionar(idx - 1, grado);
    }
}

void Nodo::prestarDeAnterior(int idx) {
    Nodo* hijo = hijos[idx];
    Nodo* hermano = hijos[idx - 1];

    for (int i = hijo->numClaves - 1; i >= 0; --i)
        hijo->claves[i + 1] = hijo->claves[i];

    if (!hijo->esHoja) {
        for (int i = hijo->numClaves; i >= 0; --i)
            hijo->hijos[i + 1] = hijo->hijos[i];
    }

    hijo->claves[0] = claves[idx - 1];

    if (!hijo->esHoja)
        hijo->hijos[0] = hermano->hijos[hermano->numClaves];

    claves[idx - 1] = hermano->claves[hermano->numClaves - 1];

    hijo->numClaves += 1;
    hermano->numClaves -= 1;
}

void Nodo::prestarDeSiguiente(int idx) {
    Nodo* hijo = hijos[idx];
    Nodo* hermano = hijos[idx + 1];

    hijo->claves[hijo->numClaves] = claves[idx];

    if (!hijo->esHoja)
        hijo->hijos[hijo->numClaves + 1] = hermano->hijos[0];

    claves[idx] = hermano->claves[0];

    for (int i = 1; i < hermano->numClaves; ++i)
        hermano->claves[i - 1] = hermano->claves[i];

    if (!hermano->esHoja) {
        for (int i = 1; i <= hermano->numClaves; ++i)
            hermano->hijos[i - 1] = hermano->hijos[i];
    }

    hijo->numClaves += 1;
    hermano->numClaves -= 1;
}

void Nodo::fusionar(int idx, int grado) {
    Nodo* hijo = hijos[idx];
    Nodo* hermano = hijos[idx + 1];

    hijo->claves[grado - 1] = claves[idx];

    for (int i = 0; i < hermano->numClaves; ++i)
        hijo->claves[i + grado] = hermano->claves[i];

    if (!hijo->esHoja) {
        for (int i = 0; i <= hermano->numClaves; ++i)
            hijo->hijos[i + grado] = hermano->hijos[i];
    }

    for (int i = idx + 1; i < numClaves; ++i)
        claves[i - 1] = claves[i];

    for (int i = idx + 2; i <= numClaves; ++i)
        hijos[i - 1] = hijos[i];

    hijo->numClaves += hermano->numClaves + 1;
    numClaves--;

    delete hermano;
}


#endif