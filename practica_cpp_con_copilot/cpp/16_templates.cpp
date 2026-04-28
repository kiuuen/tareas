/*
 * TEMA 16: TEMPLATES Y PROGRAMACION GENERICA
 *
 * TEORIA AMPLIADA:
 * - Los templates generan codigo en tiempo de compilacion.
 * - Funcion template: el compilador deduce T desde los argumentos.
 * - Clase template: el tipo se decide al instanciar Caja<int> o Caja<string>.
 * - Definicion visible: los templates suelen ir en headers o en el mismo archivo,
 *   porque el compilador necesita ver la implementacion para instanciar.
 * - Puedes usar static_assert para restringir tipos en tiempo de compilacion.
 * - Los errores de templates aparecen en compilacion, no en runtime.
 */

#include <iostream>
#include <string>

template <typename T>
T maximo(T a, T b) {
    return (a > b) ? a : b;
}

template <typename T>
class Caja {
private:
    T valor;

public:
    explicit Caja(T v) : valor(v) {}
    T get() const { return valor; }
    void set(T v) { valor = v; }
};

int main() {
    std::cout << "Maximo int: " << maximo(3, 7) << "\n";
    std::cout << "Maximo double: " << maximo(2.5, 9.1) << "\n";

    Caja<std::string> c("hola");
    std::cout << "Caja: " << c.get() << "\n";

    return 0;
}
