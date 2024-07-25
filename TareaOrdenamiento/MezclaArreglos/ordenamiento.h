#include <stdio.h>

void mezclar(int arreglo[], int izquierda, int medio, int derecha) { // Funcion para mezclar dos subarreglos 
    int i, j, k;
    int sizeIzquierda = medio - izquierda + 1; // Tamaño del subarreglo izquierdo
    int sizeDerecha = derecha - medio; // Tamaño del subarreglo derecho

    int arregloIzquierda[sizeIzquierda], arregloDerecha[sizeDerecha]; // arreglos temporales

    for (i = 0; i < sizeIzquierda; i++) // Poner los elementos del subarreglo izquierdo desde el arreglo original a un arreglo temporal
        arregloIzquierda[i] = arreglo[izquierda + i];     // Se pone el elemento i del subarreglo izquierdo del arreglo original en el arreglo temporal
    for (j = 0; j < sizeDerecha; j++) // Pone los elementos del subarreglo derecho desde el arreglo original a un arreglo temporal
        arregloDerecha[j] = arreglo[medio + 1 + j];     // Se pone el elemento j del subarreglo derecho del arreglo original en el arreglo temporal

    i = 0; // indice para el subarreglo izquierdo
    j = 0; // indice para el subarreglo derecho
    k = izquierda; // indice para el arreglo original, empezando desde izquierda

    // Mezclar los subarreglos en el arreglo original
    while (i < sizeIzquierda && j < sizeDerecha) {
        if (arregloIzquierda[i] <= arregloDerecha[j]) { 
            arreglo[k] = arregloIzquierda[i];  // Si el elemento del subarreglo izquierdo es menor o igual, lo ponemos al arreglo original
            i++; //Avanvar para recorrer el subarreglo izquierdo
        } else { 
            arreglo[k] = arregloDerecha[j];   // Si el elemento del subarreglo derecho es menor, lo ponemos al arreglo original
            j++; //Avanvar para recorrer el subarreglo derecho
        }
        k++;    // Avanzar en el arreglo original
    }

    while (i < sizeIzquierda) {
        arreglo[k] = arregloIzquierda[i];  // Mientars queden elementos, se pone los elementos restantes de arregloIzquierda
        i++;    //Avanvar para recorrer el subarreglo izquierdo
        k++;    // Avanzar en el arreglo original
    }

    while (j < sizeDerecha) {
        arreglo[k] = arregloDerecha[j];  // Mientars queden elementos, se pone los elementos restantes de arregloIzquierda
        j++;    //Avanvar para recorrer el subarreglo derecho
        k++;    // Avanzar en el arreglo original
    }
}

void mergeSortArreglos(int arreglo[], int izquierda, int derecha) {
    if (izquierda < derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;         // Encuentra el punto medio del arreglo

        // Ordena la mitad izquierda y mitad derecha
        mergeSortArreglos(arreglo, izquierda, medio);
        mergeSortArreglos(arreglo, medio + 1, derecha);

        // Mezcla las mitades ordenadas
        mezclar(arreglo, izquierda, medio, derecha);
    }
}