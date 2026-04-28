/*
 * EJERCICIO 11B: Modificar objeto por referencia
 * 
 * TAREA:
 * 1. Crea una clase Rectangulo con atributos ancho y alto (privados)
 * 2. Crea un constructor y métodos getters
 * 3. Crea una función FUERA de la clase: void escalar(Rectangulo& rect, double factor)
 *    - Esta función debe multiplicar ancho y alto por el factor
 *    - Necesitarás setters en la clase o hacer la función friend (avanzado)
 * 4. En el main, crea un rectángulo y escálalo por 2
 * 
 * EJEMPLO:
 * Rectangulo r(5, 3);
 * std::cout << "Antes: " << r.getAncho() << " x " << r.getAlto() << "\n";
 * escalar(r, 2.0);
 * std::cout << "Después: " << r.getAncho() << " x " << r.getAlto() << "\n";
 * 
 * SALIDA ESPERADA:
 * Antes: 5 x 3
 * Después: 10 x 6
 */

#include <iostream>

class Rectangulo {
    private:
        int base;
        int altura;
    public:
        int getBase() {
            return this->base;
        }
        int getAltura() {
            return this->altura;
        }
    Rectangulo(int baseW = 1, int alturaW = 1) : base(baseW), altura(alturaW){};
    friend void escalar(Rectangulo& rectangulo, int factor);
};

void escalar(Rectangulo& rectangulo, int factor) {
    rectangulo.altura *= factor;
    rectangulo.base *= factor;
}

int main() {
    Rectangulo rec1(10, 5);
    std::cout << "El rectangulo ahora mide: " << rec1.getBase() << " x " << rec1.getAltura() << std::endl;
    escalar(rec1, 10);
    std::cout << "El rectangulo ahora mide: " << rec1.getBase() << " x " << rec1.getAltura() << std::endl;
    return 0;
}
