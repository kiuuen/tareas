/*
 * EJERCICIO 12A: Jerarquía de Empleados
 * 
 * ⭐ EJERCICIO FUNDAMENTAL DE POO ⭐
 * 
 * TAREA:
 * Crea una jerarquía de clases para un sistema de empleados:
 * 
 * 1. Clase base Empleado (puede ser abstracta o no):
 *    - Atributos protected: nombre, id, salarioBase
 *    - Constructor que inicialice todos
 *    - Método virtual calcularSalario() → puede ser virtual puro
 *    - Método virtual mostrarInfo()
 *    - Destructor virtual
 * 
 * 2. Clase EmpleadoTiempoCompleto : public Empleado
 *    - Atributo adicional: bono
 *    - calcularSalario() override → salarioBase + bono
 *    - mostrarInfo() override → muestra todos los datos
 * 
 * 3. Clase EmpleadoMedioTiempo : public Empleado
 *    - Atributos adicionales: horasTrabajadas, tarifaPorHora
 *    - calcularSalario() override → horasTrabajadas * tarifaPorHora
 *    - mostrarInfo() override → muestra todos los datos
 * 
 * 4. Clase EmpleadoPorComision : public Empleado
 *    - Atributos adicionales: ventasRealizadas, porcentajeComision
 *    - calcularSalario() override → salarioBase + (ventasRealizadas * porcentajeComision)
 *    - mostrarInfo() override → muestra todos los datos
 * 
 * 5. En el main:
 *    - Crea un vector de punteros a Empleado
 *    - Agrega al menos 1 objeto de cada tipo
 *    - Muestra información de todos (polimorfismo)
 *    - Calcula la nómina total (suma de todos los salarios)
 * 
 * EJEMPLO DE SALIDA:
 * === NÓMINA DE EMPLEADOS ===
 * 
 * Empleado Tiempo Completo
 * ID: 001, Nombre: Ana López
 * Salario base: $5000, Bono: $1000
 * Salario total: $6000
 * 
 * Empleado Medio Tiempo
 * ID: 002, Nombre: Carlos Ruiz
 * Horas: 80, Tarifa: $50/hora
 * Salario total: $4000
 * 
 * ... (otros empleados)
 * 
 * === RESUMEN ===
 * Total de empleados: 5
 * Nómina total: $25000
 */

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

// TODO: Define la clase Empleado (base) aquí

// TODO: Define EmpleadoTiempoCompleto aquí

// TODO: Define EmpleadoMedioTiempo aquí

// TODO: Define EmpleadoPorComision aquí

int main() {
    
    
    
    
    return 0;
}
