/*
 * TEMA 11: PUNTEROS Y REFERENCIAS
 * 
 * TEORÍA COMPLETA:
 * 
 * ⚠️ CONCEPTO CLAVE: ESTO NO EXISTE EN JAVA (al menos no de forma explícita)
 * En Java, todas las variables de objetos son referencias implícitas.
 * En C++, tienes control total sobre memoria y referencias.
 * 
 * 1. ¿QUÉ ES UN PUNTERO?
 *    Un puntero es una variable que almacena la DIRECCIÓN DE MEMORIA de otra variable
 *    
 *    int x = 10;        // Variable normal
 *    int* ptr = &x;     // ptr almacena la dirección de x
 *    
 *    Operadores:
 *    & → "dirección de" (obtiene la dirección de memoria)
 *    * → "des-referencia" (accede al valor en esa dirección)
 * 
 * 2. ¿QUÉ ES UNA REFERENCIA?
 *    Una referencia es un ALIAS (otro nombre) para una variable existente
 *    
 *    int x = 10;        // Variable original
 *    int& ref = x;      // ref es un alias de x
 *    
 *    Cuando modificas ref, modificas x (son la misma cosa)
 * 
 * 3. DIFERENCIAS ENTRE PUNTERO Y REFERENCIA:
 * 
 *    PUNTERO                        REFERENCIA
 *    -------                        ----------
 *    int* ptr;                      int& ref = x;
 *    Puede ser nullptr              No puede ser "nula"
 *    Puede cambiar a qué apunta     Siempre apunta a lo mismo
 *    Se accede con *ptr             Se usa directamente como variable
 *    Se puede asignar después       Debe inicializarse al declararse
 * 
 * 4. PASO POR VALOR vs PASO POR REFERENCIA:
 * 
 *    // PASO POR VALOR (copia)
 *    void incrementar(int x) {
 *        x++;  // NO modifica el original
 *    }
 *    
 *    // PASO POR REFERENCIA (modifica original)
 *    void incrementar(int& x) {
 *        x++;  // SÍ modifica el original
 *    }
 *    
 *    // PASO POR PUNTERO (modifica original)
 *    void incrementar(int* x) {
 *        (*x)++;  // SÍ modifica el original
 *    }
 * 
 * 5. ¿CUÁNDO USAR CADA UNO?
 * 
 *    PASO POR VALOR:
 *    - Para tipos pequeños (int, bool, char)
 *    - Cuando NO quieres modificar el original
 *    
 *    PASO POR REFERENCIA:
 *    - Para objetos grandes (evita copiar)
 *    - Cuando quieres modificar el original
 *    - Uso: void funcion(const Tipo& obj)  // const para no modificar
 *    
 *    PUNTEROS:
 *    - Cuando necesitas nullptr (valor "vacío")
 *    - Para estructuras de datos dinámicas
 *    - Para arrays dinámicos (mejor usar vector)
 * 
 * 6. nullptr (MEJOR QUE NULL):
 *    En C++ moderno, usa nullptr en lugar de NULL
 *    
 *    int* ptr = nullptr;  // Puntero que no apunta a nada
 *    if (ptr == nullptr) {
 *        // El puntero está vacío
 *    }
 * 
 * 7. MEMORIA DINÁMICA (new y delete):
 *    ⚠️ CUIDADO: En C++ no hay garbage collector
 *    
 *    // Crear objeto en heap
 *    Persona* p = new Persona("Juan", 25);
 *    p->mostrarInfo();
 *    delete p;  // ¡DEBES LIBERAR LA MEMORIA!
 *    
 *    REGLA: Por cada "new" debe haber un "delete"
 * 
 * 8. SMART POINTERS (C++ MODERNO - RECOMENDADO):
 *    En lugar de new/delete manual, usa smart pointers:
 *    
 *    #include <memory>
 *    
 *    std::unique_ptr<Persona> p = std::make_unique<Persona>("Juan", 25);
 *    // NO necesitas delete, se libera automáticamente
 *    
 *    std::shared_ptr<Persona> p2 = std::make_shared<Persona>("Ana", 30);
 *    // Múltiples referencias al mismo objeto
 * 
 * 9. CONST CON PUNTEROS Y REFERENCIAS:
 * 
 *    const int* ptr1;       // El contenido es const (no puedes modificar *ptr1)
 *    int* const ptr2;       // El puntero es const (no puedes cambiar ptr2)
 *    const int* const ptr3; // Ambos son const
 *    
 *    void funcion(const std::string& str) {
 *        // str es referencia pero no puedes modificarla (solo leer)
 *    }
 * 
 * 10. COMPARACIÓN CON JAVA:
 * 
 *     JAVA                           C++
 *     ----                           ---
 *     String s = new String();       String s;  // En stack
 *                                    String* s = new String();  // En heap
 *     
 *     void metodo(Objeto obj) {      void metodo(Objeto& obj) {
 *         // En Java es por referencia  // En C++ por referencia explícita
 *     }
 *     
 *     obj = null;                    obj = nullptr;
 */

