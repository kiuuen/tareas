/*
 * EJERCICIO 9C: Contador de caracteres
 * 
 * TAREA:
 * - Pide una cadena al usuario
 * - Usa un unordered_map<char, int> para contar la frecuencia de cada carácter
 * - Muestra los resultados (ignora espacios)
 * 
 * EJEMPLO:
 * Introduce un texto: hola mundo
 * 
 * Frecuencia de caracteres:
 * h: 1
 * o: 2
 * l: 1
 * a: 1
 * m: 1
 * u: 1
 * n: 1
 * d: 1
 */

#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::cout << "Introduce una cadena de texto: ";
    std::string cadena;
    std::getline(std::cin, cadena);
    std::unordered_map<char, int> numLetras;
    for (char caracteres : cadena) {
        if (std::isspace(static_cast<unsigned char>(caracteres))) {
            continue; 
        }
        numLetras[caracteres]++;
        // pasamos caracter a caracter la cadena
        // "hola" seria 'h' 'o' 'l' 'a'
        // si h no existe, el operator[] crea ['h', 0] y luego el incremento ++ a ['h', 1]
        // es decir, va contando!
    }
    std::cout << "Frecuencia letras\n";
    for (const auto& contador : numLetras) {
    std::cout << contador.first << " aparece: " << contador.second << " veces\n";
    }
    return 0;
}
