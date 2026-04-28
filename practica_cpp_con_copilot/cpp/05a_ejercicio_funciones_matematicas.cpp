/*
 * EJERCICIO 5A: Funciones matemáticas básicas
 * 
 * TAREA:
 * Crea las siguientes funciones:
 * 
 * 1. int potencia(int base, int exponente)
 *    - Calcula base^exponente usando un bucle
 *    - Ejemplo: potencia(2, 3) = 8
 * 
 * 2. bool esPar(int n)
 *    - Retorna true si n es par, false si no
 * 
 * 3. int maximo(int a, int b)
 *    - Retorna el mayor de dos números
 * 
 * Luego en main(), prueba las tres funciones con diferentes valores
 */

#include <math.h>
#include <iostream>

int potencia(int base, int exponente) {
    for (int n = 1; n <= exponente; n++) {
        pow(base, exponente);
    }
}
bool parImpar(int numero) {
    if (numero % 2 != 0) {
        return false;
    }
}
int maximo(int numero1, int numero2) {
    if (numero1 > numero2) {
        return numero1;
    } else {
        return numero2;
    }
}
int main() {
    std::cout << "Selecciona que función utilizar" << "\n" << "1) Potencia" << "\n" << "2) Detector impares" << "\n" << "3) Numero mayor";
    int eleccion;
    std::cin >> eleccion;
    if (eleccion == 1) {
        std::cout << "Introduce la base";
        int base;
        std::cin >> base;
        std::cout << "Introduce el exponente";
        int exponente;
        std::cin >> exponente;
        std::cout << "El resultado es: " << potencia(base, exponente);
    }
    if (eleccion == 2) {
        std::cout << "Introduce el número";
        int numero;
        std::cin >> numero;
        if (parImpar(numero) == false) {
            std::cout << "El numero es impar";
        } else {
            std::cout << "El numero es par";
        }
    }
    if (eleccion == 3) {
        std::cout << "Introduce el primer numero";
        int numero1;
        std::cin >> numero1;
        std::cout << "Introduce el segundo numero";
        int numero2;
        std::cin >>  numero2;
        std::cout << "El numero mayor es" << maximo(numero1, numero2) << "\n";
    }
    return 0;
}