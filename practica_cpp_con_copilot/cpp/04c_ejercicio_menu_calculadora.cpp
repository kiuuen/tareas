/*
 * EJERCICIO 4C: Menú calculadora con switch
 * 
 * TAREA:
 * - Muestra un menú:
 *   1. Suma
 *   2. Resta
 *   3. Multiplicación
 *   4. División
 * - Lee la opción del usuario
 * - Lee dos números
 * - Realiza la operación seleccionada usando switch
 * 
 * EJEMPLO:
 * === CALCULADORA ===
 * 1. Suma
 * 2. Resta
 * 3. Multiplicación
 * 4. División
 * Elige una opción: 1
 * Introduce el primer número: 10
 * Introduce el segundo número: 5
 * Resultado: 10 + 5 = 15
 */

#include <iostream>
#include <utility> // usar funcion con std::pair

int numero1;
int numero2; // fuera de las funciones para hacerlas globales

std::pair<int,int> pedirNumeros() { // no lle doy parametros solo la pienso llamar
    std::cout << "Elige numero 1: ";
    std::cin >> numero1;
    std::cout << "Elige numero 2: ";
    std::cin >> numero2;
    return {numero1, numero2}; // con std pair puedo retornar dos valores
}

int main() {
    std::cout << "Bienvenido a la calculadora" << '\n';
    std::cout << "Elige que operacion usar" << '\n' << "1) Suma" << '\n' << "2) Resta" << '\n' << "3) Multiplicacion" << '\n' << "4) Division" << '\n';
    int eleccion;
    std::cin >> eleccion;
    int menu = eleccion;
    switch(menu) {
        case 1:
                pedirNumeros();
                std::cout << "La suma da = " << (numero1+numero2) << '\n';
            break;
        case 2:
                pedirNumeros();
                std::cout << "La resta da = " << (numero1-numero2) << '\n';
            break;
        case 3:
                pedirNumeros();
                std::cout << "La multiplicacion da = " << (numero1*numero2) << '\n';
            break;
        case 4:
                pedirNumeros();
                std::cout << "La division da da = " << (numero1/numero2) << '\n';
            break;

        default: // excepcion en el swtich
            std::cout << "Error, opción inválida\n";
    }
    return 0;   
}
