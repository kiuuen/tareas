/*
 * EJERCICIO 14B: Estadisticas con STL
 *
 * TAREA:
 * - Con un vector de doubles, calcula:
 *   * Minimo y maximo (minmax_element)
 *   * Promedio (accumulate)
 *   * Mediana (ordenar copia)
 *
 * EJEMPLO DE SALIDA:
 * Min: 2.0
 * Max: 9.0
 * Promedio: 5.8
 * Mediana: 6.0
 */

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

std::pair<double, double> minMax(std::vector<double> input) {
    auto [min, max] = std::minmax_element(input.begin(), input.end());
    return {*min, *max};
}
double average(std::vector<double> input) {
    double aver = std::accumulate(input.begin(), input.end(), 0);
    return aver/input.size();
}
double median(std::vector<double> vector) {
    std::sort(vector.begin(), vector.end());
    return vector[vector.size()/2];
}
void print(std::vector<double> in) {
    for (double n : in) {
        std::cout << n << " ";
    }
}
int main() {
    std::vector<double> numbers{2.0,10.0,80.0,11.0,87.0,23.0,13.2,13.1};
    std::cout << "original vector: "; print(numbers);
    std::pair<double, double> min_max = minMax(numbers);
    std::cout << "\nmin number: " << min_max.first << "\nmax number: " << min_max.second;
    std::cout << "\naverage: " << average(numbers);
    std::cout << "\nmedian: " << median(numbers);
    return 0;
}
