/*
 * EJERCICIO 21C: DFS - Componentes conexas
 * 
 * TAREA:
 * Implementa DFS (Depth-First Search) y úsalo para encontrar
 * cuántas COMPONENTES CONEXAS tiene un grafo.
 * 
 * Una componente conexa es un grupo de nodos donde puedes llegar
 * desde cualquier nodo a cualquier otro del grupo.
 * 
 * Ejemplo visual:
 *   0 -- 1    2 -- 3    4
 *        |         |
 *        5         6
 * 
 *   Componente 1: {0, 1, 5}
 *   Componente 2: {2, 3, 6}
 *   Componente 3: {4}
 *   Total: 3 componentes
 * 
 * Algoritmo:
 * - Para cada nodo de 0 a n-1:
 *   Si no ha sido visitado → es una nueva componente
 *   Llama DFS desde ese nodo → marca todos los alcanzables como visitados
 *   Incrementa el contador de componentes
 * 
 * 1. Función void dfs(grafo, nodo, visitado, componente):
 *    - Marca nodo como visitado
 *    - Agrega nodo a la componente actual
 *    - Para cada vecino no visitado: llamar dfs recursivamente
 * 
 * 2. Función int contarComponentes(grafo, n):
 *    - Recorre todos los nodos, lanza DFS desde los no visitados
 *    - Retorna el número de componentes
 * 
 * 3. Construye el grafo del ejemplo y prueba
 * 
 * EJEMPLO DE SALIDA:
 * Grafo con 7 nodos:
 * 0 → 1
 * 1 → 0 5
 * 2 → 3
 * 3 → 2 6
 * 4 → (aislado)
 * 5 → 1
 * 6 → 3
 * 
 * Componentes conexas: 3
 * Componente 1: {0, 1, 5}
 * Componente 2: {2, 3, 6}
 * Componente 3: {4}
 */

// Tu código aquí
