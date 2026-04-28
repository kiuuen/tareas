/*
 * EJERCICIO 4H: Pirámide de asteriscos
 * 
 * TAREA:
 * - Pide la altura de la pirámide
 * - Imprime una pirámide centrada usando bucles anidados
 * 
 * EJEMPLO (altura = 5):
 *     *
 *    ***
 *   *****
 *  *******
 * *********
 * 
 * PISTA:
 * - Línea 1: 4 espacios, 1 asterisco
 * - Línea 2: 3 espacios, 3 asteriscos
 * - Línea 3: 2 espacios, 5 asteriscos
 * - Línea i: (altura-i) espacios, (2*i-1) asteriscos
 */

#include <iostream>

int main() {
    std::cout << "Introduce la altura de la pirámide: ";
    int altura;
    std::cin >> altura;
    for (int n = 1; n <= altura; n++) {
        for (int m = 1; m <= altura-n; m++) {
            std::cout << " ";
        }
        for (int p = 1; p <= 2*n-1; p++) { // el 2*n-1 es para que se vaya en impares, 1, 3 ,5, 7, 9....
            std::cout << "*";
        }
        std::cout << '\n';
    }
    return 0;
}
