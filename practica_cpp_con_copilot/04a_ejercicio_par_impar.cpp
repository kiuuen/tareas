/*
 * EJERCICIO 4A: Par o Impar
 * 
 * TAREA:
 * - Pide un número al usuario
 * - Determina si es par o impar
 * - Usa el operador % (módulo)
 * 
 * PISTA: Un número es par si numero % 2 == 0
 */

#include <iostream>

int main() {
    std::cout << "Introduce un número par";
    int numero;
    std::cin >> numero;
    if (numero % 2 == 0) {
        std::cout << "El numero es par" << '\n';
    }
    else {
        std::cout << "El numero es impar" << '\n';
    }
    return 0;
}
