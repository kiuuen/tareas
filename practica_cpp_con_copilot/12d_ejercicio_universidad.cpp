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

class Persona {
    protected:
        std::string tipo;
        int id;
        std::string nombre;
        int edad;
    public:
        virtual double calcularPromedio() {
            return 0.0;
        }
        virtual std::string getTipo() {
            return this->tipo;
        }
        virtual std::string mostrarInfo() = 0;
        virtual double getSalario(){
            return 0.0;
        }
    Persona(std::string tipoW = "n/a", int idW = 0, std::string nombreW = "null", int edadW = 20) 
        : tipo(tipoW), id(idW), nombre(nombreW), edad(edadW) {};
    virtual ~Persona() {
        std::cout << "Se destruyo un objeto de la clase Persona" << std::endl;
    }
};

class Estudiante : public Persona {
    protected:
        int matricula;
        std::string carrera;
        std::vector<double> calificaciones;
    public:
        void agregarCalificaciones(double calificacion) {
            calificaciones.push_back(calificacion);
        }
        double calcularPromedio() override {
            double total;
            for (double c : calificaciones) {
                total += c;
            }
            return total/(static_cast<double>(calificaciones.size()));
        }
        std::string mostrarInfo() override {
            std::ostringstream stream;
            stream << std::fixed << std::setprecision(1);
            stream << "\n" << this->tipo
            << "\nNombre: " << this->nombre
            << ", Matricula:" << this->matricula
            << ", Carrera: " << this->carrera
            << ", Id: " << this->id
            << "\nCalificaciones: ";
            for (double c : calificaciones) {
                stream << c << ", ";
            }
            stream << "\nPromedio: " << this->calcularPromedio();      
            return stream.str();
        }
        Estudiante(int idW, std::string nombreW, int edadW, int matriculaW = 0, std::string carreraW = "sincarrera", std::vector<double> calificacionesW = {0})  
            : Persona("[ESTUDIANTE]", idW, nombreW, edadW), matricula(matriculaW), carrera(carreraW), calificaciones(calificacionesW){};
};
class Profesor : public Persona {
    protected:
        double salario;
        std::string departamento;
        std::vector<std::string> materias;
    public:
        double getSalario() override {
            return this->salario;
        }
        void agregarMaterias(std::string materia) {
            materias.push_back(materia);
        }
        std::string mostrarInfo() override {
            std::ostringstream stream;
            stream << std::fixed << std::setprecision(1);
            stream << "\n" << this->tipo
            << "\nNombre: " << this->nombre
            << ", Id: " << this->id
            << ", Departamento: " << this->departamento
            << "\nMaterias: ";
            for (std::string c : materias) {
                stream << c << ", ";
            }
            stream << "\nSalario: " << this->salario;      
            return stream.str();
        }
        Profesor(int idW, std::string nombreW, int edadW, int salarioW = 0, std::string departamentoW = "sindepartamento", std::vector<std::string> materiasW = {"sin materias"})  
            : Persona("[PROFESOR]", idW, nombreW, edadW), salario(salarioW), departamento(departamentoW), materias(materiasW){};
};
class Administrativo : public Persona {
    protected:
        double salario;
        std::string cargo;
        int antiguedad;
    public:
        double getSalario() override {
            return this->salario;
        }
        double calcularBonoAntiguedad() {
            return (salario * 0.05 * antiguedad);
        }
        std::string mostrarInfo() override {
            std::ostringstream stream;
            stream << std::fixed << std::setprecision(1);
            stream << "\n" << this->tipo
            << "\nNombre: " << this->nombre
            << ", Id: " << this->id
            << ", Cargo: " << this->cargo
            << "\nSalario: " << this->salario 
            << "\nAntiguedad: " << this->antiguedad
            << "\nBono por antiguedad: " << this->calcularBonoAntiguedad();
            return stream.str();
        }
        Administrativo(int idW, std::string nombreW, int edadW, int salarioW = 0, std::string cargoW = "sincargo", int antiguedadW = 0)  
            : Persona("[ADMINISTRATIVO]", idW, nombreW, edadW), salario(salarioW), cargo(cargoW), antiguedad(antiguedadW) {};
};

int main() {
    std::vector<Persona*> uniPersonas;
    uniPersonas.push_back(new Estudiante(2352094, "Daniel Alcantar", 18, 1929392, "Ing sistemas", {100, 90, 60, 50, 70, 90, 80}));
    uniPersonas.push_back(new Estudiante(2252334, "Fernanda perra", 18, 1929392, "Ing sistemas", {100, 10, 20, 40, 60, 30, 20}));
    uniPersonas.push_back(new Estudiante(2219204, "Papis", 18, 1929392, "Ing sistemas", {100, 90, 60, 60, 50, 40, 20}));
    uniPersonas.push_back(new Profesor(120092, "Papis perez", 39, 22000, "Industrial", {"Algebra", "Ingles", "Calculo", "Quimica"}));
    uniPersonas.push_back(new Profesor(120092, "Papis nigga", 31, 20000, "Industrial", {"Algebra", "Ingles", "Calculo", "Fisica"}));
    uniPersonas.push_back(new Administrativo(29492, "Camila", 47, 15000, "Secretaria", 20));
    std::cout << "------unison mrd-----" << std::endl;
    std::vector<Persona*> numEstudiantes;
    std::vector<Persona*> numProfesores;
    std::vector<Persona*> numAdmin;
    double nominaTotal;
    double promedioGen;
    for (Persona* m : uniPersonas) {
        std::cout << m->mostrarInfo() << std::endl; // filtro a cada tipo, como pedia el problema, se pudo mandar directamente antes
        if (m->getTipo() == "[ESTUDIANTE]") {numEstudiantes.push_back(m); promedioGen += m->calcularPromedio();}
        if (m->getTipo() == "[PROFESOR]") {numProfesores.push_back(m); nominaTotal += m->getSalario();}
        if (m->getTipo() == "[ADMINISTRATIVO]") {numAdmin.push_back(m); nominaTotal += m->getSalario();}
    }
    std::cout << "-----Resumen------"
    << "\nTotal estudiantes: " << numEstudiantes.size() << ", promedio general: " << promedioGen/(static_cast<double>(numEstudiantes.size()))
    << "\nTotal profesores: " << numProfesores.size()
    << "\nTotal administrativo: " << numAdmin.size()
    << "\nTotal nomina: " << nominaTotal;
    for (Persona* p : uniPersonas) {
        delete p; // por esto mismo no pase referencias
    }
    return 0;
}
