/*
 * EJERCICIO 9A: Contador de frecuencias de palabras
 * 
 * TAREA:
 * - Crea un vector de palabras (simula un texto)
 * - Usa un unordered_map para contar cuántas veces aparece cada palabra
 * - Muestra las frecuencias
 * 
 * EJEMPLO:
 * Palabras: {"hola", "mundo", "hola", "C++", "mundo", "hola", "adios"}
 * 
 * Frecuencias:
 * hola: 3
 * mundo: 2
 * C++: 1
 * adios: 1
 */

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <sstream>

int main() {
    std::cout << "Contador de palabras en textos, introduce el texto: ";
    std::string textSpaces;
    std::getline(std::cin, textSpaces);
    std::istringstream whitespaces(textSpaces);
    std::string individualWord;
    std::vector<std::string> separatedWords;
    std::unordered_map<std::string, int> countWordsMap;
    while (whitespaces >> individualWord) {
        separatedWords.push_back(individualWord);
    }
    for (const std::string& word : separatedWords){ // por 
        countWordsMap[word]++; // no es countWordsMap.at[] para que lo cree si no existe
        // ++ aumenta a la siguiente palabra
    } // sólo guardamos las palabras en un unordered map con indíces
    for (const auto& counter : countWordsMap) {
        std::cout << "\nLa palabra: " << counter.first << " aparece: " << counter.second << " veces.";
        // .first nos dice la key y .second la value
    }
    return 0;
}
