/*
 * EJERCICIO 20D: Problema de la mochila 0/1 (Knapsack Problem)
 * 
 * TAREA:
 * Tienes una mochila con capacidad máxima W (peso).
 * Hay N objetos, cada uno con un peso y un valor.
 * ¿Cuál es el MÁXIMO valor que puedes llevar sin exceder la capacidad?
 * Cada objeto se puede tomar 0 o 1 vez (no se puede partir).
 * 
 * Ejemplo:
 *   Capacidad: 7 kg
 *   Objetos:
 *   - Objeto 0: peso=1, valor=1
 *   - Objeto 1: peso=3, valor=4
 *   - Objeto 2: peso=4, valor=5
 *   - Objeto 3: peso=5, valor=7
 *   Máximo valor: 9 (tomar objetos 1 y 2: peso=3+4=7, valor=4+5=9)
 * 
 * Solución DP:
 *   dp[i][w] = máximo valor usando los primeros i objetos con capacidad w
 *   
 *   Para cada objeto i con peso[i] y valor[i]:
 *   - Si peso[i] > w: no cabe → dp[i][w] = dp[i-1][w]
 *   - Si peso[i] <= w: elegir el máximo entre:
 *     * No tomarlo: dp[i-1][w]
 *     * Tomarlo: dp[i-1][w - peso[i]] + valor[i]
 *     → dp[i][w] = max(dp[i-1][w], dp[i-1][w-peso[i]] + valor[i])
 * 
 * Crea una función int mochila(vector<int>& pesos, vector<int>& valores, int capacidad)
 * 
 * EJEMPLO:
 * Pesos:   [1, 3, 4, 5]
 * Valores: [1, 4, 5, 7]
 * Capacidad: 7
 * Resultado: 9
 * 
 * BONUS: También muestra CUÁLES objetos se eligieron.
 * Para esto, recorre la tabla dp de vuelta:
 * Si dp[i][w] != dp[i-1][w] → el objeto i fue tomado, w -= peso[i]
 * 
 * PISTA:
 * - Tabla dp de (n+1) x (W+1)
 * - Llena fila por fila, columna por columna
 * - La respuesta está en dp[n][W]
 */

// Tu código aquí
