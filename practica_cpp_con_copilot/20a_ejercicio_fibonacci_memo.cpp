/*
 * EJERCICIO 20A: Fibonacci con memoización
 * 
 * TAREA:
 * Implementa Fibonacci de 3 formas y compara su rendimiento:
 * 
 * 1. int fibRecursivo(int n):
 *    - Recursión pura sin optimización → O(2^n)
 *    - fib(n) = fib(n-1) + fib(n-2), base: fib(0)=0, fib(1)=1
 * 
 * 2. int fibMemo(int n, vector<int>& memo):
 *    - Top-Down con memoización → O(n)
 *    - Antes de calcular, revisa si memo[n] ya tiene valor
 *    - Después de calcular, guarda en memo[n]
 * 
 * 3. int fibTabla(int n):
 *    - Bottom-Up con tabulación → O(n)
 *    - Llena tabla dp[] desde dp[0] hasta dp[n]
 * 
 * En main():
 * - Calcula fib(40) con las 3 versiones y mide el tiempo
 * - Para fibRecursivo solo prueba hasta fib(40) para ver cuánto tarda
 *   (si tarda mucho, prueba con fib(35))
 * - Muestra la diferencia de tiempo
 * 
 * EJEMPLO DE SALIDA:
 * fib(40) = 102334155
 * 
 * Recursivo puro: 850 ms   (O(2^n) - MUY lento)
 * Con memoización: 0 ms    (O(n) - instantáneo)
 * Con tabulación:  0 ms    (O(n) - instantáneo)
 * 
 * ¡La memoización convierte O(2^n) en O(n)!
 * 
 * PISTA:
 * - Para memo: vector<int> memo(n+1, -1);  (-1 significa "no calculado")
 * - Mide con chrono igual que en el ejercicio 14a
 */

// Tu código aquí
