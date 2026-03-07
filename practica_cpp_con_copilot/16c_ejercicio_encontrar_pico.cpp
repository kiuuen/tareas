/*
 * EJERCICIO 16C: Encontrar pico en montaña (Problema estilo LeetCode #162)
 * 
 * TAREA:
 * Un "elemento pico" es aquel que es MAYOR que sus vecinos.
 * Dado un vector donde v[i] != v[i+1] (no hay elementos iguales adyacentes),
 * encuentra UN pico usando búsqueda binaria en O(log n).
 * 
 * Crea una función int encontrarPico(vector<int>& v):
 *   - Si v[mid] > v[mid+1]: el pico está a la izquierda (o es mid)
 *     → der = mid
 *   - Si v[mid] < v[mid+1]: el pico está a la derecha
 *     → izq = mid + 1
 *   - Cuando izq == der, encontraste el pico
 * 
 * ¿POR QUÉ FUNCIONA?
 * Imagina una montaña: si estás subiendo (v[mid] < v[mid+1]), 
 * el pico está adelante. Si estás bajando, el pico está atrás.
 * 
 * EJEMPLO:
 * Entrada: [1, 3, 5, 4, 2]
 * Salida: índice 2 (valor 5 es pico: 5 > 3 y 5 > 4)
 * 
 * Entrada: [1, 2, 1, 3, 5, 6, 4]
 * Salida: índice 1 o índice 5 (ambas son válidas, cualquier pico sirve)
 * 
 * Entrada: [3, 2, 1]
 * Salida: índice 0 (el primer elemento puede ser pico si v[0] > v[1])
 * 
 * PISTAS:
 * - Tratar los bordes del vector como -infinito
 * - izq = 0, der = v.size() - 1
 * - No necesitas comparar con ambos vecinos, solo con mid+1 basta
 */

// Tu código aquí
