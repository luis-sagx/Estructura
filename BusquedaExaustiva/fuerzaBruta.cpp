#include <iostream>
#include <string>

void fuerzaBrutaBusquedaCadenas(const std::string& text, const std::string& pattern) {
    int n = text.length();
    int m = pattern.length();
    int contadorIteraciones = 0;

    // Recorrer el texto hasta el punto donde el patrón puede caber
    for (int i = 0; i <= n - m; i++) {
        int j;
        // Comparar el patrón con la subcadena de text que empieza en la posición i
        for (j = 0; j < m; j++) {
            contadorIteraciones++;
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        // Si j alcanzó el tamaño del patrón, significa que se encontró una coincidencia
        if (j == m) {
            std::cout << "Patron encontrado en el indice " << i << std::endl;
        }
    }
    
    // Mostrar el número total de iteraciones realizadas
    std::cout << "Numero de iteraciones para el patron " << pattern << ": " << contadorIteraciones << std::endl;
}

int main() {
    std::string text = "coliflor";
    std::string pattern = "flor";

    std::cout << "Palabra: " << text << std::endl;
    
    fuerzaBrutaBusquedaCadenas(text, pattern);

    return 0;
}
