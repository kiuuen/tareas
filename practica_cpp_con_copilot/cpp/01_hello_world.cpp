/*
 * TEMA 1: HELLO WORLD - Tu primer programa en C++
 * 
 * TEORÍA RÁPIDA:
 * 
 * 1. ESTRUCTURA BÁSICA:
 *    - No necesitas clases como en Java (puedes tener funciones sueltas)
 *    - Todo programa C++ debe tener una función main()
 *    - main() retorna int (0 = éxito, otro valor = error)
 * 
 * 2. INCLUDES:
 *    - #include <iostream> da acceso a entrada/salida
 *    - Es como "import" en Java, pero se procesa antes de compilar
 * 
 * 3. SALIDA DE DATOS:
 *    Java:   System.out.println("texto");
 *    C++:    std::cout << "texto" << '\n';
 *    
 *    - std::cout = flujo de salida estándar
 *    - << = operador de inserción (piensa en "enviar datos")
 *    - '\n' = salto de línea (más rápido que std::endl)
 *    - std::endl = salto + flush del buffer (más lento)
 * 
 * 4. COMPILAR Y EJECUTAR:
 *    g++ -std=c++17 -Wall 01_hello_world.cpp -o 01_hello_world.exe
 *    01_hello_world.exe
 *    
 *    -std=c++17  = usar estándar C++17
 *    -Wall       = mostrar todas las advertencias
 *    -o nombre   = nombre del ejecutable
 */

#include <iostream>

int main() {
    std::cout << "¡Hola, C++!" << '\n';
    return 0;
}

// Siguiente archivo: 01a_ejercicio_salida.cpp
