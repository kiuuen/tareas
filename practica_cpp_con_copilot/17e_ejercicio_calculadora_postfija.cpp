/*
 * EJERCICIO 17E: Calculadora en notación postfija (RPN)
 * 
 * TAREA:
 * Evalúa expresiones en notación postfija (Reverse Polish Notation).
 * Los tokens están separados por espacios.
 * 
 * EJEMPLOS:
 * "2 1 + 3 *"          → 9   (= (2+1)*3)
 * "4 13 5 / +"         → 6   (= 4+(13/5))
 * "5 1 2 + 4 * + 3 -"  → 14
 */

// Tu código aquí
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <functional>
#include <sstream>
class RPN {
    private:
        std::stack<double> stack;
    public:
        template <typename Operator> // just research this, i fucking love it
        void toStack(Operator op) {
            double temp1 = 0.0;
            double temp2 = 0.0;
            if (!stack.empty()) {
                    temp1 = stack.top(); // the top is B (last) and the second last is A
                    stack.pop();
                    temp2 = op(stack.top(), temp1); // B - A, not A - B
                    stack.pop();
                    stack.push(temp2);

            } else {
                throw std::out_of_range("Invalid syntax");                 
            }
        }
        double calculate(std::string input) {
            std::istringstream iss(input);
            std::string elements;
            while (iss >> elements) {
                if (elements == "*") toStack(std::multiplies<double>());
                else if (elements == "+") toStack(std::plus<double>());
                else if (elements == "-") toStack(std::minus<double>());
                else if (elements == "/") toStack(std::divides<double>());
                else stack.push(std::stod(elements));
            }
            return stack.top();
        }
};
int main() {
    RPN RPN;
    std::string line;
    std::cout << "Enter the RPN text: " << std::endl;
    std::getline(std::cin, line);
    try {
        std::cout << "Result: " << RPN.calculate(line) << std::endl;
    } catch (std::out_of_range &e) {
        std::cerr << "Error, invalid syntax";
    }
    return 0;
};
