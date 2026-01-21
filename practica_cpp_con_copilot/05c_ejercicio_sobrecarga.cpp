/*
 * EJERCICIO 5C: Sobrecarga de funciones
 * 
 * TAREA:
 * Crea múltiples versiones de la función "maximo":
 * 
 * 1. int maximo(int a, int b)
 *    - Retorna el mayor de dos enteros
 * 
 * 2. double maximo(double a, double b)
 *    - Retorna el mayor de dos doubles
 * 
 * 3. int maximo(int a, int b, int c)
 *    - Retorna el mayor de tres enteros
 * 
 * En main(), prueba las tres versiones
 * 
 * EJEMPLO:
 * maximo(5, 10) = 10
 * maximo(5.5, 3.2) = 5.5
 * maximo(5, 10, 7) = 10
 */

#include <iostream>

int maximo(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}
int maximo(int a, int b, int c) {
    if (a > b && a > c) {
        return a;
    } if (b > c && b > a) {
        return b;
    } else {
        return c;
    }
}
double maximo(double a, double b) {
    if (a > b) {
        return a; 
    } else {
        return b;
    }
}
int main() {
    double a;
    double b;
    double c;
    std::cout << "Introduce a";
    std::cin >> a;
    std::cout << "Introduce b";
    std::cin >> b;
    std::cout << "Introduce c";
    std::cin >> c;
    std::cout << "Maximo 1) int " << int(maximo(a, b)) << "\nMaximo 2) doubles " << maximo(a, b) << "\nMaximo 3) a b y c " << maximo(a, b, c);
    return 0;
}
