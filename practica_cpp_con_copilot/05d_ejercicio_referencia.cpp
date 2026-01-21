/*
 * EJERCICIO 5D: Paso por referencia - Incremento
 * 
 * TAREA:
 * Crea dos funciones para ver la diferencia entre paso por valor y referencia:
 * 
 * 1. void incrementarPorValor(int x)
 *    - Incrementa x en 1
 *    - NO modifica el original
 * 
 * 2. void incrementarPorReferencia(int& x)
 *    - Incrementa x en 1
 *    - SÍ modifica el original (nota el &)
 * 
 * En main(), prueba ambas con el mismo número inicial
 * 
 * EJEMPLO:
 * int num = 5;
 * incrementarPorValor(num);
 * // num sigue siendo 5
 * 
 * incrementarPorReferencia(num);
 * // num ahora es 6
 */

#include <iostream>

void incrementarPorValor(int numeroOriginal) {
    numeroOriginal++;
}
void incrementarPorReferencia(int& numeroOriginal) {
    numeroOriginal++;
}
int main() {
    int numero;
    std::cout << "Introduce el número ";
    std::cin >> numero;
    incrementarPorValor(numero);
    std::cout << "Numero original: " << numero << "\nPasado por valor es " << numero;
    incrementarPorReferencia(numero);
    std::cout << "\nPor referencia ahora vale: " << numero;    
    return 0;
}

