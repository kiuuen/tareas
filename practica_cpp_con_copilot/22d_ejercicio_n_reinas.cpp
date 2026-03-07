/*
 * EJERCICIO 22D: N-Reinas (Backtracking clásico)
 * 
 * TAREA:
 * Coloca N reinas en un tablero N×N de ajedrez de forma que
 * ninguna reina ataque a otra.
 * 
 * Una reina ataca en: misma fila, misma columna, ambas diagonales.
 * 
 * Estrategia:
 * - Coloca reinas fila por fila (una reina por fila garantizado)
 * - Para cada fila, prueba cada columna
 * - Verifica si es seguro (no atacada por reinas ya colocadas)
 * - Si es seguro → coloca y avanza a la siguiente fila
 * - Si ninguna columna funciona → retrocede (backtrack)
 * 
 * Función bool esSeguro(tablero, fila, col, n):
 *   Verifica 3 cosas (solo mirando filas anteriores):
 *   1. Misma columna: ¿hay reina arriba?
 *   2. Diagonal superior-izquierda: ¿hay reina?
 *   3. Diagonal superior-derecha: ¿hay reina?
 * 
 * Función void resolver(tablero, fila, n, soluciones):
 *   - Si fila == n → solución encontrada!
 *   - Para col = 0 hasta n-1:
 *     * Si esSeguro(tablero, fila, col, n):
 *       tablero[fila][col] = 'Q'            // HACER
 *       resolver(tablero, fila+1, n, ...)    // EXPLORAR
 *       tablero[fila][col] = '.'            // DESHACER
 * 
 * Para N = 4, hay 2 soluciones:
 * 
 * Solución 1:     Solución 2:
 * . Q . .         . . Q .
 * . . . Q         Q . . .
 * Q . . .         . . . Q
 * . . Q .         . Q . .
 * 
 * EJEMPLO DE SALIDA:
 * N-Reinas para N=4:
 * Solución 1:
 * . Q . .
 * . . . Q
 * Q . . .
 * . . Q .
 * 
 * Solución 2:
 * . . Q .
 * Q . . .
 * . . . Q
 * . Q . .
 * 
 * Total: 2 soluciones
 * 
 * También muestra: N=1→1, N=2→0, N=3→0, N=4→2, N=5→10, N=8→92
 * 
 * PISTA:
 * - Representación: vector<string> tablero(n, string(n, '.'))
 * - Para N=8, hay 92 soluciones (solo muestra el conteo)
 */

// Tu código aquí
