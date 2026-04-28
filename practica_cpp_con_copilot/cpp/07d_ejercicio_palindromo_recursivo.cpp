/*
 * EJERCICIO 7D: Palíndromo recursivo
 * 
 * TAREA:
 * Crea una función recursiva bool esPalindromo(const std::string& s)
 * que determine si una cadena es un palíndromo
 * 
 * ESTRATEGIA RECURSIVA:
 * - Caso base: string vacío o de 1 carácter → true
 * - Caso recursivo: 
 *   * Compara primer y último carácter
 *   * Si son iguales, verifica recursivamente el string sin esos extremos
 *   * Si son diferentes, retorna false
 * 
 * EJEMPLO:
 * esPalindromo("radar") = true
 * esPalindromo("hola") = false
 * esPalindromo("anilina") = true
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
std::string copiaPalabra;
bool esPalindromo(const std::string& palabra, size_t posStart = 0, size_t posEnd = std::string::npos) {
    if (posEnd == std::string::npos) {
        posEnd = palabra.size(); // esto solo se hace la primera vez!
        copiaPalabra = palabra;
        std::transform(copiaPalabra.begin(), copiaPalabra.end(), copiaPalabra.begin(),
        [](unsigned char c) {
        return std::tolower(c); });
    }
    if (copiaPalabra[posStart] != copiaPalabra[posEnd -1]) { // empieza n de 0, el ultimo character es en su size -1 
        return false;
    }
    if (posStart >= posEnd) {
        return true;
    }
    return esPalindromo(palabra, posStart + 1, posEnd - 1);
}
int main() {
    std::string palabra;
    std::cout << "Introduce la palabra a detectar: ";
    std::cin >> palabra;
    if (esPalindromo(palabra) == false) {
        std::cout << "No es palindromo" << std::endl;
    } else {
        std::cout << "Es palindromo" << std::endl;
    }
    return 0;
}
