/*
 * EJERCICIO 8C: Ordenar y estadísticas
 * 
 * TAREA:
 * - Lee N números del usuario y guárdalos en un vector
 * - Ordena el vector con std::sort
 * - Muestra:
 *   * El vector ordenado
 *   * El valor mínimo (primer elemento)
 *   * El valor máximo (último elemento)
 *   * La mediana (elemento del medio)
 * 
 * EJEMPLO:
 * ¿Cuántos números? 7
 * [Introduce 7 números: 50, 20, 80, 10, 30, 90, 40]
 * 
 * Ordenado: 10 20 30 40 50 80 90
 * Mínimo: 10
 * Máximo: 90
 * Mediana: 40
 */

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::cout << "Cuantos números deseas introducir?: " << "\n";
    size_t n;
    std::cin >> n;
    int tamano;
    int mediana;
    std::vector<int> vectorUsuario(n); // reservo un vector de tamaño n (dado por usuario), con todos los elementos 0 por ahora
    for (size_t i = 0; i < vectorUsuario.size(); i++) {
        int valorVectorTemp;
        std::cout << (i+1) << ") Introduce el valor: ";
        std::cin >> valorVectorTemp;
        vectorUsuario[i] = valorVectorTemp;
        mediana += valorVectorTemp;
        tamano++;
    }    
    std::cout << "Original: ";
    for (size_t m = 0; m < vectorUsuario.size(); m++) {
        std::cout << vectorUsuario[m];
    }
    std::cout << "\nOrdenado min/max: ";
    std::sort(vectorUsuario.begin(), vectorUsuario.end());
    for (size_t l = 0; l < vectorUsuario.size(); l++) {
        std::cout << vectorUsuario[l];
    }
    std::cout << "Minimo: " << vectorUsuario.front() << "\nMaximo: " << vectorUsuario.back();
    std::cout << "\nMediana: " << (mediana/tamano);
    return 0;
}
