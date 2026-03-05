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

class Vehiculo {
    protected:
        std::string marca;
        std::string modelo;
        int ano;
        double precio;
    public:
        virtual double calcularImpuesto() = 0;
        virtual std::string mostrarInfo() = 0;
        virtual double getPrecio() {
            return this->precio;
        }
    Vehiculo(std::string marcaW = "Sin marca", std::string modeloW = "Sin modelo", int anoW = 0, double precioW = 0) : marca(marcaW), modelo(modeloW), ano(anoW), precio(precioW){};
    virtual ~Vehiculo() {
            std::cout << "\nSe destruyo un objeto vehiculo";
        }
};
class Auto : public Vehiculo {
    protected:
        int numeroPuertas;
    public:
        double calcularImpuesto() override {
            return this->precio* 0.15;
        }
        std::string mostrarInfo() override {
            return "\nMarca: " + this->marca
            + "\nModelo: " + this->modelo
            + "\nAno: " + std::to_string(this->ano)
            + "\nPuertas: " + std::to_string(this->numeroPuertas)
            + "\nPrecio:" + std::to_string(this->precio)
            + "\nPrecio con impuestos: " + std::to_string(this->precio + calcularImpuesto());
         }
    Auto(std::string marcaW, std::string modeloW, int anoW, double precioW, int numPuertasW = 0)
        : Vehiculo(marcaW, modeloW, anoW, precioW), numeroPuertas(numPuertasW){};
};
class Moto : public Vehiculo {
    protected:
        int cilindrada;
    public:
        double calcularImpuesto() override {
            return this->precio * 0.10;
        }
        std::string mostrarInfo() override {
            return "\nMarca: " + this->marca
            + "\nModelo: " + this->modelo
            + "\nAno: " + std::to_string(this->ano)
            + "\nCilindros: " + std::to_string(this->cilindrada)
            + "\nPrecio:" + std::to_string(this->precio)
            + "\nPrecio con impuestos: " + std::to_string(this->precio + calcularImpuesto());
         }
    Moto(std::string marcaW, std::string modeloW, int anoW, double precioW, int cilindradaW = 0)
        : Vehiculo(marcaW, modeloW, anoW, precioW), cilindrada(cilindradaW){};
};
class Camion : public Vehiculo {
    protected:
        int capacidadCarga;
        int ejes;
    public:
        double calcularImpuesto() override {
            return this->precio * 0.20;
        }
        std::string mostrarInfo() override {
            return "\nMarca: " + this->marca
            + "\nModelo: " + this->modelo
            + "\nAno: " + std::to_string(this->ano)
            + "\nCapacidad carga: " + std::to_string(this->capacidadCarga)
            + "\nEjes: " + std::to_string(this->ejes)
            + "\nPrecio:" + std::to_string(this->precio)
            + "\nPrecio con impuestos: " + std::to_string(this->precio + calcularImpuesto());
        }
    Camion(std::string marcaW, std::string modeloW, int anoW, double precioW, int capacidadCargaW = 0, int ejesW = 0)
        : Vehiculo(marcaW, modeloW, anoW, precioW), capacidadCarga(capacidadCargaW), ejes(ejesW){};
};
int main() {
    std::vector<Vehiculo*> listaVehiculos;
    listaVehiculos.push_back(new Auto("BMW", "C", 2010, 30000, 4));
    listaVehiculos.push_back(new Moto("Suzuki", "ninja", 1999, 60000, 300));
    listaVehiculos.push_back(new Camion("Trailer", "Continental", 2020, 120000, 1000, 8));
    std::cout << "Consesionaria momichis!!\n----Lista vehiculos----" << std::endl;
    double totalImpuestos = 0.0;
    Vehiculo* vehiculoCaro = nullptr;
    for (Vehiculo* vehiculo : listaVehiculos) {
        vehiculo->calcularImpuesto();
        std::cout << vehiculo->mostrarInfo() << "\n--------";
        totalImpuestos += vehiculo->calcularImpuesto();
        if (vehiculoCaro == nullptr || vehiculoCaro->getPrecio() < vehiculo->getPrecio()) {
            vehiculoCaro = vehiculo;
        }
    }
    std::cout << "\nResumen vehiculos---------\nTotal vehiculos: " << listaVehiculos.size()
    << "\nTotal impuestos: " << totalImpuestos
    << "\nVehiculo mas caro: " << vehiculoCaro->mostrarInfo();
    for (Vehiculo* vehiculo : listaVehiculos) {
        delete vehiculo;
    }
    return 0;
}
