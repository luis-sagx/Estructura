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