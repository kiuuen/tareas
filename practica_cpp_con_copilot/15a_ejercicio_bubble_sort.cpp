/*
 * EJERCICIO 15A: Implementar Bubble Sort
 * 
 * TAREA:
 * Implementa el algoritmo Bubble Sort (ordenamiento burbuja) desde cero.
 * 
 * 1. Crea una función void bubbleSort(vector<int>& v) que:
 *    - Recorra el vector comparando elementos adyacentes
 *    - Si v[j] > v[j+1], intercambia (swap)
 *    - Repite hasta que no haya más intercambios
 *    - OPTIMIZACIÓN: Si en una pasada no hubo ningún swap, el vector ya
 *      está ordenado → termina antes (esto lo hace O(n) en mejor caso)
 * 
 * 2. En main():
 *    - Crea el vector: {64, 34, 25, 12, 22, 11, 90}
 *    - Muestra el vector original
 *    - Llama a bubbleSort
 *    - Muestra el vector ordenado
 *    - Muestra cuántas pasadas necesitó
 * 
 * PISTAS:
 * - Para intercambiar: std::swap(v[j], v[j+1])  o hazlo manual con temp
 * - Bucle externo: i de 0 a n-1
 * - Bucle interno: j de 0 a n-i-1 (los últimos ya están en su lugar)
 * - Variable bool "huboSwap" para la optimización
 * 
 * EJEMPLO DE SALIDA:
 * Original: 64 34 25 12 22 11 90
 * Pasada 1: 34 25 12 22 11 64 90
 * Pasada 2: 25 12 22 11 34 64 90
 * Pasada 3: 12 22 11 25 34 64 90
 * Pasada 4: 12 11 22 25 34 64 90
 * Pasada 5: 11 12 22 25 34 64 90
 * Pasada 6: 11 12 22 25 34 64 90 (sin cambios → terminó)
 * 
 * Ordenado: 11 12 22 25 34 64 90
 * Pasadas necesarias: 6
 */

// Tu código aquí
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

void bubbleSort(std::vector<int>& v, int &pasadas){
    std::vector<int> lastSwap;
    for (int n = 0; n < static_cast<int>(v.size()); n++) {
        if (n == 0) {
            std::cout << "Original: ";
            for (int& i : v) {
                std::cout << i << " ";
            }
        }
        pasadas++;
    for (int m = 0; m < static_cast<int>(v.size() - 1); m++) {
        if (v[m] > v[m+1]) {
                std::swap(v[m], v[m+1]);
            }
        }     
        if (lastSwap == v) {
                std::cout << "\nOrdenado: ";
                for (int& i : v) {
                std::cout << i << " ";
                }
                return;
            } else {
                lastSwap.clear();
            }
            std::cout << "\nPasada " << n+1 << ": ";
            for (int& i : v) {
                lastSwap.push_back(i);
                std::cout << i << " ";
            }
        }
    }

int main() {
    int numPasadas = 0;
    std::vector<int> vectorOriginal;
    int numRand;
    for (int n = 0; n < 101; n++) {
        numRand = rand() % 10001;
        vectorOriginal.push_back(numRand);
    }
    std::cout << "Vector desordenado de 100 numeros del 1 al 10000 generado" << std::endl;
    bubbleSort(vectorOriginal, numPasadas);
    std::cout << "\nPasadas: " << numPasadas << std::endl;
}