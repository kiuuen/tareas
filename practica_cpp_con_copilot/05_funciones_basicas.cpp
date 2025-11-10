/*
 * TEMA 5: FUNCIONES
 * 
 * TEORÍA COMPLETA:
 * 
 * 1. DIFERENCIA FUNDAMENTAL CON JAVA:
 *    En Java: todo debe estar dentro de una clase
 *    En C++: puedes tener funciones "sueltas" (funciones libres)
 * 
 * 2. SINTAXIS BÁSICA:
 *    tipo_retorno nombre_funcion(tipo param1, tipo param2) {
 *        // código
 *        return valor;
 *    }
 * 
 * 3. PROTOTIPOS (DECLARACIONES):
 *    Puedes declarar la función antes de main() y definirla después:
 *    
 *    int suma(int a, int b);  // Prototipo
 *    
 *    int main() {
 *        int x = suma(5, 3);
 *    }
 *    
 *    int suma(int a, int b) {  // Definición
 *        return a + b;
 *    }
 * 
 * 4. SOBRECARGA DE FUNCIONES:
 *    C++ permite tener múltiples funciones con el MISMO NOMBRE
 *    pero DIFERENTES PARÁMETROS:
 *    
 *    int suma(int a, int b);
 *    double suma(double a, double b);
 *    int suma(int a, int b, int c);
 *    
 *    El compilador elige la correcta según los argumentos
 * 
 * 5. PASO POR VALOR (por defecto):
 *    void funcion(int x) { x = 10; }
 *    
 *    int num = 5;
 *    funcion(num);
 *    // num sigue siendo 5 (se pasó una COPIA)
 * 
 * 6. PASO POR REFERENCIA (con &):
 *    ¡ESTO NO EXISTE IGUAL EN JAVA!
 *    
 *    void funcion(int& x) { x = 10; }
 *    
 *    int num = 5;
 *    funcion(num);
 *    // num ahora es 10 (se modificó el ORIGINAL)
 *    
 *    El símbolo & significa "referencia al original"
 * 
 * 7. ¿CUÁNDO USAR REFERENCIA?
 *    - Para modificar el argumento original (ej: swap)
 *    - Para evitar copias costosas (ej: objetos grandes)
 *    - Usa const& si no quieres modificar: void f(const std::string& s)
 */

#include <iostream>
#include <string>

// ===== PROTOTIPOS =====
int suma(int a, int b);
double suma(double a, double b);        // Sobrecarga
int suma(int a, int b, int c);          // Sobrecarga
void saludar(std::string nombre);
int factorial(int n);
void duplicar(int& numero);             // Paso por referencia
void intercambiar(int& a, int& b);      // Swap

int main() {
    std::cout << "=== FUNCIONES BÁSICAS ===" << '\n';
    
    int r1 = suma(5, 3);
    std::cout << "suma(5, 3) = " << r1 << '\n';
    
    double r2 = suma(5.5, 3.2);         // Llama a la versión double
    std::cout << "suma(5.5, 3.2) = " << r2 << '\n';
    
    int r3 = suma(1, 2, 3);             // Llama a la versión de 3 parámetros
    std::cout << "suma(1, 2, 3) = " << r3 << '\n';
    
    std::cout << "\n=== FUNCIONES VOID ===" << '\n';
    saludar("Ana");
    
    std::cout << "\n=== RECURSIÓN ===" << '\n';
    std::cout << "factorial(5) = " << factorial(5) << '\n';
    
    std::cout << "\n=== PASO POR REFERENCIA ===" << '\n';
    
    int num = 10;
    std::cout << "Antes de duplicar: " << num << '\n';
    duplicar(num);  // Modifica num directamente
    std::cout << "Después de duplicar: " << num << '\n';
    
    int x = 5, y = 20;
    std::cout << "\nAntes de intercambiar: x=" << x << ", y=" << y << '\n';
    intercambiar(x, y);
    std::cout << "Después de intercambiar: x=" << x << ", y=" << y << '\n';
    
    return 0;
}

// ===== DEFINICIONES =====

int suma(int a, int b) {
    return a + b;
}

double suma(double a, double b) {
    return a + b;
}

int suma(int a, int b, int c) {
    return a + b + c;
}

void saludar(std::string nombre) {
    std::cout << "¡Hola, " << nombre << "!" << '\n';
}

int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

// Duplica el número (modifica el original)
void duplicar(int& numero) {
    numero *= 2;
}

// Intercambia dos valores (modifica ambos originales)
void intercambiar(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

/*
 * EXPLICACIÓN DETALLADA: PASO POR VALOR VS REFERENCIA
 * 
 * PASO POR VALOR (sin &):
 * ----------------------
 * void incrementar(int x) {
 *     x++;  // Modifica la COPIA
 * }
 * 
 * int n = 5;
 * incrementar(n);
 * // n sigue siendo 5
 * 
 * PASO POR REFERENCIA (con &):
 * ----------------------------
 * void incrementar(int& x) {
 *     x++;  // Modifica el ORIGINAL
 * }
 * 
 * int n = 5;
 * incrementar(n);
 * // n ahora es 6
 * 
 * COMPARACIÓN CON JAVA:
 * --------------------
 * En Java, los primitivos (int, double, etc.) SIEMPRE se pasan por valor.
 * Los objetos se pasan por "referencia de valor" (la referencia se copia).
 * 
 * En C++, tú decides explícitamente con el símbolo &.
 */

// Siguiente: 05a_ejercicio_funciones_matematicas.cpp
