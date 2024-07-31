#include "ArbolBinario.h"

int main() {
    ArbolBinario arbol =  ArbolBinario(10);
    arbol.insertar(1);
    arbol.insertar(2);
    arbol.insertar(3);
    arbol.insertar(4);
    arbol.insertar(5);
    arbol.insertar(6);
    arbol.insertar(8);
    arbol.insertar(11);
    arbol.insertar(8);
    arbol.insertar(44);

    cout << "Recorrido en inorden del arbol: ";
    arbol.recorrerInorden(arbol.raiz);
    cout << endl;

    cout << "Recorrido en preorden del arbol: ";
    arbol.recorrerPreorden(arbol.raiz);
    cout << endl;

    cout << "Recorrido en postorden del arbol: ";
    arbol.recorrerPostorden(arbol.raiz);
    cout << endl;

    return 0;
}
