/*
 * EJERCICIO 17D: Min Stack (Problema estilo LeetCode #155)
 * 
 * TAREA:
 * Diseña una pila que soporte push, pop, top, y obtener el mínimo
 * actual, TODO en O(1).
 * 
 * Clase MinStack:
 * - void push(int val): agrega val a la pila
 * - void pop(): elimina el tope
 * - int top(): retorna el tope
 * - int getMin(): retorna el elemento MÍNIMO actual de toda la pila en O(1)
 * 
 * TRUCO: Usa DOS pilas:
 * - pilaPrincipal: almacena todos los valores normalmente
 * - pilaMinimos: almacena el mínimo actual en cada punto
 *   Cada vez que haces push, en pilaMinimos guardas min(val, minimoActual)
 *   Cada vez que haces pop, haces pop de ambas pilas
 * 
 * EJEMPLO:
 * MinStack ms;
 * ms.push(-2);   // pila: [-2], mins: [-2]
 * ms.push(0);    // pila: [-2, 0], mins: [-2, -2]
 * ms.push(-3);   // pila: [-2, 0, -3], mins: [-2, -2, -3]
 * ms.getMin();   // → -3
 * ms.pop();      // pila: [-2, 0], mins: [-2, -2]
 * ms.top();      // → 0
 * ms.getMin();   // → -2  (¡sigue funcionando después del pop!)
 * 
 * PISTA:
 * - pilaMinimos siempre tiene el mismo tamaño que pilaPrincipal
 * - Al hacer push: pilaMinimos.push(min(val, pilaMinimos.top()))
 */

// Tu código aquí
