/*
 * EJERCICIO 13B: Agenda de contactos con persistencia
 * 
 * TAREA:
 * Crea una agenda de contactos que guarde y cargue datos de un archivo:
 * 
 * 1. Crea una clase Contacto con:
 *    - nombre, teléfono, email
 * 2. Implementa un menú:
 *    1. Agregar contacto
 *    2. Mostrar todos los contactos
 *    3. Buscar contacto por nombre
 *    4. Guardar en archivo
 *    5. Cargar desde archivo
 *    6. Salir
 * 
 * 3. Formato del archivo "contactos.txt":
 *    nombre telefono email
 *    Ana 5551234 ana@email.com
 *    Carlos 5555678 carlos@email.com
 * 
 * PISTAS:
 * - Usa un vector<Contacto> para almacenar en memoria
 * - Para guardar: recorre el vector y escribe cada contacto
 * - Para cargar: lee línea por línea y crea objetos Contacto
 * 
 * EJEMPLO DE EJECUCIÓN:
 * === AGENDA ===
 * 1. Agregar
 * 2. Mostrar todos
 * 3. Buscar
 * 4. Guardar
 * 5. Cargar
 * 6. Salir
 * Opción: 1
 * Nombre: Ana
 * Teléfono: 5551234
 * Email: ana@email.com
 * ✓ Contacto agregado
 * 
 * Opción: 4
 * ✓ 1 contactos guardados en 'contactos.txt'
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
class Contacto {
    private :
        std::string nombre;
        std::string numero;
        std::string email;
    public:
        std::string getContacto() {
            return this->nombre + " " + this->numero +  " " + this->email;
        }
        std::string getNombre() {
            return this->nombre;
        }
        std::string mostrarInfo() {
            return "Nombre: " + this->nombre
            + ", numero: " + this->numero
            + ", correo: " + this->email;
        };
        Contacto(std::string nombreW = "Sin nombre", std::string numeroW = "00000000", std::string emailW = "Sin correo")
            : nombre(nombreW), numero(numeroW), email(emailW){};
        virtual ~Contacto() {
        }
};
bool repetir() {
    std::string opcion;
    std::cout << "Deseas repetir? s/n" << std::endl;
    std::cin >> opcion;
    if (opcion == "s" || opcion == "S") { 
        return true;
    } if (opcion == "n" || opcion == "N") {
        return false;
    } else {
        std::cout << "Error, elige una opcion correcta" << std::endl;
        repetir(); // bucle de recursividad para que elija algo correcto
    }
    return false;
}
int main() {
    bool exit = false;
    int input = 0;
    std::string nombreTemporal = "";
    std::string inputTemp = "";
    std::string numTemporal = "";
    std::string correoTemporal = "";
    std::vector<Contacto*> vectorContactos;
    std::string lineaTemp;
    std::string textoRaw;
    std::ostringstream oss;
    std::ifstream leerArchivo("agenda.txt");
    do {
        std::cout << "----AGENDA-----"
        << "\n1) Agregar contacto"
        << "\n2) Eliminar contacto"
        << "\n3) Buscar contacto por nombre"
        << "\n4) Guardar en archivo"
        << "\n5) Cargar en archivo"
        << "\n6) Ver todos los contactos"
        << "\n7) Salir"
        << "\nElige una opcion: ";
        std::cin >> input;
        switch (input) {
            case 1: {
                std::cout << "Introduce el nombre: " << std::endl;std::cin >> nombreTemporal;
                std::cout << "Introduce el numero: " << std::endl;std::cin >> numTemporal;
                std::cout << "Introduce el correo (opcional, enter para omitir): " << std::endl;
                std::cin >> correoTemporal;
                if (correoTemporal.empty()){vectorContactos.push_back(new Contacto(nombreTemporal, numTemporal));
                } else {vectorContactos.push_back(new Contacto(nombreTemporal, numTemporal, correoTemporal));}
                Contacto* contactoTemp = vectorContactos.back();
                std::cout << "Se ha agregado el contacto: " << contactoTemp->mostrarInfo() << std::endl;
                if (repetir()) {
                    input = 1;
                }
                break;
            }
            case 2: {
                std::cout << "Introduce el nombre del contacto a eliminar: " << std::endl;
                std::cin >> nombreTemporal;
                for (Contacto* c : vectorContactos) {
                    if (nombreTemporal == c->getNombre()) {
                        std::cout << "Se encontro el contacto: " << c->mostrarInfo() << std::endl;
                        std::cout << "Estas seguro que deseas eliminarlo? s/n" << std::endl;
                        std::cin >> inputTemp;
                        if (inputTemp == "s" || inputTemp == "S") {
                            vectorContactos.erase(std::remove(vectorContactos.begin(), vectorContactos.end(), c));
                            delete c;
                            std::cout << "Se elimino el contacto" << std::endl;
                            break;
                        }
                    }
                    if (c == vectorContactos.back()) {
                        std::cout << "No se encontró ese contacto." << std::endl;
                    }
                }
                if (repetir()){
                    input = 2;
                    }
                    break;
                }
            case 3: {
                std::cout << "Introduce el nombre del contacto a buscar: " << std::endl;
                std::cin >> nombreTemporal;
                for (Contacto* c : vectorContactos) {
                    if (nombreTemporal == c->getNombre()) {
                        std::cout << "Se encontro el contacto: " << c->mostrarInfo() << std::endl;
                        if (repetir()) {
                        input = 3;
                        }
                        break;
                    }
                    if (c == vectorContactos.back()) {
                        std::cout << "No se encontro ese contacto." << std::endl;
                    }
                    if (repetir()) {
                    input = 3;
                    }
                    break;
                }
                if (repetir()) {
                    input = 3;
                }
                break;
            }
            case 4: { 
                std::ofstream escribirArchivo("agenda.txt");
                if (escribirArchivo.is_open()) {
                    for (Contacto* c : vectorContactos) {
                        lineaTemp = c->getContacto();
                        escribirArchivo << lineaTemp << "\n";
                    }
                    std::cout << "Se han guardado todos los contactos en el archivo: agenda.txt" << std::endl;
                    escribirArchivo.close();
                    }
                break;
            }
            case 5: {
                if (leerArchivo.is_open()) {
                    while (std::getline(leerArchivo, lineaTemp)) {
                    textoRaw.append(lineaTemp+"\n");
                }
                std::string textoTemp;
                std::vector<std::string> contactoRaw;
                std::stringstream ss(textoRaw);
                int n = 0;
                while (ss >> textoTemp) {
                    n++;
                    contactoRaw.push_back(textoTemp);
                    if (n == 3) {
                        vectorContactos.push_back(new Contacto(contactoRaw[0], contactoRaw[1], contactoRaw[2]));
                        contactoRaw.clear();
                        n = 0;
                    }
                }
                }
                leerArchivo.close();
                std::cout << "Se ha leido el archivo: agenda.txt" << std::endl;
                break;
            }
            case 6: {
                std::cout << "------CONTACTOS------" << std::endl;
                if (vectorContactos.empty()) {
                    std::cout << "No hay contactos" << std::endl;
                    break;
                }
                for (Contacto* c : vectorContactos) {
                    std::cout << c->mostrarInfo() << "\n----------" << std::endl;
                }
                break;
            }
            case 7: {
                std::cout << "Saliendo del programa..." << std::endl;
                exit = true;
                break;
            }
            default: {
                std::cout << "Error, introduce una opcion valida" << std::endl;
                break;
            }
        }
        } while(!exit);
        for (Contacto* c : vectorContactos) {
            delete c;
        }
    return 0;
}
