#include "ArbolBmas.h"

int main() {
    int grado = 3;
    ArbolBmas arbolBmas(grado);

    arbolBmas.insertar(10);
    arbolBmas.insertar(20);
    arbolBmas.insertar(5);
    arbolBmas.insertar(6);
    arbolBmas.insertar(12);
    arbolBmas.insertar(30);
    arbolBmas.insertar(7);
    arbolBmas.insertar(17);

    cout << "Recorrido del arbol B+ construido: ";
    arbolBmas.recorrer();

    return 0;
}