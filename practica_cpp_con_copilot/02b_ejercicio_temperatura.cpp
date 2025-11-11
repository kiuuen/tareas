/*
 * EJERCICIO 2B: Conversor de temperatura
 * 
 * TAREA:
 * - Declara una variable celsius = 25.0
 * - Convierte a Fahrenheit: F = C * 9/5 + 32
 * - Convierte a Kelvin: K = C + 273.15
 * - Imprime los tres valores
 * 
 * FORMATO ESPERADO:
 * 25°C = 77°F = 298.15K
 */

#include <iostream>

int main() {
    double celsius;
    std::cout << "Introduce la temperatura en celsius";
    std::cin >> celsius;
    double conversionFahrenheit = celsius * 9/5 + 32;
    double conversionKelvin = celsius + 273.15;
    std::cout << "Eso quivale a = " << conversionFahrenheit << " fahrenheits y a = " << conversionKelvin << " kelvins";
    return 0;
}
