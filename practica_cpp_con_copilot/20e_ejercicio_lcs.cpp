/*
 * EJERCICIO 20E: Subsecuencia Común más Larga (LCS - Longest Common Subsequence)
 * (Problema estilo LeetCode #1143)
 * 
 * TAREA:
 * Dadas dos cadenas, encuentra la longitud de su subsecuencia común más larga.
 * Una subsecuencia es una secuencia que se obtiene eliminando algunos (o ningún)
 * caracteres SIN cambiar el orden de los restantes.
 * 
 * Ejemplo:
 *   s1 = "ABCBDAB"
 *   s2 = "BDCAB"
 *   LCS = "BCAB" (longitud 4)
 *   
 *   A B C B D A B
 *     B   B   A B  ← subsecuencia de s1
 *   B D C A B
 *   B     A B      ← subsecuencia de s2
 *   Ambos tienen "BCAB" como subsecuencia
 * 
 * Solución DP (tabla 2D):
 *   dp[i][j] = longitud del LCS de s1[0..i-1] y s2[0..j-1]
 *   
 *   Si s1[i-1] == s2[j-1]:  dp[i][j] = dp[i-1][j-1] + 1
 *   Si s1[i-1] != s2[j-1]:  dp[i][j] = max(dp[i-1][j], dp[i][j-1])
 *   
 *   Caso base: dp[0][j] = 0, dp[i][0] = 0 (cadena vacía)
 * 
 * Crea una función int lcs(string s1, string s2)
 * 
 * EJEMPLO:
 * "abcde" y "ace" → 3 (LCS: "ace")
 * "abc" y "abc" → 3 (son iguales)
 * "abc" y "def" → 0 (nada en común)
 * "ABCBDAB" y "BDCAB" → 4 (LCS: "BCAB")
 * 
 * BONUS: Reconstruye el LCS (no solo la longitud, sino la cadena).
 * Recorre la tabla dp de vuelta:
 * - Si s1[i-1] == s2[j-1]: agregar ese carácter, ir a dp[i-1][j-1]
 * - Si no: ir al max entre dp[i-1][j] y dp[i][j-1]
 * 
 * PISTA:
 * - Tabla dp de (n+1) x (m+1) donde n = s1.length(), m = s2.length()
 * - Respuesta: dp[n][m]
 */

// Tu código aquí
