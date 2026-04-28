/*
 * TEMA 21: GRAFOS (Graphs)
 * 
 * TEORÍA COMPLETA:
 * 
 * 1. ¿QUÉ ES UN GRAFO?
 *    Un conjunto de NODOS (vértices) conectados por ARISTAS (edges).
 *    
 *    Ejemplo: Red social
 *    Ana ── Carlos
 *     |      |
 *    María ─ Luis
 *    
 *    Nodos: {Ana, Carlos, María, Luis}
 *    Aristas: {(Ana,Carlos), (Ana,María), (Carlos,Luis), (María,Luis)}
 * 
 * 2. TIPOS:
 *    - DIRIGIDO: las aristas tienen dirección (A → B no implica B → A)
 *    - NO DIRIGIDO: las aristas son bidireccionales (A -- B)
 *    - PONDERADO: las aristas tienen un peso/costo (distancias, costos)
 *    - NO PONDERADO: todas las aristas "cuestan" lo mismo
 * 
 * 3. REPRESENTACIÓN EN CÓDIGO:
 * 
 *    a) LISTA DE ADYACENCIA (la más común):
 *       vector<vector<int>> grafo(n);
 *       grafo[0] = {1, 2};    // nodo 0 conecta con 1 y 2
 *       grafo[1] = {0, 3};    // nodo 1 conecta con 0 y 3
 *       
 *       Espacio: O(V + E), Bueno para grafos dispersos
 *       
 *    b) MATRIZ DE ADYACENCIA:
 *       vector<vector<int>> matriz(n, vector<int>(n, 0));
 *       matriz[0][1] = 1;  // hay arista de 0 a 1
 *       
 *       Espacio: O(V²), Bueno para grafos densos
 * 
 * 4. RECORRIDOS FUNDAMENTALES:
 * 
 *    BFS (Breadth-First Search) - Por "niveles" (usa COLA):
 *    - Visita todos los vecinos antes de ir más profundo
 *    - Ideal para: camino más corto (sin pesos), level order
 *    - Complejidad: O(V + E)
 *    
 *    DFS (Depth-First Search) - Lo más profundo posible (usa PILA/recursión):
 *    - Va lo más lejos posible por un camino antes de retroceder
 *    - Ideal para: detectar ciclos, componentes conexas, topological sort
 *    - Complejidad: O(V + E)
 * 
 * 5. ALGORITMOS CLÁSICOS DE GRAFOS:
 *    - BFS: camino más corto sin pesos
 *    - DFS: exploración, ciclos, componentes
 *    - Dijkstra: camino más corto con pesos (no negativos)
 *    - Kruskal/Prim: árbol de expansión mínima
 *    - Topological Sort: ordenar tareas con dependencias
 *    - Floyd-Warshall: caminos más cortos entre todos los pares
 * 
 * 6. ¿POR QUÉ IMPORTAN?
 *    Los grafos modelan:
 *    - Redes sociales, internet, mapas/GPS
 *    - Dependencias entre tareas, cursos prerrequisitos
 *    - Puzzles y juegos (laberintos, sudoku)
 *    - Muchos problemas de competencia se reducen a grafos
 */

#include <iostream>
#include <vector>
#include <queue>

// BFS desde un nodo fuente
void bfs(const std::vector<std::vector<int>>& grafo, int inicio) {
    int n = static_cast<int>(grafo.size());
    std::vector<bool> visitado(n, false);
    std::queue<int> cola;
    
    visitado[inicio] = true;
    cola.push(inicio);
    
    std::cout << "BFS desde nodo " << inicio << ": ";
    while (!cola.empty()) {
        int nodo = cola.front();
        cola.pop();
        std::cout << nodo << " ";
        
        for (int vecino : grafo[nodo]) {
            if (!visitado[vecino]) {
                visitado[vecino] = true;
                cola.push(vecino);
            }
        }
    }
    std::cout << std::endl;
}

// DFS desde un nodo fuente (recursivo)
void dfsHelper(const std::vector<std::vector<int>>& grafo, int nodo, std::vector<bool>& visitado) {
    visitado[nodo] = true;
    std::cout << nodo << " ";
    
    for (int vecino : grafo[nodo]) {
        if (!visitado[vecino]) {
            dfsHelper(grafo, vecino, visitado);
        }
    }
}

void dfs(const std::vector<std::vector<int>>& grafo, int inicio) {
    std::vector<bool> visitado(grafo.size(), false);
    std::cout << "DFS desde nodo " << inicio << ": ";
    dfsHelper(grafo, inicio, visitado);
    std::cout << std::endl;
}

int main() {
    /*  Grafo no dirigido:
     *    0 -- 1 -- 3
     *    |    |
     *    2 -- 4
     */
    int n = 5;
    std::vector<std::vector<int>> grafo(n);
    
    // Agregar aristas (no dirigido = agregar en ambas direcciones)
    grafo[0] = {1, 2};
    grafo[1] = {0, 3, 4};
    grafo[2] = {0, 4};
    grafo[3] = {1};
    grafo[4] = {1, 2};
    
    std::cout << "=== GRAFO (Lista de adyacencia) ===" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << i << " → ";
        for (int v : grafo[i]) std::cout << v << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
    
    bfs(grafo, 0);
    dfs(grafo, 0);
    
    return 0;
}
