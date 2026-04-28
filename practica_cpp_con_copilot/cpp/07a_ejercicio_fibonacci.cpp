/*
 * EJERCICIO 7A: Fibonacci recursivo
 * 
 * TAREA:
 * Crea una función recursiva int fibonacci(int n) que calcule
 * el n-ésimo número de la secuencia de Fibonacci
 * 
 * Secuencia: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
 * Regla: fib(n) = fib(n-1) + fib(n-2)
 * Casos base: fib(0) = 0, fib(1) = 1
 * 
 * En main(), imprime los primeros 15 números de Fibonacci
 * 
 * EJEMPLO DE SALIDA:
 * fib(0) = 0
 * fib(1) = 1
 * fib(2) = 1
 * fib(3) = 2
 * ...
 */

#include <iostream>

int listaFibonacci[13]; // 0 esta ocupado y empieza en 0 por eso 13
int vueltas = 1;

int fibonacci(int numeroActual) {
    std::cout << ", " << numeroActual;
    if (vueltas > 13) {
        return 0;
    }
    vueltas++;
    listaFibonacci[vueltas] = numeroActual;
    int numeroSiguiente = numeroActual + listaFibonacci[vueltas-1]; // numero anterior
    return fibonacci(numeroSiguiente);
}

int main() {
    std::cout << "Primeros 15 numeros en secuencia fibonacci: 0";
    listaFibonacci[0] = 0;
    fibonacci(1);
    return 0;
}
