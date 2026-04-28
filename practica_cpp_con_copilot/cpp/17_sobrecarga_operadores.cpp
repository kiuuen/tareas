/*
 * TEMA 17: SOBRECARGA DE OPERADORES
 *
 * TEORIA AMPLIADA:
 * - Sirve para que tus clases se comporten como tipos nativos.
 * - Debe respetar la semantica esperada (no sorprender al usuario).
 * - Reglas comunes:
 *   * +, -, * suelen ser funciones libres para permitir conversiones simetricas.
 *   * +=, -= suelen ser miembros porque modifican el objeto.
 *   * << (ostream) casi siempre es funcion libre y puede ser friend.
 * - Usa const en parametros y metodos que no modifiquen el objeto.
 * - Si defines ==, considera definir != tambien.
 * - Evita sobrecargar operadores con significado confuso (&&, ||, ,).
 */

#include <iostream>

struct Vector2 {
    double x;
    double y;

    Vector2(double xVal, double yVal) : x(xVal), y(yVal) {}
};

Vector2 operator+(const Vector2& a, const Vector2& b) {
    return Vector2(a.x + b.x, a.y + b.y);
}

Vector2 operator-(const Vector2& a, const Vector2& b) {
    return Vector2(a.x - b.x, a.y - b.y);
}

std::ostream& operator<<(std::ostream& os, const Vector2& v) {
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}

int main() {
    Vector2 a(2.0, 3.0);
    Vector2 b(1.5, 4.0);

    Vector2 suma = a + b;
    Vector2 resta = a - b;

    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";
    std::cout << "a + b = " << suma << "\n";
    std::cout << "a - b = " << resta << "\n";

    return 0;
}

