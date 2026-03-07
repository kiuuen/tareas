/*
 * EJERCICIO 15E: Implementar Quick Sort
 * 
 * TAREA:
 * Implementa el algoritmo Quick Sort usando recursión.
 * 
 * 1. Crea una función int particion(vector<int>& v, int izq, int der):
 *    - Elige el último elemento como pivote: pivote = v[der]
 *    - Reorganiza: menores a la izquierda, mayores a la derecha
 *    - Retorna la posición final del pivote
 *    - Algoritmo de partición (Lomuto):
 *      * i = izq - 1 (índice del menor)
 *      * Para j de izq a der-1:
 *        Si v[j] <= pivote: incrementa i, swap(v[i], v[j])
 *      * swap(v[i+1], v[der]) para poner pivote en su lugar
 *      * retorna i+1
 * 
 * 2. Crea una función void quickSort(vector<int>& v, int izq, int der):
 *    - Caso base: si izq >= der, retorna
 *    - int pi = particion(v, izq, der)
 *    - quickSort(v, izq, pi - 1)   // Ordenar izquierda del pivote
 *    - quickSort(v, pi + 1, der)   // Ordenar derecha del pivote
 * 
 * 3. En main():
 *    - Crea el vector: {10, 80, 30, 90, 40, 50, 70}
 *    - Ordena con quickSort
 *    - Muestra el resultado
 * 
 * PISTAS:
 * - El pivote puede ser cualquier elemento, pero el último es más simple
 * - Quick Sort es O(n log n) en promedio pero O(n²) en peor caso
 * - std::sort de C++ usa Introsort (Quick Sort + Heap Sort como fallback)
 * 
 * EJEMPLO DE SALIDA:
 * Original: 10 80 30 90 40 50 70
 * Pivote=70: [10, 30, 40, 50] [70] [80, 90]
 * ...
 * Ordenado: 10 30 40 50 70 80 90
 */

// Tu código aquí
