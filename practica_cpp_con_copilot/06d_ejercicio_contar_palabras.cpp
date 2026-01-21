/*
 * EJERCICIO 6D: Contar palabras
 * 
 * TAREA:
 * - Pide una frase al usuario
 * - Cuenta cuántas palabras tiene
 * - Las palabras están separadas por espacios
 * 
 * PISTA: Recorre la cadena y cuenta las transiciones de espacio a no-espacio
 * 
 * EJEMPLO:
 * Introduce una frase: Hola mundo desde C++
 * La frase tiene 4 palabras
 */

#include <iostream>
#include <string>

int main() {
    std::string cadena;
    int contarEspacios = 1; // empieza en 1 porque la primera palabra no tiene espacio
    std::cout << "Introduce una frase: ";
    std::getline(std::cin, cadena);
    for (size_t n = 0; n <= cadena.size(); n++) {
        if (cadena[n] == (' ')) {
            contarEspacios++;
        }
    }
    std::cout << "La frase tiene" << contarEspacios << " palabras";
    return 0;
}
