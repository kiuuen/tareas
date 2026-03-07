/*
 * EJERCICIO 19B: Altura máxima del árbol (Problema estilo LeetCode #104)
 * 
 * TAREA:
 * Dada la raíz de un árbol binario, encuentra su profundidad/altura máxima.
 * La altura es el número de nodos en el camino más largo de la raíz a una hoja.
 * 
 * Crea una función int alturaMaxima(NodoArbol* nodo):
 *   - Caso base: si nodo es nullptr → retorna 0
 *   - Paso recursivo: retorna 1 + max(alturaMaxima(izq), alturaMaxima(der))
 * 
 * EJEMPLO:
 *     3
 *    / \
 *   9  20
 *      / \
 *     15  7
 * Altura: 3 (camino: 3 → 20 → 15 o 3 → 20 → 7)
 * 
 *     1
 *      \
 *       2
 * Altura: 2
 * 
 *     1
 * Altura: 1 (solo la raíz)
 * 
 * nullptr → Altura: 0
 * 
 * TAMBIÉN implementa:
 * - int contarNodos(NodoArbol* nodo): cuenta total de nodos
 * - int contarHojas(NodoArbol* nodo): cuenta nodos sin hijos
 * - int sumaValores(NodoArbol* nodo): suma todos los valores
 * 
 * Todas siguen el mismo patrón recursivo.
 */

// Tu código aquí
