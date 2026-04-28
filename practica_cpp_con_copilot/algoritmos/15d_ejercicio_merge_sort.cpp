/*
 * EJERCICIO 15D: Implementar Merge Sort
 * 
 * TAREA:
 * Implementa el algoritmo Merge Sort usando recursión.
 * Es un algoritmo divide y vencerás con complejidad O(n log n) siempre.
 * 
 * EJEMPLO DE SALIDA:
 * Original: 38 27 43 3 9 82 10
 * Ordenado:  3  9 10 27 38 43 82
 */

// Tu código aquí
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cstdlib>
void merge(std::vector<int>& vector, int izq, int mid, int der) {
    std::vector<int> temp;
    int i = izq;
    int j = mid + 1;
    while (i <= mid && j <= der) {
        if (vector[i] <= vector[j]) {
            temp.push_back(vector[i]);
            i++;
        } else{
            temp.push_back(vector[j]);
            j++;
        }
    }
    while (i <= mid) {
        temp.push_back(vector[i]);
        i++;
    }
    while (j <= der) {
        temp.push_back(vector[j]);
        j++;
    }
    for (int k = 0; k < temp.size(); k++) {
        vector[izq + k] = temp[k];
    }
}

void mergeSort(std::vector<int>& vector, int izq, int der) {
    // izq es el indice donde inicia, der es donde termina
    // cada recursividad  divido el rango a la mitad
    int mid = izq + (der - izq)/2;
    if (izq >= der) { // cuando queda un solo elemento
        return;
    }
    std::cout << "\nProcesando izquierda" << izq << ", " << mid << std::endl;
    mergeSort(vector, izq, mid);
    std::cout << "\nProcesando derecha" << izq << ", " << mid << std::endl;
    mergeSort(vector, mid+1, der);
    std::cout << "\nFusionando" << izq << ", " << mid << std::endl;
    merge(vector, izq, mid, der);
}
int main() {
    auto inicio = std::chrono::high_resolution_clock::now();
    auto fin = std::chrono::high_resolution_clock::now();
    auto duracion = std::chrono::duration_cast<std::chrono::milliseconds>(fin - inicio);
    std::vector<int> vectorInt{38, 27, 43, 3, 9, 82, 10};
    /*
    int random;
    for (int n = 0; n <= 10000; n++) {
        random = rand() % 100000;
        vectorInt.push_back(random);
    }
    */
    std::cout << "Original: ";
    for (int& v : vectorInt) {
        std::cout << v << " ";
    }
    int izq = 0;
    int der = static_cast<int>(vectorInt.size()-1);
    inicio = std::chrono::high_resolution_clock::now();
    mergeSort(vectorInt, izq, der);
    std::cout << "\nOrdenado:";
        for (int& v : vectorInt) {
        std::cout << v << " ";
    }
    fin = std::chrono::high_resolution_clock::now();
    duracion = std::chrono::duration_cast<std::chrono::milliseconds>(fin - inicio);
    std::cout << "Tiempo en ms: " << duracion.count() << std::endl;
 }