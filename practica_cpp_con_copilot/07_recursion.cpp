/*
 * TEMA 7: RECURSIÓN
 * 
 * TEORÍA COMPLETA:
 * 
 * 1. ¿QUÉ ES RECURSIÓN?
 *    Una función que se llama a sí misma para resolver un problema
 *    dividiéndolo en subproblemas más pequeños
 * 
 * 2. COMPONENTES ESENCIALES:
 *    a) CASO BASE: condición que detiene la recursión
 *    b) CASO RECURSIVO: la función se llama a sí misma con un problema más pequeño
 *    
 *    Si olvidas el caso base → ¡RECURSIÓN INFINITA! (Stack Overflow)
 * 
 * 3. EJEMPLO CLÁSICO: FACTORIAL
 *    
 *    Matemáticamente: n! = n × (n-1)!
 *    
 *    int factorial(int n) {
 *        if (n <= 1) return 1;        // Caso base
 *        return n * factorial(n - 1); // Caso recursivo
 *    }
 *    
 *    Ejecución de factorial(5):
 *    factorial(5) = 5 × factorial(4)
 *                 = 5 × 4 × factorial(3)
 *                 = 5 × 4 × 3 × factorial(2)
 *                 = 5 × 4 × 3 × 2 × factorial(1)
 *                 = 5 × 4 × 3 × 2 × 1
 *                 = 120
 * 
 * 4. COMPARACIÓN: RECURSIVO VS ITERATIVO
 *    
 *    RECURSIVO:
 *    int factorial(int n) {
 *        if (n <= 1) return 1;
 *        return n * factorial(n - 1);
 *    }
 *    
 *    ITERATIVO:
 *    int factorial(int n) {
 *        int resultado = 1;
 *        for (int i = 1; i <= n; i++) {
 *            resultado *= i;
 *        }
 *        return resultado;
 *    }
 * 
 * 5. ¿CUÁNDO USAR RECURSIÓN?
 *    ✓ Problemas naturalmente recursivos (árboles, fractales)
 *    ✓ Código más elegante y fácil de entender
 *    ✗ Puede ser más lenta (overhead de llamadas)
 *    ✗ Puede causar stack overflow con profundidad grande
 * 
 * 6. ERRORES COMUNES:
 *    - Olvidar el caso base
 *    - Caso base incorrecto
 *    - No avanzar hacia el caso base
 *    - Usar variables globales (¡evítalo!)
 * 
 * 7. TU EJERCICIO DE JAVA (nov_11_3.java):
 *    Tenías un contador de vocales recursivo, pero usaba
 *    una variable global (totalVocales). En C++ es mejor
 *    que la función RETORNE el contador:
 *    
 *    int contarVocales(const std::string& s, size_t idx = 0) {
 *        if (idx >= s.length()) return 0;
 *        bool esVocal = (tolower(s[idx]) es a/e/i/o/u);
 *        return (esVocal ? 1 : 0) + contarVocales(s, idx + 1);
 *    }
 */

#include <iostream>
#include <string>

// ===== FACTORIAL RECURSIVO =====
int factorial(int n) {
    // Caso base
    if (n <= 1) {
        return 1;
    }
    // Caso recursivo
    return n * factorial(n - 1);
}

