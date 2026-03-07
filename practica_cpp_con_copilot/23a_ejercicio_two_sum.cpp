/*
 * EJERCICIO 23A: Two Sum (LeetCode #1 style)
 * 
 * TAREA:
 * Dado un array de enteros y un target, encuentra DOS números 
 * que sumen exactamente el target. Retorna sus índices.
 * 
 * Implementa DOS soluciones:
 * 
 * 1. FUERZA BRUTA O(n²): Dos bucles anidados, prueba todos los pares
 * 
 * 2. HASH MAP O(n): Para cada número, busca si (target - num) ya está 
 *    en el mapa. Si sí → encontrado. Si no → agrega num al mapa.
 *    unordered_map<int, int> visto;  // valor → índice
 * 
 * 3. TWO POINTERS O(n log n): Solo funciona si ordenas primero.
 *    - Crea pares {valor, índice_original}, ordena por valor
 *    - Usa dos punteros desde extremos
 *    - ⚠️ Cuidado: los índices originales se pierden al ordenar
 * 
 * EJEMPLO:
 * nums = [2, 7, 11, 15], target = 9
 * Salida: [0, 1] porque nums[0] + nums[1] = 2 + 7 = 9
 * 
 * nums = [3, 2, 4], target = 6
 * Salida: [1, 2] porque nums[1] + nums[2] = 2 + 4 = 6
 * 
 * EJEMPLO DE SALIDA:
 * === Two Sum ===
 * Array: [2, 7, 11, 15], Target: 9
 * Fuerza bruta: indices [0, 1]
 * Hash map:     indices [0, 1]
 * Two pointers: indices [0, 1]
 * 
 * PISTA:
 * - La solución con hash map es la más elegante y la que esperan en entrevistas
 * - Si existe solución, siempre habrá exactamente una respuesta
 */

// Tu código aquí
