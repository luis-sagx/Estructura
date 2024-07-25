#include "ListaAlCuadrado.h"
using namespace std;

int main(){
    insertar(11);
    insertar(22);
    insertar(-1);
    insertar(22);
    insertar(3);
    insertar(11);
    insertar(3);
    insertar(0);
    insertar(-2);
    insertar(22);
    insertar(5);
    insertar(15);
    insertar(12);
    insertar(27);
    insertar(-10);
    printf("Lista original:\n");
    imprimir();
    printf("Lista luego de eliminar los numeros repetidos:\n");
    eliminar();
    imprimir();
    sumarLista();
    insertarCuadrados();
    imprimirListaCuadrados();
    return 0;
}