/*
 * EJERCICIO 19C: Árbol simétrico (Problema estilo LeetCode #101)
 * 
 * TAREA:
 * Dado un árbol binario, verifica si es simétrico (espejo de sí mismo).
 * 
 * Un árbol es simétrico si el subárbol izquierdo es el espejo del derecho:
 * 
 *     SIMÉTRICO:          NO SIMÉTRICO:
 *        1                    1
 *       / \                  / \
 *      2   2                2   2
 *     / \ / \                \   \
 *    3  4 4  3              3    3
 * 
 * Crea una función bool esSimetrico(NodoArbol* raiz):
 *   - Llama a una función auxiliar: esEspejo(NodoArbol* izq, NodoArbol* der)
 * 
 * bool esEspejo(NodoArbol* izq, NodoArbol* der):
 *   - Si ambos son nullptr → true
 *   - Si uno es nullptr y el otro no → false
 *   - Si izq->valor != der->valor → false
 *   - Retorna: esEspejo(izq->izquierdo, der->derecho) 
 *           && esEspejo(izq->derecho, der->izquierdo)
 * 
 * EJEMPLO:
 * Árbol [1, 2, 2, 3, 4, 4, 3] → true (simétrico)
 * Árbol [1, 2, 2, null, 3, null, 3] → false (no simétrico)
 * 
 * PISTA:
 * - La clave es comparar: hijo-izq-del-izq con hijo-der-del-der
 *   Y: hijo-der-del-izq con hijo-izq-del-der
 * - Es un problema recursivo muy elegante
 */

// Tu código aquí
