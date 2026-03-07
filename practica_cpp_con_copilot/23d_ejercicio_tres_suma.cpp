/*
 * EJERCICIO 23D: 3Sum (LeetCode #15 style)
 * 
 * TAREA:
 * Dado un array de enteros, encuentra TODOS los tripletes únicos
 * [nums[i], nums[j], nums[k]] tales que i ≠ j ≠ k y
 * nums[i] + nums[j] + nums[k] == 0.
 * 
 * La solución NO debe contener tripletes duplicados.
 * 
 * ALGORITMO: Ordenar + Two Pointers
 * 1. Ordena el array
 * 2. Para cada i de 0 a n-3:
 *    - Si nums[i] == nums[i-1] → skip (evitar duplicados)
 *    - izq = i+1, der = n-1
 *    - While izq < der:
 *      * suma = nums[i] + nums[izq] + nums[der]
 *      * Si suma == 0 → agregar triplete, avanzar izq y der (skip duplicados)
 *      * Si suma < 0 → izq++
 *      * Si suma > 0 → der--
 * 
 * EJEMPLO:
 * nums = [-1, 0, 1, 2, -1, -4]
 * Ordenado: [-4, -1, -1, 0, 1, 2]
 * 
 * Tripletes que suman 0:
 * [-1, -1, 2]
 * [-1, 0, 1]
 * 
 * Más casos:
 * nums = [0, 0, 0]        → [[0, 0, 0]]
 * nums = [0, 0, 0, 0]     → [[0, 0, 0]]
 * nums = [-2, 0, 1, 1, 2] → [[-2, 0, 2], [-2, 1, 1]]
 * 
 * EJEMPLO DE SALIDA:
 * Array: [-1, 0, 1, 2, -1, -4]
 * Ordenado: [-4, -1, -1, 0, 1, 2]
 * 
 * Tripletes que suman 0:
 * [-1, -1, 2]
 * [-1, 0, 1]
 * Total: 2 tripletes
 * 
 * PISTA:
 * - La clave es skip duplicados en 3 lugares:
 *   1. Skip para i: if (i > 0 && nums[i] == nums[i-1]) continue
 *   2. Skip para izq: while (izq < der && nums[izq] == nums[izq-1]) izq++
 *   3. Skip para der: while (izq < der && nums[der] == nums[der+1]) der--
 * - Complejidad: O(n²) — mucho mejor que O(n³) de fuerza bruta
 */

// Tu código aquí
