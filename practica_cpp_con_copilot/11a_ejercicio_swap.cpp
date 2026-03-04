/*
 * EJERCICIO 11A: Intercambiar valores (swap)
 * 
 * TAREA:
 * Crea una función que intercambie los valores de dos variables enteras
 * usando referencias.
 * 
 * - Implementa: void intercambiar(int& a, int& b)
 * - La función debe intercambiar los contenidos de a y b
 * - En el main, prueba con dos números y verifica que se intercambian
 * 
 * EJEMPLO:
 * int x = 10, y = 20;
 * std::cout << "Antes: x=" << x << ", y=" << y << "\n";
 * intercambiar(x, y);
 * std::cout << "Después: x=" << x << ", y=" << y << "\n";
 * 
 * SALIDA ESPERADA:
 * Antes: x=10, y=20
 * Después: x=20, y=10
 */

#include <iostream>

void intercambiar(int& A, int& B) {
    int c = A; // variable temporal
    A = B;
    B = c;
    // Se modifican los parametros  A y B, que al ser por referencia, modifican el a,b que le damos después
    std::cout << "\nSe intercambiaron a y b" << std::endl;
}
 
int main() {
    int a = 10;
    int b = 20;
    std::cout << "El valor de a es: " << a << "\nEl valor de b es: " << b << std::endl;
    intercambiar(a, b);
    std::cout << "El valor de a es: " << a << "\nEl valor de b es: " << b << std::endl;
    return 0;
}
