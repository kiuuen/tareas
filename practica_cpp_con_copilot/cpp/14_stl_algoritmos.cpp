/*
 * TEMA 14: STL Y ALGORITMOS (C++ IDIOMATICO)
 *
 * TEORIA AMPLIADA:
 * - La STL trabaja con rangos [begin, end). Casi todos los algoritmos reciben
 *   dos iteradores: inicio y fin.
 * - <algorithm> contiene algoritmos genericos:
 *   * sort / stable_sort: ordena en O(n log n). stable_sort conserva el orden
 *     relativo de elementos iguales.
 *   * find_if / count_if: usan un predicado (funcion o lambda).
 *   * copy_if: copia solo lo que cumple el predicado. Usa back_inserter si el
 *     vector destino esta vacio.
 *   * transform: aplica una funcion a cada elemento. Requiere destino con size
 *     ya reservado o un back_inserter.
 *   * partial_sort / nth_element: ordenar parcialmente, muy util para top K elementos.
 *   * remove_if / erase: el modismo Erase-Remove indispensable (los algoritmos de STL no cambian el tamano del contenedor, debes llamar .erase despues).
 * - <numeric>:
 *   * accumulate: reduce un rango a un valor. El tipo del resultado depende
 *     del valor inicial (0 vs 0.0).
 * - Lambdas:
 *   * Sintaxis: [captura](parametros) { cuerpo }
 *   * Captura por valor [=] o por referencia [&] cuando necesitas variables externas.
 * - Complejidad: la mayoria de algoritmos son O(n) o O(n log n). Esto importa
 *   mas que micro-optimizaciones en loops manuales.
 *
 * OBJETIVO:
 * - Resolver tareas comunes con menos loops manuales y codigo mas expresivo.
 * - Aprender a leer y escribir soluciones idiomaticas en C++.
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>
#include <vector>

void imprimir(const std::vector<int>& v, const std::string& etiqueta) {
    std::cout << etiqueta << ": ";
    for (int x : v) {
        std::cout << x << " ";
    }
    std::cout << "\n";
}

int main() {
    std::vector<int> datos = {7, 2, 9, 4, 1, 6};

    imprimir(datos, "Original");
    std::sort(datos.begin(), datos.end());
    imprimir(datos, "Ordenado");

    int pares = std::count_if(datos.begin(), datos.end(), [](int x) {
        return x % 2 == 0;
    });
    std::cout << "Pares: " << pares << "\n";

    std::vector<int> mayores;
    std::copy_if(datos.begin(), datos.end(), std::back_inserter(mayores), [](int x) {
        return x >= 5;
    });
    imprimir(mayores, "Mayores o iguales a 5");

    std::vector<int> dobles(datos.size());
    std::transform(datos.begin(), datos.end(), dobles.begin(), [](int x) {
        return x * 2;
    });
    imprimir(dobles, "Dobles");

    int suma = std::accumulate(datos.begin(), datos.end(), 0);
    std::cout << "Suma: " << suma << "\n";

    return 0;
}

