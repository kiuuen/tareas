/*
 * EJERCICIO 11C: Buscar elemento y retornar puntero
 * 
 * TAREA:
 * 1. Crea un vector de enteros con varios números
 * 2. Implementa una función: int* buscar(std::vector<int>& vec, int valor)
 *    - Busca el valor en el vector
 *    - Si lo encuentra, retorna un puntero al elemento (&vec[i])
 *    - Si no lo encuentra, retorna nullptr
 * 3. En el main, busca un valor y si lo encuentra, modifícalo
 * 
 * EJEMPLO:
 * std::vector<int> numeros = {10, 20, 30, 40, 50};
 * int* ptr = buscar(numeros, 30);
 * if (ptr != nullptr) {
 *     std::cout << "Encontrado: " << *ptr << "\n";
 *     *ptr = 999;  // Modificar el elemento
 * }
 * 
 * SALIDA ESPERADA:
 * Encontrado: 30
 * Vector después: 10 20 999 40 50
 */

#include <iostream>
#include <vector>
#include <algorithm>
int* buscar(std::vector<int>& vector, int valorBuscar) {
    auto it = std::find(vector.begin(), vector.end(), valorBuscar);
    if (it != vector.end()) {
        std::cout << "\nValor: " << *it << " encontrado" << std::endl;
        return &(*it);
    }
    else {
        std::cout << "No se encontro el valor" << std::endl;
        return nullptr;
    }
} 
int main() {
    std::vector<int> vectorNumeros = {10, 2, 5, 8};
    std::cout << "El vector es: ";
    for (int& v : vectorNumeros) {
        std::cout << v << ", ";
    }
    int* ptr = buscar(vectorNumeros, 8);
    *ptr = 999; 
    std::cout << "\nEl vector es: ";
    for (int& v : vectorNumeros) {
        std::cout << v << ", ";
    }
    return 0;
}
