#include "Mochila.h"

int main() {
    int numArticulos = 4;
    Articulo** articulos = new Articulo*[numArticulos]; // Arreglo dinámico de punteros a Articulo

    // Crear los artículos
    articulos[0] = new Articulo("Rojo", 4, 10);
    articulos[1] = new Articulo("Azul", 3, 40);
    articulos[2] = new Articulo("Verde", 5, 30);
    articulos[3] = new Articulo("Amarillo", 2, 20);

    float pesoMaximo = 8;
    // Crear la mochila y pasar los artículos
    Mochila mochila(pesoMaximo, articulos, numArticulos);

    // Llenar la mochila
    mochila.llenarMochila();

    return 0;
}
