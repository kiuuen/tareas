/*
 * EJERCICIO 2A: Calculadora de área de círculo
 * 
 * TAREA:
 * - Declara una constante PI = 3.14159
 * - Declara una variable radio = 5.0
 * - Calcula el área: area = PI * radio * radio
 * - Calcula el perímetro: perimetro = 2 * PI * radio
 * - Imprime ambos resultados
 */

#include <iostream>

int main() {
    std::cout << "Calculadora de area y perimetro" << '\n' << "Introduce el radio del circulo";
    int radio;
    std::cin >> radio;
    double pi = 3.14159;
    double area = pi * (static_cast<double>(radio)) * (static_cast<double>(radio));
    double perimetro = 2 * pi * radio;
    std::cout << '\n' << "El area es = " << area << " metros cuadrados";
    std::cout << '\n' << "El perimetro es de = " << perimetro << " metros";
    return 0;
}
