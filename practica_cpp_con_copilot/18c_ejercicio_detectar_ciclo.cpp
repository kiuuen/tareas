/*
 * EJERCICIO 18C: Detectar ciclo en lista (Estilo LeetCode #141)
 * 
 * TAREA:
 * Dada una lista enlazada, determina si tiene un ciclo.
 * Usa el algoritmo de Floyd (tortuga y liebre) en O(1) espacio.
 * 
 * EJEMPLO DE SALIDA:
 * Lista sin ciclo: 1 → 2 → 3 → 4 → nullptr
 * ¿Tiene ciclo? No
 * 
 * Lista con ciclo: 1 → 2 → 3 → 4 → (vuelve a 2)
 * ¿Tiene ciclo? Sí
 * 
 * NOTA: No intentes imprimir una lista con ciclo.
 */

// Tu código aquí
#include <iostream>
#include <vector>
#include <algorithm>