/*
 * EJERCICIO 16D: Raíz cuadrada entera (Estilo LeetCode #69)
 * 
 * TAREA:
 * Dado un entero positivo x, calcula su raíz cuadrada entera truncada
 * (el mayor n tal que n*n <= x).
 * NO puedes usar sqrt(), pow() ni funciones matemáticas. Usa búsqueda binaria.
 * 
 * EJEMPLOS:
 * raizCuadrada(4)  → 2
 * raizCuadrada(8)  → 2
 * raizCuadrada(27) → 5
 * raizCuadrada(0)  → 0
 */

// Tu código aquí
#include <iostream>
#include <vector>
#include <algorithm>

int minePow(const int integer) {
    int start = 0;
    int end = integer;
    int mid = static_cast<int>(start + (end - start)/2);
    while (start <= end) {
        if (start == end - 1) {
            return start;
        }
        mid = static_cast<int>(start + (end - start)/2);
        if ((mid * mid) == integer) {
            break;
        }
        if ((mid * mid) < integer) {
            start = mid;
            end = mid*2; // the number is between the previous number (thats why *2) an this one that his square is lower than the integer

        } else {
            end = mid;
        }
    }
    return mid;
    /*for example debug mind explanation, if the integer is 15, 15/2 = 7, 7 * 7 = 49, its third case, higher, so 7/2 = 3, 3*3 = 9, is lower
    so, the number is between 3, and 6 (3*2), so lets check the mid in that, 6 - 3 = 3, 3/2 = 1 + 3 = 4
    4*4 = 16, is higher, so, the range, from 3 - 6, now is 3 - 4, so start = end-1, so return the number start, 3!
    
    if the number is 25, 25/2 = 12, 12*12 = 144, higher, so 12/2 = 6, 6*6 = 36, higher, 6/2 = 3, 3 * 3 = 9, lower, range [3 - 6]
    3 + (6 - 3)/2 = 3 + 1 = 4, 4*4 = 16, lower, so the range is [4 - 6], 4 + (6 -4) / 2 = 4 + 1 = 5, 5*5 = 25, thats the integer, so return mid (5!)*/
}
int main() {
    int integer = 37;
    std::cout << "The root square of " << integer << " its: " << minePow(integer) << std::endl;
}