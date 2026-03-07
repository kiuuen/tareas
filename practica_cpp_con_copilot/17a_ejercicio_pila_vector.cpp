/*
 * EJERCICIO 17A: Implementar pila con vector
 * 
 * TAREA:
 * Implementa tu propia clase MiPila<T> usando un std::vector internamente.
 * NO uses std::stack. El objetivo es entender cómo funciona por dentro.
 * 
 * La clase debe tener:
 * - void push(int valor): agrega al tope (usa push_back del vector)
 * - void pop(): elimina del tope (usa pop_back) - si está vacía, muestra error
 * - int top(): retorna el tope (back() del vector) - si está vacía, muestra error
 * - bool empty(): retorna si está vacía
 * - int size(): retorna el tamaño
 * - void mostrar(): imprime la pila de arriba a abajo
 * 
 * En main() demuestra todas las operaciones:
 * - Push: 10, 20, 30
 * - Mostrar la pila
 * - Top → debe ser 30
 * - Pop → remueve 30
 * - Top → ahora debe ser 20
 * - Size → debe ser 2
 * 
 * EJEMPLO DE SALIDA:
 * Push: 10, 20, 30
 * Pila (tope → base): 30 20 10
 * Top: 30
 * Pop!
 * Top: 20
 * Size: 2
 * Empty: No
 * 
 * PISTA:
 * - push_back() del vector = push de la pila
 * - back() del vector = top de la pila
 * - pop_back() del vector = pop de la pila
 */

// Tu código aquí
