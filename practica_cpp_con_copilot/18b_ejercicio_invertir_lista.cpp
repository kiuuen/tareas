/*
 * EJERCICIO 18B: Invertir lista enlazada (Problema estilo LeetCode #206)
 * 
 * TAREA:
 * Dada una lista enlazada, inviértela y retorna la nueva cabeza.
 * 
 * Implementa DOS versiones:
 * 
 * 1. Nodo* invertirIterativo(Nodo* cabeza):
 *    - Usa tres punteros: anterior(nullptr), actual(cabeza), siguiente
 *    - En cada paso:
 *      * siguiente = actual->siguiente (guardar referencia)
 *      * actual->siguiente = anterior  (invertir el enlace)
 *      * anterior = actual             (avanzar anterior)
 *      * actual = siguiente            (avanzar actual)
 *    - Al final, anterior es la nueva cabeza
 * 
 * 2. Nodo* invertirRecursivo(Nodo* cabeza):
 *    - Caso base: si cabeza es nullptr o cabeza->siguiente es nullptr, retorna cabeza
 *    - Paso recursivo:
 *      * Nodo* nuevaCabeza = invertirRecursivo(cabeza->siguiente)
 *      * cabeza->siguiente->siguiente = cabeza (el siguiente ahora apunta a mí)
 *      * cabeza->siguiente = nullptr (yo ya no apunto a nadie)
 *      * retorna nuevaCabeza
 * 
 * EJEMPLO:
 * Original: 1 → 2 → 3 → 4 → 5 → nullptr
 * Invertida: 5 → 4 → 3 → 2 → 1 → nullptr
 * 
 * Original: 1 → 2 → nullptr
 * Invertida: 2 → 1 → nullptr
 * 
 * Original: nullptr (lista vacía)
 * Invertida: nullptr
 */

// Tu código aquí
