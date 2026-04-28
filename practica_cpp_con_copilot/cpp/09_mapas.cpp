/*
 * TEMA 9: MAPAS (std::unordered_map)
 * 
 * TEORÍA COMPLETA:
 * 
 * 1. ¿QUÉ ES std::unordered_map?
 *    Es el equivalente de HashMap en Java: almacena pares clave-valor
 *    
 *    Java:  HashMap<String, Integer> mapa = new HashMap<>();
 *    C++:   std::unordered_map<std::string, int> mapa;
 *    
 *    IMPORTANTE: Necesitas #include <unordered_map>
 * 
 * 2. ¿POR QUÉ "unordered"?
 *    - std::map → Ordenado (árbol binario), O(log n)
 *    - std::unordered_map → No ordenado (tabla hash), O(1) promedio
 *    
 *    Para la mayoría de casos, usa unordered_map (como HashMap en Java)
 * 
 * 3. DECLARACIÓN:
 *    std::unordered_map<std::string, int> edades;
 *    std::unordered_map<int, std::string> nombres;
 *    std::unordered_map<std::string, std::vector<int>> listas;
 * 
 * 4. MÉTODOS PRINCIPALES (comparación con Java):
 * 
 *    Java (HashMap)                C++ (unordered_map)
 *    --------------                -------------------
 *    mapa.put(k, v)                mapa[k] = v  o  mapa.insert({k, v})
 *    mapa.get(k)                   mapa[k]  o  mapa.at(k)
 *    mapa.containsKey(k)           mapa.find(k) != mapa.end()  o  mapa.count(k)
 *    mapa.remove(k)                mapa.erase(k)
 *    mapa.size()                   mapa.size()
 *    mapa.isEmpty()                mapa.empty()
 *    mapa.clear()                  mapa.clear()
 * 
 * 5. INSERTAR ELEMENTOS:
 *    Forma 1: mapa["clave"] = valor;
 *    Forma 2: mapa.insert({"clave", valor});
 *    Forma 3: mapa.emplace("clave", valor);  // Más eficiente
 * 
 * 6. ACCESO A ELEMENTOS:
 *    mapa["clave"]     → Si no existe, LA CREA con valor por defecto
 *    mapa.at("clave")  → Si no existe, LANZA EXCEPCIÓN
 *    
 *    ¡CUIDADO! mapa["x"] crea la clave si no existe
 * 
 * 7. VERIFICAR SI EXISTE:
 *    Forma 1: if (mapa.find("clave") != mapa.end()) { ... }
 *    Forma 2: if (mapa.count("clave") > 0) { ... }
 * 
 * 8. ITERACIÓN:
 *    for (const auto& par : mapa) {
 *        std::cout << par.first << ": " << par.second << '\n';
 *    }
 *    
 *    - par.first  → la clave
 *    - par.second → el valor
 *    - const auto& para evitar copias
 * 
 * 9. CASOS DE USO COMUNES:
 *    - Contar frecuencias (palabras, caracteres, etc.)
 *    - Almacenar configuraciones (clave → valor)
 *    - Caché de resultados
 *    - Traducción/mapeo de IDs
 */

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

