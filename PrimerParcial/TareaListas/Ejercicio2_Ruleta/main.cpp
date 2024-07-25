#include "Ruleta.h"

int main(){
    insertarPremio("Premio 4 -> Mouse");
    insertarPremio("Premio 3 -> Teclado");
    insertarPremio("Premio 2 -> Monitor");
    insertarPremio("Premio 1 -> Parlantes");
    imprimirTodosLosPremios();
    girarRuleta();
    imprimirPremio();
    return 0;
}