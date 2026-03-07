/*
 * EJERCICIO 24F: Longest Palindromic Substring (LeetCode #5 style)
 * 
 * TAREA:
 * Dada una cadena, encuentra la SUBCADENA palindrómica más larga.
 * 
 * Palindromo: se lee igual de izquierda a derecha y viceversa.
 * Subcadena: caracteres CONTIGUOS.
 * 
 * ALGORITMO: Expand Around Center
 * - Un palíndromo se puede expandir desde su centro
 * - Para cada posición i, expande hacia afuera mientras sea palíndromo
 * - Hay 2n-1 posibles centros (cada char + cada espacio entre chars)
 *   * Centro en un carácter: "aba" (longitud impar)
 *   * Centro entre dos caracteres: "abba" (longitud par)
 * 
 * Función string expandir(s, izq, der):
 *   while (izq >= 0 && der < n && s[izq] == s[der]):
 *     izq--, der++
 *   return s.substr(izq+1, der-izq-1)
 * 
 * En main:
 *   Para cada i:
 *     p1 = expandir(s, i, i)      // palíndromo impar
 *     p2 = expandir(s, i, i+1)    // palíndromo par
 *     actualizar mejor si es más largo
 * 
 * EJEMPLOS:
 * "babad" → "bab" (o "aba", ambos válidos)
 * "cbbd"  → "bb"
 * "a"     → "a"
 * "racecar" → "racecar"
 * "bananas" → "anana"
 * 
 * EJEMPLO DE SALIDA:
 * String: "bananas"
 * 
 * Expandiendo desde cada centro:
 * Centro 'b'(0): "b"
 * Centro 'a'(1): "a"
 * Centro 'n'(2): "anana" ← más largo hasta ahora
 * Centro 'a'(3): "anana"
 * Centro 'n'(4): "ana"
 * Centro 'a'(5): "a"
 * Centro 's'(6): "s"
 * 
 * Palíndromo más largo: "anana" (longitud 5)
 * 
 * PISTA:
 * - Complejidad: O(n²) con expand around center
 * - Existe solución O(n) (Manacher's), pero no es necesaria para entrevistas
 */

// Tu código aquí
