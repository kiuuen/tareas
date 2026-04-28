/*
 * EJERCICIO 6C: Invertir cadena
 * 
 * TAREA:
 * - Pide una cadena al usuario
 * - Imprime la cadena invertida
 * 
 * MÉTODO 1: Usa un bucle
 * MÉTODO 2: Usa std::reverse de <algorithm>
 * 
 * EJEMPLO:
 * Introduce una cadena: Hola
 * Invertida: aloH
 */

#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string cadena;
    std::cout << "Introduce una cadena";
    std::getline(std::cin, cadena);
    std::reverse(cadena.begin(), cadena.end());
    std::cout << cadena;
    return 0;
}
