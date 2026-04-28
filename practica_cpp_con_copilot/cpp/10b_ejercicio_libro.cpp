/*
 * EJERCICIO 10B: Clase Libro
 * 
 * TAREA:
 * Crea una clase Libro para una biblioteca con:
 * - Atributos: título, autor, ISBN, año de publicación, disponible (bool)
 * - Constructor que inicialice todos los datos (disponible por defecto en true)
 * - Métodos para:
 *   * Prestar el libro (cambiar disponible a false, retorna bool si tuvo éxito)
 *   * Devolver el libro (cambiar disponible a true)
 *   * Mostrar información del libro
 *   * Calcular antigüedad (años desde publicación hasta 2026)
 *   * Verificar si es un clásico (más de 50 años)
 * 
 * EJEMPLO DE USO:
 * Libro libro("1984", "George Orwell", "978-0451524935", 1949);
 * libro.mostrarInfo();
 * libro.prestar();
 * libro.devolver();
 */
#include <format>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
class Persona {
    private:
        std::string nombre;
        int edad;
        std::vector<Libro> librosPertenencia;
    public:
        void devolverLibro(Libro& libroPrestado) {
            auto it = std::find(librosPertenencia.begin(), librosPertenencia.end(), libroPrestado); // si es true, si lo tiene
            if (it != librosPertenencia.end()) {
                librosPertenencia.erase(it);
                std::cout << "AVISO, se ha devuelto el libro: " << libroPrestado.getNombre() << " que lo tenia: " << this->nombre << std::endl;
            }
        }
        void agregarLibro(const Libro& libroPrestado) { // ocupo acceder desde la clase persona pq es privado y no puedo acceder directamente desde libro
            librosPertenencia.push_back(libroPrestado);
        }
        std::string getNombre() {
            return this->nombre;
        }
        Persona(std::string nombreW = "default",  int edadW = 18) : nombre(nombreW), edad(edadW){};
};
class Libro {
    private:
        std::string titulo;
        std::string autor;
        int añoPublicacion;
        std::string ISBN;
        bool disponible;
        std::string duenoActual;
        int antiguedad;
        bool esClasico;
    public:
        void prestarLibro(Libro libroPrestar, Persona& personaPrestar) {
            if (this->disponible) {// si es true 
                personaPrestar.agregarLibro(*this); // le mando el libro real, no una copia
                this->disponible = false;
                this->duenoActual = personaPrestar.getNombre();
            } 
        }
        std::string mostrarInfo() const {
            return std::format("---Info libro---\n"
            "Titulo: {}\n"
            "Autor: {}\n"
            "Año: {}\n"
            "Disponible: {}"
            "ISBN: {}"
            "Antiguedad: {}"
            "Es clasico: {}",
            this->titulo, this->autor, this-> añoPublicacion, this->disponible ? "si" : "no", this->ISBN, this->antiguedad, this->esClasico ? "si" : "no");
        }
        void setDueño(Persona& dueno) {
            this->duenoActual = dueno.getNombre();
        }
        void calcularAntiguedad() {
            this->antiguedad = 2026-añoPublicacion;
            if (antiguedad > 49) {
                esClasico = true;
            }
        }
        std::string getNombre() {
            return this->titulo;
        }
        Libro(std::string tituloW = "blank", std::string autorW = "smith", int añoW = 0, std::string ISBNW = "0000", bool disponibleW = true, std::string duenoW = "biblioteca") : titulo(tituloW), autor(autorW), añoPublicacion(añoW), ISBN(ISBNW), disponible(disponibleW), duenoActual(duenoW){}; 
};
int main() {
    Libro lib1("Memorias del subsuelo", "Fyodor Dostoievsky", 1864, "0102isajs");
    std::cout << lib1.mostrarInfo() << std::endl;
    Persona per1("Daniel", 18);
    lib1.prestarLibro(lib1, per1);
    std::cout << lib1.mostrarInfo() << std::endl;
    // que diga que el dueño ahora es "Daniel" por ejemplo
    per1.devolverLibro(lib1);
    return 0;
}
