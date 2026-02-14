/*
 * EJERCICIO 8D: Filtrar pares e impares
 * 
 * TAREA:
 * - Crea un vector con números del 1 al 20
 * - Crea dos vectores nuevos:
 *   * pares: solo números pares
 *   * impares: solo números impares
 * - Muestra ambos vectores
 * 
 * EJEMPLO:
 * Original: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
 * Pares: 2 4 6 8 10 12 14 16 18 20
 * Impares: 1 3 5 7 9 11 13 15 17 19
 */

#include <iostream>
#include <vector>

int main() {
    std::vector<int> vectorNum = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    std::vector<int> vectorTwin;
    std::vector<int> vectorOdd;
    std::cout << "Original: ";
    for (size_t n = 0; n < vectorNum.size(); n++) {
        std::cout << vectorNum[n] << " "; 
        if ((vectorNum[n] % 2) == 0) {
            vectorTwin.push_back(vectorNum[n]);
        } else {
            vectorOdd.push_back(vectorNum[n]);
        }
    }
    std::cout << "\nPares: ";
    for (size_t n = 0; n < vectorTwin.size(); n++) {
        std::cout << vectorTwin[n] << " ";
    }
    std::cout << "\nImpares: ";
    for (size_t n = 0; n < vectorOdd.size(); n++) {
        std::cout << vectorOdd[n] << " ";
    }
    return 0;
}
