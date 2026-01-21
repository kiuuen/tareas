/*
 * EJERCICIO 7B: Contar vocales recursivo (mejorado)
 * 
 * TAREA:
 * Crea una versión MEJORADA de tu ejercicio nov_11_3.java:
 * 
 * int contarVocales(const std::string& s, size_t idx = 0)
 * 
 * MEJORAS sobre tu versión Java:
 * - NO uses variables globales
 * - RETORNA el resultado en lugar de imprimirlo
 * - Convierte a minúsculas dentro de la función
 * - Usa índice en lugar de substring (más eficiente)
 * 
 * En main():
 * - Pide una cadena al usuario
 * - Llama a la función y muestra el resultado
 * 
 * EJEMPLO:
 * Introduce una cadena: Hola Mundo
 * La cadena tiene 4 vocales
 */

#include <iostream>
#include <string>
#include <algorithm>

int contarVocales(const std::string& palabra, size_t pos = 0) {
    if (pos == palabra.size()) {
        return 0;
    }
    std::string palabraCopia = palabra;
    std::transform(palabraCopia.begin(), palabraCopia.end(), palabraCopia.begin(),
     [](unsigned char c) { return std::tolower(c);});
    char charPos = palabraCopia[pos];
    int esVocal = charPos == 'a' || charPos == 'e' || charPos == 'i' || charPos == 'o' || charPos == 'u' ? 1 : 0; // ternario, si se cumple esVocal vale 1, si no se cumple vale 0
    return esVocal + contarVocales(palabra, pos + 1); // pos++ da error por como funciona las llamadas en c++, primero evalua luego incrementa pos por lo que no se hace la recursividad como tal
}
int main() {
    std::cout << "Introduce la cadena: ";
    std::string cadena;
    std::getline(std::cin, cadena);
    int totalVocales = contarVocales(cadena);
    std::cout << "La palabra tiene: " << totalVocales << " vocales";
    return 0;
}
