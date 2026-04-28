/*
 * EJERCICIO 16B: Primera y última ocurrencia (Estilo LeetCode #34)
 * 
 * TAREA:
 * Dado un vector ORDENADO con posibles repeticiones y un valor target,
 * encuentra la primera y última posición donde aparece.
 * Si no existe, retorna -1 para ambas.
 * 
 * EJEMPLO DE SALIDA:
 * Vector: 1 2 2 2 3 4 4 5 5 5 5 6
 * Valor 2: primera=1, última=3 (aparece 3 veces)
 * Valor 5: primera=7, última=10 (aparece 4 veces)
 * Valor 7: no encontrado
 */
#include <iostream>
#include <vector>
#include <algorithm>

std::pair<int, int> binarySearchConcurrencies(const std::vector<int> vector, int target) {
    int start = 0;
    int end = vector.size() -1 ;
    int mid = start + (end - start) / 2;
    int first = -1;
    int last = -1;
    while (start <= end) {
        mid = start + (end - start) / 2;
        if (vector[mid] == target) {
            first = mid;
            end = mid - 1;
        }
        else if (target > vector[mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    if (first == -1) {
        return {-1, -1};
    }
    end = vector.size()-1;
    start = first;
    while (start <= end) {
        mid = start + (end - start) / 2;
        if (vector[mid] == target) {
            last = mid;
            start = mid + 1;
        }
        else if (target > vector[mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return {first, last};
}
    /* first version, without double search
    if (vector[mid] != target) {
        return -1;
    }
    start = mid;
    posL = mid;
    if (target != vector.back()) {
        while (vector[start + 1] == vector[mid]) { // already know that start its in the vector, so start with the next
        start++;
        }
    }
    if (target != vector.front()) {
        while (vector[posL - 1] == vector[mid]) {
        posL--;
        }
    } 
    if (start == mid && posL == mid) { // if only moves by one, then only appears one time
        return 1;
    } else if ((start - mid) > (mid - posL)) {
        return static_cast<int>((start - mid) - (mid - posL)) + 3;
    }
    return static_cast<int>((mid - posL) - (start - mid)) + 3;
    */
int main() {
    std::vector<int> vectorNumbers{1, 1, 1,2,2,2,2,3,4,4,4,4,4,4,5,5,5,5,6,6, 6, 6, 6, 6, 6};
    std::cout << "original vector: ";
    for (int v: vectorNumbers) {
        std::cout << v<< " ";
    }
    int target = 0;
    while (target <= vectorNumbers.back()) {
        target++;
        auto [first, last] = binarySearchConcurrencies(vectorNumbers, target);
        int concurrencies = last - first + 1;
        if (first == -1) {
            std::cout << "\n0 concurrencies, the target '" << target << "' doesnt below to the vector";
        } else {
            std::cout << "\nthe target '" << target << "' appears: " << concurrencies << " times\nfirst: " << first << ", last: " << last;
        }
    }
}
