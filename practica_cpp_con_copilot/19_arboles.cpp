/*
 * TEMA 19: ÁRBOLES BINARIOS (Binary Trees)
 * 
 * TEORÍA COMPLETA:
 * 
 * 1. ¿QUÉ ES UN ÁRBOL BINARIO?
 *    Estructura de datos jerárquica donde cada nodo tiene como máximo 2 hijos.
 *    
 *          1          ← raíz (root)
 *         / \
 *        2   3        ← hijos de 1
 *       / \   \
 *      4   5   6      ← hojas (no tienen hijos)
 *    
 *    Terminología:
 *    - Raíz: nodo sin padre (el de arriba)
 *    - Hoja: nodo sin hijos (los de abajo)
 *    - Altura: distancia máxima de la raíz a una hoja
 *    - Profundidad: distancia de un nodo a la raíz
 *    - Subárbol: cada nodo es raíz de su propio subárbol
 * 
 * 2. NODO DE ÁRBOL EN C++:
 *    struct NodoArbol {
 *        int valor;
 *        NodoArbol* izquierdo;
 *        NodoArbol* derecho;
 *        NodoArbol(int v) : valor(v), izquierdo(nullptr), derecho(nullptr) {}
 *    };
 * 
 * 3. TIPOS DE ÁRBOLES:
 *    - Árbol binario: cada nodo tiene 0, 1, o 2 hijos
 *    - BST (Binary Search Tree): izquierdo < raíz < derecho
 *    - Árbol completo: todos los niveles llenos excepto quizás el último
 *    - Árbol balanceado: la diferencia de altura entre subárboles es ≤ 1
 * 
 * 4. RECORRIDOS (los 3 más importantes):
 * 
 *    INORDER (izq → raíz → der):  4 2 5 1 3 6  ← Para BST: da orden SORTED
 *    PREORDER (raíz → izq → der): 1 2 4 5 3 6  ← Útil para copiar/serializar
 *    POSTORDER (izq → der → raíz): 4 5 2 6 3 1 ← Útil para eliminar/evaluar
 *    
 *    LEVEL ORDER (BFS por niveles): 1 2 3 4 5 6 ← Usa una cola (queue)
 * 
 * 5. BST (Binary Search Tree):
 *    Propiedad: Para cada nodo, TODOS los valores del subárbol izquierdo
 *    son MENORES y TODOS los del derecho son MAYORES.
 *    
 *          8
 *         / \
 *        3   10
 *       / \    \
 *      1   6   14
 *    
 *    Buscar en BST: O(log n) promedio, O(n) peor caso (degenerado)
 *    Insertar en BST: O(log n) promedio
 * 
 * 6. ¿POR QUÉ IMPORTAN?
 *    - Base de estructuras como mapas ordenados (std::map usa Red-Black Tree)
 *    - Heaps (para priority_queue)
 *    - Problemas de recursión elegantes
 *    - Aparecen MUCHO en entrevistas y competencias
 *    - La recursión en árboles es la forma más natural de recorrerlos
 */

#include <iostream>
#include <queue>

struct NodoArbol {
    int valor;
    NodoArbol* izquierdo;
    NodoArbol* derecho;
    NodoArbol(int v) : valor(v), izquierdo(nullptr), derecho(nullptr) {}
};

// Recorrido INORDER (izq → raíz → der)
void inorder(NodoArbol* nodo) {
    if (nodo == nullptr) return;
    inorder(nodo->izquierdo);
    std::cout << nodo->valor << " ";
    inorder(nodo->derecho);
}

// Recorrido PREORDER (raíz → izq → der)
void preorder(NodoArbol* nodo) {
    if (nodo == nullptr) return;
    std::cout << nodo->valor << " ";
    preorder(nodo->izquierdo);
    preorder(nodo->derecho);
}

// Recorrido por niveles (Level Order / BFS)
void levelOrder(NodoArbol* raiz) {
    if (raiz == nullptr) return;
    std::queue<NodoArbol*> cola;
    cola.push(raiz);
    while (!cola.empty()) {
        NodoArbol* actual = cola.front();
        cola.pop();
        std::cout << actual->valor << " ";
        if (actual->izquierdo) cola.push(actual->izquierdo);
        if (actual->derecho) cola.push(actual->derecho);
    }
}

// Altura del árbol
int altura(NodoArbol* nodo) {
    if (nodo == nullptr) return 0;
    return 1 + std::max(altura(nodo->izquierdo), altura(nodo->derecho));
}

// Liberar memoria
void liberar(NodoArbol* nodo) {
    if (nodo == nullptr) return;
    liberar(nodo->izquierdo);
    liberar(nodo->derecho);
    delete nodo;
}

int main() {
    /*  Construir este árbol:
     *        1
     *       / \
     *      2   3
     *     / \   \
     *    4   5   6
     */
    NodoArbol* raiz = new NodoArbol(1);
    raiz->izquierdo = new NodoArbol(2);
    raiz->derecho = new NodoArbol(3);
    raiz->izquierdo->izquierdo = new NodoArbol(4);
    raiz->izquierdo->derecho = new NodoArbol(5);
    raiz->derecho->derecho = new NodoArbol(6);

    std::cout << "=== RECORRIDOS DEL ÁRBOL ===" << std::endl;
    std::cout << "Inorder:    "; inorder(raiz); std::cout << std::endl;
    std::cout << "Preorder:   "; preorder(raiz); std::cout << std::endl;
    std::cout << "Level Order: "; levelOrder(raiz); std::cout << std::endl;
    std::cout << "Altura: " << altura(raiz) << std::endl;

    liberar(raiz);
    return 0;
}
