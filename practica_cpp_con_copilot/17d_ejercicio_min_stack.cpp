/*
 * EJERCICIO 17D: Min Stack (Estilo LeetCode #155)
 * 
 * TAREA:
 * Diseña una pila que soporte push, pop, top y getMin() en O(1).
 * getMin() debe devolver el mínimo actual de toda la pila.
 * 
 * EJEMPLO:
 * push(-2), push(0), push(-3)
 * getMin() → -3
 * pop()
 * top()    → 0
 * getMin() → -2  (¡sigue correcto después del pop!)
 */

// Tu código aquí
#include <iostream>
#include <vector>
#include <algorithm>

class stack {
    private:
        std::vector<int> stack;
        std::vector<int> mins;
    public:
        void push(int n) {
            if (stack.empty() || mins.back() > n) {
                mins.push_back(n);
            }
            stack.push_back(n);
        }
        void pop() {
            if (stack.empty()) {
                throw std::out_of_range("");
            }
            if (stack.back() == mins.back()) {
                mins.pop_back();
            }
            stack.pop_back();
        }
        int top(){
            if (stack.empty()) {
                throw std::out_of_range("");
            }
            return stack.back();
        }    
        int getMin() {
            if (stack.empty()) {
                throw std::out_of_range("");
            }
           return mins.back();
        }
};
int main() {
    try {
    stack stack;
    stack.push(-2);
    stack.push(0);
    stack.push(-3);
    std::cout << "min element: " << stack.getMin() << std::endl;
    stack.pop();
    std::cout << "top element: " << stack.top() << std::endl;
    std::cout << "min element: " << stack.getMin() << std::endl;
    } catch (std::out_of_range &e) {
        std::cerr << "error: stack was empty";
    }
    return 0;
};