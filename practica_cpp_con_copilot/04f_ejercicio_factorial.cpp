/*
 * EJERCICIO 4F: Factorial
 * 
 * TAREA:
 * - Pide un número N al usuario
 * - Calcula N! = N × (N-1) × (N-2) × ... × 1
 * - Usa un bucle for o while
 * 
 * EJEMPLO:
 * Introduce un número: 5
 * 5! = 120
 * 
 * EXPLICACIÓN: 5! = 5 × 4 × 3 × 2 × 1 = 120
 */

#include <iostream>

int main() {
    unsigned long long total = 1;
    std::cout << "Introduce el numero N ";
    int numero; 
    std::cin >> numero;
    for (int l = 1; l <= numero; l++) {
        total *= l;
    }
    std::cout << numero << "! = " << total << '\n';
    return 0;
}
