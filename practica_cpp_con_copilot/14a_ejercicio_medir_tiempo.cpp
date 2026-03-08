/*
 * EJERCICIO 14A: Medir tiempo de ejecución
 * 
 * TAREA:
 * Escribe dos funciones que resuelvan el MISMO problema de formas distintas
 * y mide cuál es más rápida:
 * 
 * Problema: Dado un vector de N números, encontrar si hay algún duplicado.
 * 
 * 1. Función tieneDuplicados_ON2(vector<int>& v):
 *    - Usa dos bucles anidados (fuerza bruta) → O(n²)
 *    - Compara cada par de elementos
 * 
 * 2. Función tieneDuplicados_ON(vector<int>& v):
 *    - Usa un unordered_set (hash set) → O(n)
 *    - Recorre una vez: si el elemento ya está en el set, hay duplicado
 * 
 * 3. En main():
 *    - Genera un vector de 50,000 números aleatorios (entre 0 y 100,000)
 *    - Mide el tiempo de cada función usando <chrono>
 *    - Muestra cuánto tardó cada una
 * 
 * PISTAS:
 * - #include <chrono> para medir tiempo
 * - #include <unordered_set> para el hash set
 * - #include <cstdlib> para rand()
 * - auto inicio = std::chrono::high_resolution_clock::now();
 *   // ... código ...
 *   auto fin = std::chrono::high_resolution_clock::now();
 *   auto duracion = std::chrono::duration_cast<std::chrono::milliseconds>(fin - inicio);
 * 
 * EJEMPLO DE SALIDA:
 * Vector de 50000 elementos generado
 * 
 * O(n²) - Fuerza bruta: 2450 ms → Resultado: tiene duplicados
 * O(n)  - Hash set:      3 ms   → Resultado: tiene duplicados
 * 
 * ¡La versión O(n) fue ~816x más rápida!
 */

// Tu código aquí
#include <chrono>
#include <vector>
#include <unordered_set>
#include <iostream>
#include <cstdlib>

std::string tieneDuplicados_ON2 (std::vector<int>& vector) {
    for (size_t n = 0; n < vector.size(); n++) {
        for (size_t m = n+1; m < vector.size(); m++) {
            if (vector.at(n) == vector.at(m)) {
                return "Resultado: tiene duplicados";
            }
        }
    }
    return "Resultado: no tiene duplicados";
}
std::string tieneDuplicados_ON(std::vector<int>& vector) {
    std::unordered_set<int> setNumeros;
    for (const int& i : vector) {
        if (!setNumeros.insert(i).second) {
            return "Resultado: tiene duplicados";
        }
    }
    return "Resultado: no tiene duplicados";
}
int main() {
    auto inicio = std::chrono::high_resolution_clock::now();
    auto fin = std::chrono::high_resolution_clock::now();
    auto duracion = std::chrono::duration_cast<std::chrono::milliseconds>(fin - inicio);
    std::vector<int> listaNumeros;
    // int numRand;
    for (int n = 1; n < 30001; n++) {
        // numRand = rand() % 100001;
        listaNumeros.push_back(n);
    }
    std::cout << "Vector de 30,000 de elementos generado" << std::endl;
    inicio = std::chrono::high_resolution_clock::now();
    std::cout << tieneDuplicados_ON2(listaNumeros) << std::endl;
    fin = std::chrono::high_resolution_clock::now();
    duracion = std::chrono::duration_cast<std::chrono::milliseconds>(fin - inicio);
    auto duracionTemp = duracion;
    std::cout << "O(n^2) fuerza bruta tarda: " << duracion.count() << " milisegundos" << std::endl;
    inicio = std::chrono::high_resolution_clock::now();
    std::cout << tieneDuplicados_ON(listaNumeros) << std::endl;
    fin = std::chrono::high_resolution_clock::now();
    duracion = std::chrono::duration_cast<std::chrono::milliseconds>(fin - inicio);
    std::cout << "O(n) usando hash set tarda: " << duracion.count() << " milisegundos" << std::endl;
    std::cout << "O(n) es mas rapido que O(n^2) por: " << static_cast<int>(duracionTemp.count())/static_cast<int>(duracion.count()) << "x veces" << std::endl;
}