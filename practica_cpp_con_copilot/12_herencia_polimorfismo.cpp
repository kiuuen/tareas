/*
 * TEMA 12: HERENCIA Y POLIMORFISMO (POO AVANZADA)
 * 
 * ⭐ TEMA CENTRAL DEL SEMESTRE ⭐
 * 
 * TEORÍA COMPLETA:
 * 
 * 1. ¿QUÉ ES LA HERENCIA?
 *    Permite crear clases nuevas basadas en clases existentes
 *    La clase hija (derivada) hereda atributos y métodos de la clase padre (base)
 *    
 *    Java:                          C++:
 *    class Perro extends Animal {   class Perro : public Animal {
 *        ...                            ...
 *    }                              };
 * 
 * 2. SINTAXIS BÁSICA:
 * 
 *    // Clase base (padre)
 *    class Animal {
 *    protected:                    // ¡NOTA! protected, no private
 *        std::string nombre;
 *    public:
 *        Animal(std::string n) : nombre(n) {}
 *        void comer() { ... }
 *    };
 *    
 *    // Clase derivada (hijo)
 *    class Perro : public Animal {
 *    private:
 *        std::string raza;
 *    public:
 *        Perro(std::string n, std::string r) 
 *            : Animal(n), raza(r) {}  // Llama al constructor del padre
 *        void ladrar() { ... }
 *    };
 * 
 * 3. TIPOS DE HERENCIA EN C++:
 *    
 *    HERENCIA PÚBLICA (public) - LA MÁS COMÚN:
 *    class Perro : public Animal { ... };
 *    - public de Animal → public en Perro
 *    - protected de Animal → protected en Perro
 *    
 *    HERENCIA PROTEGIDA (protected) - POCO COMÚN:
 *    class Perro : protected Animal { ... };
 *    
 *    HERENCIA PRIVADA (private) - POCO COMÚN:
 *    class Perro : private Animal { ... };
 *    
 *    ⚠️ En Java solo existe herencia pública (extends)
 * 
 * 4. MODIFICADORES DE ACCESO Y HERENCIA:
 *    
 *    private:   Solo la clase puede acceder (NO heredable)
 *    protected: La clase y sus hijos pueden acceder (SÍ heredable)
 *    public:    Todos pueden acceder
 *    
 *    Ejemplo:
 *    class Padre {
 *    private:
 *        int privado;      // NO accesible desde hijo
 *    protected:
 *        int protegido;    // SÍ accesible desde hijo
 *    public:
 *        int publico;      // SÍ accesible desde todos
 *    };
 * 
 * 5. CONSTRUCTORES CON HERENCIA:
 *    
 *    El constructor del hijo DEBE llamar al constructor del padre:
 *    
 *    Perro(std::string n, std::string r) 
 *        : Animal(n),        // PRIMERO: constructor del padre
 *          raza(r) {         // LUEGO: inicializar propios atributos
 *        // Cuerpo del constructor
 *    }
 *    
 *    ORDEN DE CONSTRUCCIÓN:
 *    1. Constructor de la clase base (padre)
 *    2. Constructor de la clase derivada (hijo)
 *    
 *    ORDEN DE DESTRUCCIÓN (inverso):
 *    1. Destructor de la clase derivada
 *    2. Destructor de la clase base
 * 
 * 6. POLIMORFISMO Y MÉTODOS VIRTUALES:
 *    
 *    ⭐ CONCEPTO MÁS IMPORTANTE ⭐
 *    
 *    En Java:
 *    @Override
 *    public void hacerSonido() { ... }
 *    
 *    En C++ necesitas "virtual" en la clase base:
 *    
 *    class Animal {
 *    public:
 *        virtual void hacerSonido() { 
 *            std::cout << "Sonido genérico\n";
 *        }
 *    };
 *    
 *    class Perro : public Animal {
 *    public:
 *        void hacerSonido() override {  // override es opcional pero recomendado
 *            std::cout << "Guau!\n";
 *        }
 *    };
 *    
 *    ⚠️ SIN "virtual", NO hay polimorfismo en C++
 * 
 * 7. DESTRUCTORES VIRTUALES:
 *    
 *    ⚠️ MUY IMPORTANTE: Si tienes métodos virtuales, el destructor debe ser virtual:
 *    
 *    class Animal {
 *    public:
 *        virtual ~Animal() {  // Destructor virtual
 *            // Limpieza
 *        }
 *    };
 *    
 *    Si no es virtual, no se llama el destructor del hijo correctamente
 * 
 * 8. POLIMORFISMO EN ACCIÓN:
 *    
 *    Animal* animal1 = new Perro("Firulais", "Labrador");
 *    Animal* animal2 = new Gato("Michi", "Siamés");
 *    
 *    animal1->hacerSonido();  // "Guau!" (llama al método de Perro)
 *    animal2->hacerSonido();  // "Miau!" (llama al método de Gato)
 *    
 *    std::vector<Animal*> animales = {animal1, animal2};
 *    for (Animal* a : animales) {
 *        a->hacerSonido();  // Polimorfismo dinámico
 *    }
 * 
 * 9. CLASES ABSTRACTAS Y MÉTODOS VIRTUALES PUROS:
 *    
 *    En Java:
 *    public abstract class Figura {
 *        public abstract double calcularArea();
 *    }
 *    
 *    En C++:
 *    class Figura {
 *    public:
 *        virtual double calcularArea() = 0;  // = 0 indica método puro
 *        virtual ~Figura() {}  // Destructor virtual
 *    };
 *    
 *    No puedes crear objetos de una clase abstracta:
 *    Figura f;  // ✗ ERROR
 *    
 *    Pero sí de sus hijos que implementen los métodos puros:
 *    Circulo c(5);  // ✓ OK
 * 
 * 10. PALABRA CLAVE "override":
 *     
 *     Es opcional, pero ALTAMENTE RECOMENDADO:
 *     
 *     void hacerSonido() override {  // El compilador verifica que sobreescribes
 *         ...
 *     }
 *     
 *     Ventajas:
 *     - El compilador detecta errores de tipeo
 *     - Claridad en el código
 * 
 * 11. PALABRA CLAVE "final":
 *     
 *     Para evitar que una clase sea heredada:
 *     class ClaseFinal final {  // No se puede heredar
 *         ...
 *     };
 *     
 *     Para evitar que un método sea sobreescrito:
 *     virtual void metodo() final {  // No se puede override
 *         ...
 *     }
 * 
 * 12. COMPARACIÓN JAVA vs C++:
 * 
 *     ASPECTO               JAVA                    C++
 *     -------               ----                    ---
 *     Herencia              extends                 : public
 *     Polimorfismo          Automático              Requiere "virtual"
 *     Método abstracto      abstract                = 0
 *     Override              @Override               override (opcional)
 *     Destructor virtual    No existe               virtual ~Clase()
 *     Herencia múltiple     NO (solo interfaces)    SÍ (pero complejo)
 */

