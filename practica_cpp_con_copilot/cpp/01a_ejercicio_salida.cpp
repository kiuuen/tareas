/*
 * EJERCICIO 1A: Práctica de salida
 * 
 * TAREA: Imprime la siguiente información en líneas separadas:
 * - Tu nombre completo
 * - Tu edad
 * - Tu ciudad
 * - Tu lenguaje favorito
 * 
 * BONUS: Imprime todo en una sola línea separado por comas
 */

#include <iostream>

int main() {
    // standart library character out 
    std::cout << "Daniel" << '\n'; // '\n' hace saltos de linea, concateno con <<
    std::cout << "17" << '\n';
    std::cout << "ola" << '\n';    
    std::cout << "jaba" << '\n';    
// bonus
    std::cout << "Daniel" << '\n' << "17" << '\n' << "ola" << '\n' << "jaba" << '\n';
    
    return 0;
}
