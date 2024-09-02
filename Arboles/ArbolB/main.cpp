#include "ArbolB.h"

int main() {
    int grado = 2;
    ArbolB arbolB(grado);

    arbolB.insertar(10);
    arbolB.insertar(20);
    arbolB.insertar(5);
    arbolB.insertar(6);
    arbolB.insertar(12);
    arbolB.insertar(30);
    arbolB.insertar(7);
    arbolB.insertar(17);

    cout << "Recorrido del árbol B construido: ";
    arbolB.recorrer();

    return 0;
}