#include <iostream>
#include <string>
#include <vector>
#include <memory>  // Para smart pointers

// ===== EJEMPLO 1: Herencia Básica =====
class Animal {
protected:  // protected para que los hijos puedan acceder
    std::string nombre;
    int edad;

public:
    Animal(std::string n, int e) : nombre(n), edad(e) {
        std::cout << "[Animal constructor: " << nombre << "]\n";
    }
    
    virtual ~Animal() {  // Destructor virtual ⚠️
        std::cout << "[Animal destructor: " << nombre << "]\n";
    }
    
    // Método virtual (puede ser sobreescrito)
    virtual void hacerSonido() const {
        std::cout << nombre << " hace un sonido genérico\n";
    }
    
    // Método NO virtual (no se sobreescribe)
    void dormir() const {
        std::cout << nombre << " está durmiendo... zzz\n";
    }
    
    virtual void mostrarInfo() const {
        std::cout << "Animal: " << nombre << ", Edad: " << edad << " años\n";
    }
};

class Perro : public Animal {
private:
    std::string raza;

public:
    Perro(std::string n, int e, std::string r) 
        : Animal(n, e), raza(r) {  // Llama al constructor del padre
        std::cout << "[Perro constructor: " << nombre << "]\n";
    }
    
    ~Perro() {
        std::cout << "[Perro destructor: " << nombre << "]\n";
    }
    
    // Override del método virtual
    void hacerSonido() const override {
        std::cout << nombre << " dice: ¡Guau guau!\n";
    }
    
    void mostrarInfo() const override {
        std::cout << "Perro: " << nombre << ", Edad: " << edad 
                  << " años, Raza: " << raza << "\n";
    }
    
    // Método específico de Perro
    void perseguirCola() const {
        std::cout << nombre << " está persiguiendo su cola\n";
    }
};

class Gato : public Animal {
private:
    bool esInterior;

public:
    Gato(std::string n, int e, bool interior) 
        : Animal(n, e), esInterior(interior) {
        std::cout << "[Gato constructor: " << nombre << "]\n";
    }
    
    ~Gato() {
        std::cout << "[Gato destructor: " << nombre << "]\n";
    }
    
    void hacerSonido() const override {
        std::cout << nombre << " dice: ¡Miau miau!\n";
    }
    
    void mostrarInfo() const override {
        std::cout << "Gato: " << nombre << ", Edad: " << edad 
                  << " años, Tipo: " << (esInterior ? "Interior" : "Exterior") << "\n";
    }
    
    void rasguñar() const {
        std::cout << nombre << " está rasguñando\n";
    }
};

// ===== EJEMPLO 2: Clase Abstracta =====
class Figura {
protected:
    std::string nombre;

public:
    Figura(std::string n) : nombre(n) {}
    
    virtual ~Figura() {}  // Destructor virtual
    
    // Métodos virtuales puros (= 0) → Clase abstracta
    virtual double calcularArea() const = 0;
    virtual double calcularPerimetro() const = 0;
    
    // Método virtual normal
    virtual void mostrar() const {
        std::cout << "Figura: " << nombre << "\n";
    }
};

