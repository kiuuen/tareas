/*
 * EJERCICIO 8B: Buscar en vector
 * 
 * TAREA:
 * - Crea un vector con los números {10, 25, 30, 15, 40, 20}
 * - Pide un número al usuario
 * - Busca ese número en el vector usando std::find
 * - Si existe, muestra su posición
 * - Si no existe, indica que no está
 * 
 * EJEMPLO:
 * Vector: 10 25 30 15 40 20
 * ¿Qué número buscas? 30
 * 30 encontrado en posición 2
 * 
 * ¿Qué número buscas? 99
 * 99 no encontrado
 * 
 * PISTA:
 * auto it = std::find(v.begin(), v.end(), valor);
 * if (it != v.end()) { ... }
 */

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::cout << "Introduce el valor a buscar en la lista: ";
    int valor;
    std::cin >> valor;
    std::vector <int> vector;
    vector.push_back(10);
    vector.push_back(25);
    vector.push_back(30);
    vector.push_back(15);
    vector.push_back(40);
    vector.push_back(20);
    auto buscador = std::find(vector.begin(), vector.end(), valor);
    if (buscador != vector.end()) { // si no llega el final, es decir se detuvo antes pq encontró
        std::cout << "Se encontró " << valor << " en la lista en la posicion " << (buscador - vector.begin()); // begin - donde lo encontro (posiciones recorridas hasta encontrarlo)
    } else { // si no lo encontró pq siguió hasta el
        std::cout << "No se encontró ese valor en la lista\n";
    }
    return 0;
}
