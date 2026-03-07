/*
 * EJERCICIO 20B: Subir escaleras (Problema estilo LeetCode #70)
 * 
 * TAREA:
 * Estás al pie de una escalera con N escalones.
 * En cada paso puedes subir 1 o 2 escalones.
 * ¿De cuántas formas distintas puedes llegar al tope?
 * 
 * Crea una función int subirEscaleras(int n):
 * 
 * Análisis:
 * - Para llegar al escalón n, pudiste venir del escalón n-1 (un paso)
 *   o del escalón n-2 (dos pasos)
 * - Entonces: dp[n] = dp[n-1] + dp[n-2]  ← ¡Es Fibonacci!
 * - Caso base: dp[1] = 1 (una forma), dp[2] = 2 (dos formas: 1+1 o 2)
 * 
 * EJEMPLO:
 * n=1: 1 forma  → [1]
 * n=2: 2 formas → [1+1, 2]
 * n=3: 3 formas → [1+1+1, 1+2, 2+1]
 * n=4: 5 formas → [1+1+1+1, 1+1+2, 1+2+1, 2+1+1, 2+2]
 * n=5: 8 formas
 * 
 * Implementa con:
 * a) Bottom-Up con vector dp[]
 * b) Bottom-Up optimizado con solo 2 variables (O(1) espacio)
 * 
 * BONUS: ¿Y si pudieras subir 1, 2, o 3 escalones?
 * Entonces: dp[n] = dp[n-1] + dp[n-2] + dp[n-3]
 * Implementa también esta variante.
 * 
 * SALIDA ESPERADA:
 * Escalones: 1 → 1 forma
 * Escalones: 2 → 2 formas
 * Escalones: 3 → 3 formas
 * Escalones: 5 → 8 formas
 * Escalones: 10 → 89 formas
 * 
 * Con 3 pasos:
 * Escalones: 5 → 13 formas
 */

// Tu código aquí
