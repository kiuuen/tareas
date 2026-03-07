/*
 * EJERCICIO 17C: Implementar cola con dos pilas
 * 
 * TAREA:
 * Implementa una cola (FIFO) usando SOLAMENTE dos pilas (LIFO).
 * (Problema estilo LeetCode #232)
 * 
 * Clase MiCola con dos std::stack<int> internos: pilaEntrada y pilaSalida
 * 
 * Métodos:
 * - void push(int x): agrega a pilaEntrada
 * - int front(): retorna el frente de la cola
 * - void pop(): elimina el frente de la cola
 * - bool empty(): retorna si está vacía
 * 
 * TRUCO:
 * - Para sacar del frente, necesitas invertir el orden
 * - Cuando pilaSalida está vacía, pasa TODOS los elementos de pilaEntrada
 *   a pilaSalida (uno por uno con pop/push). Esto invierte el orden.
 * - Si pilaSalida NO está vacía, simplemente saca de pilaSalida
 * 
 * Ejemplo visual:
 *   push(1), push(2), push(3)
 *   pilaEntrada: [1, 2, 3] (3 arriba)  pilaSalida: []
 *   
 *   front() → transferir todo a pilaSalida:
 *   pilaEntrada: []  pilaSalida: [3, 2, 1] (1 arriba)
 *   front() → 1 ✓ (FIFO)
 * 
 * EJEMPLO DE SALIDA:
 * push(1), push(2), push(3)
 * front() → 1
 * pop()
 * front() → 2
 * push(4)
 * front() → 2
 * pop(), pop()
 * front() → 4
 */

// Tu código aquí
