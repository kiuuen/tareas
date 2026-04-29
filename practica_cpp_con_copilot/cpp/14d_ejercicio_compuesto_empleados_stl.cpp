/*
 * EJERCICIO 14D: Filtrado de Empleados (Compuesto: STL + POO + Archivos)
 *
 * TAREA:
 * - Simula lectura de un archivo (o usa arreglos hardcodeados) de Empleados (id, nombre, departamento, salario).
 * - Usa std::copy_if para extraer solo a los del departamento 'IT'.
 * - Usa std::remove_if (erase-remove idiom) para descartar a los que ganan menos de 3000.
 * - Finalmente usa std::transform para darles un bono de +10% al salario.
 * - Imprime el resultado con for_each.
 */
#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
const char* NAME_FILE = "employees.txt";
struct Employee {
    int id;
    std::string name;
    std::string department;
    double salary;
};

void saveEmployee(std::fstream &file, const Employee &e) {
    if (file.is_open()) {
        if (file.peek() == std::ifstream::traits_type::eof()) {
            return; // the file is empty
        }
        file << "\nname: " + e.name +
        "\nid: " + std::to_string(e.id) +
        "\ndepartment: " + e.department +
        "\nsalary: " + std::to_string(e.salary);
    }
    file.close();
}
std::vector<Employee> loadFile(std::fstream &file) {
    std::vector<Employee> employee;
    std::string line;
    bool secondWord = false;
    int counter = 0;
    std::string individualWords;
    std::istringstream iss;
    Employee tempEmployee;
    while (std::getline(file, line)) { 
        if (counter < 5) { 
            counter++;
            std::istringstream iss(line);
            while (iss >> individualWords) {
                if (secondWord) {
                    if (counter == 1) tempEmployee.name = individualWords;
                    else if (counter == 2) tempEmployee.id = std::stoi(individualWords);
                    else if (counter == 3) tempEmployee.department = individualWords;
                    else if (counter == 4) tempEmployee.salary = std::stod(individualWords);
                }
                secondWord = !secondWord;
            }
        } else {
            employee.push_back(tempEmployee);
            ~tempEmployee;
        }
    }

}