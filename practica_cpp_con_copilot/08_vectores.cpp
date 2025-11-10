/*
 * TEMA 8: VECTORES (std::vector)
 * 
 * TEORÍA COMPLETA:
 * 
 * 1. ¿QUÉ ES std::vector?
 *    Es el equivalente de ArrayList en Java: un array dinámico que crece automáticamente
 *    
 *    Java:  ArrayList<Integer> lista = new ArrayList<>();
 *    C++:   std::vector<int> lista;
 *    
 *    IMPORTANTE: Necesitas #include <vector>
 * 
 * 2. DECLARACIÓN:
 *    std::vector<int> v1;                    // Vector vacío
 *    std::vector<int> v2(10);                // 10 elementos (valor 0)
 *    std::vector<int> v3(10, 5);             // 10 elementos (valor 5)
 *    std::vector<int> v4 = {1, 2, 3, 4, 5}; // Inicialización con valores
 * 
 * 3. MÉTODOS PRINCIPALES (comparación con Java):
 * 
 *    Java (ArrayList)              C++ (std::vector)
 *    ----------------              -----------------
 *    lista.add(valor)              v.push_back(valor)
 *    lista.get(i)                  v[i] o v.at(i)
 *    lista.set(i, valor)           v[i] = valor
 *    lista.size()                  v.size()
 *    lista.isEmpty()               v.empty()
 *    lista.clear()                 v.clear()
 *    lista.remove(i)               v.erase(v.begin() + i)
 *    lista.contains(valor)         std::find(v.begin(), v.end(), valor) != v.end()
 * 
 * 4. ACCESO A ELEMENTOS:
 *    v[i]      → Acceso directo (NO verifica límites, más rápido)
 *    v.at(i)   → Acceso seguro (lanza excepción si fuera de rango)
 *    v.front() → Primer elemento
 *    v.back()  → Último elemento
 * 
 * 5. AGREGAR Y ELIMINAR:
 *    v.push_back(x)   → Añade al final
 *    v.pop_back()     → Elimina el último
 *    v.insert(pos, x) → Inserta en posición
 *    v.erase(pos)     → Elimina en posición
 * 
 * 6. ITERACIÓN (3 formas):
 *    
 *    // Forma 1: índice clásico
 *    for (size_t i = 0; i < v.size(); i++) {
 *        cout << v[i] << " ";
 *    }
 *    
 *    // Forma 2: iteradores
 *    for (auto it = v.begin(); it != v.end(); ++it) {
 *        cout << *it << " ";
 *    }
 *    
 *    // Forma 3: range-based for (MÁS COMÚN Y LIMPIO)
 *    for (int x : v) {
 *        cout << x << " ";
 *    }
 *    
 *    // Forma 4: range-based con referencia (si quieres modificar)
 *    for (int& x : v) {
 *        x *= 2;  // Duplica cada elemento
 *    }
 * 
 * 7. ORDENAMIENTO Y BÚSQUEDA:
 *    std::sort(v.begin(), v.end());              // Ordenar
 *    std::reverse(v.begin(), v.end());           // Invertir
 *    auto it = std::find(v.begin(), v.end(), 5); // Buscar
 *    
 *    IMPORTANTE: Necesitas #include <algorithm>
 * 
 * 8. DIFERENCIAS IMPORTANTES CON JAVA:
 *    - En C++ usas size_t (unsigned) para índices, no int
 *    - vector.size() retorna size_t, no int
 *    - No hay método contains(), usas std::find
 *    - Para iterar, range-based for es más simple que iteradores
 */

#include <iostream>
#include <vector>
#include <algorithm>  // sort, find, reverse

