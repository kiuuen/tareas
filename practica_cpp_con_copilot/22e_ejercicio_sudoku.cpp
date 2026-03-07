/*
 * EJERCICIO 22E: Resolver Sudoku (Backtracking)
 * 
 * TAREA:
 * Escribe un programa que resuelva un Sudoku 9×9 usando backtracking.
 * 
 * Reglas del Sudoku:
 * - Cada fila debe tener los dígitos 1-9 sin repetir
 * - Cada columna debe tener los dígitos 1-9 sin repetir
 * - Cada subcuadro 3×3 debe tener los dígitos 1-9 sin repetir
 * 
 * Algoritmo:
 * 1. Encuentra la siguiente celda vacía (valor 0)
 * 2. Prueba números del 1 al 9
 * 3. Si el número es válido (no viola reglas) → colócalo y avanza
 * 4. Si ningún número funciona → retrocede (backtrack)
 * 5. Si no hay celdas vacías → ¡resuelto!
 * 
 * Función bool esValido(tablero, fila, col, num):
 *   - ¿num ya está en la misma fila?
 *   - ¿num ya está en la misma columna?
 *   - ¿num ya está en el mismo subcuadro 3×3?
 *   (Para el subcuadro: inicio_fila = fila - fila%3, inicio_col = col - col%3)
 * 
 * Función bool resolver(tablero):
 *   - Busca celda vacía. Si no hay → return true (resuelto)
 *   - Para num=1 a 9:
 *     * Si esValido(tablero, fila, col, num):
 *       tablero[fila][col] = num     // HACER
 *       Si resolver(tablero) → return true   // EXPLORAR
 *       tablero[fila][col] = 0       // DESHACER (backtrack)
 *   - return false (ningún número funcionó)
 * 
 * TABLERO DE PRUEBA (0 = vacío):
 * 5 3 0 | 0 7 0 | 0 0 0
 * 6 0 0 | 1 9 5 | 0 0 0
 * 0 9 8 | 0 0 0 | 0 6 0
 * ------+-------+------
 * 8 0 0 | 0 6 0 | 0 0 3
 * 4 0 0 | 8 0 3 | 0 0 1
 * 7 0 0 | 0 2 0 | 0 0 6
 * ------+-------+------
 * 0 6 0 | 0 0 0 | 2 8 0
 * 0 0 0 | 4 1 9 | 0 0 5
 * 0 0 0 | 0 8 0 | 0 7 9
 * 
 * EJEMPLO DE SALIDA:
 * Sudoku original:
 * 5 3 . | . 7 . | . . .
 * 6 . . | 1 9 5 | . . .
 * . 9 8 | . . . | . 6 .
 * ------+-------+------
 * ...
 * 
 * Sudoku resuelto:
 * 5 3 4 | 6 7 8 | 9 1 2
 * 6 7 2 | 1 9 5 | 3 4 8
 * 1 9 8 | 3 4 2 | 5 6 7
 * ------+-------+------
 * 8 5 9 | 7 6 1 | 4 2 3
 * 4 2 6 | 8 5 3 | 7 9 1
 * 7 1 3 | 9 2 4 | 8 5 6
 * ------+-------+------
 * 9 6 1 | 5 3 7 | 2 8 4
 * 2 8 7 | 4 1 9 | 6 3 5
 * 3 4 5 | 2 8 6 | 1 7 9
 * 
 * PISTA:
 * - Usa int tablero[9][9] o vector<vector<int>>
 * - El subcuadro de (fila, col) empieza en (fila/3*3, col/3*3)
 */

// Tu código aquí
