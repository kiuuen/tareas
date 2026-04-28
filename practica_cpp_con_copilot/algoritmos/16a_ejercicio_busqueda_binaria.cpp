/*
 * EJERCICIO 16A: Implementar búsqueda binaria
 * 
 * TAREA:
 * Implementa búsqueda binaria desde cero (sin usar std::binary_search).
 * Dado un vector ORDENADO y un target, retorna su índice o -1 si no existe.
 * Incluye un contador de comparaciones para analizar la eficiencia.
 * 
 * EJEMPLO DE SALIDA:
 * Vector: 2 5 8 12 16 23 38 45 56 72 91
 * Buscar 23: encontrado en índice 5 (3 comparaciones)
 * Buscar 72: encontrado en índice 9 (4 comparaciones)
 * Buscar 15: NO encontrado (4 comparaciones)
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cstdlib>
// intento de hacerlo en ingles
int binarySearch(std::vector<int>& vector, int key, int& att) {
    size_t start = 0;
    size_t end = vector.size() - 1;
    size_t mid = start + (end - start) / 2;
    while (start <= end) {
        mid = start + (end - start) / 2;
        if (vector[mid] == key) {
            att++;
            return static_cast<int>(mid); // index where its allocated
        }
        else if (key > vector[mid]) {
            att++;
            start = mid + 1;
            continue;
        } 
        else {
            att++;
            end = mid - 1;
            continue;
        }
    }
    return -1;
}
int main() {
    auto inicio = std::chrono::high_resolution_clock::now();
    auto fin = std::chrono::high_resolution_clock::now();
    auto duracion = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio);
    std::vector<int> vectorNumbers;
    for (int n = 1; n < 100000001; n++) {
        vectorNumbers.push_back(n);
    }
    int key = 10000000;
    int numAtt = 0;
    inicio = std::chrono::high_resolution_clock::now();
    int answ = binarySearch(vectorNumbers, key, numAtt);
    fin = std::chrono::high_resolution_clock::now();
    if (answ == -1) {
        std::cout << "\n" << key << " wasnt found in the arr, attemps: " << numAtt << std::endl;
    } else {
        std::cout << "\n" << key << " was found in the arr, index: " << answ << ", attempts: " << numAtt << std::endl;
    }   
    duracion = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio);
    std::cout << "Total duration " << duracion.count() << " microseconds" << std::endl;
}