/*
 * TEMA 19: SEMANTICA DE MOVIMIENTO (Move Semantics) Y RVALUES
 *
 * TEORIA:
 * - C++ permite "mover" recursos de un objeto temporal a otro, sin copiar datos costosos.
 * - Se usa std::move(obj) para indicar que 'obj' puede ser despojado de sus recursos.
 * - Se definen el Constructor de Movimiento y el Operador de Asignacion de Movimiento.
 * - Esencial para optimizar vectores, strings y tipos propios.
 */

#include <iostream>
#include <vector>
#include <string>
#include <utility>

class Contenedor {
private:
    std::string* data;
public:
    Contenedor(const std::string& d) : data(new std::string(d)) {
        std::cout << "Constructor normal\n";
    }
    
    // Constructor de Movimiento
    Contenedor(Contenedor&& otro) noexcept : data(otro.data) {
        otro.data = nullptr; // Dejamos el otro objeto en estado nulo
        std::cout << "Constructor de MOVIMIENTO\n";
    }
    
    ~Contenedor() {
        delete data;
    }
};

int main() {
    Contenedor c1("Hola");
    
    // Mover c1 a c2 (c1 ya no deberia usarse para su valor original)
    Contenedor c2 = std::move(c1);

    return 0;
}
