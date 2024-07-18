#include <iostream>
using namespace std;

void hanoi(int numDiscos, char origen, char auxiliar, char destino) {
    if (numDiscos == 1) {
        printf("Mover disco 1 de %c a %c\n", origen, destino);
        return;
    }
    hanoi(numDiscos - 1, origen, auxiliar, destino);
    printf("Mover disco %d de %c a %c\n", numDiscos, origen, destino);
    hanoi(numDiscos - 1, auxiliar, destino, origen);
}

int main() {
    int numDiscos;
    cout << "Ingrese el numero de discos: ";
    cin >> numDiscos;
    hanoi(numDiscos, 'A', 'B', 'C');
    return 0;
}
