#include <iostream>
using namespace std;

class Articulo {
public:
    string nombre;
    float peso;
    float ganancia;
    float valorPorPeso;

    Articulo(string nombre, float peso, float ganancia) {
        this->nombre = nombre;
        this->peso = peso;
        this->ganancia = ganancia;
        this->valorPorPeso = ganancia / peso;
    }
};

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
        
        articulos = new Articulo*[numArticulos];
        for (int i = 0; i < numArticulos; i++) {
            articulos[i] = articulosExternos[i];
        }

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

int main() {
    int numArticulos = 4;
    Articulo** articulos = new Articulo*[numArticulos]; // Arreglo dinámico de punteros a Articulo

    articulos[0] = new Articulo("Rojo", 4, 10);
    articulos[1] = new Articulo("Azul", 3, 40);
    articulos[2] = new Articulo("Verde", 5, 30);
    articulos[3] = new Articulo("Amarillo", 2, 20);

    float pesoMaximo = 8;
    Mochila mochila(pesoMaximo, articulos, numArticulos);
    mochila.llenarMochila();

    return 0;
}
