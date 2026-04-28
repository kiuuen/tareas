/*
 * EJERCICIO 16C: Encontrar elemento pico (Estilo LeetCode #162)
 * 
 * TAREA:
 * Un "elemento pico" es aquel mayor que sus vecinos inmediatos.
 * Dado un vector donde no hay elementos iguales adyacentes,
 * encuentra cualquier pico usando búsqueda binaria en O(log n).
 * 
 * EJEMPLOS:
 * Entrada: [1, 3, 5, 4, 2]    → índice 2 (valor 5)
 * Entrada: [1, 2, 3, 4, 5]    → índice 4 (valor 5)
 * Entrada: [3, 2, 1]          → índice 0 (valor 3)
 */

// Tu código aquí

#include <iostream>
#include <vector>
#include <algorithm>

int findPickElement(const std::vector<int> vector) {
    int start = 0;
    int end = vector.size() - 1;
    int mid = start + (end - start)/2;
    while (start <= end) {
        int mid = start + (end - start)/2;
        if (vector[mid] > vector[mid+1] && vector[mid] > vector[mid-1]) {
            return mid;
        }
        else if (vector[mid+1] > vector[mid]) {
            start = mid + 1;
        } else {
            end = mid;
        }
    }
    return -1;
}
int main() {
    std::vector<int> vectorNum{1, 3, 5, 4, 2, 5, 6, 7, 8, 9, 11, 2, 99, 101, 23};
    std::cout << "original vec: ";
    for (int v : vectorNum) {
        std::cout << v << " ";
    }
    int mid = findPickElement(vectorNum);
    if (mid == -1) {
        std::cout << "\ntheres no pick element" << std::endl;
        return 0;
    }
    std::cout << "\npick element: " << vectorNum[mid] << " at index: " << mid; 
    return 0;
}
