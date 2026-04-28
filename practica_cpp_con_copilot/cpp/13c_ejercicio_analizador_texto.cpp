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
#include <cmath>

int main() {
    std::string palabraLarga;
    int numChar = 0;
    std::vector<std::pair<std::string, int>> vectorPalabrasClave;
    std::ifstream leerArchivo("intro.txt");
    std::string lineasTemp;
    int numLineas = 0;
    std::vector<std::string> vectorPalabras;
    std::string textoRaw;
    std::unordered_map<std::string, int> palabras;
    if (leerArchivo.is_open()) {
        while (std::getline(leerArchivo, lineasTemp)) {
            textoRaw.append(lineasTemp + "\n");
            numLineas++;
        }
    }  
    leerArchivo.close();
    std::istringstream iss(textoRaw);
    while (iss >> textoRaw) {
        vectorPalabras.push_back(textoRaw);
    }
    if (!vectorPalabras.empty()){
    palabraLarga = vectorPalabras[0];
    }
    for (const std::string& s : vectorPalabras) {
        palabras[s]++; // agrego la palabara al hashmap, no uso .at para que la cree si no hay un valor ya con esa palabra
        // si lo hay, lo aumenta y no la repite (entonces cuenta)
        numChar += static_cast<int>(s.length());
        if (s.length() > palabraLarga.length()) {
            palabraLarga = s;
            }
        }
    vectorPalabrasClave.reserve(palabras.size());
    for (const auto& a : palabras) {
        vectorPalabrasClave.emplace_back(a.first, a.second);
    }
    std::sort(vectorPalabrasClave.begin(), vectorPalabrasClave.end(), 
        [](const auto &a, const auto &b) {
        if (a.second != b.second) {
            return a.second > b.second; // primero ordena por tamaño
        }
            return a.first < b.first; // luego ordena alfabeticamente en caso de empatar
        });
    std::string textoTop;
    for (size_t n = 0; n < std::min(vectorPalabrasClave.size(), static_cast<size_t>(5)); n++) {
        textoTop.append("\n'" + vectorPalabrasClave[n].first + "' aparece: " + std::to_string(vectorPalabrasClave[n].second) + " veces"); 
    }
    std::ofstream escribirArchivo("reporte.txt");
    if (escribirArchivo.is_open()) {
        escribirArchivo << "Analisis del archivo 'intro.txt'"
        << "\nLineas: " << numLineas
        << "\nPalabras: " << vectorPalabras.size()
        << "\nCaracteres (total): " << numChar + (pow(numLineas, 2))
        << "\nCaracteres (sin espacios): " << numChar
        << "\n5 palabras mas frecuentes: " << textoTop;
    }
    escribirArchivo.close();
    std::cout << "Se termino el analisis y su reporte en: 'reporte.txt'" << std::endl;
    return 0;
}