int main() {
    // ===== CREACIÓN E INSERCIÓN =====
    std::cout << "=== CREAR E INSERTAR ===" << '\n';
    
    std::unordered_map<std::string, int> edades;
    
    // Forma 1: operador []
    edades["Ana"] = 25;
    edades["Luis"] = 30;
    edades["María"] = 22;
    
    // Forma 2: insert
    edades.insert({"Carlos", 28});
    
    std::cout << "Edad de Ana: " << edades["Ana"] << '\n';
    std::cout << "Tamaño: " << edades.size() << '\n';
    
    // ===== VERIFICAR SI EXISTE =====
    std::cout << "\n=== VERIFICAR EXISTENCIA ===" << '\n';
    
    std::string buscar = "Luis";
    if (edades.find(buscar) != edades.end()) {
        std::cout << buscar << " existe, edad: " << edades[buscar] << '\n';
    } else {
        std::cout << buscar << " no existe" << '\n';
    }
    
    // Usando count()
    if (edades.count("Pedro") > 0) {
        std::cout << "Pedro existe" << '\n';
    } else {
        std::cout << "Pedro no existe" << '\n';
    }
    
    // ===== ITERACIÓN =====
    std::cout << "\n=== ITERAR ===" << '\n';
    std::cout << "Todas las edades:" << '\n';
    
    for (const auto& par : edades) {
        std::cout << "  " << par.first << ": " << par.second << " años" << '\n';
    }
    
    // ===== MODIFICAR VALORES =====
    std::cout << "\n=== MODIFICAR ===" << '\n';
    
    edades["Ana"] = 26;  // Incrementa edad
    std::cout << "Nueva edad de Ana: " << edades["Ana"] << '\n';
    
    // ===== ELIMINAR =====
    std::cout << "\n=== ELIMINAR ===" << '\n';
    
    edades.erase("Carlos");
    std::cout << "Después de eliminar a Carlos, tamaño: " << edades.size() << '\n';
    
    // ===== CONTAR FRECUENCIAS (CASO COMÚN) =====
    std::cout << "\n=== CONTAR FRECUENCIAS ===" << '\n';
    
    std::string texto = "hola mundo hola C++ mundo hola";
    std::unordered_map<std::string, int> frecuencias;
    
    // Simulamos split (en un ejemplo real usarías stringstream)
    std::vector<std::string> palabras = {"hola", "mundo", "hola", "C++", "mundo", "hola"};
    
    for (const std::string& palabra : palabras) {
        frecuencias[palabra]++;  // Si no existe, se crea con 0 y luego se incrementa
    }
    
    std::cout << "Frecuencia de palabras:" << '\n';
    for (const auto& par : frecuencias) {
        std::cout << "  " << par.first << ": " << par.second << " veces" << '\n';
    }
    
    // ===== MAPA CON DIFERENTES TIPOS =====
    std::cout << "\n=== DIFERENTES TIPOS ===" << '\n';
    
    // Mapa de int a string
    std::unordered_map<int, std::string> dias;
    dias[1] = "Lunes";
    dias[2] = "Martes";
    dias[3] = "Miércoles";
    
    std::cout << "Día 2: " << dias[2] << '\n';
    
    // Mapa de string a vector
    std::unordered_map<std::string, std::vector<int>> calificaciones;
    calificaciones["Ana"] = {90, 85, 92};
    calificaciones["Luis"] = {78, 88, 85};
    
    std::cout << "Calificaciones de Ana: ";
    for (int nota : calificaciones["Ana"]) {
        std::cout << nota << " ";
    }
    std::cout << '\n';
    
    // ===== BUSCAR Y ACCESO SEGURO =====
    std::cout << "\n=== ACCESO SEGURO ===" << '\n';
    
    // CUIDADO: usar [] crea la clave si no existe
    std::cout << "Antes de acceder a 'Pedro', tamaño: " << edades.size() << '\n';
    int edad = edades["Pedro"];  // ¡CREA a Pedro con edad 0!
    std::cout << "Después de edades['Pedro'], tamaño: " << edades.size() << '\n';
    std::cout << "Edad de Pedro: " << edad << '\n';
    
    // Forma segura: verificar primero
    if (edades.find("Juan") != edades.end()) {
        std::cout << "Juan: " << edades["Juan"] << '\n';
    } else {
        std::cout << "Juan no existe (y no lo creamos)" << '\n';
    }
    
    // ===== CLEAR =====
    std::cout << "\n=== LIMPIAR ===" << '\n';
    
    edades.clear();
    std::cout << "Después de clear(), tamaño: " << edades.size() << '\n';
    std::cout << "¿Está vacío? " << (edades.empty() ? "Sí" : "No") << '\n';
    
    return 0;
}

/*
 * COMPARACIÓN CON TU hashmap.java:
 * 
 * Si en Java hacías:
 * HashMap<String, Integer> mapa = new HashMap<>();
 * mapa.put("Ana", 25);
 * int edad = mapa.get("Ana");
 * if (mapa.containsKey("Luis")) { ... }
 * mapa.remove("Ana");
 * 
 * En C++:
 * std::unordered_map<std::string, int> mapa;
 * mapa["Ana"] = 25;  // o mapa.insert({"Ana", 25});
 * int edad = mapa["Ana"];  // o mapa.at("Ana")
 * if (mapa.find("Luis") != mapa.end()) { ... }
 * mapa.erase("Ana");
 * 
 * EJERCICIO TÍPICO: CONTADOR DE PALABRAS
 * En tus ejercicios de Java probablemente hiciste algo así.
 * Ahora lo harás en C++ con unordered_map.
 */

// Siguiente: 09a_ejercicio_contador_palabras.cpp