#include <iostream>
#include <string>
#include <memory>  // Para smart pointers

// ===== EJEMPLO 1: Punteros básicos =====
void ejemploPunterosBasicos() {
    std::cout << "=== EJEMPLO 1: Punteros Básicos ===\n";
    
    int x = 42;
    int* ptr = &x;  // ptr almacena la dirección de x
    
    std::cout << "Valor de x: " << x << "\n";
    std::cout << "Dirección de x: " << &x << "\n";
    std::cout << "Valor de ptr (dirección que almacena): " << ptr << "\n";
    std::cout << "Valor al que apunta ptr: " << *ptr << "\n";
    
    // Modificar a través del puntero
    *ptr = 100;
    std::cout << "Después de *ptr = 100:\n";
    std::cout << "Valor de x: " << x << "\n";
}

// ===== EJEMPLO 2: Referencias =====
void ejemploReferencias() {
    std::cout << "\n=== EJEMPLO 2: Referencias ===\n";
    
    int x = 10;
    int& ref = x;  // ref es un alias de x
    
    std::cout << "Valor de x: " << x << "\n";
    std::cout << "Valor de ref: " << ref << "\n";
    
    ref = 20;  // Modificar ref modifica x
    std::cout << "Después de ref = 20:\n";
    std::cout << "Valor de x: " << x << "\n";
    std::cout << "Valor de ref: " << ref << "\n";
}

// ===== EJEMPLO 3: Paso por valor vs referencia =====
void incrementarPorValor(int x) {
    x++;  // NO modifica el original
}

void incrementarPorReferencia(int& x) {
    x++;  // SÍ modifica el original
}

void incrementarPorPuntero(int* x) {
    (*x)++;  // SÍ modifica el original
}

void ejemploPasoPorValorYReferencia() {
    std::cout << "\n=== EJEMPLO 3: Paso por Valor vs Referencia ===\n";
    
    int num1 = 5, num2 = 5, num3 = 5;
    
    std::cout << "Valores iniciales: " << num1 << ", " << num2 << ", " << num3 << "\n";
    
    incrementarPorValor(num1);
    std::cout << "Después de incrementarPorValor: " << num1 << "\n";
    
    incrementarPorReferencia(num2);
    std::cout << "Después de incrementarPorReferencia: " << num2 << "\n";
    
    incrementarPorPuntero(&num3);
    std::cout << "Después de incrementarPorPuntero: " << num3 << "\n";
}

// ===== EJEMPLO 4: Uso en funciones con objetos =====
void mostrarStringPorValor(std::string str) {
    // Copia todo el string (ineficiente para objetos grandes)
    std::cout << "String (por valor): " << str << "\n";
}

void mostrarStringPorReferencia(const std::string& str) {
    // NO copia, solo pasa referencia (eficiente)
    // const asegura que no se modifique
    std::cout << "String (por referencia): " << str << "\n";
}

void modificarString(std::string& str) {
    // Puede modificar porque no es const
    str += " MODIFICADO";
}

