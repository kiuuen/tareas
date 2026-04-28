#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <format>

class Empleado {
    protected:
        std::string nombre;
        double salarioBase;
        int id;
        double salarioTotal;
        std::string tipo;
    public:
        virtual ~Empleado() {
            std::cout << "Se ejecutó el destructor de Empleado" << std::endl;
        }
        virtual void calcularSalario() {}
        virtual double getSalario() {
            return salarioTotal;
        }
        virtual std::string mostrarInfo() {
            return std::format("Tipo de empleado: {}\nSalario: {}\nID: {}\nNombre: {}\nSalario total: {}",
                               this->tipo, this->salarioBase, this->id, this->nombre, this->salarioTotal);
        }
        Empleado(std::string tipoW = "notipo", double salarioW = 0, std::string nombreW = "Vacio", int idW = 0, double salarioTotalW = 0)
            : nombre(nombreW), salarioBase(salarioW), id(idW), salarioTotal(salarioTotalW), tipo(tipoW){};
};

class EmpleadoTiempoCompleto : public Empleado {
    protected:
        double bono;
    public:
        void calcularSalario() override {
            this->salarioTotal = this->salarioBase + this->bono;
        }
        std::string mostrarInfo() override {
            return std::format("Tipo de empleado: {}\nSalario: {}, Bono: {}\nID: {}\nNombre: {}\nSalario total: {}",
                               this->tipo, this->salarioBase, this->bono, this->id, this->nombre, this->salarioTotal);
        }
        EmpleadoTiempoCompleto(std::string nombreW, int idW, double salarioBaseW, double bonoW)
            : Empleado("Tiempo Completo", salarioBaseW, nombreW, idW), bono(bonoW) {}
};

class EmpleadoMedioTiempo : public Empleado {
    protected:
        double tarifa;
        double horas;
    public:
        void calcularSalario() override {
            this->salarioTotal = this->tarifa * this->horas;
        }
        std::string mostrarInfo() override {
            return std::format("Tipo de empleado: {}\nTarifa: {}, Horas: {}\nID: {}\nNombre: {}\nSalario total: {}",
                               this->tipo, this->tarifa, this->horas, this->id, this->nombre, this->salarioTotal);
        }
        EmpleadoMedioTiempo(std::string nombreW, int idW, double tarifaW, double horasW)
            : Empleado("Medio tiempo", 0, nombreW, idW), tarifa(tarifaW), horas(horasW) {}
};

class EmpleadoComision : public Empleado {
    protected:
        double ventasRealizadas;
        double porcentajeComision;
    public:
        void calcularSalario() override {
            this->salarioTotal = this->ventasRealizadas * this->porcentajeComision;
        }
        std::string mostrarInfo() override {
            return std::format("Tipo de empleado: {}\nVentas: {}, Porcentaje de comision: {}\nID: {}\nNombre: {}\nSalario total: {}",
                               this->tipo, this->ventasRealizadas, this->porcentajeComision, this->id, this->nombre, this->salarioTotal);
        }
        EmpleadoComision(std::string nombreW, int idW, double ventasW, double comisionW)
            : Empleado("Por comision", 0, nombreW, idW), ventasRealizadas(ventasW), porcentajeComision(comisionW) {}
};

int main() {
    std::vector<Empleado*> listaEmpleados;
    listaEmpleados.push_back(new EmpleadoTiempoCompleto("Daniel", 1, 3000, 1000));
    listaEmpleados.push_back(new EmpleadoMedioTiempo("Jorge", 2, 100, 20));
    listaEmpleados.push_back(new EmpleadoComision("Papis", 3, 20, 0.3));

    std::cout << "------Info de empleados------" << std::endl;
    double totalNomina = 0; // Inicializar totalNomina
    for (Empleado* empleado : listaEmpleados) {
        empleado->calcularSalario();
        totalNomina += empleado->getSalario();
        std::cout << empleado->mostrarInfo() << "\n-----------"<< std::endl;
    }

    std::cout << "Total empleados: " << listaEmpleados.size() << "\nTotal nomina: " << totalNomina << std::endl;

    for (Empleado* empleado : listaEmpleados) {
        delete empleado; // llama al destructor y libera memoria
    }

    return 0;
}