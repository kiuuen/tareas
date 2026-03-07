/*
 * EJERCICIO 15D: Implementar Merge Sort
 * 
 * TAREA:
 * Implementa el algoritmo Merge Sort (ordenamiento por mezcla) usando recursión.
 * Este es tu primer algoritmo "divide y vencerás".
 * 
 * 1. Crea una función void merge(vector<int>& v, int izq, int mid, int der):
 *    - Mezcla dos subvectores ordenados: v[izq..mid] y v[mid+1..der]
 *    - Usa un vector temporal para la mezcla
 *    - Compara elementos de ambas mitades y coloca el menor primero
 * 
 * 2. Crea una función void mergeSort(vector<int>& v, int izq, int der):
 *    - Caso base: si izq >= der, retorna (1 elemento = ya ordenado)
 *    - Calcula mid = izq + (der - izq) / 2
 *    - Llama mergeSort para la mitad izquierda: mergeSort(v, izq, mid)
 *    - Llama mergeSort para la mitad derecha: mergeSort(v, mid+1, der)
 *    - Llama merge para combinar: merge(v, izq, mid, der)
 * 
 * 3. En main():
 *    - Crea el vector: {38, 27, 43, 3, 9, 82, 10}
 *    - Muestra el vector original
 *    - Llama mergeSort(v, 0, v.size()-1)
 *    - Muestra el resultado
 * 
 * PISTAS:
 * - En merge(): usa dos índices i, j para recorrer cada mitad
 * - while (i <= mid && j <= der): compara y agrega el menor al temp
 * - Después, copia lo que quede de cada mitad
 * - Finalmente copia temp de vuelta a v
 * 
 * EJEMPLO DE SALIDA:
 * Original: 38 27 43 3 9 82 10
 * 
 * Dividiendo: [38, 27, 43] y [3, 9, 82, 10]
 * Dividiendo: [38] y [27, 43]
 * Mezclando: [27, 43] → [27, 43]
 * Mezclando: [38] y [27, 43] → [27, 38, 43]
 * ...
 * 
 * Ordenado: 3 9 10 27 38 43 82
 * Complejidad: O(n log n) siempre ✓
 */

// Tu código aquí
