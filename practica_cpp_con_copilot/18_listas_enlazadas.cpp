/*
 * TEMA 18: LISTAS ENLAZADAS (Linked Lists)
 * 
 * TEORÍA COMPLETA:
 * 
 * 1. ¿QUÉ ES UNA LISTA ENLAZADA?
 *    Una secuencia de nodos donde cada nodo contiene:
 *    - Un valor (dato)
 *    - Un puntero al siguiente nodo (next)
 *    
 *    [10 | →] → [20 | →] → [30 | →] → nullptr
 *    
 *    Comparación con vector:
 *    ┌──────────────┬──────────────────┬──────────────────┐
 *    │ Operación    │ Vector           │ Lista enlazada   │
 *    ├──────────────┼──────────────────┼──────────────────┤
 *    │ Acceso [i]   │ O(1) ✓          │ O(n) ✗           │
 *    │ Insertar ini │ O(n) ✗          │ O(1) ✓           │
 *    │ Insertar fin │ O(1) amortizado │ O(1) si hay tail │
 *    │ Eliminar     │ O(n)            │ O(1) si tienes ptr│
 *    │ Búsqueda     │ O(n)            │ O(n)             │
 *    │ Memoria      │ Contigua        │ Dispersa         │
 *    └──────────────┴──────────────────┴──────────────────┘
 * 
 * 2. DEFINICIÓN DE UN NODO EN C++:
 *    struct Nodo {
 *        int valor;
 *        Nodo* siguiente;  // Puntero al siguiente nodo
 *        Nodo(int v) : valor(v), siguiente(nullptr) {}
 *    };
 * 
 * 3. TIPOS DE LISTAS:
 *    - Simple: cada nodo apunta al siguiente → → →
 *    - Doble: cada nodo apunta al anterior y siguiente ← → ← →
 *    - Circular: el último apunta al primero → → → ↩
 * 
 * 4. ¿POR QUÉ IMPORTAN LAS LISTAS ENLAZADAS?
 *    - Son la BASE de muchas estructuras (pilas, colas, grafos, hash tables)
 *    - Aparecen MUCHO en entrevistas técnicas y competencias
 *    - Te enseñan a manejar PUNTEROS, que es la esencia de C++
 *    - En Java/Python están ocultas; en C++ las manejas tú directamente
 * 
 * 5. TÉCNICAS COMUNES CON LISTAS:
 *    - Two pointers (lento/rápido): detectar ciclos, encontrar el medio
 *    - Recursión: invertir, recorrer
 *    - Nodo dummy: simplificar inserciones/eliminaciones al inicio
 * 
 * 6. MANEJO DE MEMORIA:
 *    IMPORTANTE: En C++, si creas nodos con "new", debes liberarlos con "delete".
 *    Nodo* n = new Nodo(10);  // Reserva memoria
 *    delete n;                 // Libera memoria
 *    En programas de competencia se suele ignorar (el OS limpia al terminar),
 *    pero en proyectos reales es CRÍTICO evitar memory leaks.
 */

#include <iostream>

struct Nodo {
    int valor;
    Nodo* siguiente;
    Nodo(int v) : valor(v), siguiente(nullptr) {}
};

// Imprimir lista
void imprimir(Nodo* cabeza) {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        std::cout << actual->valor;
        if (actual->siguiente) std::cout << " → ";
        actual = actual->siguiente;
    }
    std::cout << " → nullptr" << std::endl;
}

// Insertar al inicio (O(1))
Nodo* insertarInicio(Nodo* cabeza, int valor) {
    Nodo* nuevo = new Nodo(valor);
    nuevo->siguiente = cabeza;
    return nuevo;  // El nuevo nodo es la nueva cabeza
}

// Insertar al final (O(n))
Nodo* insertarFinal(Nodo* cabeza, int valor) {
    Nodo* nuevo = new Nodo(valor);
    if (cabeza == nullptr) return nuevo;
    
    Nodo* actual = cabeza;
    while (actual->siguiente != nullptr) {
        actual = actual->siguiente;
    }
    actual->siguiente = nuevo;
    return cabeza;
}

// Liberar toda la lista
void liberar(Nodo* cabeza) {
    while (cabeza != nullptr) {
        Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }
}

int main() {
    std::cout << "=== LISTA ENLAZADA ===" << std::endl;
    
    // Crear lista: 10 → 20 → 30
    Nodo* lista = nullptr;
    lista = insertarFinal(lista, 10);
    lista = insertarFinal(lista, 20);
    lista = insertarFinal(lista, 30);
    
    std::cout << "Lista: ";
    imprimir(lista);
    
    // Insertar al inicio
    lista = insertarInicio(lista, 5);
    std::cout << "Después de insertar 5 al inicio: ";
    imprimir(lista);
    
    // Contar elementos
    int count = 0;
    for (Nodo* n = lista; n != nullptr; n = n->siguiente) count++;
    std::cout << "Tamaño: " << count << std::endl;
    
    // Liberar memoria
    liberar(lista);
    std::cout << "Memoria liberada ✓" << std::endl;
    
    return 0;
}
