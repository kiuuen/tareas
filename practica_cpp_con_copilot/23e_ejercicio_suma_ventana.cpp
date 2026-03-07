/*
 * EJERCICIO 23E: Suma máxima de subarray de tamaño k (Sliding Window fija)
 * 
 * TAREA:
 * Dado un array de enteros y un número k, encuentra la suma máxima
 * de cualquier subarray contiguo de tamaño exacto k.
 * 
 * Solución NAIVE O(n×k): Para cada posición, suma los k elementos.
 * 
 * Solución SLIDING WINDOW O(n):
 * 1. Calcula la suma de los primeros k elementos
 * 2. "Desliza" la ventana: 
 *    - Suma el nuevo elemento (derecha)
 *    - Resta el que sale (izquierda)
 *    - Actualiza el máximo
 * 
 * Visualización con [2, 1, 5, 1, 3, 2], k=3:
 * [2, 1, 5] 1, 3, 2  → suma = 8
 *  2,[1, 5, 1] 3, 2  → suma = 8-2+1 = 7
 *  2, 1,[5, 1, 3] 2  → suma = 7-1+3 = 9  ← MÁXIMO
 *  2, 1, 5,[1, 3, 2] → suma = 9-5+2 = 6
 * 
 * EJEMPLO DE SALIDA:
 * Array: [2, 1, 5, 1, 3, 2], k = 3
 * 
 * Ventana [0-2]: [2, 1, 5] = 8
 * Ventana [1-3]: [1, 5, 1] = 7
 * Ventana [2-4]: [5, 1, 3] = 9  ← máximo
 * Ventana [3-5]: [1, 3, 2] = 6
 * 
 * Suma máxima de subarray de tamaño 3: 9
 * Subarray: [5, 1, 3] en posición 2
 * 
 * BONUS: También encuentra la suma MÍNIMA.
 * 
 * PISTA:
 * - No necesitas recomputar la suma cada vez
 * - Solo suma += nums[i], suma -= nums[i-k]
 */

// Tu código aquí
