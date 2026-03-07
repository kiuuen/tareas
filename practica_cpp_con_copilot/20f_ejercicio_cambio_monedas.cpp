/*
 * EJERCICIO 20F: Cambio de monedas (Problema estilo LeetCode #322)
 * 
 * TAREA:
 * Dado un conjunto de denominaciones de monedas y un monto total,
 * encuentra el MÍNIMO número de monedas necesarias para formar ese monto.
 * Si no es posible, retorna -1.
 * Puedes usar cada denominación las veces que quieras.
 * 
 * Ejemplo: monedas = [1, 5, 10, 25], monto = 30
 * Respuesta: 2 (una de 25 + una de 5)
 * NO: 3 monedas de 10 (eso son 3, no es el mínimo)
 * 
 * Solución DP:
 *   dp[i] = mínimo número de monedas para formar el monto i
 *   
 *   dp[0] = 0 (0 monedas para monto 0)
 *   Para cada monto i de 1 a monto:
 *     Para cada moneda c:
 *       Si i >= c y dp[i - c] != infinito:
 *         dp[i] = min(dp[i], dp[i - c] + 1)
 *   
 *   Respuesta: dp[monto] (si es infinito → -1)
 * 
 * Crea una función int cambioMonedas(vector<int>& monedas, int monto)
 * 
 * EJEMPLO:
 * Monedas [1, 5, 10, 25], monto 30 → 2 (25 + 5)
 * Monedas [1, 5, 10, 25], monto 11 → 2 (10 + 1)
 * Monedas [2], monto 3 → -1 (imposible)
 * Monedas [1], monto 0 → 0
 * Monedas [1, 2, 5], monto 11 → 3 (5 + 5 + 1)
 * 
 * BONUS: Además del mínimo número, muestra CUÁLES monedas se usaron.
 * Para esto, guarda de dónde vino cada dp[i] (qué moneda se usó).
 * 
 * PISTA:
 * - Inicializa dp[i] = INT_MAX o un valor grande (infinito)
 * - dp[0] = 0
 * - Recorre cada monto de 1 a monto, y para cada monto prueba cada moneda
 */

// Tu código aquí
