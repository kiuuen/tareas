/*
 * EJERCICIO 17C: Implementar cola con dos pilas (Estilo LeetCode #232)
 * 
 * TAREA:
 * Implementa una cola FIFO usando ÚNICAMENTE dos pilas (LIFO).
 * Métodos: push (encolar), front (ver frente), pop (desencolar), empty.
 * 
 * EJEMPLO DE SALIDA:
 * push(1), push(2), push(3)
 * front() → 1
 * pop()
 * front() → 2
 * push(4)
 * front() → 2
 * pop(), pop()
 * front() → 4
 */

// Tu código aquí

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

class queueFIFO {
    private:
        std::stack<int> stack1;
        std::stack<int> stack2;
        // i think the idea is using the second stack as a inverse mirror of the stack
        /* input 1 2 3
        stack1 = 1 2 3
        stack 2 = 3
        */
    public:
        void STQ() { // "Stack To Queue"
            if (stack2.empty()) { // so no extra calls
                while (!stack1.empty()) {
                    stack2.push(stack1.top());
                    stack1.pop();
                }
            }
        }
        void push(int n) {
            stack1.push(n);
            std::cout << n << " was added" << std::endl;
        }
        int front() {
            if (stack1.empty() && stack2.empty()) {
                throw std::out_of_range("there is no elements in the queue");
            }
            STQ();
            return stack2.top();
        }
        void pop() {
            if (stack1.empty() && stack2.empty()) {
                throw std::out_of_range("there is no elements in the queue");
            }
            std::cout << "the front item was deleted" << std::endl;
            stack2.pop();
        }
        bool empty() {
            return (stack2.empty() && stack1.empty());
        }
};
int main() {
    queueFIFO queue;
    try {
        queue.push(1);
        queue.push(2);
        queue.push(3);
        std::cout << "Front: " << queue.front() << std::endl;
        queue.pop();
        std::cout << "Front: " << queue.front() << std::endl;
        std::cout << (queue.empty() ? "Queue empty" : "Queue not empty") << std::endl;
        queue.pop();
        queue.pop();
        std::cout << (queue.empty() ? "Queue empty" : "Queue not empty") << std::endl;
        queue.pop();
    } catch (std::out_of_range &e) {
        std::cerr << "Error: no elements";
    }
    return 0;
}