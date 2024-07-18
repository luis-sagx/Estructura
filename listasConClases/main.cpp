#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include "Lista.h"
using namespace std;

int main(){
    Lista lista;
    lista.insertarInicio(0);
    lista.insertarInicio(11);
    lista.insetarFinal(99);
    lista.insertarInicio(77);
    lista.mostrarLista();
    return 0;
}