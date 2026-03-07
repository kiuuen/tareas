/*
 * EJERCICIO 18A: Implementar lista enlazada completa
 * 
 * TAREA:
 * Implementa una clase ListaEnlazada con las operaciones básicas.
 * 
 * struct Nodo {
 *     int valor;
 *     Nodo* siguiente;
 *     Nodo(int v) : valor(v), siguiente(nullptr) {}
 * };
 * 
 * Clase ListaEnlazada:
 * - void insertarInicio(int val): inserta al inicio en O(1)
 * - void insertarFinal(int val): inserta al final en O(n)
 * - bool eliminar(int val): elimina la PRIMERA ocurrencia del valor. Retorna true/false.
 * - bool buscar(int val): retorna true si el valor existe
 * - int tamaño(): retorna cuántos nodos hay
 * - void imprimir(): muestra la lista como: 10 → 20 → 30 → nullptr
 * - void invertir(): invierte la lista in-place (sin crear nueva)
 * - ~ListaEnlazada(): destructor que libera toda la memoria con delete
 * 
 * Atributo privado: Nodo* cabeza;
 * 
 * En main(), demuestra:
 * - Inserta: 10, 20, 30, 40
 * - Imprime
 * - Busca 20 (true), busca 50 (false)
 * - Elimina 20
 * - Imprime de nuevo
 * - Invierte la lista
 * - Imprime invertida
 * 
 * EJEMPLO DE SALIDA:
 * Lista: 10 → 20 → 30 → 40 → nullptr
 * ¿Existe 20? Sí
 * ¿Existe 50? No
 * Eliminando 20...
 * Lista: 10 → 30 → 40 → nullptr
 * Invirtiendo...
 * Lista: 40 → 30 → 10 → nullptr
 * Tamaño: 3
 * 
 * PISTA PARA INVERTIR:
 * - Usa tres punteros: anterior, actual, siguiente
 * - Recorre y redirige los punteros uno por uno
 */

// Tu código aquí
