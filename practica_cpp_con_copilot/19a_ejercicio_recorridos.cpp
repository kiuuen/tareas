/*
 * EJERCICIO 19A: Recorridos de árbol binario
 * 
 * TAREA:
 * Dado un árbol binario, implementa los 4 recorridos principales.
 * 
 * Construye este árbol:
 *        1
 *       / \
 *      2   3
 *     / \
 *    4   5
 * 
 * Implementa las funciones:
 * 1. void inorder(NodoArbol* nodo)    → izquierda, raíz, derecha
 * 2. void preorder(NodoArbol* nodo)   → raíz, izquierda, derecha
 * 3. void postorder(NodoArbol* nodo)  → izquierda, derecha, raíz
 * 4. void levelOrder(NodoArbol* raiz) → nivel por nivel (usa queue)
 * 
 * EJEMPLO DE SALIDA:
 * Inorder:    4 2 5 1 3
 * Preorder:   1 2 4 5 3
 * Postorder:  4 5 2 3 1
 * Level Order: 1 2 3 4 5
 * 
 * PISTAS:
 * - Inorder, preorder y postorder son recursivos (3 líneas cada uno)
 * - Level Order usa std::queue:
 *   queue.push(raiz)
 *   while (!queue.empty()):
 *     nodo = queue.front(); queue.pop();
 *     imprimir nodo
 *     si tiene izquierdo → queue.push(izquierdo)
 *     si tiene derecho → queue.push(derecho)
 * 
 * BONUS: Implementa inorder ITERATIVO usando una pila (stack)
 * Es más difícil pero aparece en entrevistas.
 */

// Tu código aquí
