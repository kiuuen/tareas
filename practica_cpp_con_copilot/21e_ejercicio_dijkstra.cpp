/*
 * EJERCICIO 21E: Dijkstra - Camino más corto con pesos
 * 
 * TAREA:
 * Implementa el algoritmo de Dijkstra para encontrar el camino más corto
 * desde un nodo fuente a todos los demás en un grafo PONDERADO (con pesos).
 * 
 * Dijkstra funciona cuando TODOS los pesos son NO NEGATIVOS.
 * 
 * Representación: vector<vector<pair<int,int>>> grafo;
 * grafo[u] = {{v, peso}, ...} → arista de u a v con peso dado
 * 
 * Algoritmo:
 * 1. dist[v] = infinito para todos, dist[inicio] = 0
 * 2. Usa priority_queue (min-heap): {distancia, nodo}
 * 3. Mientras la cola no esté vacía:
 *    - Saca el nodo con menor distancia: {d, u}
 *    - Si d > dist[u], ignora (ya procesado)
 *    - Para cada vecino (v, peso) de u:
 *      Si dist[u] + peso < dist[v]:
 *        dist[v] = dist[u] + peso
 *        push {dist[v], v} a la cola
 * 
 * Grafo de prueba (imagina ciudades y distancias):
 *    0 --4-- 1 --1-- 2
 *    |       |       |
 *    8       2       6
 *    |       |       |
 *    3 --3-- 4 --9-- 5
 * 
 * Aristas: (0,1,4), (0,3,8), (1,2,1), (1,4,2), (2,5,6), (3,4,3), (4,5,9)
 * 
 * EJEMPLO DE SALIDA:
 * Dijkstra desde nodo 0:
 * Distancia a 0: 0
 * Distancia a 1: 4  (camino: 0 → 1)
 * Distancia a 2: 5  (camino: 0 → 1 → 2)
 * Distancia a 3: 8  (camino: 0 → 3)
 * Distancia a 4: 6  (camino: 0 → 1 → 4)
 * Distancia a 5: 11 (camino: 0 → 1 → 2 → 5)
 * 
 * PISTA:
 * - priority_queue con greater<> para min-heap:
 *   priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
 * - Para reconstruir caminos, guarda padre[v] = u cuando actualizas dist[v]
 */

// Tu código aquí
