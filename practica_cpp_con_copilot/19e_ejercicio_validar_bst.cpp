/*
 * EJERCICIO 19E: Validar BST (Problema estilo LeetCode #98)
 * 
 * TAREA:
 * Dado un árbol binario, determina si es un BST válido.
 * 
 * Un BST válido cumple:
 * - TODOS los nodos del subárbol izquierdo son MENORES que la raíz
 * - TODOS los nodos del subárbol derecho son MAYORES que la raíz
 * - Ambos subárboles también son BST válidos
 * 
 * CUIDADO: No basta con verificar solo el hijo directo.
 * Este árbol NO es BST aunque cada nodo sea mayor que su hijo izquierdo:
 *       5
 *      / \
 *     1   4     ← 4 < 5, pero...
 *        / \
 *       3   6   ← 3 está en el subárbol DERECHO de 5, y 3 < 5 ← ¡INVÁLIDO!
 * 
 * Crea una función bool esValidoBST(NodoArbol* nodo, long minVal, long maxVal):
 *   - Si nodo es nullptr → true
 *   - Si nodo->valor <= minVal O nodo->valor >= maxVal → false
 *   - Retorna: esValidoBST(izq, minVal, nodo->valor) 
 *           && esValidoBST(der, nodo->valor, maxVal)
 * 
 * Llamada inicial: esValidoBST(raiz, LONG_MIN, LONG_MAX)
 * (usa long para evitar problemas con INT_MIN/INT_MAX como valores en nodos)
 * 
 * EJEMPLO:
 *     2
 *    / \
 *   1   3   → true (BST válido)
 * 
 *     5
 *    / \
 *   1   4
 *      / \
 *     3   6  → false (3 está en subárbol derecho de 5, pero 3 < 5)
 * 
 * ALTERNATIVA: Haz un recorrido INORDER y verifica que sale ordenado estrictamente.
 */

// Tu código aquí
