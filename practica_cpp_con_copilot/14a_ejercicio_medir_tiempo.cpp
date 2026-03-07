/*
 * EJERCICIO 14A: Medir tiempo de ejecución
 * 
 * TAREA:
 * Escribe dos funciones que resuelvan el MISMO problema de formas distintas
 * y mide cuál es más rápida:
 * 
 * Problema: Dado un vector de N números, encontrar si hay algún duplicado.
 * 
 * 1. Función tieneDuplicados_ON2(vector<int>& v):
 *    - Usa dos bucles anidados (fuerza bruta) → O(n²)
 *    - Compara cada par de elementos
 * 
 * 2. Función tieneDuplicados_ON(vector<int>& v):
 *    - Usa un unordered_set (hash set) → O(n)
 *    - Recorre una vez: si el elemento ya está en el set, hay duplicado
 * 
 * 3. En main():
 *    - Genera un vector de 50,000 números aleatorios (entre 0 y 100,000)
 *    - Mide el tiempo de cada función usando <chrono>
 *    - Muestra cuánto tardó cada una
 * 
 * PISTAS:
 * - #include <chrono> para medir tiempo
 * - #include <unordered_set> para el hash set
 * - #include <cstdlib> para rand()
 * - auto inicio = std::chrono::high_resolution_clock::now();
 *   // ... código ...
 *   auto fin = std::chrono::high_resolution_clock::now();
 *   auto duracion = std::chrono::duration_cast<std::chrono::milliseconds>(fin - inicio);
 * 
 * EJEMPLO DE SALIDA:
 * Vector de 50000 elementos generado
 * 
 * O(n²) - Fuerza bruta: 2450 ms → Resultado: tiene duplicados
 * O(n)  - Hash set:      3 ms   → Resultado: tiene duplicados
 * 
 * ¡La versión O(n) fue ~816x más rápida!
 */

// Tu código aquí
