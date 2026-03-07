/*
 * TEMA 22: GREEDY Y BACKTRACKING
 * 
 * TEORÍA COMPLETA:
 * 
 * ═══════════════════════════════════════
 * PARTE 1: ALGORITMOS GREEDY (Voraces)
 * ═══════════════════════════════════════
 * 
 * IDEA: En cada paso, toma la mejor decisión LOCAL esperando
 *       que lleve a la mejor solución GLOBAL.
 * 
 * ¿Cuándo funciona?
 * - Cuando la "elección local óptima" siempre lleva al "óptimo global"
 * - No siempre funciona (ejemplo: cambio de monedas con valores raros)
 * - Si funciona, suele ser más eficiente que DP
 * 
 * PATRÓN:
 * 1. Ordenar los datos según algún criterio
 * 2. Recorrer y tomar la mejor decisión en cada paso
 * 3. Nunca "deshaces" una decisión
 * 
 * Ejemplo clásico: Selección de actividades
 * Tienes actividades con (inicio, fin). ¿Cuántas puedes hacer sin solaparte?
 * Greedy: ordena por hora de fin, siempre toma la que termine primero.
 * 
 * ═══════════════════════════════════════
 * PARTE 2: BACKTRACKING (Vuelta atrás)
 * ═══════════════════════════════════════
 * 
 * IDEA: Construye soluciones incrementalmente. Si en algún punto 
 *       la solución parcial no puede completarse, RETROCEDE y 
 *       prueba otra opción.
 * 
 * Es como explorar un laberinto:
 * - Avanzas por un camino
 * - Si llegas a un callejón sin salida → retrocedes al último cruce
 * - Tomas otro camino
 * - Repites hasta encontrar la salida (o explorar todo)
 * 
 * PATRÓN (Template):
 * void backtrack(estado, decisiones, resultados) {
 *     if (es_solucion(estado)) {
 *         resultados.push_back(estado);
 *         return;
 *     }
 *     for (cada opción posible) {
 *         if (es_válida(opción)) {
 *             hacer(opción);                // HACER
 *             backtrack(nuevo_estado, ...);  // EXPLORAR
 *             deshacer(opción);              // DESHACER (backtrack)
 *         }
 *     }
 * }
 * 
 * Ejemplos clásicos: N-Reinas, Sudoku, Permutaciones, Subconjuntos
 * 
 * RELACIÓN:
 * - Greedy: rápido, no siempre correcto
 * - Backtracking: más lento, siempre encuentra solución si existe
 * - DP: memoriza resultados, evita calcular lo mismo 2 veces
 */

#include <iostream>
#include <vector>
#include <algorithm>

// ═══════════════════════════════════════
// EJEMPLO GREEDY: Selección de actividades
// ═══════════════════════════════════════
void seleccionActividades() {
    // {inicio, fin}
    std::vector<std::pair<int,int>> actividades = {
        {1, 3}, {2, 5}, {4, 7}, {1, 8}, {5, 9}, {8, 10}
    };
    
    // Ordenar por hora de fin
    std::sort(actividades.begin(), actividades.end(), 
        [](const auto& a, const auto& b) { return a.second < b.second; });
    
    std::cout << "=== Greedy: Selección de Actividades ===" << std::endl;
    std::vector<std::pair<int,int>> seleccionadas;
    int ultimoFin = 0;
    
    for (const auto& [ini, fin] : actividades) {
        if (ini >= ultimoFin) {
            seleccionadas.push_back({ini, fin});
            ultimoFin = fin;
        }
    }
    
    std::cout << "Actividades seleccionadas: " << seleccionadas.size() << std::endl;
    for (const auto& [ini, fin] : seleccionadas) {
        std::cout << "  [" << ini << ", " << fin << ")" << std::endl;
    }
}

// ═══════════════════════════════════════
// EJEMPLO BACKTRACKING: Generar subconjuntos
// ═══════════════════════════════════════
void generarSubconjuntos(std::vector<int>& nums, int idx, 
                          std::vector<int>& actual, 
                          std::vector<std::vector<int>>& resultado) {
    resultado.push_back(actual);  // cada estado parcial es un subconjunto
    
    for (int i = idx; i < static_cast<int>(nums.size()); i++) {
        actual.push_back(nums[i]);                  // HACER
        generarSubconjuntos(nums, i + 1, actual, resultado);  // EXPLORAR
        actual.pop_back();                            // DESHACER
    }
}

int main() {
    seleccionActividades();
    
    std::cout << "\n=== Backtracking: Subconjuntos de {1, 2, 3} ===" << std::endl;
    std::vector<int> nums = {1, 2, 3};
    std::vector<int> actual;
    std::vector<std::vector<int>> resultado;
    generarSubconjuntos(nums, 0, actual, resultado);
    
    for (const auto& sub : resultado) {
        std::cout << "{ ";
        for (int x : sub) std::cout << x << " ";
        std::cout << "}" << std::endl;
    }
    // Salida: {}, {1}, {1,2}, {1,2,3}, {1,3}, {2}, {2,3}, {3}
    
    return 0;
}
