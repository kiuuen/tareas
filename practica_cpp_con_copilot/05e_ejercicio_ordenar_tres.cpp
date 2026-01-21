/*
 * EJERCICIO 5E: Ordenar tres números
 * 
 * TAREA:
 * Crea una función void ordenar(int& a, int& b, int& c) que:
 * - Ordena los tres números de MENOR a MAYOR
 * - Modifica los valores originales usando referencias
 * 
 * PISTA: Usa comparaciones e intercambios
 * 
 * EJEMPLO:
 * int x = 30, y = 10, z = 20;
 * ordenar(x, y, z);
 * // Ahora: x=10, y=20, z=30
 */

#include <iostream>

void sortMayorMenor(int& a, int& b, int& c) {
    int temporal = 0;
    int temporal2 = 0;
    if (b > a) {
        temporal = b;
        temporal2 = a;
        b = temporal2;
        a = temporal;
    } if (c > a) {
        temporal = c;
        temporal2 = a;
        c = temporal2;
        a = temporal;
    } if (c > b) {
        temporal = c;
        temporal2 = b;
        c = temporal2;
        b = temporal;
    }
}
void sortMenorMayor(int& a, int& c) {
    int temporal = 0;
    int temporal3 = 0;
    temporal = a;
    temporal3 = c;
    c = temporal;
    a = temporal3;
}

int main() {
    int a;
    int b;
    int c;
    std::cout << "Introduce a: ";
    std::cin >> a;
    std::cout << "Introduce b: ";
    std::cin >> b;
    std::cout << "Introduce c: ";
    std::cin >> c;
    std::cout << "El orden sin sortear es: " << a << b << c << "\nEl nuevo orden sorteado (MAYOR A MENOR) es: ";
    sortMayorMenor(a, b, c);
    std::cout << a << b << c << "\nDe MENOR a MAYOR es: ";
    sortMenorMayor(a, c);
    std::cout << a << b << c;
    return 0;
}
