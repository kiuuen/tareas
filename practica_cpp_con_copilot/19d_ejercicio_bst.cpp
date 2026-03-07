/*
 * EJERCICIO 19D: BST - Insertar y Buscar
 * 
 * TAREA:
 * Implementa un Árbol Binario de Búsqueda (BST) con las operaciones
 * de insertar y buscar.
 * 
 * Propiedad BST: Para cada nodo, izquierdo < nodo < derecho
 * 
 * 1. NodoArbol* insertar(NodoArbol* raiz, int valor):
 *    - Si raiz es nullptr → crea nuevo nodo con el valor
 *    - Si valor < raiz->valor → insertar en subárbol izquierdo
 *    - Si valor > raiz->valor → insertar en subárbol derecho
 *    - Si valor == raiz->valor → no insertar (sin duplicados)
 *    - Retorna la raíz (posiblemente modificada)
 * 
 * 2. bool buscar(NodoArbol* raiz, int valor):
 *    - Si raiz es nullptr → false
 *    - Si valor == raiz->valor → true
 *    - Si valor < raiz->valor → buscar en izquierdo
 *    - Si valor > raiz->valor → buscar en derecho
 * 
 * En main():
 * - Inserta: 8, 3, 10, 1, 6, 14, 4, 7
 * - Haz un recorrido INORDER (debe salir ordenado por la propiedad BST)
 * - Busca: 6 (true), 13 (false), 14 (true)
 * 
 * EJEMPLO:
 * Insertando: 8 3 10 1 6 14 4 7
 * Árbol resultante:
 *          8
 *         / \
 *        3   10
 *       / \    \
 *      1   6   14
 *         / \
 *        4   7
 * 
 * Inorder: 1 3 4 6 7 8 10 14 (¡ordenado!)
 * ¿Existe 6?  Sí
 * ¿Existe 13? No
 * ¿Existe 14? Sí
 * 
 * PISTA:
 * - Insertar es recursivo: raiz->izquierdo = insertar(raiz->izquierdo, valor)
 * - Buscar es como búsqueda binaria pero en un árbol
 */

// Tu código aquí
