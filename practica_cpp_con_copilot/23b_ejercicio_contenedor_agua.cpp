/*
 * EJERCICIO 23B: Container With Most Water (LeetCode #11 style)
 * 
 * TAREA:
 * Dado un array de alturas, donde cada elemento representa la altura
 * de una línea vertical, encuentra dos líneas que junto con el eje X
 * formen un contenedor que almacene la MAYOR cantidad de agua.
 * 
 * Área = min(altura[izq], altura[der]) × (der - izq)
 * 
 * Visualización para alturas = [1, 8, 6, 2, 5, 4, 8, 3, 7]:
 * 
 *    8 |   █           █        
 *    7 |   █     ~  ~  █  ~  █  ← El contenedor más grande
 *    6 |   █  █  ~  ~  █  ~  █  
 *    5 |   █  █  ~  █  █  ~  █  
 *    4 |   █  █  ~  █  █  █  █  
 *    3 |   █  █  ~  █  █  █  █  █
 *    2 |   █  █  █  █  █  █  █  █
 *    1 |█  █  █  █  █  █  █  █  █
 *      +--0--1--2--3--4--5--6--7--8
 * 
 * Mejor: líneas en posición 1 (h=8) y 8 (h=7)
 * Área = min(8, 7) × (8 - 1) = 7 × 7 = 49
 * 
 * ALGORITMO TWO POINTERS:
 * - izq = 0, der = n-1
 * - Calcula área actual
 * - Mueve el puntero del lado MÁS BAJO (porque mover el alto
 *   nunca puede mejorar el resultado - la altura está limitada
 *   por el lado bajo)
 * 
 * EJEMPLO DE SALIDA:
 * Alturas: [1, 8, 6, 2, 5, 4, 8, 3, 7]
 * 
 * Compara fuerza bruta vs two pointers:
 * Fuerza bruta O(n²): área máxima = 49 (entre índices 1 y 8)
 * Two pointers O(n):  área máxima = 49 (entre índices 1 y 8)
 * 
 * PISTA:
 * - ¿Por qué movemos el puntero más bajo?
 *   Si movemos el alto, la anchura baja Y la altura sigue limitada → peor
 *   Si movemos el bajo, la anchura baja PERO la altura podría subir → chance de mejorar
 */

// Tu código aquí
