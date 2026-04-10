/*
 * EJERCICIO 17B: Paréntesis válidos (Estilo LeetCode #20)
 * 
 * TAREA:
 * Dada una cadena con solo '(', ')', '{', '}', '[', ']',
 * determina si los paréntesis están correctamente balanceados.
 * 
 * EJEMPLOS:
 * "()"       → true
 * "()[]{}"   → true
 * "(]"       → false
 * "([)]"     → false
 * "{[]}"     → true
 * "((("      → false
 */

// Tu código aquí
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <sstream>

bool pilaParentesis(std::string cadena) {
    std::stack<std::string> pila;
    std::istringstream iss(cadena);
    std::vector<std::string> chars;
    std::string palabras;
    while (iss >> palabras) {
        chars.push_back(palabras);
    }
    for (std::string s : chars) {
        if (s == "(" || s == "{" || s == "[") {
            pila.push(s);
            std::cout << "\nSe agrego " << s << " a la pila" << std::endl;
        } else {
            if (!pila.empty()) {
                pila.pop();
                std::cout << "\nSe elimino " << s << "  la pila" << std::endl;
            }
        }
    }
    return pila.empty();
}
int main() {
    std::string cadena;
    std::cout << "Introduce una cadena de parentesis: " << std::endl;
    std::getline(std::cin, cadena);
    std::cout << "La cadena" << (pilaParentesis(cadena) ? " esta balanceada" : " no esta balanceada")  << std::endl;
}