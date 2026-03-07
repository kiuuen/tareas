/*
 * EJERCICIO 22C: Generar todas las permutaciones (Backtracking)
 * 
 * TAREA:
 * Dado un vector de números DISTINTOS, genera TODAS las permutaciones
 * posibles usando backtracking.
 * 
 * Para {1, 2, 3} hay 3! = 6 permutaciones.
 * 
 * Estrategia de backtracking:
 * - En cada posición, prueba colocar cada número disponible
 * - Marca el número como "usado"
 * - Avanza a la siguiente posición (recursión)
 * - Desmarca el número (backtrack)
 * 
 * Función void permutar(nums, actual, usado, resultado):
 *   - Si actual.size() == nums.size() → encontramos una permutación completa
 *   - Para cada número i:
 *     * Si no usado[i]:
 *       - usado[i] = true, actual.push_back(nums[i])   // HACER
 *       - permutar(...)                                  // EXPLORAR
 *       - usado[i] = false, actual.pop_back()            // DESHACER
 * 
 * EJEMPLO DE SALIDA:
 * Permutaciones de {1, 2, 3}:
 * [1, 2, 3]
 * [1, 3, 2]
 * [2, 1, 3]
 * [2, 3, 1]
 * [3, 1, 2]
 * [3, 2, 1]
 * Total: 6 permutaciones
 * 
 * BONUS: También genera las permutaciones de "ABC" → todas las
 * combinaciones posibles de esas 3 letras.
 * 
 * PISTA (estilo LeetCode #46):
 * - vector<bool> usado(n, false) para marcar qué números ya están en "actual"
 * - El tamaño de "actual" te dice en qué posición de la permutación estás
 */

// Tu código aquí
