/*
 * EJERCICIO 4D: Tabla de multiplicar
 * 
 * TAREA:
 * - Pide un número al usuario
 * - Imprime su tabla de multiplicar del 1 al 10
 * - Usa un bucle for
 * 
 * EJEMPLO:
 * ¿De qué número quieres la tabla? 7
 * Tabla del 7:
 * 7 x 1 = 7
 * 7 x 2 = 14
 * 7 x 3 = 21
 * ...
 * 7 x 10 = 70
 */

#include <iostream>

int main() {
    std::cout << "Tabla de multiplicar\nIntroduce el numero" << '\n';
    int numero;
    std::cin >> numero;
    for (int n = 1; n <= 10; n++) {
        std::cout << numero << " x " << n << " = " << numero*n << '\n';
    }
    return 0;
}
