/*
 * EJERCICIO 13A: Guardar y cargar calificaciones
 * 
 * TAREA:
 * 1. Crea un programa que solicite calificaciones al usuario
 * 2. Guarda las calificaciones en un archivo "calificaciones.txt"
 *    - Una calificación por línea
 * 3. Luego lee el archivo y calcula:
 *    - Promedio
 *    - Calificación más alta
 *    - Calificación más baja
 *    - Cantidad de calificaciones
 * 
 * FORMATO DEL ARCHIVO:
 * 8.5
 * 9.0
 * 7.5
 * 8.8
 * 
 * EJEMPLO DE EJECUCIÓN:
 * ¿Cuántas calificaciones? 4
 * Calificación 1: 8.5
 * Calificación 2: 9.0
 * Calificación 3: 7.5
 * Calificación 4: 8.8
 * ✓ Calificaciones guardadas en 'calificaciones.txt'
 * 
 * Leyendo calificaciones...
 * Promedio: 8.45
 * Más alta: 9.0
 * Más baja: 7.5
 * Total: 4 calificaciones
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdio>   
#include <thread>
#include <chrono>
int main() {
    std::string linea;
    const char* nombreArchivo = "calificaciones.txt";
    double valor = 0.0;
    double total = 0.0;
    double masAlta = 0.0;
    double masBaja = 0.0;
    int numMaterias = 0;
    double calificacion = 0.0; 
    std::vector<double> calificaciones;
    std::cout << "Introduce el numero de materias: " << std::endl;
    std::cin >> numMaterias;
    for (int n = 1; n <= numMaterias; n++) {
        std::cout << n << ") Introduce la calificacion; " << std::endl;
        std::cin >> calificacion;
        calificaciones.push_back(calificacion);
    }
    std::ofstream archivoEscritura("calificaciones.txt");
    if (archivoEscritura.is_open()) {
        for (double d : calificaciones)
        archivoEscritura << d << "\n";
    }    
    archivoEscritura.close();
    std::cout << "Calificaciones guardadas en calificaciones.txt"
    << "\nLeyendo calificaciones..." << std::endl;
    calificaciones.clear();
    std::ifstream archivoLectura("calificaciones.txt");
    if (archivoLectura.is_open()) {
        while (std::getline(archivoLectura, linea)) {
            valor = std::stod(linea);
            calificaciones.push_back(valor);
        }
    }
    if (!calificaciones.empty()) {
        masAlta = calificaciones[0];
        masBaja = calificaciones[0];
    }
        for (double valores : calificaciones) {
            total += valores;
            if (masAlta < valores) {
                masAlta = valores;
            }
            if (masBaja > valores) {
                masBaja = valores;
            }
        }
        archivoLectura.close();
        std::cout << "Archivo leido"
        << "\nPromedio: " << total/(static_cast<double>(calificaciones.size()))
        << "\nMas alta: " << masAlta
        << "\nMas baja: " << masBaja
        << "\nTotal: " << calificaciones.size() << " materias." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));
        // para poder ver como se borra
       if (std::remove(nombreArchivo) == 0) {
        std::cout << "Se borro el archivo: " << nombreArchivo << std::endl;
       } else {
        std::cerr << "Error al borrar el archivo:  " << nombreArchivo << std::endl;
        return 1;
       }
       
    return 0;
}
