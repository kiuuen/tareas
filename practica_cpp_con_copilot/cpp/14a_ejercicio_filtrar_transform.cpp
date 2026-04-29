/*
 * EJERCICIO 14A: Filtrar y transformar con STL
 *
 * TAREA:
 * - Dado un vector {1..10}:
 *   1) Filtra solo los pares
 *   2) Eleva cada par al cuadrado
 *   3) Calcula la suma de los cuadrados
 * - Usa: copy_if, transform, accumulate
 *
 * SALIDA ESPERADA (aprox):
 * Pares: 2 4 6 8 10
 * Cuadrados: 4 16 36 64 100
 * Suma: 220
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
std::vector<int> filterPairs(std::vector<int> input) {
    std::vector<int> pairs;
    // oit = output iterator gg jeje
    auto oit = std::copy_if(input.begin(), input.end(), std::back_inserter(pairs), []
    (int x) {
        return (x % 2 == 0); // pair true no pair false
    });
    return pairs;
 }
std::vector<int> pow(std::vector<int> input) {
    std::vector<int> squarePairs;
    auto oit = std::transform(input.begin(), input.end(), std::back_inserter(squarePairs), []
        (int x) {
            return (x*x);
        });
    return squarePairs;
}
int plus(std::vector<int> input) {
    std::vector<int> plusSquares;
    int total = std::accumulate(input.begin(), input.end(), 0);
    return total;
}
void print(std::vector<int> in) {
    for (int n : in) {
        std::cout << n << " ";
    }
}
int main() {
    std::vector<int> numbers{1,2,3,4,5,6,7,8,9,10};
    std::vector<int> pairs = filterPairs(numbers);
    std::vector<int> squaredPairs = pow(pairs);
    std::cout << "original vector: "; print(numbers);
    std::cout << "\nonly pairs: "; print(pairs);
    std::cout << "\nsquared pairs: "; print(squaredPairs);
    std::cout << "\nthe total is: " << plus(squaredPairs) << std::endl;
    return 0;
 }