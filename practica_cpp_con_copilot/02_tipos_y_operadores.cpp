/*
 * TEMA 2: TIPOS Y VARIABLES
 * 
 * TEORÍA RÁPIDA:
 * 
 * 1. TIPOS PRIMITIVOS:
 *    Java          C++           Diferencia
 *    ----          ---           ----------
 *    boolean       bool          Mismo concepto
 *    int           int           Mismo tamaño típico (4 bytes)
 *    long          long long     En C++ long puede ser 4 u 8 bytes, long long siempre 8
 *    float         float         Igual
 *    double        double        Igual
 *    char          char          En C++ es 1 byte, en Java 2 bytes (Unicode)
 * 
 * 2. INICIALIZACIÓN:
 *    int x = 5;           // Forma clásica
 *    int y(10);           // Constructor
 *    int z{15};           // Lista (recomendado, previene pérdida de datos)
 *    auto w = 20;         // Deducción automática de tipo
 * 
 * 3. CONSTANTES:
 *    Java:  final int MAX = 100;
 *    C++:   const int MAX = 100;
 *    
 *    const significa que NO SE PUEDE MODIFICAR después de inicializar
 * 
 * 4. AUTO (C++11+):
 *    El compilador deduce el tipo automáticamente:
 *    auto x = 5;        // x es int
 *    auto y = 3.14;     // y es double
 *    auto nombre = "Hi"; // nombre es const char* (array de caracteres)
 */

#include <iostream>

int main() {
    // TIPOS BÁSICOS
    int entero = 42;
    double decimal = 3.14159;
    bool activo = true;
    char letra = 'A';
    
    // AUTO - deducción automática
    auto numero = 100;      // int
    auto pi = 3.14;         // double
    
    // CONSTANTES
    const int DIAS_SEMANA = 7;
    // DIAS_SEMANA = 8;     // ERROR: no se puede modificar
    
    // IMPRIMIR
    std::cout << "Entero: " << entero << '\n';
    std::cout << "Decimal: " << decimal << '\n';
    std::cout << "Bool: " << activo << '\n';        // Imprime 1 o 0
    std::cout << "Char: " << letra << '\n';
    
    // OPERADORES (igual que en Java)
    int a = 10, b = 3;
    std::cout << "\nOperaciones:" << '\n';
    std::cout << "a + b = " << (a + b) << '\n';
    std::cout << "a - b = " << (a - b) << '\n';
    std::cout << "a * b = " << (a * b) << '\n';
    std::cout << "a / b = " << (a / b) << '\n';    // División entera: 3
    std::cout << "a % b = " << (a % b) << '\n';    // Módulo: 1
    
    // División con decimales (casting)
    std::cout << "a / (double)b = " << (a / static_cast<double>(b)) << '\n';
    
    return 0;
}

// Siguiente: 02a_ejercicio_calculadora.cpp
