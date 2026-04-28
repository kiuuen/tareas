/*
 * TEMA 17: PILAS Y COLAS (Stack & Queue)
 * 
 * TEORÍA COMPLETA:
 * 
 * 1. PILA (STACK) - LIFO: Last In, First Out
 *    Imagina una pila de platos: el último que pones es el primero que sacas.
 *    
 *    Operaciones (todas O(1)):
 *    - push(x): agregar al tope
 *    - pop():   remover del tope
 *    - top():   ver el tope sin remover
 *    - empty(): ¿está vacía?
 *    - size():  cuántos elementos tiene
 *    
 *    C++: #include <stack>
 *         std::stack<int> pila;
 *    
 *    USOS COMUNES:
 *    - Verificar paréntesis balanceados
 *    - Evaluación de expresiones (postfija, infija)
 *    - Deshacer/Rehacer (Ctrl+Z)
 *    - Recorrido DFS (implícito en recursión)
 *    - Historial del navegador
 * 
 * 2. COLA (QUEUE) - FIFO: First In, First Out
 *    Imagina la fila del supermercado: el primero en llegar es el primero en salir.
 *    
 *    Operaciones (todas O(1)):
 *    - push(x): agregar al final
 *    - pop():   remover del frente
 *    - front(): ver el frente sin remover
 *    - back():  ver el final sin remover
 *    - empty(): ¿está vacía?
 *    
 *    C++: #include <queue>
 *         std::queue<int> cola;
 *    
 *    USOS COMUNES:
 *    - BFS (Breadth-First Search) en grafos
 *    - Simulación de procesos (turnos, impresoras)
 *    - Buffer de datos
 * 
 * 3. COLA DE PRIORIDAD (PRIORITY QUEUE) - Siempre saca el mayor/menor
 *    Es un HEAP: el elemento con mayor prioridad siempre está al frente.
 *    
 *    C++: std::priority_queue<int> maxHeap;  // Por defecto: mayor primero
 *         std::priority_queue<int, vector<int>, greater<int>> minHeap;  // Menor primero
 *    
 *    Operaciones:
 *    - push(x): O(log n)
 *    - pop():   O(log n) 
 *    - top():   O(1)
 *    
 *    USOS: Dijkstra, K elementos más grandes/pequeños, mediana en stream
 * 
 * 4. DEQUE (DOUBLE-ENDED QUEUE) - Cola doble
 *    Puedes insertar/remover por ambos extremos en O(1).
 *    C++: #include <deque>
 *         std::deque<int> dq;
 *    
 *    Tiene push_front, push_back, pop_front, pop_back
 *    USOS: Sliding window maximum, implementar stack y queue a la vez
 */

#include <iostream>
#include <stack>
#include <queue>
#include <string>

int main() {
    // === EJEMPLO: Pila ===
    std::cout << "=== PILA (Stack) ===" << std::endl;
    std::stack<std::string> historial;
    historial.push("google.com");
    historial.push("github.com");
    historial.push("stackoverflow.com");
    
    std::cout << "Página actual: " << historial.top() << std::endl;
    historial.pop();  // "Atrás"
    std::cout << "Después de 'Atrás': " << historial.top() << std::endl;
    
    // === EJEMPLO: Cola ===
    std::cout << "\n=== COLA (Queue) ===" << std::endl;
    std::queue<std::string> turno;
    turno.push("Ana");
    turno.push("Carlos");
    turno.push("María");
    
    while (!turno.empty()) {
        std::cout << "Atendiendo a: " << turno.front() << std::endl;
        turno.pop();
    }
    
    // === EJEMPLO: Cola de Prioridad ===
    std::cout << "\n=== PRIORITY QUEUE ===" << std::endl;
    std::priority_queue<int> maxHeap;
    maxHeap.push(30);
    maxHeap.push(10);
    maxHeap.push(50);
    maxHeap.push(20);
    
    std::cout << "Sacando en orden de prioridad: ";
    while (!maxHeap.empty()) {
        std::cout << maxHeap.top() << " ";  // 50, 30, 20, 10
        maxHeap.pop();
    }
    std::cout << std::endl;
    
    return 0;
}
