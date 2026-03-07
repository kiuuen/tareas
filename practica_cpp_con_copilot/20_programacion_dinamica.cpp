/*
 * TEMA 20: PROGRAMACIÓN DINÁMICA (Dynamic Programming - DP)
 * 
 * TEORÍA COMPLETA:
 * 
 * 1. ¿QUÉ ES PROGRAMACIÓN DINÁMICA?
 *    Es una técnica para resolver problemas dividiéndolos en subproblemas
 *    más pequeños y GUARDANDO sus resultados para no recalcularlos.
 *    
 *    Si un problema tiene:
 *    ✓ Subproblemas superpuestos (se repiten los mismos cálculos)
 *    ✓ Subestructura óptima (la solución óptima se construye de soluciones óptimas de subproblemas)
 *    → Se puede resolver con DP
 * 
 * 2. EJEMPLO CLÁSICO - FIBONACCI:
 *    
 *    Sin DP (recursión pura) → O(2^n) ← ¡HORRIBLE!
 *    fib(5) = fib(4) + fib(3)
 *    fib(4) = fib(3) + fib(2)    ← fib(3) se calcula DOS veces
 *    fib(3) = fib(2) + fib(1)    ← fib(2) se calcula TRES veces
 *    
 *    Con DP (memoización) → O(n) ← ¡MUCHO mejor!
 *    Guardas fib(2), fib(3), etc. y no los recalculas.
 * 
 * 3. DOS ENFOQUES DE DP:
 * 
 *    a) TOP-DOWN (Memoización): 
 *       - Recursión + tabla/mapa para guardar resultados
 *       - "De arriba hacia abajo": empiezas con el problema grande
 *       - Más intuitivo, parece recursión normal con cache
 *       
 *       int fib(int n, vector<int>& memo) {
 *           if (n <= 1) return n;
 *           if (memo[n] != -1) return memo[n];     // Ya calculado
 *           memo[n] = fib(n-1, memo) + fib(n-2, memo);
 *           return memo[n];
 *       }
 *    
 *    b) BOTTOM-UP (Tabulación):
 *       - Iterativo con tabla/vector
 *       - "De abajo hacia arriba": empiezas con los casos base
 *       - Generalmente más eficiente (no hay overhead de recursión)
 *       
 *       int fib(int n) {
 *           vector<int> dp(n+1);
 *           dp[0] = 0; dp[1] = 1;
 *           for (int i = 2; i <= n; i++)
 *               dp[i] = dp[i-1] + dp[i-2];
 *           return dp[n];
 *       }
 * 
 * 4. PATRÓN GENERAL PARA RESOLVER DP:
 *    Paso 1: Define qué representa dp[i] (¿qué almacena?)
 *    Paso 2: Encuentra la RELACIÓN DE RECURRENCIA (cómo calcular dp[i] a partir de otros)
 *    Paso 3: Define los CASOS BASE (dp[0], dp[1], etc.)
 *    Paso 4: Decide el ORDEN de cálculo (de menor a mayor, generalmente)
 *    Paso 5: ¿La respuesta es dp[n]? ¿O el máximo de todo dp?
 * 
 * 5. PATRONES COMUNES DE DP:
 *    - 1D lineal: Fibonacci, subir escaleras, casa ladrón
 *    - 2D grid: caminos en matriz, LCS, edit distance
 *    - Decisión sí/no: mochila 0/1, subset sum
 *    - Intervalos: longest palindromic substring, matrix chain
 * 
 * 6. CUÁNDO SOSPECHAR QUE ES DP:
 *    - "Encuentra el MÍNIMO/MÁXIMO..."
 *    - "¿Cuántas FORMAS hay de...?"
 *    - "¿Es POSIBLE llegar a...?"
 *    - El espacio de búsqueda tiene subproblemas que se repiten
 */

#include <iostream>
#include <vector>

// Fibonacci Top-Down (Memoización)
int fibMemo(int n, std::vector<int>& memo) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    memo[n] = fibMemo(n-1, memo) + fibMemo(n-2, memo);
    return memo[n];
}

// Fibonacci Bottom-Up (Tabulación)
int fibTab(int n) {
    if (n <= 1) return n;
    std::vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

// Fibonacci Bottom-Up optimizado (O(1) espacio)
int fibOpt(int n) {
    if (n <= 1) return n;
    int a = 0, b = 1;
    for (int i = 2; i <= n; i++) {
        int temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

int main() {
    int n = 10;
    
    // Top-Down
    std::vector<int> memo(n + 1, -1);
    std::cout << "Fibonacci Top-Down:   fib(" << n << ") = " << fibMemo(n, memo) << std::endl;
    
    // Bottom-Up
    std::cout << "Fibonacci Bottom-Up:  fib(" << n << ") = " << fibTab(n) << std::endl;
    
    // Optimizado
    std::cout << "Fibonacci Optimizado: fib(" << n << ") = " << fibOpt(n) << std::endl;
    
    // Mostrar la secuencia
    std::cout << "\nSecuencia: ";
    for (int i = 0; i <= n; i++) {
        std::cout << fibOpt(i) << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
