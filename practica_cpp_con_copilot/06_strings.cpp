/*
 * TEMA 6: STRINGS EN C++
 * 
 * TEORÍA COMPLETA:
 * 
 * 1. DIFERENCIA CON JAVA:
 *    Java: String es una clase, siempre usas métodos
 *    C++: std::string es una clase de la biblioteca estándar
 *    
 *    IMPORTANTE: Necesitas #include <string>
 * 
 * 2. CREACIÓN:
 *    std::string s1 = "Hola";
 *    std::string s2("Mundo");
 *    std::string s3;              // String vacío
 *    auto s4 = "Auto";            // Deduce std::string? NO! Es const char*
 *    std::string s5 = "Correcto"; // Usa esto
 * 
 * 3. MÉTODOS PRINCIPALES (comparación con Java):
 * 
 *    Java                          C++
 *    ----                          ---
 *    s.length()                    s.length() o s.size()
 *    s.charAt(i)                   s[i] o s.at(i)
 *    s.substring(inicio, fin)      s.substr(inicio, longitud)  ← CUIDADO: 2º param es longitud
 *    s.indexOf("texto")            s.find("texto")
 *    s.isEmpty()                   s.empty()
 *    s.toLowerCase()               NO EXISTE directamente (usar <algorithm>)
 *    s.toUpperCase()               NO EXISTE directamente (usar <algorithm>)
 *    s1.equals(s2)                 s1 == s2  (operador ==)
 *    s1 + s2                       s1 + s2  (operador +)
 * 
 * 4. CONVERSIONES:
 *    String a int:     int n = std::stoi("123");
 *    String a double:  double d = std::stod("3.14");
 *    Int a String:     std::string s = std::to_string(123);
 * 
 * 5. ACCESO A CARACTERES:
 *    s[i]      → Acceso directo (NO verifica límites, más rápido pero peligroso)
 *    s.at(i)   → Acceso seguro (lanza excepción si i está fuera de rango)
 * 
 * 6. COMPARACIÓN:
 *    s1 == s2     → Igualdad
 *    s1 != s2     → Desigualdad
 *    s1 < s2      → Orden lexicográfico
 * 
 * 7. MODIFICACIÓN:
 *    s.push_back('x')     → Añade carácter al final
 *    s.pop_back()         → Elimina último carácter
 *    s.append("texto")    → Concatena
 *    s.insert(pos, "txt") → Inserta en posición
 *    s.erase(pos, len)    → Elimina caracteres
 *    s.clear()            → Vacía el string
 */

#include <iostream>
#include <string>
#include <algorithm>  // Para transform, tolower, toupper

int main() {
    // ===== CREACIÓN =====
    std::cout << "=== CREACIÓN ===" << '\n';
    
    std::string s1 = "Hola";
    std::string s2 = "Mundo";
    std::string s3 = s1 + " " + s2;  // Concatenación
    
    std::cout << s3 << '\n';
    
    // ===== LONGITUD =====
    std::cout << "\n=== LONGITUD ===" << '\n';
    std::cout << "Longitud de '" << s1 << "': " << s1.length() << '\n';
    std::cout << "¿Está vacío? " << (s1.empty() ? "Sí" : "No") << '\n';
    
    // ===== ACCESO A CARACTERES =====
    std::cout << "\n=== ACCESO A CARACTERES ===" << '\n';
    std::string palabra = "Programar";
    
    std::cout << "Primera letra: " << palabra[0] << '\n';
    std::cout << "Última letra: " << palabra[palabra.length() - 1] << '\n';
    
    // Recorrer carácter por carácter
    std::cout << "Caracteres: ";
    for (size_t i = 0; i < palabra.length(); i++) {
        std::cout << palabra[i] << " ";
    }
    std::cout << '\n';
    
    // Range-based for (más limpio)
    std::cout << "Caracteres (v2): ";
    for (char c : palabra) {
        std::cout << c << " ";
    }
    std::cout << '\n';
    
    // ===== SUBSTRING =====
    std::cout << "\n=== SUBSTRING ===" << '\n';
    std::string texto = "Hola Mundo";
    
    // substr(inicio, longitud)  ← CUIDADO: en Java es (inicio, fin)
    std::string sub1 = texto.substr(0, 4);   // "Hola"
    std::string sub2 = texto.substr(5);      // "Mundo" (del 5 hasta el final)
    
    std::cout << "Original: " << texto << '\n';
    std::cout << "substr(0, 4): " << sub1 << '\n';
    std::cout << "substr(5): " << sub2 << '\n';
    
    // ===== BÚSQUEDA =====
    std::cout << "\n=== BÚSQUEDA ===" << '\n';
    std::string frase = "C++ es genial";
    
    size_t pos = frase.find("es");
    if (pos != std::string::npos) {  // npos = "no encontrado"
        std::cout << "'es' encontrado en posición: " << pos << '\n';
    }
    
    // ===== COMPARACIÓN =====
    std::cout << "\n=== COMPARACIÓN ===" << '\n';
    std::string a = "hola";
    std::string b = "hola";
    std::string c = "Hola";
    
    std::cout << "a == b: " << (a == b) << '\n';  // 1 (true)
    std::cout << "a == c: " << (a == c) << '\n';  // 0 (false, case-sensitive)
    
    // ===== MODIFICACIÓN =====
    std::cout << "\n=== MODIFICACIÓN ===" << '\n';
    std::string nombre = "Ana";
    
    nombre.push_back('!');           // "Ana!"
    std::cout << "Después de push_back: " << nombre << '\n';
    
    nombre.append(" García");        // "Ana! García"
    std::cout << "Después de append: " << nombre << '\n';
    
    // ===== CONVERSIONES =====
    std::cout << "\n=== CONVERSIONES ===" << '\n';
    
    // String a número
    std::string numStr = "123";
    int numero = std::stoi(numStr);
    std::cout << "String '123' a int: " << numero << '\n';
    
    std::string piStr = "3.14159";
    double pi = std::stod(piStr);
    std::cout << "String '3.14159' a double: " << pi << '\n';
    
    // Número a string
    int valor = 456;
    std::string valorStr = std::to_string(valor);
    std::cout << "Int 456 a string: '" << valorStr << "'" << '\n';
    
    // ===== MAYÚSCULAS/MINÚSCULAS =====
    std::cout << "\n=== MAYÚSCULAS/MINÚSCULAS ===" << '\n';
    std::string original = "HoLa MuNdO";
    std::string minusculas = original;
    std::string mayusculas = original;
    
    // Convertir a minúsculas
    std::transform(minusculas.begin(), minusculas.end(), minusculas.begin(),
                   [](unsigned char c){ return std::tolower(c); });
    
    // Convertir a mayúsculas
    std::transform(mayusculas.begin(), mayusculas.end(), mayusculas.begin(),
                   [](unsigned char c){ return std::toupper(c); });
    
    std::cout << "Original: " << original << '\n';
    std::cout << "Minúsculas: " << minusculas << '\n';
    std::cout << "Mayúsculas: " << mayusculas << '\n';
    
    return 0;
}

// Siguiente: 06a_ejercicio_contar_vocales.cpp
