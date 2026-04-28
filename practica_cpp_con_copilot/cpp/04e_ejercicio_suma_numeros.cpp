/*
 * EJERCICIO 4E: Suma de números
 * 
 * TAREA:
 * - Pide al usuario cuántos números quiere sumar
 * - Lee esa cantidad de números usando un bucle
 * - Muestra la suma total
 * 
 * EJEMPLO:
 * ¿Cuántos números quieres sumar? 5
 * Introduce el número 1: 10
 * Introduce el número 2: 20
 * Introduce el número 3: 5
 * Introduce el número 4: 15
 * Introduce el número 5: 8
 * La suma total es: 58
 */

#include <iostream>
int total = 0;
int main() {
    std::cout << "Cuantos numeros desea sumar?: " << '\n';
    int cantidad;
    std::cin >> cantidad;
    for (int n = 1;n <= cantidad; n++) {
        std::cout << "Introduce el numero " << n << ": ";
        int sumatoria;
        std::cin >> sumatoria;
        total += sumatoria;
    }
    std::cout << "La suma total es: " << total;
    
    return 0;
}
