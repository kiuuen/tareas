/*
 * EJERCICIO 17A: Implementar pila con vector
 * 
 * TAREA:
 * Implementa una clase MiPila usando un std::vector internamente.
 * NO uses std::stack.
 * Métodos requeridos: push, pop, top, empty, size, mostrar.
 * Maneja el caso de pop/top sobre pila vacía.
 * 
 * EJEMPLO DE SALIDA:
 * Push: 10, 20, 30
 * Pila (tope → base): 30 20 10
 * Top: 30
 * Pop!
 * Top: 20
 * Size: 2
 */

// Tu código aquí

#include <iostream>
#include <vector>
#include <algorithm>
/*- opciones en una pila:
        push(x): agregar al tope
 *    - pop():   remover del tope
 *    - top():   ver el tope sin remover
 *    - empty(): ¿está vacía?
 *    - size():  cuántos elementos tiene*/
class miPila {
    private:
        std::vector<int> pila;
    public:
        void push(const int x) {
            std::cout << "\nPush: " << x;
            pila.push_back(x);
        }
        void pop() {
            if (!pila.empty()) {
                std::cout << "\nPopeando el ultimo elemento de la pila: " << pila.back();
                pila.pop_back();
            } else {
                std::cout << "\nError, la pila esta vacia" << std::endl;
            }

        }
        int top() {
            if (!pila.empty()) {
                return pila.back();
            }
            else {
                std::cout << "\nError, la pila esta vacia" << std::endl;
                return 0;
            }
        }
        int size() {
            return static_cast<int>(pila.size() - 1);
        }
        bool empty() {
            return pila.empty();
        }
    miPila(std::vector<int> pilaW = {0}) : pila(pilaW){};
};
int main() {
    miPila pila;
    pila.push(3);
    pila.push(5);
    pila.push(7);
    std::cout << "\nEl tamano de la pila es de: " << pila.size() << std::endl;
    pila.size();
    pila.pop();
    std::cout << "\nEl ultimo elemento de la pila ahora es: " << pila.top()  << std::endl;
    std::cout << "La pila " << (pila.empty() ? " esta vacia" : " no esta vacia") << std::endl;
    std::cout << "El tamano de la pila es de: " << pila.size() << std::endl;
}