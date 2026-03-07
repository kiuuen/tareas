/*
 * EJERCICIO 15F: Ordenar colores (Problema estilo LeetCode #75)
 * 
 * TAREA:
 * Dado un vector con N elementos donde cada elemento es 0 (rojo), 1 (blanco),
 * o 2 (azul), ordénalos IN-PLACE para que queden [0,0,...,1,1,...,2,2,...].
 * 
 * RESTRICCIÓN: NO puedes usar std::sort ni contar y reconstruir.
 * Debes hacerlo en UNA sola pasada con O(1) espacio extra.
 * 
 * Algoritmo: "Dutch National Flag" (Bandera Nacional Holandesa) de Dijkstra
 * - Usa tres punteros: bajo, medio, alto
 * - bajo: todo antes de bajo son 0s
 * - medio: puntero actual que recorre
 * - alto: todo después de alto son 2s
 * 
 * Crea una función void ordenarColores(vector<int>& v) que:
 *   - Inicializa bajo = 0, medio = 0, alto = v.size() - 1
 *   - Mientras medio <= alto:
 *     * Si v[medio] == 0: swap(v[bajo], v[medio]), bajo++, medio++
 *     * Si v[medio] == 1: medio++
 *     * Si v[medio] == 2: swap(v[medio], v[alto]), alto--
 * 
 * EJEMPLO:
 * Entrada: [2, 0, 2, 1, 1, 0]
 * Salida:  [0, 0, 1, 1, 2, 2]
 * 
 * Entrada: [2, 0, 1]
 * Salida:  [0, 1, 2]
 * 
 * PRUEBAS ADICIONALES:
 * - [0] → [0]
 * - [1, 0] → [0, 1]
 * - [2, 2, 2, 0, 0, 0] → [0, 0, 0, 2, 2, 2]
 * - [0, 0, 0] → [0, 0, 0] (ya ordenado)
 */

// Tu código aquí
