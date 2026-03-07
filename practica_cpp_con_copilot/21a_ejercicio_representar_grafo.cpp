/*
 * EJERCICIO 21A: Representar y recorrer un grafo
 * 
 * TAREA:
 * Crea un grafo NO dirigido usando lista de adyacencia e implementa
 * la función para agregar aristas y mostrar el grafo.
 * 
 * 1. Usa: vector<vector<int>> grafo(n);
 * 
 * 2. Función void agregarArista(grafo, u, v):
 *    - Agrega v a la lista de u
 *    - Agrega u a la lista de v (porque es no dirigido)
 * 
 * 3. Función void mostrarGrafo(grafo):
 *    - Para cada nodo, imprime sus vecinos
 * 
 * 4. En main(), construye este grafo:
 *    0 -- 1
 *    |  / |
 *    | /  |
 *    2 -- 3
 *         |
 *         4
 *    
 *    Aristas: (0,1), (0,2), (1,2), (1,3), (2,3), (3,4)
 * 
 * 5. Muestra el grafo y responde:
 *    - ¿Cuántas aristas tiene?
 *    - ¿Cuál es el grado de cada nodo? (número de conexiones)
 *    - ¿Cuál nodo tiene más conexiones?
 * 
 * EJEMPLO DE SALIDA:
 * Grafo (5 nodos, 6 aristas):
 * 0 → 1 2
 * 1 → 0 2 3
 * 2 → 0 1 3
 * 3 → 1 2 4
 * 4 → 3
 * 
 * Grados: 0→2, 1→3, 2→3, 3→3, 4→1
 * Nodo con más conexiones: 1 (o 2 o 3), con grado 3
 */

// Tu código aquí
