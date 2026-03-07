/*
 * EJERCICIO 18C: Detectar ciclo en lista (Problema estilo LeetCode #141)
 * 
 * TAREA:
 * Dada una lista enlazada, determina si tiene un ciclo.
 * Un ciclo existe si algún nodo's siguiente apunta a un nodo anterior.
 * 
 * Usa el algoritmo de Floyd (tortuga y liebre):
 * - Dos punteros: lento (avanza 1 paso) y rapido (avanza 2 pasos)
 * - Si hay ciclo, eventualmente se encuentran
 * - Si no hay ciclo, rapido llega a nullptr
 * 
 * Crea una función bool tieneCiclo(Nodo* cabeza):
 *   - lento = cabeza, rapido = cabeza
 *   - Mientras rapido != nullptr Y rapido->siguiente != nullptr:
 *     * lento = lento->siguiente
 *     * rapido = rapido->siguiente->siguiente
 *     * Si lento == rapido → return true (hay ciclo!)
 *   - return false (rapido llegó al final, no hay ciclo)
 * 
 * En main():
 * - Crea una lista SIN ciclo: 1 → 2 → 3 → 4 → nullptr (resultado: false)
 * - Crea una lista CON ciclo: 1 → 2 → 3 → 4 → 2 (4 apunta a 2) (resultado: true)
 * 
 * EJEMPLO:
 * Lista sin ciclo: 1 → 2 → 3 → 4 → nullptr
 * ¿Tiene ciclo? No
 * 
 * Lista con ciclo: 1 → 2 → 3 → 4 → (vuelve a 2)
 * ¿Tiene ciclo? Sí
 * 
 * NOTA: Para crear el ciclo, haz que el último nodo apunte a otro nodo de la lista.
 * CUIDADO: No intentes imprimir una lista con ciclo (bucle infinito).
 * NO hagas delete en nodos de listas con ciclo sin romper el ciclo primero.
 * 
 * PISTA:
 * - ¿Por qué funciona? Si piensas en una pista circular, el corredor rápido
 *   eventualmente "alcanza" al lento. Es como un reloj: la manecilla rápida
 *   siempre alcanza a la lenta.
 */

// Tu código aquí
