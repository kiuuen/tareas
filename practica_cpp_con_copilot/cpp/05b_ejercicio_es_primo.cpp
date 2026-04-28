/*
 * EJERCICIO 5B: Verificador de primo
 * 
 * TAREA:
 * Crea una función bool esPrimo(int n) que:
 * - Retorna true si n es primo
 * - Retorna false si no es primo
 * - Un número es primo si solo es divisible por 1 y por sí mismo
 * 
 * PISTA: Prueba divisores desde 2 hasta n-1
 * Si encuentras alguno que divida exactamente, no es primo
 * 
 * En main(), pide un número al usuario y usa la función
 * 
 * EJEMPLO:
 * Introduce un número: 17
 * 17 es primo
 * 
 * Introduce un número: 20
 * 20 no es primo
 */

#include <iostream>

bool esPrimo(int numero) {
    for (int n = 2; n <= numero-1; n++) { // checo si es divisible, el numero, 1 y 0 siempre dan
        if (numero % n == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int numero;
    std::cout << "Detector numeros primos\nIntroduce el numero";
    std::cin >> numero;
    if (esPrimo(numero) == true) {
        std::cout << numero << " es primo";
    } if (esPrimo(numero) == false) {
        std::cout << numero <<  " no es primo";
    }
    return 0;
}

