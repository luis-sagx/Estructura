#pragma once
#include "registro.h"

class Nodo {
public:
    Registro* registro;
    Nodo* siguiente;

    // Constructor
    Nodo(Registro* reg);
};

