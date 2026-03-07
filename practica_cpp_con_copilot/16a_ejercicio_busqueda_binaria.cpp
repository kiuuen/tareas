/*
 * EJERCICIO 16A: Implementar búsqueda binaria
 * 
 * TAREA:
 * Implementa búsqueda binaria desde cero (sin usar std::binary_search).
 * 
 * 1. Crea una función int busquedaBinaria(vector<int>& v, int target):
 *    - Inicializa izq = 0, der = v.size() - 1
 *    - Mientras izq <= der:
 *      * mid = izq + (der - izq) / 2
 *      * Si v[mid] == target → retorna mid
 *      * Si v[mid] < target → izq = mid + 1
 *      * Si v[mid] > target → der = mid - 1
 *    - Si no lo encontró, retorna -1
 * 
 * 2. En main():
 *    - Crea un vector ordenado: {2, 5, 8, 12, 16, 23, 38, 45, 56, 72, 91}
 *    - Busca varios valores: 23 (existe), 72 (existe), 15 (no existe)
 *    - Para cada búsqueda, muestra cuántas comparaciones hizo
 * 
 * PISTA:
 * - Usa un contador de comparaciones dentro de la función
 * - Puedes retornar un pair<int,int> con {índice, comparaciones}
 *   o pasar el contador por referencia
 * 
 * EJEMPLO DE SALIDA:
 * Vector: 2 5 8 12 16 23 38 45 56 72 91
 * 
 * Buscar 23: encontrado en índice 5 (3 comparaciones)
 * Buscar 72: encontrado en índice 9 (4 comparaciones)
 * Buscar 15: NO encontrado (-1) (4 comparaciones)
 * 
 * Máximo teórico de comparaciones: log2(11) ≈ 4
 */

// Tu código aquí
