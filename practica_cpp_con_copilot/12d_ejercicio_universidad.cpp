/*
 * EJERCICIO 12D: Sistema de Universidad (POO Completo)
 * 
 * ⭐ EJERCICIO INTEGRADOR - DESAFIANTE ⭐
 * 
 * TAREA:
 * Crea un sistema universitario con herencia múltiple de conceptos:
 * 
 * 1. Clase base Persona:
 *    - Atributos protected: nombre, id, edad
 *    - Constructor
 *    - Método virtual mostrarInfo()
 *    - Destructor virtual
 * 
 * 2. Clase Estudiante : public Persona
 *    - Atributos adicionales: matricula, carrera, vector<double> calificaciones
 *    - Constructor
 *    - Métodos:
 *      * agregarCalificacion(double calif)
 *      * calcularPromedio() const
 *      * mostrarInfo() override
 * 
 * 3. Clase Profesor : public Persona
 *    - Atributos adicionales: departamento, salario, vector<string> materias
 *    - Constructor
 *    - Métodos:
 *      * agregarMateria(string materia)
 *      * mostrarInfo() override
 * 
 * 4. Clase Administrativo : public Persona
 *    - Atributos adicionales: cargo, salario, antiguedad (años)
 *    - Constructor
 *    - Métodos:
 *      * calcularBonoAntiguedad() → salario * 0.05 * antiguedad
 *      * mostrarInfo() override
 * 
 * 5. En el main:
 *    - Crea un vector de Persona* (punteros a la clase base)
 *    - Agrega al menos:
 *      * 3 estudiantes con calificaciones
 *      * 2 profesores con materias
 *      * 1 administrativo
 *    - Muestra información de todos usando polimorfismo
 *    - Calcula:
 *      * Promedio general de todos los estudiantes
 *      * Nómina total (profesores + administrativos)
 *      * Cantidad de cada tipo
 * 
 * RETO ADICIONAL:
 * - Implementa un método virtual puro getTipo() que retorne el tipo de persona
 * - Filtra solo estudiantes o solo profesores del vector
 * 
 * EJEMPLO DE SALIDA:
 * === SISTEMA UNIVERSITARIO ===
 * 
 * [ESTUDIANTE]
 * ID: E001, Nombre: Ana López, Edad: 20
 * Matrícula: 2024001, Carrera: Ingeniería
 * Calificaciones: 8.5, 9.0, 8.8
 * Promedio: 8.77
 * 
 * [PROFESOR]
 * ID: P001, Nombre: Dr. Carlos Ruiz, Edad: 45
 * Departamento: Computación, Salario: $15000
 * Materias: POO, Algoritmos, Estructuras de Datos
 * 
 * [ADMINISTRATIVO]
 * ID: A001, Nombre: María Sánchez, Edad: 35
 * Cargo: Secretaria, Salario: $8000
 * Antigüedad: 5 años
 * Bono por antigüedad: $2000
 * 
 * === ESTADÍSTICAS ===
 * Total de personas: 6
 * Estudiantes: 3 (Promedio general: 8.45)
 * Profesores: 2
 * Administrativos: 1
 * Nómina total: $45000
 */

#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <iomanip>

// TODO: Define la clase Persona (base) aquí

// TODO: Define Estudiante aquí

// TODO: Define Profesor aquí

// TODO: Define Administrativo aquí

int main() {
    
    
    
    
    return 0;
}

/*
 * CONCEPTOS QUE ESTE EJERCICIO REFUERZA:
 * 
 * ✓ Herencia simple
 * ✓ Polimorfismo con punteros a clase base
 * ✓ Métodos virtuales override
 * ✓ Destructores virtuales
 * ✓ Vector de punteros polimórficos
 * ✓ Uso de const en métodos
 * ✓ Composición (vector dentro de clase)
 * ✓ Cálculos agregados sobre colecciones
 * 
 * Este ejercicio es típico de:
 * - Exámenes parciales/finales de POO
 * - Proyectos de curso
 * - Entrevistas técnicas
 * 
 * ¡Tómate tu tiempo para hacerlo bien!
 */
