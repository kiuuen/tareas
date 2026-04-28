/*
 * TEMA 3: ENTRADA Y SALIDA
 * 
 * TEORÍA RÁPIDA:
 * 
 * 1. ENTRADA DE DATOS:
 *    Java (Scanner):              C++:
 *    int x = sc.nextInt();        int x; std::cin >> x;
 *    String s = sc.next();        std::string s; std::cin >> s;
 *    String linea = sc.nextLine(); std::string linea; std::getline(std::cin, linea);
 * 
 * 2. std::cin >> variable:
 *    - Lee hasta encontrar espacio, tab o enter
 *    - NO lee espacios dentro de la entrada
 *    - Equivale a Scanner.next() o nextInt()
 * 
 * 3. std::getline(std::cin, string):
 *    - Lee una línea COMPLETA (incluye espacios)
 *    - Equivale a Scanner.nextLine()
 * 
 * 4. PROBLEMA COMÚN - BUFFER RESIDUAL:
 *    Cuando usas >> y luego getline(), queda un '\n' en el buffer
 *    Solución: std::cin.ignore(); después de >>
 * 
 *    Ejemplo:
 *    std::cin >> edad;           // Usuario escribe "25" y Enter
 *    std::cin.ignore();          // Ignora el '\n' que quedó
 *    std::getline(std::cin, nombre); // Ahora funciona correctamente
 * 
 * 5. NECESITAS #include <string> PARA std::string
 */

#include <iostream>
#include <string>

int main() {
    // LECTURA BÁSICA CON >>
    std::cout << "Introduce tu edad: ";
    int edad;
    std::cin >> edad;
    
    std::cout << "Tienes " << edad << " años\n";
    
    // LIMPIAR BUFFER antes de usar getline
    std::cin.ignore();
    
    // LECTURA DE LÍNEA COMPLETA
    std::cout << "Introduce tu nombre completo: ";
    std::string nombre;
    std::getline(std::cin, nombre);
    
    std::cout << "Hola, " << nombre << "!\n";
    
    // MÚLTIPLES VALORES
    std::cout << "Introduce peso (kg) y altura (m): ";
    double peso, altura;
    std::cin >> peso >> altura;
    
    double imc = peso / (altura * altura);
    std::cout << "Tu IMC es: " << imc << '\n';
    
    return 0;
}

// Siguiente: 03a_ejercicio_calculadora_input.cpp
