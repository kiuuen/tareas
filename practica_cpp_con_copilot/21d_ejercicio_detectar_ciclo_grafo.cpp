/*
 * EJERCICIO 21D: Detectar ciclo en grafo dirigido
 * 
 * TAREA:
 * Dado un grafo DIRIGIDO, determina si contiene un ciclo.
 * 
 * Ejemplo con ciclo:       Ejemplo sin ciclo:
 *   0 → 1                    0 → 1
 *   ↑   ↓                         ↓
 *   3 ← 2                    2 → 3
 *   (ciclo: 0→1→2→3→0)
 * 
 * Usa DFS con 3 estados para cada nodo:
 * - BLANCO (0): no visitado
 * - GRIS (1):   en proceso (está en la pila de recursión actual)
 * - NEGRO (2):  completamente procesado
 * 
 * Si durante DFS llegas a un nodo GRIS → ¡HAY CICLO!
 * (Significa que volviste a un nodo que aún no terminó de procesarse)
 * 
 * Función bool tieneCiclo(grafo):
 *   - Array de colores, todos empiezan BLANCO
 *   - Para cada nodo blanco, lanzar DFS
 *   - DFS(nodo): 
 *     * Color[nodo] = GRIS
 *     * Para cada vecino:
 *       - Si es GRIS → retorna true (ciclo!)
 *       - Si es BLANCO → si DFS(vecino) es true, retorna true
 *     * Color[nodo] = NEGRO
 *     * Retorna false
 * 
 * EJEMPLO DE SALIDA:
 * Grafo dirigido 1: 0→1, 1→2, 2→3, 3→0
 * ¿Tiene ciclo? Sí (0 → 1 → 2 → 3 → 0)
 * 
 * Grafo dirigido 2: 0→1, 1→2, 2→3
 * ¿Tiene ciclo? No
 * 
 * NOTA: En grafos NO dirigidos, la detección de ciclos es diferente
 * (debes ignorar el padre directo, no es lo mismo que un nodo gris).
 */

// Tu código aquí
