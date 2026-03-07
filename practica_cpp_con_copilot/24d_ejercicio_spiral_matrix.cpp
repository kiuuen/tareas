/*
 * EJERCICIO 24D: Spiral Matrix (LeetCode #54 style)
 * 
 * TAREA:
 * Dada una matriz m×n, devuelve todos sus elementos en orden ESPIRAL.
 * 
 * Ejemplo para una matriz 3×3:
 * 1  2  3
 * 4  5  6
 * 7  8  9
 * 
 * Recorrido espiral: 1→2→3→6→9→8→7→4→5
 * 
 * Dirección: → ↓ ← ↑ → ↓ ← ↑ ... (repite)
 * 
 * Algoritmo con 4 bordes:
 * - top = 0, bottom = m-1, left = 0, right = n-1
 * - Mientras top <= bottom AND left <= right:
 *   1. Recorre fila top de left a right    → (derecha)
 *      top++
 *   2. Recorre columna right de top a bottom  ↓ (abajo)
 *      right--
 *   3. Si top <= bottom: Recorre fila bottom de right a left  ← (izquierda)
 *      bottom--
 *   4. Si left <= right: Recorre columna left de bottom a top  ↑ (arriba)
 *      left++
 * 
 * EJEMPLOS:
 * Matriz 3×3:         Espiral: [1,2,3,6,9,8,7,4,5]
 * 1 2 3
 * 4 5 6
 * 7 8 9
 * 
 * Matriz 3×4:         Espiral: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 1  2  3  4
 * 5  6  7  8
 * 9 10 11 12
 * 
 * Matriz 1×4:         Espiral: [1,2,3,4]
 * 1 2 3 4
 * 
 * EJEMPLO DE SALIDA:
 * Matriz:
 * 1  2  3
 * 4  5  6
 * 7  8  9
 * 
 * Recorrido espiral: 1 2 3 6 9 8 7 4 5
 * 
 * BONUS: También implementa la operación inversa:
 * dado un vector y dimensiones m×n, llena la matriz en espiral.
 * 
 * PISTA:
 * - Los 4 bordes se van "cerrando" después de cada pasada
 * - Cuidado con matrices no cuadradas (m ≠ n)
 */

// Tu código aquí
