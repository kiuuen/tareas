/*
 * TEMA 15: EXCEPCIONES Y MANEJO DE ERRORES
 *
 * TEORIA AMPLIADA:
 * - Una excepcion representa un error excepcional (no el flujo normal).
 * - throw crea la excepcion y detiene la ejecucion normal hasta encontrar un catch.
 * - El stack se desenrolla: se destruyen objetos locales (RAII) al subir.
 * - Captura siempre por referencia const: catch (const std::exception&).
 * - Ordena los catch de mas especifico a mas general.
 * - Tipos comunes:
 *   * invalid_argument: argumento invalido (p. ej. division por cero).
 *   * out_of_range: indice fuera de rango.
 *   * runtime_error: fallos en tiempo de ejecucion (I/O, archivos).
 *   * logic_error: errores de logica en el codigo.
 * - No uses excepciones para control de flujo normal (if/else).
 * - Si una funcion puede fallar, define claramente su contrato: que lanza y cuando.
 */

#include <iostream>
#include <stdexcept>
#include <string>

double dividir(double a, double b) {
    if (b == 0.0) {
        throw std::invalid_argument("division por cero");
    }
    return a / b;
}

int parseEntero(const std::string& texto) {
    std::size_t idx = 0;
    int valor = std::stoi(texto, &idx);
    if (idx != texto.size()) {
        throw std::invalid_argument("texto con caracteres extra");
    }
    return valor;
}

int main() {
    try {
        std::cout << "10 / 2 = " << dividir(10, 2) << "\n";
        std::cout << "parseEntero(\"123\") = " << parseEntero("123") << "\n";
        std::cout << "parseEntero(\"12x\") = " << parseEntero("12x") << "\n";
    } catch (const std::exception& ex) {
        std::cout << "Error: " << ex.what() << "\n";
    }

    return 0;
}

