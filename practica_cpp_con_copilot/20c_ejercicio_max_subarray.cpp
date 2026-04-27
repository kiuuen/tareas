/*
 * EJERCICIO 20C: Máximo subarray / Kadane (Estilo LeetCode #53)
 * 
 * TAREA:
 * Dado un vector de enteros (puede tener negativos), encuentra
 * el subarray contiguo con la mayor suma posible.
 * 
 * EJEMPLOS:
 * [-2, 1, -3, 4, -1, 2, 1, -5, 4] → 6  (subarray [4, -1, 2, 1])
 * [5, 4, -1, 7, 8]                 → 23 (todo el vector)
 * [-1, -2, -3]                     → -1
 * 
 * BONUS: Además de la suma, muestra cuál es el subarray.
 */

#include <iostream>
#include <vector>

// this aproach only works with sorted arrays
/*std::pair<std::vector<int>, int> minMax(std::vector<int> dp) {
    int size = dp.size();
    std::vector<int> maxsub;
    std::vector<int> actualsub;
    int temptotal = 0;
    int total = dp[0];
    for (int i = 0; i < size; i++) {
        actualsub.push_back(dp[i]);
        temptotal += dp[i];
        if (temptotal >= total) { 
            total = temptotal; 
            continue;
            } 
        actualsub.pop_back(); 
        maxsub = actualsub;
        actualsub.clear();
        temptotal = 0;
        }
    return std::pair(maxsub, total);   
}*/
std::pair<std::vector<int>, int> minMax(std::vector<int> dp) {
    std::pair<std::vector<int>, int> tempArray;
    std::pair<std::vector<int>, int> maxArray; maxArray.second = INT_MIN;
    int size = dp.size();
    int begin = 0;
    int total = 0;
    for (int end = begin; end < size; end++) {
        tempArray.first.push_back(dp[end]); 
        tempArray.second += dp[end];
        if (tempArray.second > maxArray.second) { // continue with the sub array
            maxArray = tempArray;
        } else if (tempArray.second < 0) { // start a new one with the begin index
            // ok this is the final resolution, start a new one if the total is now < 0 (no the next number)
            begin = end;
            tempArray.first.clear();
            tempArray.second = 0; 
        } 
    }
    return maxArray;
}

int main() {
    std::vector<int> vector{5, 4, -1, 7, 8};
    std::cout << "original vector is: ";
    for (int n : vector) {
        std::cout << n << " ";
    }
    std::pair<std::vector<int>, int> result = minMax(vector);
    std::cout << "\nthe max sum of the vector is: " << result.second << std::endl;
    std::cout << "the max sum vector is: ";
    for (int n : result.first) {
        std::cout << n << " ";
    }
    return 0;
}
