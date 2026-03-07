/*
 * EJERCICIO 24E: Merge Intervals (LeetCode #56 style)
 * 
 * TAREA:
 * Dado un array de intervalos [inicio, fin], fusiona todos los 
 * intervalos que se solapan.
 * 
 * Dos intervalos se solapan si: a.inicio <= b.fin AND b.inicio <= a.fin
 * Ejemplo: [1,3] y [2,6] se solapan → se fusionan en [1,6]
 * 
 * ALGORITMO:
 * 1. Ordena los intervalos por inicio
 * 2. Recorre: si el intervalo actual se solapa con el anterior 
 *    → extiende el anterior (max de fines)
 * 3. Si no se solapa → agrega uno nuevo
 * 
 * EJEMPLOS:
 * Input:  [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explicación: [1,3] y [2,6] se solapan → [1,6]
 * 
 * Input:  [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explicación: [1,4] y [4,5] se tocan → se fusionan
 * 
 * Input:  [[1,4],[0,4]]
 * Output: [[0,4]]
 * 
 * Input:  [[1,4],[2,3]]
 * Output: [[1,4]]
 * Explicación: [2,3] está completamente dentro de [1,4]
 * 
 * EJEMPLO DE SALIDA:
 * Intervalos originales: [1,3] [2,6] [8,10] [15,18]
 * Ordenados:             [1,3] [2,6] [8,10] [15,18]
 * 
 * Proceso:
 * [1,3] → inicio de resultado
 * [2,6] → se solapa con [1,3] → fusionar → [1,6]
 * [8,10] → no se solapa → agregar
 * [15,18] → no se solapa → agregar
 * 
 * Resultado: [1,6] [8,10] [15,18]
 * 
 * PISTA:
 * - Usa vector<pair<int,int>> o vector<vector<int>>
 * - Después de ordenar, solo necesitas comparar con el ÚLTIMO intervalo del resultado
 * - resultado.back().second = max(resultado.back().second, actual.second)
 */

// Tu código aquí
