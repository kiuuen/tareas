/*
 * EJERCICIO 3B: Perfil de usuario
 * 
 * TAREA:
 * - Pide al usuario:
 *   * Edad (int)
 *   * Nombre completo (string con espacios)
 *   * Ciudad (string con espacios)
 * - Imprime un resumen
 * 
 * IMPORTANTE: Usa cin.ignore() después de leer la edad
 * 
 * EJEMPLO:
 * Introduce tu edad: 20
 * Introduce tu nombre completo: Juan Pérez
 * Introduce tu ciudad: Ciudad de México
 * 
 * === PERFIL ===
 * Nombre: Juan Pérez
 * Edad: 20 años
 * Ciudad: Ciudad de México
 */

#include <iostream>
#include <string> // para usar el std::string

int main() {
    std::cout << "Introduce tu edad" << '\n';
    int edad;
    std::cin >> edad;
    std::cout << "Introduce tu nombre completo" << '\n';
    std::string nombre;
    std::cin.ignore();
    std::getline(std::cin, nombre);
    std::cout << "Introduce tu ciudad" << '\n';
    std::string ciudad;
    std::getline(std::cin, ciudad);
    // aqui no ocupo pq es la ultima
    std::cout << "Tu nombre es = " << nombre << '\n';
    std::cout << "Tu edad es = " << edad << '\n';
    std::cout << "Tu ciudad es = " << ciudad << '\n';
    return 0;
}
