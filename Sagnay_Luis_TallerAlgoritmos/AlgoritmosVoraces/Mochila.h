#ifndef ARTICULO_H
#define ARTICULO_H

#include "Articulo.h"

class Mochila {
private:
    Articulo** articulos; // Arreglo dinámico de punteros a Articulo
    int numArticulos;
    float pesoMaximo;
    float pesoActual;
    float gananciaTotal;
    int iteraciones;

public:
    Mochila(float pesoMaximo, Articulo** articulosExternos, int numArticulos) {
        this->pesoMaximo = pesoMaximo;
        this->pesoActual = 0;
        this->gananciaTotal = 0;
        this->iteraciones = 0;
        this->numArticulos = numArticulos;
        
        // Asignar y copiar los artículos desde el arreglo externo
        articulos = new Articulo*[numArticulos];
        for (int i = 0; i < numArticulos; i++) {
            articulos[i] = articulosExternos[i];
        }

        // Ordenar artículos por valor por peso (de mayor a menor)
        ordenarArticulos();
    }

    void ordenarArticulos() {
        for (int i = 0; i < numArticulos; i++) {
            for (int j = i + 1; j < numArticulos; j++) {
                if (articulos[i]->valorPorPeso < articulos[j]->valorPorPeso) {
                    swap(articulos[i], articulos[j]);
                }
            }
        }
    }

    void llenarMochila() {
        cout << "Artículos seleccionados:" << endl;

        while (pesoActual < pesoMaximo) {
            bool agregado = false;
            for (int i = 0; i < numArticulos; i++) {
                if (pesoActual + articulos[i]->peso <= pesoMaximo) {
                    pesoActual += articulos[i]->peso;
                    gananciaTotal += articulos[i]->ganancia;
                    cout << "Agregado: " << articulos[i]->nombre << endl;
                    iteraciones++;
                    agregado = true;
                    break;
                }
            }
            if (!agregado) {
                break; // No se pudo agregar ningún artículo
            }
        }

        cout << "Ganancia total: $" << gananciaTotal << endl;
        cout << "Peso total: " << pesoActual << "kg" << endl;
        cout << "Número de iteraciones: " << iteraciones << endl;
    }
};

#endif