/*
 * TEMA 13: ARCHIVOS (FILE I/O)
 * 
 * TEORÍA COMPLETA:
 * 
 * 1. ¿CÓMO TRABAJAR CON ARCHIVOS EN C++?
 *    Usamos las clases de <fstream>:
 *    
 *    ifstream → Input File Stream (LEER archivos)
 *    ofstream → Output File Stream (ESCRIBIR archivos)
 *    fstream  → File Stream (LEER y ESCRIBIR)
 * 
 * 2. COMPARACIÓN CON JAVA:
 *    
 *    JAVA                                C++
 *    ----                                ---
 *    FileReader/BufferedReader           std::ifstream
 *    FileWriter/BufferedWriter           std::ofstream
 *    Scanner(new File(...))              std::ifstream + >>
 *    
 *    try {                               std::ifstream file("datos.txt");
 *        BufferedReader br = ...         if (!file.is_open()) {
 *    } catch (IOException e) {               // Error
 *    }                                   }
 * 
 * 3. ESCRIBIR EN UN ARCHIVO:
 *    
 *    #include <fstream>
 *    
 *    std::ofstream archivo("salida.txt");
 *    if (archivo.is_open()) {
 *        archivo << "Hola mundo\n";
 *        archivo << "Número: " << 42 << "\n";
 *        archivo.close();
 *    }
 * 
 * 4. LEER DE UN ARCHIVO:
 *    
 *    std::ifstream archivo("entrada.txt");
 *    if (archivo.is_open()) {
 *        std::string linea;
 *        while (std::getline(archivo, linea)) {
 *            std::cout << linea << "\n";
 *        }
 *        archivo.close();
 *    }
 * 
 * 5. MODOS DE APERTURA:
 *    
 *    std::ios::in      → Lectura (por defecto en ifstream)
 *    std::ios::out     → Escritura (por defecto en ofstream)
 *    std::ios::app     → Append (agregar al final)
 *    std::ios::trunc   → Truncar (borrar contenido existente)
 *    std::ios::binary  → Modo binario
 *    
 *    Ejemplo:
 *    std::ofstream archivo("log.txt", std::ios::app);  // Agregar al final
 * 
 * 6. LEER PALABRA POR PALABRA vs LÍNEA POR LÍNEA:
 *    
 *    // Palabra por palabra (separado por espacios)
 *    std::string palabra;
 *    while (archivo >> palabra) {
 *        std::cout << palabra << "\n";
 *    }
 *    
 *    // Línea por línea (incluye espacios)
 *    std::string linea;
 *    while (std::getline(archivo, linea)) {
 *        std::cout << linea << "\n";
 *    }
 * 
 * 7. VERIFICAR SI UN ARCHIVO SE ABRIÓ CORRECTAMENTE:
 *    
 *    std::ifstream archivo("datos.txt");
 *    if (!archivo.is_open()) {
 *        std::cerr << "Error: no se pudo abrir el archivo\n";
 *        return 1;
 *    }
 *    
 *    // Alternativa:
 *    if (!archivo) {
 *        std::cerr << "Error\n";
 *    }
 * 
 * 8. CERRAR ARCHIVOS:
 *    
 *    archivo.close();  // Cierra manualmente
 *    
 *    NOTA: Si no llamas a close(), se cierra automáticamente
 *    cuando el objeto sale del scope (RAII)
 * 
 * 9. LEER DATOS ESTRUCTURADOS:
 *    
 *    // Archivo: datos.txt
 *    // Juan 25 8.5
 *    // Ana 30 9.0
 *    
 *    std::string nombre;
 *    int edad;
 *    double calificacion;
 *    
 *    while (archivo >> nombre >> edad >> calificacion) {
 *        std::cout << nombre << " tiene " << edad << " años\n";
 *    }
 * 
 * 10. VERIFICAR FIN DE ARCHIVO Y ERRORES:
 *     
 *     if (archivo.eof()) {       // End of file
 *         std::cout << "Fin del archivo\n";
 *     }
 *     
 *     if (archivo.fail()) {      // Error de lectura/escritura
 *         std::cerr << "Error de I/O\n";
 *     }
 *     
 *     if (archivo.good()) {      // Todo OK
 *         // Continuar operaciones
 *     }
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

// ===== EJEMPLO 1: Escribir en un archivo =====
void ejemploEscribirArchivo() {
    std::cout << "=== EJEMPLO 1: Escribir en archivo ===\n";
    
    std::ofstream archivo("salida.txt");
    
    if (!archivo.is_open()) {
        std::cerr << "Error: no se pudo crear el archivo\n";
        return;
    }
    
    // Escribir diferentes tipos de datos
    archivo << "=== Mi Archivo de Prueba ===\n";
    archivo << "Autor: C++ Developer\n";
    archivo << "Fecha: 2026-02-13\n";
    archivo << "\n";
    archivo << "Números: " << 10 << ", " << 20 << ", " << 30 << "\n";
    archivo << "Valor de PI: " << std::fixed << std::setprecision(10) << 3.14159265359 << "\n";
    
    archivo.close();
    std::cout << "✓ Archivo 'salida.txt' creado exitosamente\n\n";
}

// ===== EJEMPLO 2: Leer de un archivo (línea por línea) =====
void ejemploLeerArchivo() {
    std::cout << "=== EJEMPLO 2: Leer archivo línea por línea ===\n";
    
    std::ifstream archivo("salida.txt");
    
    if (!archivo.is_open()) {
        std::cerr << "Error: no se pudo abrir el archivo\n";
        return;
    }
    
    std::string linea;
    int numeroLinea = 1;
    
    while (std::getline(archivo, linea)) {
        std::cout << numeroLinea << ": " << linea << "\n";
        numeroLinea++;
    }
    
    archivo.close();
    std::cout << "\n";
}

// ===== EJEMPLO 3: Agregar contenido (append) =====
void ejemploAgregarArchivo() {
    std::cout << "=== EJEMPLO 3: Agregar contenido al final ===\n";
    
    std::ofstream archivo("salida.txt", std::ios::app);  // Modo append
    
    if (!archivo.is_open()) {
        std::cerr << "Error: no se pudo abrir el archivo\n";
        return;
    }
    
    archivo << "\n=== CONTENIDO AGREGADO ===\n";
    archivo << "Esta línea se agregó después\n";
    archivo << "Timestamp: " << 1707812400 << "\n";
    
    archivo.close();
    std::cout << "✓ Contenido agregado a 'salida.txt'\n\n";
}

// ===== EJEMPLO 4: Escribir y leer datos estructurados =====
struct Estudiante {
    std::string nombre;
    int edad;
    double promedio;
};

void ejemploDatosEstructurados() {
    std::cout << "=== EJEMPLO 4: Datos estructurados ===\n";
    
    // Guardar estudiantes
    std::vector<Estudiante> estudiantes = {
        {"Ana", 20, 8.5},
        {"Carlos", 22, 9.0},
        {"María", 21, 8.8}
    };
    
    std::ofstream archivoSalida("estudiantes.txt");
    if (archivoSalida.is_open()) {
        archivoSalida << "# Nombre Edad Promedio\n";
        for (const auto& est : estudiantes) {
            archivoSalida << est.nombre << " " 
                         << est.edad << " " 
                         << est.promedio << "\n";
        }
        archivoSalida.close();
        std::cout << "✓ Estudiantes guardados en 'estudiantes.txt'\n";
    }
    
    // Leer estudiantes
    std::ifstream archivoEntrada("estudiantes.txt");
    if (archivoEntrada.is_open()) {
        std::string linea;
        std::getline(archivoEntrada, linea);  // Saltar encabezado
        
        std::cout << "\nEstudiantes leídos del archivo:\n";
        std::string nombre;
        int edad;
        double promedio;
        
        while (archivoEntrada >> nombre >> edad >> promedio) {
            std::cout << "  " << nombre << " - " << edad << " años - "
                      << "Promedio: " << promedio << "\n";
        }
        
        archivoEntrada.close();
    }
    std::cout << "\n";
}

// ===== EJEMPLO 5: Contar líneas, palabras y caracteres =====
void ejemploEstadisticasArchivo() {
    std::cout << "=== EJEMPLO 5: Estadísticas de archivo ===\n";
    
    std::ifstream archivo("salida.txt");
    
    if (!archivo.is_open()) {
        std::cerr << "Error: no se pudo abrir el archivo\n";
        return;
    }
    
    int lineas = 0;
    int palabras = 0;
    int caracteres = 0;
    
    std::string linea;
    while (std::getline(archivo, linea)) {
        lineas++;
        caracteres += linea.length();
        
        // Contar palabras en la línea
        std::string palabra;
        std::istringstream stream(linea);
        while (stream >> palabra) {
            palabras++;
        }
    }
    
    archivo.close();
    
    std::cout << "Estadísticas de 'salida.txt':\n";
    std::cout << "  Líneas: " << lineas << "\n";
    std::cout << "  Palabras: " << palabras << "\n";
    std::cout << "  Caracteres: " << caracteres << "\n\n";
}

// ===== EJEMPLO 6: Buscar texto en archivo =====
void ejemploBuscarEnArchivo() {
    std::cout << "=== EJEMPLO 6: Buscar texto en archivo ===\n";
    
    std::string buscar = "C++";
    std::ifstream archivo("salida.txt");
    
    if (!archivo.is_open()) {
        std::cerr << "Error: no se pudo abrir el archivo\n";
        return;
    }
    
    std::string linea;
    int numeroLinea = 1;
    int coincidencias = 0;
    
    std::cout << "Buscando '" << buscar << "' en el archivo:\n";
    while (std::getline(archivo, linea)) {
        if (linea.find(buscar) != std::string::npos) {
            std::cout << "  Línea " << numeroLinea << ": " << linea << "\n";
            coincidencias++;
        }
        numeroLinea++;
    }
    
    archivo.close();
    
    if (coincidencias == 0) {
        std::cout << "  No se encontraron coincidencias\n";
    } else {
        std::cout << "\nTotal de coincidencias: " << coincidencias << "\n";
    }
    std::cout << "\n";
}

int main() {
    std::cout << "╔════════════════════════════════════════╗\n";
    std::cout << "║     MANEJO DE ARCHIVOS EN C++         ║\n";
    std::cout << "╚════════════════════════════════════════╝\n\n";
    
    ejemploEscribirArchivo();
    ejemploLeerArchivo();
    ejemploAgregarArchivo();
    ejemploLeerArchivo();  // Leer de nuevo para ver el contenido agregado
    ejemploDatosEstructurados();
    ejemploEstadisticasArchivo();
    ejemploBuscarEnArchivo();
    
    std::cout << "=== FIN DEL PROGRAMA ===\n";
    std::cout << "Archivos creados: salida.txt, estudiantes.txt\n";
    
    return 0;
}

/*
 * CONCEPTOS CLAVE:
 * 
 * 1. CLASES PRINCIPALES:
 *    ifstream → leer
 *    ofstream → escribir
 *    fstream  → leer y escribir
 * 
 * 2. VERIFICAR APERTURA:
 *    if (!archivo.is_open()) { ... }
 * 
 * 3. LECTURA:
 *    archivo >> variable            // Palabra por palabra
 *    std::getline(archivo, linea)   // Línea por línea
 * 
 * 4. ESCRITURA:
 *    archivo << "texto" << variable << "\n";
 * 
 * 5. MODOS:
 *    std::ios::app    → agregar al final
 *    std::ios::trunc  → sobrescribir
 * 
 * 6. CIERRE AUTOMÁTICO:
 *    No es necesario close() (RAII), pero es buena práctica
 * 
 * 7. RUTAS DE ARCHIVOS:
 *    "archivo.txt"              → directorio actual
 *    "C:\\Users\\...\\file.txt" → ruta absoluta (Windows)
 *    "../datos/file.txt"        → ruta relativa
 * 
 * COMPARACIÓN CON JAVA:
 * 
 * Java es más verboso con try-catch:
 * try {
 *     FileWriter writer = new FileWriter("file.txt");
 *     writer.write("texto");
 *     writer.close();
 * } catch (IOException e) {
 *     e.printStackTrace();
 * }
 * 
 * C++ es más simple (sin checked exceptions):
 * std::ofstream archivo("file.txt");
 * if (archivo.is_open()) {
 *     archivo << "texto";
 * }
 */
