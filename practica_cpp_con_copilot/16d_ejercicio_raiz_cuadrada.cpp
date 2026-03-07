/*
 * EJERCICIO 16D: Raíz cuadrada entera (Problema estilo LeetCode #69)
 * 
 * TAREA:
 * Dado un entero positivo x, calcula su raíz cuadrada entera (truncada).
 * Es decir, encuentra el mayor entero n tal que n*n <= x.
 * NO puedes usar sqrt(), pow(), ni funciones matemáticas.
 * 
 * Usa BÚSQUEDA BINARIA sobre la respuesta:
 * - La respuesta está entre 0 y x
 * - Para cada mid: si mid*mid <= x, puede ser la respuesta (guárdala, busca más grande)
 * - Si mid*mid > x, es demasiado grande (busca más pequeño)
 * 
 * Crea una función int raizCuadrada(int x):
 *   - izq = 0, der = x
 *   - resultado = 0
 *   - Mientras izq <= der:
 *     * mid = izq + (der - izq) / 2
 *     * Si mid <= x / mid (evita overflow vs mid*mid):
 *       resultado = mid, izq = mid + 1
 *     * Si no: der = mid - 1
 *   - Retorna resultado
 * 
 * EJEMPLO:
 * raizCuadrada(4)  → 2  (2*2 = 4)
 * raizCuadrada(8)  → 2  (2*2=4 ≤ 8, 3*3=9 > 8)
 * raizCuadrada(16) → 4  (4*4 = 16)
 * raizCuadrada(27) → 5  (5*5=25 ≤ 27, 6*6=36 > 27)
 * raizCuadrada(0)  → 0
 * raizCuadrada(1)  → 1
 * 
 * NOTA: Este es un ejemplo clásico de "binary search on answer"
 * (buscar la respuesta en un rango usando búsqueda binaria).
 * Esta técnica aparece MUCHO en problemas de competencias.
 */

// Tu código aquí
