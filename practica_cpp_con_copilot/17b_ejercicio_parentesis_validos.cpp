/*
 * EJERCICIO 17B: Paréntesis válidos (Problema estilo LeetCode #20)
 * 
 * TAREA:
 * Dada una cadena que contiene solo los caracteres '(', ')', '{', '}', '[', ']',
 * determina si la cadena tiene paréntesis válidos (bien balanceados).
 * 
 * Reglas:
 * - Cada paréntesis de apertura debe cerrarse con el mismo tipo
 * - Los paréntesis deben cerrarse en el orden correcto
 * - Cada cierre debe tener su apertura correspondiente
 * 
 * Crea una función bool esValido(string s) usando una PILA:
 *   - Recorre cada carácter:
 *     * Si es apertura ('(', '{', '['): push a la pila
 *     * Si es cierre (')', '}', ']'):
 *       - Si la pila está vacía → false (no hay apertura)
 *       - Si el tope NO coincide con el cierre → false
 *       - Si coincide → pop
 *   - Al final: retorna true si la pila está vacía
 * 
 * EJEMPLO:
 * "()"       → true
 * "()[]{}"   → true
 * "(]"       → false
 * "([)]"     → false (cierre en orden incorrecto)
 * "{[]}"     → true  (anidados correctamente)
 * ""         → true  (cadena vacía es válida)
 * "((("      → false (aperturas sin cierre)
 * ")))"      → false (cierres sin apertura)
 * 
 * PISTA:
 * - Usa un map para emparejar: ')' → '(', ']' → '[', '}' → '{'
 * - O usa if/else para cada caso
 */

// Tu código aquí
