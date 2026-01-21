/*
 * EJERCICIO 7C: Suma de dígitos
 * 
 * TAREA:
 * Crea una función recursiva int sumaDigitos(int n) que
 * sume todos los dígitos de un número
 * 
 * EJEMPLO:
 * sumaDigitos(12345) = 1 + 2 + 3 + 4 + 5 = 15
 * sumaDigitos(999) = 9 + 9 + 9 = 27
 * 
 * PISTA:
 * - Caso base: n == 0, retorna 0
 * - Caso recursivo: (n % 10) + sumaDigitos(n / 10)
 *   (último dígito + suma del resto)
 * 
 * En main(), pide un número y muestra la suma de sus dígitos
 */

#include <iostream>

int sumarDigitos(int numero) {
    if (numero == 0) {
        return 0;
    }
    return (numero % 10) + sumarDigitos((numero / 10)); // residuo se va ir sumando solo con cada return
    // si es 123, / 10 = 12.3, el residuo de eso es 3. Como es int va a quedar en 12, y el ultimo digito (residuos) 3 separados
}

int main() { 
    std::cout << "Introduce los numeros, para sumar sus digitos: ";
    int numeros;
    std::cin >> numeros;
    std::cout << "La suma de sus digitos es: " << sumarDigitos(numeros);
    return 0;
}
