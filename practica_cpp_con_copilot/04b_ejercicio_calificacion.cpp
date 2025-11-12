/*
 * EJERCICIO 4B: Calificación con letras
 * 
 * TAREA:
 * - Pide una calificación numérica (0-100)
 * - Convierte a letra según:
 *   * 90-100: A
 *   * 80-89:  B
 *   * 70-79:  C
 *   * 60-69:  D
 *   * 0-59:   F
 * - Usa if/else if
 * 
 * EJEMPLO:
 * Introduce tu calificación: 85
 * Tu calificación es: B
 */

#include <iostream>

int main() {
    std::cout << "Introduce tu calificacion";
    int calificacion;
    std::cin >> calificacion;
    if (calificacion > -1) {
        if (calificacion >= 90 && calificacion <= 100) {
            std::cout << "Tu calificacion es: A";
        }
        if (calificacion >= 80 && calificacion <= 89) {
            std::cout << "Tu calificacion es: B";
        }    
        if (calificacion >= 70 && calificacion <= 79) {
            std::cout << "Tu calificacion es: C";
        }    
        if (calificacion >= 60 && calificacion <= 69) {
            std::cout << "Tu calificacion es: D";
        }
        if (calificacion >= 0 && calificacion <= 59) {
            std::cout << "Tu calificacion es: F";
        }
    } else {
        std::cout << "calificacion imposible";
    }
    return 0;
}
