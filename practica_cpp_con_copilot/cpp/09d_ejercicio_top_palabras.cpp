/*
 * EJERCICIO 9D: Top 3 palabras más frecuentes
 * 
 * TAREA (DESAFÍO):
 * - Dado un vector de palabras
 * - Cuenta la frecuencia de cada palabra usando unordered_map
 * - Encuentra las 3 palabras más frecuentes
 * - Muestra los resultados en orden de frecuencia
 * 
 * PISTA: 
 * 1. Cuenta frecuencias en un map
 * 2. Copia los pares a un vector
 * 3. Ordena el vector por frecuencia (descendente)
 * 4. Muestra los primeros 3
 * 
 * EJEMPLO:
 * Palabras: {"hola", "mundo", "hola", "C++", "mundo", "hola", "adios", "mundo"}
 * 
 * Top 3:
 * 1. hola: 3
 * 2. mundo: 3
 * 3. adios: 1
 */
#include <sstream>
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
int main() {
    std::cout << "Introduce la cadena: ";
    std::string cadenaInput;
    std::getline(std::cin, cadenaInput);
    std::istringstream cadenaStream(cadenaInput);
    std::vector<std::string> vectorPalabras;
    std::string palabrasIndividuales;
    std::unordered_map<std::string, int> mapPalabras;
    std::vector<std::pair<std::string, int>> vectorPalabrasConKeys;

    while (cadenaStream >> palabrasIndividuales) {
        vectorPalabras.push_back(palabrasIndividuales);
        // para mas aprendizaje estos cout
        std::cout << "\nSe agregó la palabra: " << palabrasIndividuales;
    }

    for (const std::string& contador : vectorPalabras) {
        std::cout << "\nFor each recorrió a la posición: " << contador;
        mapPalabras[contador]++;
        std::cout << "\nSe agregó al map, ahora es (valor de la key): " << mapPalabras.at(contador);
    }
    std::cout << "\nSe terminó de agregar palabras al map";
    vectorPalabrasConKeys.reserve(mapPalabras.size());
    std::cout << "\nSe reservó en memoria: " << mapPalabras.size();
    for (const auto& reemplazar : mapPalabras) {
        vectorPalabrasConKeys.emplace_back(reemplazar.first, reemplazar.second);
        std::cout << "\nReemplazando hacia el vector pair, clave: " << reemplazar.first << " key: " << reemplazar.second;
    }
    std::cout << "\nSe terminó con el reemplazo";
    std::sort(vectorPalabrasConKeys.begin(), vectorPalabrasConKeys.end(), 
        [](const auto &a, const auto &b) {
        if (a.second != b.second) {
            return a.second > b.second; // primero ordena por tamaño
        }
            return a.first < b.first; // luego ordena alfabeticamente en caso de empatar
        });
    std::cout << "\nPalabras ordenadas según aparición (todas): \n";
    for (const auto& contador : vectorPalabrasConKeys) {
        std::cout << "La palabra: " << contador.first << " que aparece: " << contador.second << "\n";
    }
    std::cout << "\nPalabras ordenadas según aparición (top 3): ";
    for (size_t n = 0; n < 3; n++){
            std::cout << "\n" << (n+1) << ") la palabra: " << vectorPalabrasConKeys[n].first << " que aparece: " << vectorPalabrasConKeys[n].second;
        }
    return 0;
}
