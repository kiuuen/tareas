/*
 * EJERCICIO 6A: Contador de vocales (iterativo)
 * 
 * TAREA:
 * - Pide una cadena al usuario
 * - Cuenta cuántas vocales tiene (a, e, i, o, u)
 * - Ignora mayúsculas/minúsculas
 * - Usa un bucle para recorrer cada carácter
 * 
 * PISTA: Convierte la cadena a minúsculas primero
 * 
 * EJEMPLO:
 * Introduce una cadena: Hola Mundo
 * La cadena tiene 4 vocales
 */

#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string cadena;
    std::cout << "Introduce una/s palabra/s para contar vocales: ";
    std::getline(std::cin, cadena);
    std::string tolower(std::string cadena);
    int contador = 0;
    for (size_t n = 0; n <= cadena.size(); n++) {
        char primero = cadena[n];
        if (primero == 'a' || primero == 'e' || primero == 'i' || primero == 'o' || primero == 'u') {
            contador++;
        }
    }
    std::cout << "Tiene " << contador << " vocales";
    return 0;
}
