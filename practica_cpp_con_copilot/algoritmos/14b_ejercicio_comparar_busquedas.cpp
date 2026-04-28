/*
 * EJERCICIO 14B: Comparar búsqueda lineal vs binaria
 * 
 * TAREA:
 * Implementa dos funciones de búsqueda y compara su rendimiento:
 * 
 * 1. int busquedaLineal(vector<int>& v, int target):
 *    - Recorre el vector elemento por elemento → O(n)
 *    - Retorna el índice donde encontró target, o -1 si no existe
 * 
 * 2. int busquedaBinaria(vector<int>& v, int target):
 *    - Requiere vector ORDENADO
 *    - Divide el espacio de búsqueda a la mitad cada vez → O(log n)
 *    - Retorna el índice donde encontró target, o -1 si no existe
 * 
 * 3. En main():
 *    - Genera un vector ORDENADO de 10,000,000 de números (0, 1, 2, ..., 9999999)
 *    - Busca el elemento 9,999,998 (casi al final, peor caso para lineal)
 *    - Mide el tiempo de cada búsqueda
 *    - Muestra la diferencia
 * 
 * PISTAS:
 * - Búsqueda binaria: izq = 0, der = size-1, mid = (izq+der)/2
 *   Si v[mid] == target → encontrado
 *   Si v[mid] < target → izq = mid + 1
 *   Si v[mid] > target → der = mid - 1
 * 
 * EJEMPLO DE SALIDA:
 * Vector ordenado de 10,000,000 elementos
 * Buscando el valor 9999998...
 * 
 * Búsqueda lineal: 12 ms  → encontrado en índice 9999998
 * Búsqueda binaria: 0 ms  → encontrado en índice 9999998
 * 
 * La binaria hizo ~23 comparaciones vs ~10,000,000 de la lineal
 */

// Tu código aquí

#include <iostream>
#include <vector>
#include <chrono>

int busquedaLineal(std::vector<int>& v, int target, int &comparacion) {
    for (size_t n = 0; n < v.size(); n++) {
        comparacion++;
        if (static_cast<int>(n) == target) {
            return static_cast<int>(n);
        }
    }
    std::cout << "No encontrado" << std::endl;
    return -1; // no encontrado
}

int busquedaBinaria(std::vector<int>& v, int target, int &comparacion) {
    int izq = 0;
    int der = static_cast<int>(v.size())-1;
    comparacion++;
    while (izq <= der) {
    comparacion++;
    int mid = izq + (der - izq)/2;
        if (v[mid] == target) {
            return mid+1;
        }
        if (v[mid] < target) {
            izq = mid + 1;
        }
        if (v[mid] > target) {
            der = mid - 1;
        }
    }
    std::cout << "No encontrado" << std::endl;
    return -1;
}
int main () {  
    int comparacionesLineal = 0;
    auto inicio = std::chrono::high_resolution_clock::now();
    auto fin = std::chrono::high_resolution_clock::now();
    auto duracion = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio);
    int comparacionesBinario = 0;
    std::vector<int> vectorNumeros;
    for (int n = 1; n < 10000001; n++) {
        vectorNumeros.push_back(n);
    }

    std::cout << "\nBuscando 9,999,998\n";
    inicio = std::chrono::high_resolution_clock::now();
    std::cout<< "\nBusqueda lineal: Encontrado en indice: " << busquedaLineal(vectorNumeros, 9999998, comparacionesLineal) << ", comparaciones: " << comparacionesLineal << std::endl;
    fin = std::chrono::high_resolution_clock::now();
    auto duracionTemp = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio);
    inicio = std::chrono::high_resolution_clock::now();
    std::cout << "\nBusqueda binaria: Encontrado en indice: " << busquedaBinaria(vectorNumeros, 9999998, comparacionesBinario) << ", comparaciones: " << comparacionesBinario << std::endl;
    fin = std::chrono::high_resolution_clock::now();
    duracion = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio);
    std::cout << "\nTiempo lineal: " << duracionTemp.count() << " microsegundos"
    << "\nTiempo binario: " << duracion.count() << " microsegundos"
    << "\nDiferencia en veces lineal/binario: " << (static_cast<int>(duracionTemp.count()))/(static_cast<int>(duracion.count())) << " veces mas rapido" << std::endl;
}