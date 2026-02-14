/*
 * EJERCICIO 13C: Analizador de archivo de texto
 * 
 * TAREA:
 * Crea un programa que analice un archivo de texto y genere estadísticas:
 * 
 * 1. Lee un archivo llamado "texto.txt" (créalo manualmente con contenido)
 * 2. Calcula y muestra:
 *    - Número de líneas
 *    - Número de palabras
 *    - Número de caracteres (con y sin espacios)
 *    - Palabra más larga
 *    - Frecuencia de cada palabra (top 5)
 * 3. Genera un reporte en "reporte.txt" con las estadísticas
 * 
 * PISTAS:
 * - Usa std::getline() para contar líneas
 * - Usa std::istringstream para separar palabras
 * - Usa std::unordered_map<string, int> para frecuencias
 * - Para top 5: copia el map a un vector y ordena
 * 
 * EJEMPLO texto.txt:
 * Hola mundo desde C++
 * Este es un ejemplo de archivo
 * C++ es genial
 * 
 * SALIDA ESPERADA:
 * === ANÁLISIS DE ARCHIVO ===
 * Archivo: texto.txt
 * 
 * Líneas: 3
 * Palabras: 12
 * Caracteres (total): 58
 * Caracteres (sin espacios): 47
 * Palabra más larga: "ejemplo" (7 letras)
 * 
 * Top 5 palabras más frecuentes:
 * 1. "C++" - 2 veces
 * 2. "es" - 2 veces
 * 3. "Hola" - 1 vez
 * 4. "mundo" - 1 vez
 * 5. "desde" - 1 vez
 * 
 * ✓ Reporte guardado en 'reporte.txt'
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <algorithm>

int main() {
    
    
    
    
    return 0;
}
