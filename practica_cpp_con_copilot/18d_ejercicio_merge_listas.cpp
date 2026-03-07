/*
 * EJERCICIO 18D: Merge de dos listas ordenadas (Problema estilo LeetCode #21)
 * 
 * TAREA:
 * Dadas dos listas enlazadas ORDENADAS, combínalas en UNA sola lista ordenada.
 * 
 * Crea una función Nodo* mergeListas(Nodo* l1, Nodo* l2):
 * 
 * Método 1 - Iterativo con nodo dummy:
 *   - Crea un nodo dummy (ficticio) como punto de inicio
 *   - Puntero "actual" que va construyendo la lista resultado
 *   - Mientras ambas listas tengan elementos:
 *     * Si l1->valor <= l2->valor: actual->siguiente = l1, l1 = l1->siguiente
 *     * Si no: actual->siguiente = l2, l2 = l2->siguiente
 *     * actual = actual->siguiente
 *   - Conecta lo que quede de l1 o l2
 *   - Retorna dummy->siguiente (la cabeza real)
 * 
 * EJEMPLO:
 * l1: 1 → 3 → 5 → nullptr
 * l2: 2 → 4 → 6 → nullptr
 * Resultado: 1 → 2 → 3 → 4 → 5 → 6 → nullptr
 * 
 * l1: 1 → 1 → 1 → nullptr
 * l2: 2 → 2 → nullptr
 * Resultado: 1 → 1 → 1 → 2 → 2 → nullptr
 * 
 * l1: nullptr (vacía)
 * l2: 1 → 2 → 3 → nullptr
 * Resultado: 1 → 2 → 3 → nullptr
 * 
 * PISTA:
 * - El "nodo dummy" es un truco MUY útil. Evita casos especiales para el primer nodo.
 * - Nodo dummy(-1); // No importa el valor, es temporal
 *   Nodo* actual = &dummy;
 *   // ... construir ...
 *   return dummy.siguiente;
 * 
 * BONUS: Intenta también una versión RECURSIVA:
 *   Si l1->valor <= l2->valor: l1->siguiente = mergeListas(l1->siguiente, l2); return l1;
 *   Si no: l2->siguiente = mergeListas(l1, l2->siguiente); return l2;
 */

// Tu código aquí
