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
 * PISTA: Usa π = 3.14159 o #include <cmath> con PI
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
const double PI = 3.141592653589793;
class Figura3D {
    protected:
        std::string nombre;
    public:
        virtual double calcularVolumen() = 0;
        virtual double calcularSuperficie() = 0;
        virtual std::string mostrarInfo() = 0;
        virtual std::string getNombre() {
            return this->nombre;
        }
    Figura3D(std::string nombreW = "figura") : nombre(nombreW) {};
    virtual ~Figura3D() {
            std::cout << "\nSe destruyo un objeto de Figura3D";
        }
};
class Esfera : public Figura3D {
    protected:
        double radio;
    public:
        double calcularVolumen() override {
            return (4.0/3.0) * PI * pow(this->radio, 3);
        }
        double calcularSuperficie() override {
            return 4 * PI * pow(this->radio, 2);
        }
        std::string mostrarInfo() override {
            std::ostringstream stream;
            stream << std::fixed << std::setprecision(2);
            stream << "\nFigura: " << this->nombre
            << "\nVolumen: " << (this->calcularVolumen())
            << "\nSuperficie: " << (this->calcularSuperficie())
            << "\nRadio: " << (this->radio); 
            return stream.str();
        }
        Esfera(double radioW = 1.0) 
            : Figura3D("ESFERA"), radio(radioW) {};
};

class Cubo : public Figura3D {
    protected: 
        double lado;
    public:
        double calcularVolumen() override {
            return pow(lado, 3);
        }
        double calcularSuperficie() override {
            return 6 * pow(lado, 2);
        }
        std::string mostrarInfo() override {
            std::ostringstream stream;
            stream << std::fixed << std::setprecision(2);
            stream << "\nFigura: " + this->nombre
            << "\nVolumen: " << (this->calcularVolumen())
            << "\nSuperficie: " << (this->calcularSuperficie())
            << "\nLado: " << (this->lado); 
            return stream.str();
        }
    Cubo(double ladoW = 1) :
        Figura3D("CUBO"), lado(ladoW) {};      
};
class Cilindro : public Figura3D {
    protected:
        double radio;
        double altura;
    public:
        double calcularVolumen() override {
            return PI * pow(radio, 2) * altura;
        }
        double calcularSuperficie() override {
            return 2 * PI * pow(radio, 2) + 2 * PI * radio * altura;
        }
        std::string mostrarInfo() override { 
            std::ostringstream stream;
            stream << std::fixed << std::setprecision(2);
            stream << "\nFigura: " << this->nombre
            << "\nVolumen: " << (this->calcularVolumen())
            << "\nSuperficie: " << (this->calcularSuperficie())
            << "\nRadio: " << (this->radio)
            << "\nAltura: " << (this->altura);
            return stream.str();
        }
    Cilindro(double radioW = 1, double alturaW = 1)
        : Figura3D("CILINDRO"), radio(radioW), altura(alturaW) {};
};

class Cono : public Figura3D {
    protected:
        double radio;
        double altura;
    public:
        double calcularVolumen() override { 
            return (1.0/3.0) * PI * (pow(this->radio, 2)) * this->altura;
        }
        double calcularSuperficie() override {
            return PI * pow(radio, 2) + PI*radio * (sqrt((pow(this->radio, 2)) + (pow(this->altura, 2))));
        }
        std::string mostrarInfo() override { 
            std::ostringstream stream;
            stream << std::fixed << std::setprecision(2);
            stream << "\nFigura: " << this->nombre
            << "\nVolumen: " << (this->calcularVolumen())
            << "\nSuperficie: " << (this->calcularSuperficie())
            << "\nRadio: " << (this->radio)
            << "\nAltura: " << (this->altura);
            return stream.str();
        }
    Cono(double radioW = 1, double alturaW = 1)
        : Figura3D("CONO"), radio(radioW), altura(alturaW){};
};

int main() {
    std::vector<Figura3D*> listaFiguras;
    listaFiguras.push_back(new Esfera(4));
    listaFiguras.push_back(new Cubo(10));
    listaFiguras.push_back(new Cilindro(10, 20));
    listaFiguras.push_back(new Cono(30, 20));
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "-------CALCULADORA DE FIGURAS 3D--------" << std::endl;
    double superficieTotal = 0.0;
    double volumenTotal = 0.0;
    Figura3D* figuraMayor = nullptr; 
    for (Figura3D* figura : listaFiguras) {
        figura->calcularSuperficie(); figura->calcularVolumen(); figura->mostrarInfo();
        if (figuraMayor == nullptr) {
            figuraMayor = figura;
        } if (figura->calcularVolumen() > figuraMayor->calcularVolumen()) {
            figuraMayor = figura;
        }
        std::cout << figura->mostrarInfo() << std::endl;
        superficieTotal += figura->calcularSuperficie();
        volumenTotal += figura->calcularVolumen();
    }
    std::cout << "----------RESUMEN----------"
    << "\nSuperficie total: " << superficieTotal 
    << "\nVolumen total: " << volumenTotal
    << "\nFigura mayor volumen: " << figuraMayor->getNombre() << "(" << figuraMayor->calcularVolumen() << "cm^3)"
    << std::endl;
    for (Figura3D* figura : listaFiguras) {
        delete figura;
    }
    return 0;
}
