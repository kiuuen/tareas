/*
 * EJERCICIO 15C: Implementar Insertion Sort
 * 
 * TAREA:
 * Implementa el algoritmo Insertion Sort (ordenamiento por inserción).
 * 
 * 1. Crea una función void insertionSort(vector<int>& v) que:
 *    - Para cada elemento desde la posición 1:
 *      a) Guarda el elemento actual como "clave"
 *      b) Mueve hacia la derecha todos los elementos mayores que la clave
 *      c) Inserta la clave en su posición correcta
 *    - Es como ordenar cartas en tu mano
 * 
 * 2. En main():
 *    - Crea el vector: {12, 11, 13, 5, 6}
 *    - Muestra el estado después de insertar cada elemento
 *    - Muestra el vector final ordenado
 * 
 * PISTAS:
 * - Bucle externo: i de 1 a n-1
 * - int clave = v[i]; int j = i - 1;
 * - while (j >= 0 && v[j] > clave): mover v[j] a v[j+1], j--
 * - v[j+1] = clave (insertar en su lugar)
 * 
 * EJEMPLO DE SALIDA:
 * Original: 12 11 13 5 6
 * Insertar 11: [11, 12, 13, 5, 6]
 * Insertar 13: [11, 12, 13, 5, 6]  (ya en posición)
 * Insertar 5:  [5, 11, 12, 13, 6]
 * Insertar 6:  [5, 6, 11, 12, 13]
 * 
 * Ordenado: 5 6 11 12 13
 */

// Tu código aquí
#include <iostream>
#include <vector>
#include <algorithm>

void selectionSort(std::vector<int>& v) {
    for (int i = 1; i < static_cast<int>(v.size()); i++) {
        if (i == 1) {
            std::cout << "\nOriginal: ";
            for (int in : v) {
                std::cout << in << " ";
            }
        }
        int clave = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > clave) { // todos los elementos mayores a el segundo elemento
            v[j] = v[j+1];
            j--;
        }
        v[j+1] = clave; // pongo el segundo elemento en el primer espacio (siguiente iteracion: el tercer elemento será el segundo elemento)
        std::cout << "\nInsertar " << clave << ": ";
        for (int in : v) {
            std::cout << in << " ";
        } 
    }
}
int main() {
    std::vector<int> vectorNumeros{12, 11, 13, 5, 6};
    selectionSort(vectorNumeros);
}