// ===== FIBONACCI RECURSIVO =====
// Fibonacci: 0, 1, 1, 2, 3, 5, 8, 13, 21, ...
// fib(n) = fib(n-1) + fib(n-2)
int fibonacci(int n) {
    // Casos base
    if (n == 0) return 0;
    if (n == 1) return 1;
    // Caso recursivo
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// ===== SUMA DE DÍGITOS =====
// Ejemplo: sumaDigitos(12345) = 1+2+3+4+5 = 15
int sumaDigitos(int n) {
    // Caso base
    if (n == 0) return 0;
    // Caso recursivo: último dígito + suma del resto
    return (n % 10) + sumaDigitos(n / 10);
}

// ===== POTENCIA RECURSIVA =====
// potencia(2, 3) = 2 × 2 × 2 = 8
int potencia(int base, int exponente) {
    // Caso base
    if (exponente == 0) return 1;
    // Caso recursivo
    return base * potencia(base, exponente - 1);
}

// ===== CONTAR VOCALES (VERSIÓN MEJORADA DE TU EJERCICIO) =====
int contarVocales(const std::string& s, size_t idx = 0) {
    // Caso base: llegamos al final
    if (idx >= s.length()) {
        return 0;
    }
    
    // Verificar si el carácter actual es vocal
    char c = std::tolower(s[idx]);
    bool esVocal = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    
    // Caso recursivo: vocal actual + contar en el resto
    return (esVocal ? 1 : 0) + contarVocales(s, idx + 1);
}

// ===== INVERTIR STRING =====
std::string invertir(const std::string& s) {
    // Caso base: string vacío o de 1 carácter
    if (s.length() <= 1) {
        return s;
    }
    // Caso recursivo: último carácter + invertir el resto
    return s[s.length() - 1] + invertir(s.substr(0, s.length() - 1));
}

int main() {
    std::cout << "=== FACTORIAL ===" << '\n';
    std::cout << "5! = " << factorial(5) << '\n';
    std::cout << "7! = " << factorial(7) << '\n';
    
    std::cout << "\n=== FIBONACCI ===" << '\n';
    std::cout << "Primeros 10 números de Fibonacci:" << '\n';
    for (int i = 0; i < 10; i++) {
        std::cout << fibonacci(i) << " ";
    }
    std::cout << '\n';
    
    std::cout << "\n=== SUMA DE DÍGITOS ===" << '\n';
    std::cout << "sumaDigitos(12345) = " << sumaDigitos(12345) << '\n';
    std::cout << "sumaDigitos(999) = " << sumaDigitos(999) << '\n';
    
    std::cout << "\n=== POTENCIA ===" << '\n';
    std::cout << "2^5 = " << potencia(2, 5) << '\n';
    std::cout << "3^4 = " << potencia(3, 4) << '\n';
    
    std::cout << "\n=== CONTAR VOCALES ===" << '\n';
    std::string texto = "Hola Mundo";
    std::cout << "Vocales en '" << texto << "': " << contarVocales(texto) << '\n';
    
    std::cout << "\n=== INVERTIR STRING ===" << '\n';
    std::cout << "invertir('Hola') = '" << invertir("Hola") << "'" << '\n';
    
    return 0;
}

/*
 * COMPARACIÓN CON TU CÓDIGO JAVA (nov_11_3.java):
 * 
 * TU VERSIÓN JAVA (con problemas):
 * ----------------------------------
 * static int totalVocales = 0;  // Variable global ← PROBLEMA
 * 
 * public static void numeroVocales(String cadena) {
 *     if (cadena.equals("")) {
 *         System.out.println("La cadena tiene: " + totalVocales + " vocales");
 *         return;
 *     }
 *     if (cadena.startsWith("a") || ...) {
 *         totalVocales++;  // Modifica global
 *         numeroVocales(cadena.substring(1));
 *     } else {
 *         numeroVocales(cadena.substring(1));
 *     }
 * }
 * 
 * PROBLEMAS:
 * 1. Usa variable global (no reutilizable, no thread-safe)
 * 2. No retorna valor, solo imprime
 * 3. Convierte a minúsculas DESPUÉS de llamar la función
 * 
 * VERSIÓN C++ MEJORADA (arriba):
 * -------------------------------
 * int contarVocales(const std::string& s, size_t idx = 0) {
 *     if (idx >= s.length()) return 0;
 *     char c = std::tolower(s[idx]);
 *     bool esVocal = (c == 'a' || ...);
 *     return (esVocal ? 1 : 0) + contarVocales(s, idx + 1);
 * }
 * 
 * MEJORAS:
 * 1. Sin variables globales
 * 2. Retorna el resultado (más flexible)
 * 3. Convierte a minúsculas en el lugar correcto
 * 4. Usa índice en lugar de substring (más eficiente)
 */

// Siguiente: 07a_ejercicio_fibonacci.cpp
