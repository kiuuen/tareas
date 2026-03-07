/*
 * EJERCICIO 21B: BFS - Camino más corto sin pesos
 * 
 * TAREA:
 * Implementa BFS (Breadth-First Search) y úsalo para encontrar
 * el camino más corto entre dos nodos en un grafo no ponderado.
 * 
 * 1. Función vector<int> bfs(grafo, inicio, destino):
 *    - Usa queue<int> para el recorrido
 *    - Usa vector<bool> visitado para no repetir nodos
 *    - Usa vector<int> padre para reconstruir el camino
 *      padre[v] = u significa "llegué a v desde u"
 *    - Cuando llegas al destino, reconstruye el camino usando padre
 *    - Retorna el camino como vector de nodos
 * 
 * 2. Grafo de prueba (imagina un mapa simplificado):
 *    0 -- 1 -- 2
 *    |         |
 *    3 -- 4 -- 5
 *         |
 *         6 -- 7
 * 
 * 3. Encuentra el camino más corto de 0 a 7
 *    y de 0 a 5
 * 
 * EJEMPLO DE SALIDA:
 * BFS desde 0:
 * Orden de visita: 0 1 3 2 4 5 6 7
 * 
 * Camino más corto de 0 a 7: 0 → 3 → 4 → 6 → 7 (distancia: 4)
 * Camino más corto de 0 a 5: 0 → 1 → 2 → 5 (distancia: 3)
 * 
 * PISTA:
 * - Inicializa padre[inicio] = -1 (no tiene padre)
 * - Al encontrar destino, recorre padre[] hacia atrás:
 *   camino = [destino]
 *   while (camino.back() != inicio): camino.push_back(padre[camino.back()])
 *   reverse(camino)
 */

// Tu código aquí
