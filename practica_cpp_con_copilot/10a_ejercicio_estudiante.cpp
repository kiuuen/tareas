/*
 * EJERCICIO 10A: Clase Estudiante
 * 
 * TAREA:
 * Crea una clase Estudiante con:
 * - Atributos privados: nombre, matrícula, carrera, y un vector de calificaciones
 * - Constructor que inicialize nombre, matrícula y carrera
 * - Métodos para:
 *   * Agregar una calificación (validar que esté entre 0 y 10)
 *   * Calcular el promedio de calificaciones
 *   * Mostrar información completa del estudiante
 *   * Verificar si está aprobado (promedio >= 6.0)
 * 
 * EJEMPLO DE USO:
 * Estudiante est("Ana García", "A12345", "Ingeniería");
 * est.agregarCalificacion(8.5);
 * est.agregarCalificacion(9.0);
 * est.agregarCalificacion(7.5);
 * est.mostrarInfo();
 * 
 * SALIDA ESPERADA:
 * === Información del Estudiante ===
 * Nombre: Ana García
 * Matrícula: A12345
 * Carrera: Ingeniería
 * Calificaciones: 8.5, 9.0, 7.5
 * Promedio: 8.33
 * Estado: APROBADO
 */
#include <iostream>
#include <vector>
#include <string>
#include <numeric>  // para accumulate
class Estudiante {
    private:
        std::string nombre;
        int matricula;
        std::string carrera;
        std::vector<double> calificaciones;
    public:
        void agregarCalificacion(double calificacionInput) {
            if (calificacionInput > -1 && calificacionInput < 11) {
                this->calificaciones.push_back(calificacionInput);
            }
        }
        double calcularPromedio(const std::vector<double>& calificacionesInput) {
            if (calificacionesInput.empty()) {return 0.0;} 
            double suma = std::accumulate(calificacionesInput.begin(), calificacionesInput.end(), 0.0);
            return suma/calificacionesInput.size();
        }
        std::string verEstado() { // no un getter realmente
            if (calcularPromedio(this->calificaciones) < 6.0) {
                return "REPROBADO";
            } else {
                return "APROBADO";
            }
        }
        void mostrarInfo() { // no ocupo poner el objeto de parametro al ser un metodo que ya tiene él mismo
            std::cout << "---Info estudiante---\nNombre: " << this->nombre << "\nMatricula: " << this->matricula << "\nCarrera: " << this->carrera << "\nCalificaciones: ";
            for(const double& contador : this->calificaciones) {
                std::cout << contador << "\n";
            }
            std::cout << "\nPromedio: " << calcularPromedio(this->calificaciones) << "\nEstado: " << verEstado() << std::endl;
        }
        Estudiante(std::string nombreConstructor = "estudiante", int matriculaConstructor = 0, std::string carreraConstructor = "sincarrera") : nombre(nombreConstructor), matricula(matriculaConstructor), carrera(carreraConstructor) {}
    };
int main() {
    Estudiante est1("Daniel", 225209204, "ISI");
    est1.agregarCalificacion(5);
    est1.agregarCalificacion(10);
    est1.agregarCalificacion(8);
    est1.agregarCalificacion(5.6);
    est1.agregarCalificacion(10);
    est1.mostrarInfo();
    return 0;
}