class Circulo : public Figura {
private:
    double radio;

public:
    Circulo(double r) : Figura("Círculo"), radio(r) {}
    
    double calcularArea() const override {
        return 3.14159 * radio * radio;
    }
    
    double calcularPerimetro() const override {
        return 2 * 3.14159 * radio;
    }
    
    void mostrar() const override {
        std::cout << "Círculo - Radio: " << radio 
                  << ", Área: " << calcularArea()
                  << ", Perímetro: " << calcularPerimetro() << "\n";
    }
};

class Rectangulo : public Figura {
private:
    double ancho, alto;

public:
    Rectangulo(double a, double h) 
        : Figura("Rectángulo"), ancho(a), alto(h) {}
    
    double calcularArea() const override {
        return ancho * alto;
    }
    
    double calcularPerimetro() const override {
        return 2 * (ancho + alto);
    }
    
    void mostrar() const override {
        std::cout << "Rectángulo - " << ancho << "x" << alto
                  << ", Área: " << calcularArea()
                  << ", Perímetro: " << calcularPerimetro() << "\n";
    }
};

int main() {
    std::cout << "╔════════════════════════════════════════╗\n";
    std::cout << "║   HERENCIA Y POLIMORFISMO EN C++      ║\n";
    std::cout << "╚════════════════════════════════════════╝\n\n";
    
    // ===== USO DIRECTO DE CLASES =====
    std::cout << "=== EJEMPLO 1: Herencia Básica ===\n\n";
    
    Perro perro1("Firulais", 3, "Labrador");
    Gato gato1("Michi", 2, true);
    
    std::cout << "\n";
    perro1.hacerSonido();
    gato1.hacerSonido();
    
    std::cout << "\n";
    perro1.mostrarInfo();
    gato1.mostrarInfo();
    
    std::cout << "\n";
    perro1.perseguirCola();
    gato1.rasguñar();
    
    // ===== POLIMORFISMO =====
    std::cout << "\n\n=== POLIMORFISMO EN ACCIÓN ===\n\n";
    
    // Crear un vector de punteros a Animal (clase base)
    std::vector<Animal*> animales;
    animales.push_back(new Perro("Rex", 5, "Pastor Alemán"));
    animales.push_back(new Gato("Luna", 1, true));
    animales.push_back(new Perro("Max", 2, "Bulldog"));
    
    // Polimorfismo: cada objeto llama a su propio método
    std::cout << "Todos los animales hacen sonidos:\n";
    for (const auto& animal : animales) {
        animal->hacerSonido();  // Polimorfismo dinámico
    }
    
    std::cout << "\nInformación de todos los animales:\n";
    for (const auto& animal : animales) {
        animal->mostrarInfo();
    }
    
    // Liberar memoria
    for (auto animal : animales) {
        delete animal;
    }
    animales.clear();
    
    // ===== CLASE ABSTRACTA =====
    std::cout << "\n\n=== EJEMPLO 2: Clase Abstracta ===\n\n";
    
    // Figura f;  // ✗ ERROR: no se puede instanciar clase abstracta
    
    std::vector<Figura*> figuras;
    figuras.push_back(new Circulo(5.0));
    figuras.push_back(new Rectangulo(4.0, 6.0));
    figuras.push_back(new Circulo(3.0));
    
    std::cout << "Información de todas las figuras:\n";
    for (const auto& figura : figuras) {
        figura->mostrar();
    }
    
    double areaTotal = 0;
    for (const auto& figura : figuras) {
        areaTotal += figura->calcularArea();
    }
    std::cout << "\nÁrea total: " << areaTotal << "\n";
    
    // Liberar memoria
    for (auto figura : figuras) {
        delete figura;
    }
    
    std::cout << "\n=== FIN DEL PROGRAMA ===\n";
    return 0;
}

/*
 * CONCEPTOS CLAVE:
 * 
 * 1. HERENCIA EN C++:
 *    - class Hijo : public Padre {}
 *    - Usar protected para atributos que los hijos necesiten
 * 
 * 2. CONSTRUCTORES:
 *    - El hijo debe llamar al constructor del padre
 *    - Hijo() : Padre(), miembro() {}
 * 
 * 3. POLIMORFISMO:
 *    - Requiere "virtual" en la clase base
 *    - Usa "override" en las clases derivadas (recomendado)
 * 
 * 4. DESTRUCTOR VIRTUAL:
 *    - ⚠️ SIEMPRE virtual ~Clase() si tienes métodos virtuales
 * 
 * 5. CLASES ABSTRACTAS:
 *    - Método virtual puro: virtual void metodo() = 0;
 *    - No se pueden instanciar
 * 
 * 6. MEMORIA:
 *    - Usa smart pointers para evitar leaks
 *    - std::unique_ptr o std::shared_ptr
 * 
 * 7. DIFERENCIAS CON JAVA:
 *    - Java: polimorfismo automático
 *    - C++: requiere "virtual" explícito
 *    - Java: no hay destructores
 *    - C++: destructores virtuales son críticos
 */
