/*
 * EJERCICIO 12B: Sistema de Vehículos (Herencia Clásica)
 * 
 * ⭐ EJERCICIO POPULAR EN EXÁMENES ⭐
 * 
 * TAREA:
 * Crea una jerarquía de vehículos:
 * 
 * 1. Clase abstracta Vehiculo:
 *    - Atributos protected: marca, modelo, año, precio
 *    - Constructor
 *    - Método virtual puro: calcularImpuesto() = 0
 *    - Método virtual puro: mostrarInfo() = 0
 *    - Método normal: getters para cada atributo
 *    - Destructor virtual
 * 
 * 2. Clase Auto : public Vehiculo
 *    - Atributo adicional: numeroPuertas
 *    - calcularImpuesto() → precio * 0.15 (15% de impuesto)
 *    - mostrarInfo() → muestra todos los datos incluyendo impuesto
 * 
 * 3. Clase Moto : public Vehiculo
 *    - Atributo adicional: cilindrada (ejemplo: 250, 500, 1000 cc)
 *    - calcularImpuesto() → precio * 0.10 (10% de impuesto)
 *    - mostrarInfo() → muestra todos los datos incluyendo impuesto
 * 
 * 4. Clase Camion : public Vehiculo
 *    - Atributos adicionales: capacidadCarga (en kg), numEjes
 *    - calcularImpuesto() → precio * 0.20 (20% de impuesto)
 *    - mostrarInfo() → muestra todos los datos incluyendo impuesto
 * 
 * 5. En el main:
 *    - Crea un vector de Vehiculo* (punteros)
 *    - Agrega varios vehículos de cada tipo
 *    - Muestra información de todos usando polimorfismo
 *    - Calcula el total de impuestos a pagar
 *    - Encuentra el vehículo más caro
 * 
 * EJEMPLO DE SALIDA:
 * === CONCESIONARIA C++ ===
 * 
 * AUTO
 * Marca: Toyota, Modelo: Corolla, Año: 2023
 * Precio: $25000, Puertas: 4
 * Impuesto: $3750
 * 
 * MOTO
 * Marca: Yamaha, Modelo: R1, Año: 2024
 * Precio: $15000, Cilindrada: 1000 cc
 * Impuesto: $1500
 * 
 * ... (otros vehículos)
 * 
 * === RESUMEN ===
 * Total vehículos: 6
 * Impuestos totales: $12000
 * Vehículo más caro: Camión Volvo FH16
 */

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

// TODO: Define la clase abstracta Vehiculo aquí

// TODO: Define Auto aquí

// TODO: Define Moto aquí

// TODO: Define Camion aquí

int main() {
    
    
    
    
    return 0;
}
