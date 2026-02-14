/*
 * TEMA 10: PROGRAMACIÓN ORIENTADA A OBJETOS (POO) - BÁSICA
 * 
 * TEORÍA COMPLETA:
 * 
 * 1. ¿QUÉ ES UNA CLASE EN C++?
 *    Similar a Java, pero con diferencias importantes:
 *    
 *    Java:                         C++:
 *    public class Persona {        class Persona {
 *        private String nombre;        private:
 *        public Persona() {...}            std::string nombre;
 *    }                                 public:
 *                                          Persona() {...}
 *                                   };  // ¡PUNTO Y COMA!
 * 
 * 2. MODIFICADORES DE ACCESO:
 *    - private: Solo accesible dentro de la clase (como Java)
 *    - public: Accesible desde cualquier parte (como Java)
 *    - protected: Accesible desde clases derivadas (como Java)
 *    
 *    DIFERENCIA CLAVE: En C++ se agrupan por sección, no por cada miembro
 * 
 * 3. CONSTRUCTORES:
 *    En Java:
 *    public Persona(String n) {
 *        nombre = n;
 *    }
 *    
 *    En C++ (forma tradicional):
 *    Persona(std::string n) {
 *        nombre = n;
 *    }
 *    
 *    En C++ (forma preferida - lista de inicialización):
 *    Persona(std::string n) : nombre(n) {
 *        // Constructor más eficiente
 *    }
 * 
 * 4. DESTRUCTORES (¡NO EXISTEN EN JAVA!):
 *    En C++ no hay garbage collector, así que las clases tienen destructores
 *    que se llaman automáticamente cuando el objeto se destruye
 *    
 *    ~Persona() {
 *        // Liberar recursos si es necesario
 *    }
 * 
 * 5. MÉTODOS GETTER Y SETTER:
 *    Java:                         C++:
 *    public String getNombre() {   std::string getNombre() const {
 *        return nombre;                return nombre;
 *    }                             }
 *    public void setNombre(...) {  void setNombre(std::string n) {
 *        nombre = n;                   nombre = n;
 *    }                             }
 *    
 *    NOTA: "const" al final indica que el método no modifica el objeto
 * 
 * 6. THIS EN C++:
 *    Java: this.nombre           C++: this->nombre (con puntero)
 *    
 *    Pero normalmente no es necesario en C++ a menos que haya ambigüedad
 * 
 * 7. CREAR OBJETOS:
 *    Java:                        C++:
 *    Persona p = new Persona();   // Forma 1: objeto en stack (recomendado)
 *                                 Persona p;
 *                                 Persona p("Juan", 25);
 *                                 
 *                                 // Forma 2: objeto en heap (como Java)
 *                                 Persona* p = new Persona();
 *                                 delete p;  // ¡Debes liberar memoria!
 * 
 * 8. ACCESO A MIEMBROS:
 *    Con objeto:   objeto.metodo()
 *    Con puntero:  puntero->metodo()  o  (*puntero).metodo()
 * 
 * 9. SOBRECARGA DE CONSTRUCTORES:
 *    Igual que Java, puedes tener múltiples constructores
 * 
 * 10. MÉTODOS CONST:
 *     void mostrar() const { ... }
 *     Indica que el método no modifica el estado del objeto (buena práctica)
 */

#include <iostream>
#include <string>

// EJEMPLO 1: Clase básica Persona
class Persona {
private:
    std::string nombre;
    int edad;

public:
    // Constructor por defecto
    Persona() : nombre("Sin nombre"), edad(0) {
        std::cout << "Constructor por defecto llamado\n";
    }
    
    // Constructor con parámetros (FORMA PREFERIDA: lista de inicialización)
    Persona(std::string n, int e) : nombre(n), edad(e) {
        std::cout << "Constructor con parámetros llamado para: " << nombre << "\n";
    }
    
    // Destructor
    ~Persona() {
        std::cout << "Destructor llamado para: " << nombre << "\n";
    }
    
    // Getters (const porque no modifican el objeto)
    std::string getNombre() const {
        return nombre;
    }
    
    int getEdad() const {
        return edad;
    }
    
    // Setters
    void setNombre(std::string n) {
        nombre = n;
    }
    
    void setEdad(int e) {
        if (e >= 0) {
            edad = e;
        }
    }
    
    // Método para mostrar información
    void mostrar() const {
        std::cout << "Nombre: " << nombre << ", Edad: " << edad << " años\n";
    }
    
    // Método que verifica si es mayor de edad
    bool esMayorDeEdad() const {
        return edad >= 18;
    }
};

// EJEMPLO 2: Clase Rectangulo con métodos de cálculo
class Rectangulo {
private:
    double ancho;
    double alto;

public:
    // Constructor
    Rectangulo(double a, double h) : ancho(a), alto(h) {}
    
    // Métodos para calcular área y perímetro
    double calcularArea() const {
        return ancho * alto;
    }
    
