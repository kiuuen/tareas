/*
 * EJERCICIO 12C: Figuras Geométricas 3D (Clase Abstracta)
 * 
 * ⭐ EXCELENTE PARA ENTENDER CLASES ABSTRACTAS ⭐
 * 
 * TAREA:
 * Crea una jerarquía para figuras 3D:
 * 
 * 1. Clase abstracta Figura3D:
 *    - Atributo protected: nombre
 *    - Constructor
 *    - Métodos virtuales puros:
 *      * calcularVolumen() = 0
 *      * calcularSuperficie() = 0
 *    - Método virtual normal: mostrarInfo()
 *    - Destructor virtual
 * 
 * 2. Clase Esfera : public Figura3D
 *    - Atributo: radio
 *    - Volumen = (4/3) * π * r³
 *    - Superficie = 4 * π * r²
 *    - mostrarInfo() con los cálculos
 * 
 * 3. Clase Cubo : public Figura3D
 *    - Atributo: lado
 *    - Volumen = lado³
 *    - Superficie = 6 * lado²
 * 
 * 4. Clase Cilindro : public Figura3D
 *    - Atributos: radio, altura
 *    - Volumen = π * r² * h
 *    - Superficie = 2πr² + 2πrh
 * 
 * 5. Clase Cono : public Figura3D
 *    - Atributos: radio, altura
 *    - Volumen = (1/3) * π * r² * h
 *    - Superficie = πr² + πr√(r² + h²)
 * 
 * 6. En el main:
 *    - Crea un vector de Figura3D*
 *    - Agrega varias figuras
 *    - Muestra información de todas
 *    - Calcula volumen total y superficie total
 *    - Encuentra la figura con mayor volumen
 * 
 * PISTA: Usa π = 3.14159 o #include <cmath> con M_PI
 * 
 * EJEMPLO DE SALIDA:
 * === CALCULADORA DE FIGURAS 3D ===
 * 
 * ESFERA
 * Radio: 5 cm
 * Volumen: 523.60 cm³
 * Superficie: 314.16 cm²
 * 
 * CUBO
 * Lado: 4 cm
 * Volumen: 64.00 cm³
 * Superficie: 96.00 cm²
 * 
 * ... (otras figuras)
 * 
 * === RESUMEN ===
 * Total de figuras: 5
 * Volumen total: 1234.56 cm³
 * Superficie total: 678.90 cm²
 * Figura con mayor volumen: Cilindro (500 cm³)
 */

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

const double PI = 3.14159;

// TODO: Define la clase abstracta Figura3D aquí

// TODO: Define Esfera aquí

// TODO: Define Cubo aquí

// TODO: Define Cilindro aquí

// TODO: Define Cono aquí (opcional, pero buen desafío)

int main() {
    
    
    
    
    return 0;
}
