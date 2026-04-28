/*
 * EJERCICIO 6B: Palíndromo
 * 
 * TAREA:
 * - Pide una palabra al usuario
 * - Determina si es un palíndromo (se lee igual al revés)
 * - Ignora mayúsculas/minúsculas
 * 
 * PISTA: Compara caracteres desde los extremos hacia el centro
 * 
 * EJEMPLO:
 * Introduce una palabra: radar
 * "radar" es un palíndromo
 * 
 * Introduce una palabra: hola
 * "hola" no es un palíndromo
 */

#include <iostream>
#include <string>
#include <algorithm>

std::string detectorPalindromos(std::string palabra) {
    size_t pos1 = 0;
    size_t pos2 = palabra.size() - 1;
    while (pos1 < pos2) {
        if (palabra[pos1] != palabra[pos2]) {
            return "No es palindromo";
        }
        pos1++;
        --pos2;
    }
    return "Es palindromo";
}
int main() {
    std::cout << "Detector palindromos, introduce la palabra: ";
    std::string palabra;
    std::cin >> palabra;
    std::cout << detectorPalindromos(palabra);
    return 0;
}
