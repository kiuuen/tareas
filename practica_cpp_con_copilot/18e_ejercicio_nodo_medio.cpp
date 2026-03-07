/*
 * EJERCICIO 18E: Encontrar el nodo del medio (Problema estilo LeetCode #876)
 * 
 * TAREA:
 * Dada una lista enlazada, encuentra el nodo del MEDIO.
 * Si hay dos nodos centrales, retorna el SEGUNDO de ellos.
 * 
 * Usa la técnica de TWO POINTERS (lento/rápido):
 *   - lento avanza 1 paso
 *   - rapido avanza 2 pasos
 *   - Cuando rapido llega al final, lento está en el medio
 * 
 * ¿POR QUÉ FUNCIONA?
 * Si rapido recorre el doble de rápido, cuando rapido termina,
 * lento ha recorrido exactamente la mitad.
 * 
 * Crea una función Nodo* encontrarMedio(Nodo* cabeza)
 * 
 * EJEMPLO:
 * Lista: 1 → 2 → 3 → 4 → 5 → nullptr
 * Medio: 3 (nodo del medio)
 * 
 * Lista: 1 → 2 → 3 → 4 → 5 → 6 → nullptr
 * Medio: 4 (segundo nodo central, hay dos: 3 y 4)
 * 
 * Lista: 1 → nullptr
 * Medio: 1
 * 
 * PRUEBA: Imprime desde el nodo del medio hasta el final.
 * Para 1→2→3→4→5: debe imprimir 3→4→5→nullptr
 */

// Tu código aquí