int main() {
    // ===== CREACIÓN E INICIALIZACIÓN =====
    std::cout << "=== CREACIÓN ===" << '\n';
    
    std::vector<int> v1;                    // Vacío
    std::vector<int> v2 = {10, 20, 30, 40, 50};
    std::vector<std::string> nombres = {"Ana", "Luis", "María"};
    
    std::cout << "v2 tiene " << v2.size() << " elementos" << '\n';
    
    // ===== AGREGAR ELEMENTOS =====
    std::cout << "\n=== AGREGAR ===" << '\n';
    
    v1.push_back(100);
    v1.push_back(200);
    v1.push_back(300);
    
    std::cout << "v1 después de push_back: ";
    for (int x : v1) {
        std::cout << x << " ";
    }
    std::cout << '\n';
    
    // ===== ACCESO A ELEMENTOS =====
    std::cout << "\n=== ACCESO ===" << '\n';
    
    std::cout << "Primer elemento de v2: " << v2.front() << '\n';
    std::cout << "Último elemento de v2: " << v2.back() << '\n';
    std::cout << "Elemento en índice 2: " << v2[2] << '\n';
    
    // ===== MODIFICAR ELEMENTOS =====
    v2[0] = 99;
    std::cout << "Después de v2[0] = 99: " << v2[0] << '\n';
    
    // ===== ITERACIÓN (3 formas) =====
    std::cout << "\n=== ITERACIÓN ===" << '\n';
    
    // Forma 1: índice
    std::cout << "Con índice: ";
    for (size_t i = 0; i < v2.size(); i++) {
        std::cout << v2[i] << " ";
    }
    std::cout << '\n';
    
    // Forma 2: range-based for (más limpio)
    std::cout << "Range-based: ";
    for (int x : v2) {
        std::cout << x << " ";
    }
    std::cout << '\n';
    
    // Forma 3: modificar con referencia
    std::cout << "Duplicando cada elemento..." << '\n';
    for (int& x : v2) {
        x *= 2;
    }
    std::cout << "Resultado: ";
    for (int x : v2) {
        std::cout << x << " ";
    }
    std::cout << '\n';
    
    // ===== ELIMINAR ELEMENTOS =====
    std::cout << "\n=== ELIMINAR ===" << '\n';
    
    std::vector<int> v3 = {10, 20, 30, 40, 50};
    std::cout << "Antes: ";
    for (int x : v3) std::cout << x << " ";
    std::cout << '\n';
    
    v3.pop_back();  // Elimina el último (50)
    std::cout << "Después de pop_back: ";
    for (int x : v3) std::cout << x << " ";
    std::cout << '\n';
    
    v3.erase(v3.begin() + 1);  // Elimina índice 1 (20)
    std::cout << "Después de erase(1): ";
    for (int x : v3) std::cout << x << " ";
    std::cout << '\n';
    
    // ===== ORDENAMIENTO =====
    std::cout << "\n=== ORDENAMIENTO ===" << '\n';
    
    std::vector<int> numeros = {50, 20, 60, 10, 40, 30};
    std::cout << "Original: ";
    for (int x : numeros) std::cout << x << " ";
    std::cout << '\n';
    
    std::sort(numeros.begin(), numeros.end());
    std::cout << "Ordenado: ";
    for (int x : numeros) std::cout << x << " ";
    std::cout << '\n';
    
    std::reverse(numeros.begin(), numeros.end());
    std::cout << "Invertido: ";
    for (int x : numeros) std::cout << x << " ";
    std::cout << '\n';
    
    // ===== BÚSQUEDA =====
    std::cout << "\n=== BÚSQUEDA ===" << '\n';
    
    auto it = std::find(numeros.begin(), numeros.end(), 30);
    if (it != numeros.end()) {
        std::cout << "30 encontrado en posición: " 
                  << (it - numeros.begin()) << '\n';
    } else {
        std::cout << "30 no encontrado" << '\n';
    }
    
    // ===== TAMAÑO Y VACÍO =====
    std::cout << "\n=== INFO ===" << '\n';
    std::cout << "Tamaño de numeros: " << numeros.size() << '\n';
    std::cout << "¿Está vacío? " << (numeros.empty() ? "Sí" : "No") << '\n';
    
    numeros.clear();
    std::cout << "Después de clear, tamaño: " << numeros.size() << '\n';
    
    // ===== VECTOR DE STRINGS =====
    std::cout << "\n=== VECTOR DE STRINGS ===" << '\n';
    
    std::vector<std::string> frutas = {"manzana", "banana", "naranja"};
    frutas.push_back("pera");
    
    std::cout << "Frutas: ";
    for (const std::string& f : frutas) {  // const& para evitar copia
        std::cout << f << " ";
    }
    std::cout << '\n';
    
    std::sort(frutas.begin(), frutas.end());
    std::cout << "Ordenadas: ";
    for (const std::string& f : frutas) {
        std::cout << f << " ";
    }
    std::cout << '\n';
    
    return 0;
}

/*
 * COMPARACIÓN CON TU arraylistt.java:
 * 
 * Si en Java hacías:
 * ArrayList<Integer> lista = new ArrayList<>();
 * lista.add(10);
 * lista.add(20);
 * int valor = lista.get(0);
 * lista.remove(0);
 * 
 * En C++:
 * std::vector<int> lista;
 * lista.push_back(10);
 * lista.push_back(20);
 * int valor = lista[0];  // o lista.at(0)
 * lista.erase(lista.begin());
 */

// Siguiente: 08a_ejercicio_vector_basico.cpp
