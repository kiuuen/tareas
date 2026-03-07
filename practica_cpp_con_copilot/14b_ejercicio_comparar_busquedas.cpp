/*
 * EJERCICIO 14B: Comparar búsqueda lineal vs binaria
 * 
 * TAREA:
 * Implementa dos funciones de búsqueda y compara su rendimiento:
 * 
 * 1. int busquedaLineal(vector<int>& v, int target):
 *    - Recorre el vector elemento por elemento → O(n)
 *    - Retorna el índice donde encontró target, o -1 si no existe
 * 
 * 2. int busquedaBinaria(vector<int>& v, int target):
 *    - Requiere vector ORDENADO
 *    - Divide el espacio de búsqueda a la mitad cada vez → O(log n)
 *    - Retorna el índice donde encontró target, o -1 si no existe
 * 
 * 3. En main():
 *    - Genera un vector ORDENADO de 10,000,000 de números (0, 1, 2, ..., 9999999)
 *    - Busca el elemento 9,999,998 (casi al final, peor caso para lineal)
 *    - Mide el tiempo de cada búsqueda
 *    - Muestra la diferencia
 * 
 * PISTAS:
 * - Búsqueda binaria: izq = 0, der = size-1, mid = (izq+der)/2
 *   Si v[mid] == target → encontrado
 *   Si v[mid] < target → izq = mid + 1
 *   Si v[mid] > target → der = mid - 1
 * 
 * EJEMPLO DE SALIDA:
 * Vector ordenado de 10,000,000 elementos
 * Buscando el valor 9999998...
 * 
 * Búsqueda lineal: 12 ms  → encontrado en índice 9999998
 * Búsqueda binaria: 0 ms  → encontrado en índice 9999998
 * 
 * La binaria hizo ~23 comparaciones vs ~10,000,000 de la lineal
 */

// Tu código aquí