void ejemploReferenciaConObjetos() {
    std::cout << "\n=== EJEMPLO 4: Referencias con Objetos ===\n";
    
    std::string texto = "Hola C++";
    mostrarStringPorValor(texto);
    mostrarStringPorReferencia(texto);
    
    modificarString(texto);
    std::cout << "Después de modificar: " << texto << "\n";
}

// ===== EJEMPLO 5: Punteros y nullptr =====
void ejemploPunterosYNullptr() {
    std::cout << "\n=== EJEMPLO 5: Punteros y nullptr ===\n";
    
    int* ptr = nullptr;  // Puntero que no apunta a nada
    
    if (ptr == nullptr) {
        std::cout << "El puntero está vacío\n";
    }
    
    int x = 42;
    ptr = &x;  // Ahora apunta a x
    
    if (ptr != nullptr) {
        std::cout << "Ahora el puntero apunta a: " << *ptr << "\n";
    }
}

// ===== EJEMPLO 6: Smart Pointers (RECOMENDADO) =====
class Ejemplo {
private:
    std::string nombre;
public:
    Ejemplo(std::string n) : nombre(n) {
        std::cout << "  [Constructor llamado para: " << nombre << "]\n";
    }
    ~Ejemplo() {
        std::cout << "  [Destructor llamado para: " << nombre << "]\n";
    }
    void mostrar() const {
        std::cout << "  Soy: " << nombre << "\n";
    }
};

void ejemploSmartPointers() {
    std::cout << "\n=== EJEMPLO 6: Smart Pointers ===\n";
    
    std::cout << "Usando unique_ptr (propiedad única):\n";
    {
        std::unique_ptr<Ejemplo> ptr1 = std::make_unique<Ejemplo>("Objeto1");
        ptr1->mostrar();
        // NO necesitas delete, se libera automáticamente al salir del scope
    }
    std::cout << "(Se liberó automáticamente)\n";
    
    std::cout << "\nUsando shared_ptr (propiedad compartida):\n";
    {
        std::shared_ptr<Ejemplo> ptr2 = std::make_shared<Ejemplo>("Objeto2");
        {
            std::shared_ptr<Ejemplo> ptr3 = ptr2;  // Ambos apuntan al mismo objeto
            std::cout << "  Cantidad de referencias: " << ptr2.use_count() << "\n";
        }
        std::cout << "  Después de que ptr3 salió del scope: " << ptr2.use_count() << "\n";
    }
    std::cout << "(Se liberó cuando ya no hay referencias)\n";
}

int main() {
    ejemploPunterosBasicos();
    ejemploReferencias();
    ejemploPasoPorValorYReferencia();
    ejemploReferenciaConObjetos();
    ejemploPunterosYNullptr();
    ejemploSmartPointers();
    
    std::cout << "\n=== FIN DEL PROGRAMA ===\n";
    return 0;
}

/*
 * CONCEPTOS CLAVE PARA RECORDAR:
 * 
 * 1. & tiene DOS usos:
 *    - En declaración: int& ref = x;  → Referencia
 *    - En expresión: &x  → Dirección de memoria
 * 
 * 2. * tiene DOS usos:
 *    - En declaración: int* ptr;  → Declarar puntero
 *    - En expresión: *ptr  → Des-referenciar (obtener valor)
 * 
 * 3. BUENAS PRÁCTICAS:
 *    ✓ Usa referencias const para pasar objetos grandes
 *    ✓ Usa smart pointers en lugar de new/delete
 *    ✓ Usa nullptr en lugar de NULL
 *    ✓ Inicializa punteros siempre (nullptr si no apuntan a nada)
 *    ✗ Evita punteros crudos (raw pointers) cuando sea posible
 *    ✗ Evita delete manual (usa smart pointers)
 * 
 * 4. ¿POR QUÉ ES IMPORTANTE?
 *    - Eficiencia: pasar por referencia evita copias
 *    - Modificación: puedes alterar variables desde funciones
 *    - POO: necesario para métodos que modifican otros objetos
 *    - Estructuras de datos: listas, árboles, grafos
 * 
 * 5. RELACIÓN CON JAVA:
 *    En Java, los objetos siempre se pasan por referencia (implícito)
 *    En C++, tú decides: valor, referencia o puntero (explícito)
 */
