/*
 * EJERCICIO 4G: Número primo
 * 
 * TAREA:
 * - Pide un número N al usuario
 * - Determina si es primo (solo divisible por 1 y por sí mismo)
 * - Usa un bucle para probar divisores desde 2 hasta N-1
 * 
 * PISTA: Si encuentras algún divisor, no es primo
 * 
 * EJEMPLO:
 * Introduce un número: 17
 * 17 es primo
 * 
 * Introduce un número: 20
 * 20 no es primo
 */

#include <iostream>

int main() {
    int intentos = 0;
    std::cout << "Detector de numeros primeros\nIntroduce el numero N " << '\n';
    int numero;
    std::cin >> numero;
    if (numero > 0) { // le hago que empiece en 2 porque entre 1 todos dan, y numero-1 por lo mismo
        for (int c = 2; c <= numero-1; c++) { // ese c++ predecible de mi parte
            if (numero % c != 0) {  
                intentos++;          
            }
        }
        if (intentos == numero-2){ //empieza de 2 y llega hasta numero-1, por eso le quito el # de intentos
            std::cout << numero << " es primo" << '\n';
        } else {
            std::cout << numero << " no es primo" << '\n';
        }
    } else {
        std::cout << "Introduce un numero > 0" << '\n';
    }
    return 0;
}
