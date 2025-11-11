/*
 * EJERCICIO 3A: Calculadora con entrada de usuario
 * 
 * TAREA:
 * - Pide al usuario dos números
 * - Calcula y muestra:
 *   * Suma
 *   * Resta
 *   * Multiplicación
 *   * División
 * 
 * EJEMPLO:
 * Introduce el primer número: 10
 * Introduce el segundo número: 3
 * 10 + 3 = 13
 * 10 - 3 = 7
 * 10 * 3 = 30
 * 10 / 3 = 3.33333
 */

#include <iostream>

int main() {
    std::cout << "Introduce el primer numero";
    double numero1;
    std::cin >> numero1;
    std::cout << "Introduce el segundo numero";
    double numero2;
    std::cin >> numero2;
    std::cout << "La suma da = " << (numero1 + numero2) << '\n';
    std::cout << "La resta da = " << (numero1 - numero2) << '\n';
    std::cout << "La multiplicacion da = " << (numero1*numero2) << '\n';
    std::cout << "La division da = " << (numero1/numero2) << '\n';
    return 0;
}
