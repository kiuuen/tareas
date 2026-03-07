/*
 * EJERCICIO 17E: Calculadora postfija (Notación Polaca Inversa)
 * 
 * TAREA:
 * Evalúa una expresión en notación postfija (Reverse Polish Notation).
 * En RPN, los operadores van DESPUÉS de los operandos.
 * 
 * Ejemplo: "3 4 +" significa 3 + 4 = 7
 * Ejemplo: "3 4 + 2 *" significa (3 + 4) * 2 = 14
 * 
 * Algoritmo con PILA:
 * - Lee token por token (separados por espacio):
 *   * Si es número: push a la pila
 *   * Si es operador (+, -, *, /):
 *     - Pop dos valores: b = top (pop), a = top (pop)
 *     - Calcula: resultado = a operador b
 *     - Push resultado
 * - Al final, el resultado está en el tope de la pila
 * 
 * Crea una función int evaluarRPN(string expresion):
 *   - Usa istringstream para separar tokens por espacio
 *   - Usa una pila de enteros
 *   - CUIDADO con el orden: primero sacas b, luego a → a op b
 * 
 * EJEMPLO:
 * "2 1 + 3 *"       → ((2 + 1) * 3) = 9
 * "4 13 5 / +"      → (4 + (13 / 5)) = 4 + 2 = 6
 * "5 1 2 + 4 * + 3 -" → (5 + ((1 + 2) * 4)) - 3 = 14
 * 
 * PRUEBA tu calculadora con estas expresiones y verifica los resultados.
 * 
 * PISTA:
 * - Para verificar si un token es operador: token == "+" || token == "-" etc
 * - Para convertir string a int: std::stoi(token)
 * - La división es entera (trunca hacia cero)
 */

// Tu código aquí
