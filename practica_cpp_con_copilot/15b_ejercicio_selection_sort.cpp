/*
 * EJERCICIO 15B: Implementar Selection Sort
 * 
 * TAREA:
 * Implementa el algoritmo Selection Sort (ordenamiento por selección).
 * 
 * 1. Crea una función void selectionSort(vector<int>& v) que:
 *    - Para cada posición i (de 0 a n-1):
 *      a) Encuentra el MÍNIMO en el subvector [i, n-1]
 *      b) Intercambia el mínimo con el elemento en posición i
 *    - Después de cada iteración, los primeros i elementos están ordenados
 * 
 * 2. En main():
 *    - Crea el vector: {29, 10, 14, 37, 13}
 *    - Muestra el estado del vector después de cada selección
 *    - Muestra el vector final ordenado
 * 
 * PISTAS:
 * - Bucle externo: i de 0 a n-1
 * - Bucle interno: j de i+1 a n-1 (buscar mínimo)
 * - Guarda el ÍNDICE del mínimo, no el valor
 * - Al final del bucle interno: swap(v[i], v[indiceMin])
 * 
 * EJEMPLO DE SALIDA:
 * Original: 29 10 14 37 13
 * Paso 1: mínimo=10 (pos 1) → swap con pos 0 → [10, 29, 14, 37, 13]
 * Paso 2: mínimo=13 (pos 4) → swap con pos 1 → [10, 13, 14, 37, 29]
 * Paso 3: mínimo=14 (pos 2) → ya está         → [10, 13, 14, 37, 29]
 * Paso 4: mínimo=29 (pos 4) → swap con pos 3 → [10, 13, 14, 29, 37]
 * 
 * Ordenado: 10 13 14 29 37
 */

// Tu código aquí