    double calcularPerimetro() const {
        return 2 * (ancho + alto);
    }
    
    // Getters
    double getAncho() const { return ancho; }
    double getAlto() const { return alto; }
    
    // Setters con validación
    void setAncho(double a) {
        if (a > 0) ancho = a;
    }
    
    void setAlto(double h) {
        if (h > 0) alto = h;
    }
    
    void mostrar() const {
        std::cout << "Rectángulo: " << ancho << " x " << alto << "\n";
        std::cout << "Área: " << calcularArea() << "\n";
        std::cout << "Perímetro: " << calcularPerimetro() << "\n";
    }
};

// EJEMPLO 3: Clase CuentaBancaria (ejemplo más completo)
class CuentaBancaria {
private:
    std::string titular;
    std::string numeroCuenta;
    double saldo;

public:
    // Constructor
    CuentaBancaria(std::string t, std::string num) 
        : titular(t), numeroCuenta(num), saldo(0.0) {
        std::cout << "Cuenta creada para: " << titular << "\n";
    }
    
    // Métodos para depositar y retirar
    void depositar(double cantidad) {
        if (cantidad > 0) {
            saldo += cantidad;
            std::cout << "Depositado: $" << cantidad << "\n";
        } else {
            std::cout << "Cantidad inválida\n";
        }
    }
    
    bool retirar(double cantidad) {
        if (cantidad > 0 && cantidad <= saldo) {
            saldo -= cantidad;
            std::cout << "Retirado: $" << cantidad << "\n";
            return true;
        } else {
            std::cout << "Fondos insuficientes o cantidad inválida\n";
            return false;
        }
    }
    
    void mostrarInfo() const {
        std::cout << "\n=== Información de Cuenta ===\n";
        std::cout << "Titular: " << titular << "\n";
        std::cout << "Número: " << numeroCuenta << "\n";
        std::cout << "Saldo: $" << saldo << "\n";
    }
    
    double getSaldo() const { return saldo; }
};

int main() {
    std::cout << "=== EJEMPLO 1: Clase Persona ===\n\n";
    
    // Crear objetos en el stack (forma recomendada en C++)
    Persona p1;  // Constructor por defecto
    p1.mostrar();
    
    Persona p2("Juan", 25);  // Constructor con parámetros
    p2.mostrar();
    
    // Usar setters
    p1.setNombre("María");
    p1.setEdad(30);
    p1.mostrar();
    
    // Verificar si es mayor de edad
    if (p2.esMayorDeEdad()) {
        std::cout << p2.getNombre() << " es mayor de edad\n";
    }
    
    std::cout << "\n=== EJEMPLO 2: Clase Rectangulo ===\n\n";
    
    Rectangulo r1(5.0, 3.0);
    r1.mostrar();
    
    std::cout << "\n=== EJEMPLO 3: Clase CuentaBancaria ===\n\n";
    
    CuentaBancaria cuenta("Ana López", "001-234567");
    cuenta.depositar(1000);
    cuenta.depositar(500);
    cuenta.retirar(300);
    cuenta.mostrarInfo();
    
    std::cout << "\n=== FIN DEL PROGRAMA ===\n";
    std::cout << "(Observa cómo se llaman los destructores automáticamente)\n\n";
    
    return 0;
}

/*
 * DIFERENCIAS CLAVE ENTRE JAVA Y C++ EN POO:
 * 
 * 1. NO HAY GARBAGE COLLECTOR en C++
 *    - Los objetos en el stack se destruyen automáticamente
 *    - Los objetos en el heap (con new) debes eliminarlos con delete
 * 
 * 2. CONSTRUCTORES Y DESTRUCTORES
 *    - C++ tiene destructores (~Clase), Java no
 *    - Los destructores liberan recursos automáticamente (RAII)
 * 
 * 3. LISTA DE INICIALIZACIÓN
 *    - En C++ es más eficiente: Constructor() : miembro(valor) {}
 *    - En Java solo puedes asignar en el cuerpo del constructor
 * 
 * 4. CONST CORRECTNESS
 *    - En C++ puedes marcar métodos como const
 *    - Esto indica que no modifican el objeto (buena práctica)
 * 
 * 5. CREACIÓN DE OBJETOS
 *    - Java: siempre con new (en heap)
 *    - C++: preferir sin new (en stack), usar new solo si es necesario
 * 
 * 6. PUNTO Y COMA DESPUÉS DE LA CLASE
 *    - C++ requiere ; después del } de la clase
 *    - Java no lo requiere
 * 
 * 7. SEPARACIÓN DE DECLARACIÓN E IMPLEMENTACIÓN
 *    - C++ puede tener .h (header) y .cpp separados
 *    - Java solo tiene .java
 * 
 * CONSEJO: En C++ moderno, prefiere:
 * - Objetos en stack cuando sea posible
 * - std::unique_ptr o std::shared_ptr en lugar de new/delete manual
 * - Lista de inicialización en constructores
 * - Métodos const cuando no modifiquen el objeto
 */
