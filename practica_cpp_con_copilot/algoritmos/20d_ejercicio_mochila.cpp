/*
 * EJERCICIO 20D: Problema de la mochila 0/1 (Knapsack)
 * 
 * TAREA:
 * Dada una mochila con capacidad W y N objetos (cada uno con peso y valor),
 * elige qué objetos llevar para MAXIMIZAR el valor sin exceder el peso.
 * Cada objeto se puede tomar 0 o 1 vez.
 * 
 * EJEMPLO:
 * Capacidad: 7 kg
 * Objetos: peso=[1,3,4,5], valor=[1,4,5,7]
 * Resultado: 9 (objetos 1 y 2: peso=3+4=7, valor=4+5=9)
 * 
 * BONUS: Muestra cuáles objetos se eligieron.
 */

// Tu código aquí
#include <iostream>
#include <vector>

std::pair<std::vector<std::pair<int, int>>,int> maxValue(std::vector<std::pair<int,int>> objects, const int& weight) {
    int size = objects.size();
    std::vector<std::vector<int>> dp(size+1, std::vector<int>(weight+1, 0));
    // matrix with rows = objects, cols = weights, and [row][col] = value
    for (int obj = 1; obj < size; obj++) {
       for (int w = 0; w <= weight; w++) {
            dp[obj][w] = dp[obj-1][w];
            if (objects[obj-1].first <= w) {
                dp[obj][w] = std::max(dp[obj][w], objects[obj-1].second + dp[obj-1][w - objects[obj-1].first]);
            }
       }
    }
}
int main() {
    std::vector<std::pair<int,int>> objects{std::pair(1, 1), std::pair(3,4), std::pair(4,5), std::pair(5,7)};
    std::pair<std::vector<std::pair<int,int>>,int> max = maxValue(objects, 7);
    std::cout << "the maximum value is: " << max.second << std::endl;
    std::cout << "the objects are: \n";
    int n = 1;
    for (std::pair p : max.first) {
        std::cout << "object " << n << " weight: " << p.first << std::endl;
        std::cout << "object " << n << " value: " << p.second << std::endl;
        n++;
    }
    return 0;
}