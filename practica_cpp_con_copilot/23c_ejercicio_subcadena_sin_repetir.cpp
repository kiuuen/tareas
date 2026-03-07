/*
 * EJERCICIO 23C: Subcadena más larga sin repetir (LeetCode #3 style)
 * 
 * TAREA:
 * Dada una cadena, encuentra la longitud de la SUBCADENA más larga
 * que no contenga caracteres repetidos.
 * 
 * Subcadena = caracteres CONTIGUOS (no subsecuencia)
 * 
 * Usa SLIDING WINDOW con un set o map:
 * 1. Expande la ventana por la derecha (der++)
 * 2. Si el carácter ya está en la ventana:
 *    - Contrae desde la izquierda (izq++) hasta eliminar el duplicado
 * 3. Actualiza el máximo con (der - izq + 1)
 * 
 * EJEMPLOS:
 * "abcabcbb" → 3  (subcadena "abc")
 * "bbbbb"    → 1  (subcadena "b")
 * "pwwkew"   → 3  (subcadena "wke")
 * ""         → 0
 * "abcdef"   → 6  (toda la cadena)
 * "dvdf"     → 3  (subcadena "vdf")
 * 
 * EJEMPLO DE SALIDA:
 * String: "abcabcbb"
 * Ventana actual: [a] → max=1
 * Ventana actual: [ab] → max=2
 * Ventana actual: [abc] → max=3
 * Duplicado 'a', contrae: [bca] → max=3
 * Duplicado 'b', contrae: [cab] → max=3
 * ...
 * Respuesta: 3 (subcadena "abc")
 * 
 * PISTA:
 * - Opción 1: unordered_set<char> con erase(s[izq]) al contraer
 * - Opción 2: unordered_map<char, int> guardando última posición del char
 *   → más eficiente: izq = max(izq, mapa[s[der]] + 1)
 */

// Tu código aquí
