/*
 * EJERCICIO 20C: Máximo subarray / Algoritmo de Kadane (Problema estilo LeetCode #53)
 * 
 * TAREA:
 * Dado un vector de enteros (puede tener negativos), encuentra el subarray
 * contiguo con la mayor suma.
 * 
 * Ejemplo: [-2, 1, -3, 4, -1, 2, 1, -5, 4]
 * El subarray con mayor suma es [4, -1, 2, 1] = 6
 * 
 * Algoritmo de Kadane (DP lineal):
 * - dp[i] = máxima suma de subarray que TERMINA en posición i
 * - dp[i] = max(nums[i], dp[i-1] + nums[i])
 *   Es decir: ¿es mejor empezar de nuevo aquí, o continuar el subarray anterior?
 * - La respuesta es el máximo de todos los dp[i]
 * 
 * Crea una función int maxSubarray(vector<int>& nums):
 *   - maxActual = nums[0], maxGlobal = nums[0]
 *   - Para i de 1 a n-1:
 *     * maxActual = max(nums[i], maxActual + nums[i])
 *     * maxGlobal = max(maxGlobal, maxActual)
 *   - Retorna maxGlobal
 * 
 * EJEMPLO:
 * [-2, 1, -3, 4, -1, 2, 1, -5, 4] → 6 (subarray: [4, -1, 2, 1])
 * [1] → 1
 * [5, 4, -1, 7, 8] → 23 (todo el vector)
 * [-1, -2, -3] → -1 (el menos negativo)
 * 
 * BONUS: Además de la suma máxima, muestra CUÁL es el subarray.
 * Para esto, guarda los índices de inicio y fin.
 * 
 * PISTA para el bonus:
 * - Cuando maxActual se resetea a nums[i], el inicio del subarray es i
 * - Cuando maxGlobal se actualiza, guarda los índices actuales
 */

// Tu código aquí
