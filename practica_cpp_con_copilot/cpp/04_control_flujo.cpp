/*
 * TEMA 4: CONTROL DE FLUJO (if, switch, for, while)
 * 
 * TEORÍA RÁPIDA:
 * 
 * ¡BUENAS NOTICIAS! La sintaxis es IDÉNTICA a Java:
 * 
 * 1. CONDICIONALES:
 *    if (condición) { }
 *    else if (condición) { }
 *    else { }
 *    
 *    Operador ternario: variable = (condición) ? valor_si_true : valor_si_false;
 * 
 * 2. SWITCH:
 *    switch (variable) {
 *        case valor1:
 *            // código
 *            break;
 *        case valor2:
 *            // código
 *            break;
 *        default:
 *            // código
 *    }
 *    IMPORTANTE: No olvides el break, o caerá al siguiente case
 * 
 * 3. BUCLES:
 *    for (inicialización; condición; incremento) { }
 *    while (condición) { }
 *    do { } while (condición);
 * 
 * 4. BREAK Y CONTINUE:
 *    break: sale del bucle inmediatamente
 *    continue: salta a la siguiente iteración
 * 
 * 5. ÚNICO EXTRA EN C++ (lo veremos después):
 *    Range-based for: for (auto elemento : coleccion) { }
 */

#include <iostream>
#include <string>

int main() {
    // ===== IF / ELSE =====
    std::cout << "=== IF / ELSE ===" << '\n';
    
    int edad = 18;
    
    if (edad >= 18) {
        std::cout << "Eres mayor de edad" << '\n';
    } else {
        std::cout << "Eres menor de edad" << '\n';
    }
    
    // Múltiples condiciones
    int nota = 85;
    
    if (nota >= 90) {
        std::cout << "Calificación: A" << '\n';
    } else if (nota >= 80) {
        std::cout << "Calificación: B" << '\n';
    } else if (nota >= 70) {
        std::cout << "Calificación: C" << '\n';
    } else {
        std::cout << "Calificación: Reprobado" << '\n';
    }
    
    // Operador ternario
    std::string resultado = (nota >= 70) ? "Aprobado" : "Reprobado";
    std::cout << "Resultado: " << resultado << '\n';
    
    // ===== SWITCH =====
    std::cout << "\n=== SWITCH ===" << '\n';
    
    int opcion = 2;
    
    switch (opcion) {
        case 1:
            std::cout << "Opción: Nuevo" << '\n';
            break;
        case 2:
            std::cout << "Opción: Abrir" << '\n';
            break;
        case 3:
            std::cout << "Opción: Guardar" << '\n';
            break;
        default:
            std::cout << "Opción inválida" << '\n';
    }
    
    // Switch con múltiples casos
    char letra = 'a';
    
    switch (letra) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            std::cout << letra << " es una vocal" << '\n';
            break;
        default:
            std::cout << letra << " es una consonante" << '\n';
    }
    
    // ===== FOR LOOP =====
    std::cout << "\n=== FOR LOOP ===" << '\n';
    
    // Básico: del 1 al 5
    std::cout << "Números del 1 al 5: ";
    for (int i = 1; i <= 5; i++) {
        std::cout << i << " ";
    }
    std::cout << '\n';
    
    // Cuenta regresiva
    std::cout << "Cuenta regresiva: ";
    for (int i = 5; i >= 1; i--) {
        std::cout << i << " ";
    }
    std::cout << "¡Despegue!\n";
    
    // De 2 en 2
    std::cout << "Números pares del 0 al 10: ";
    for (int i = 0; i <= 10; i += 2) {
        std::cout << i << " ";
    }
    std::cout << '\n';
    
    // ===== WHILE LOOP =====
    std::cout << "\n=== WHILE LOOP ===" << '\n';
    
    int contador = 0;
    while (contador < 5) {
        std::cout << "Iteración " << contador << '\n';
        contador++;
    }
    
    // ===== DO-WHILE LOOP =====
    std::cout << "\n=== DO-WHILE LOOP ===" << '\n';
    
    int num = 1;
    do {
        std::cout << "Número: " << num << '\n';
        num++;
    } while (num <= 3);
    
    // ===== BREAK Y CONTINUE =====
    std::cout << "\n=== BREAK ===" << '\n';
    std::cout << "Buscar el 5: ";
    for (int i = 1; i <= 10; i++) {
        std::cout << i << " ";
        if (i == 5) {
            std::cout << "¡Encontrado!";
            break;  // Sale del bucle
        }
    }
    std::cout << '\n';
    
    std::cout << "\n=== CONTINUE ===" << '\n';
    std::cout << "Números impares: ";
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) {
            continue;  // Salta a la siguiente iteración
        }
        std::cout << i << " ";
    }
    std::cout << '\n';
    
    // ===== BUCLES ANIDADOS =====
    std::cout << "\n=== BUCLES ANIDADOS ===" << '\n';
    
    // Tabla de multiplicar
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            std::cout << i << "x" << j << "=" << (i*j) << "  ";
        }
        std::cout << '\n';
    }
    
    // Triángulo de asteriscos
    std::cout << "\nTriángulo:" << '\n';
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= i; j++) {
            std::cout << "* ";
        }
        std::cout << '\n';
    }
    
    return 0;
}

// Siguiente: 04a_ejercicio_par_impar.cpp
