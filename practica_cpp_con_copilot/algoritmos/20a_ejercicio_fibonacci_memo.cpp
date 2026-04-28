/*
 * EJERCICIO 20A: Fibonacci con memoización
 * 
 * TAREA:
 * Implementa Fibonacci de 3 formas y compara su rendimiento:
 * 1. Recursión pura (sin optimización)
 * 2. Top-Down con memoización
 * 3. Bottom-Up con tabulación
 * 
 * Calcula fib(40) con las 3 versiones y mide el tiempo de cada una.
 * 
 * EJEMPLO DE SALIDA:
 * fib(40) = 102334155
 * Recursivo puro:   ~850 ms
 * Con memoización:  ~0 ms
 * Con tabulación:   ~0 ms
 */

// Tu código aquí
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <chrono>

unsigned int fibonacci(const int n, int prev = 0, int next = 1) {
    if (n<=1) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

int fibonacciMemo(int n, std::vector<int>& memo) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    memo[n] = fibonacciMemo(n-1, memo) + fibonacciMemo(n-2, memo);
    return memo[n];
}
int fibonacciTab(int n) {
    std::vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
int main() {
    auto start = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    int number = 40; 
    std::vector<int> memo(number+1, -1);
    start = std::chrono::high_resolution_clock::now();
    std::cout << "fibonnaci recursive " << number << " " << fibonacci(number) << std::endl;
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Elapsed time in microseconds: " << duration.count() << " mcs" << std::endl;
    start = std::chrono::high_resolution_clock::now();
    std::cout << "fibonnaci " << number << " with memoization " << fibonacciMemo(number, memo) << std::endl;
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Elapsed time in microseconds: " << duration.count() << " mcs" << std::endl;
    start = std::chrono::high_resolution_clock::now();
    std::cout << "fibonnaci " << number << " with tabularization " << fibonacciTab(number) << std::endl;
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Elapsed time in microseconds: " << duration.count() << " mcs" << std::endl;
    return 0;
}