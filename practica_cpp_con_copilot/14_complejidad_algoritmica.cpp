/*
 * TEMA 14: COMPLEJIDAD ALGORÍTMICA (Big O)
 * 
 * TEORÍA COMPLETA:
 * 
 * 1. ¿QUÉ ES LA COMPLEJIDAD ALGORÍTMICA?
 *    Es una forma de medir qué tan eficiente es un algoritmo.
 *    NO mide tiempo exacto, sino cómo CRECE el tiempo con el tamaño de entrada (n).
 *    
 *    Ejemplo: Si tienes un vector de 10 elementos vs uno de 1,000,000:
 *    - Un algoritmo O(n) tarda ~100,000x más
 *    - Un algoritmo O(n²) tarda ~10,000,000,000x más  ← MUCHO peor
 * 
 * 2. NOTACIÓN BIG O - DE MEJOR A PEOR:
 * 
 *    O(1)       → Constante     → Acceder a un índice de vector: v[5]
 *    O(log n)   → Logarítmico   → Búsqueda binaria
 *    O(n)       → Lineal        → Recorrer un vector una vez
 *    O(n log n) → Casi lineal   → Merge Sort, Quick Sort (promedio)
 *    O(n²)      → Cuadrático    → Bubble Sort, dos bucles anidados
 *    O(2^n)     → Exponencial   → Fibonacci recursivo sin memo
 *    O(n!)      → Factorial     → Generar todas las permutaciones
 * 
 * 3. ¿CÓMO CALCULAR LA COMPLEJIDAD?
 * 
 *    REGLA 1: Un bucle simple de 0 a n → O(n)
 *    for (int i = 0; i < n; i++) { ... }   // O(n)
 * 
 *    REGLA 2: Dos bucles anidados → O(n²)
 *    for (int i = 0; i < n; i++)
 *        for (int j = 0; j < n; j++) { ... }   // O(n²)
 * 
 *    REGLA 3: Dividir a la mitad cada paso → O(log n)
 *    while (n > 0) { n /= 2; }   // O(log n)
 * 
 *    REGLA 4: Se ignoran constantes y términos menores
 *    O(3n + 5) → O(n)
 *    O(n² + n) → O(n²)
 *    O(2 * n log n) → O(n log n)
 * 
 * 4. TABLA PRÁCTICA DE LÍMITES (para competencias):
 *    Dado que una computadora hace ~10^8 operaciones/segundo:
 *    
 *    n ≤ 10       → O(n!) o O(2^n)    → Fuerza bruta/backtracking
 *    n ≤ 20       → O(2^n)            → Subsets, bitmask
 *    n ≤ 500      → O(n³)             → Floyd-Warshall
 *    n ≤ 5,000    → O(n²)             → Bubble Sort, DP cuadrático
 *    n ≤ 1,000,000 → O(n log n)       → Merge Sort, Sort + Binary Search
 *    n ≤ 10^8     → O(n)              → Un solo recorrido
 *    n > 10^8     → O(log n) o O(1)   → Math, Binary Search
 * 
 * 5. COMPLEJIDAD DE ESPACIO:
 *    Además del tiempo, importa cuánta MEMORIA usa tu algoritmo.
 *    - O(1) espacio: solo usas variables sueltas
 *    - O(n) espacio: creas un vector del tamaño de la entrada
 *    - O(n²) espacio: creas una matriz n×n
 * 
 * 6. EJEMPLO: MISMO PROBLEMA, DIFERENTE COMPLEJIDAD
 * 
 *    Problema: ¿Hay dos números en el vector que sumen un target?
 *    
 *    Solución O(n²): Dos bucles anidados, comparar todos los pares
 *    Solución O(n):  Un unordered_map para buscar el complemento
 */

#include <iostream>
#include <vector>
#include <chrono>  // Para medir tiempo
#include <algorithm>

// === EJEMPLO O(1): Acceso directo ===
int accederElemento(const std::vector<int>& v, int indice) {
    return v[indice];  // Siempre tarda lo mismo, no importa el tamaño de v
}

// === EJEMPLO O(n): Recorrido lineal ===
int sumaVector(const std::vector<int>& v) {
    int suma = 0;
    for (int x : v) {   // Recorre n elementos → O(n)
        suma += x;
    }
    return suma;
}

// === EJEMPLO O(n²): Dos bucles anidados ===
bool tieneDuplicados_lento(const std::vector<int>& v) {
    for (size_t i = 0; i < v.size(); i++) {          // n veces
        for (size_t j = i + 1; j < v.size(); j++) {  // n veces (aprox)
            if (v[i] == v[j]) return true;            // → O(n²)
        }
    }
    return false;
}

// === EJEMPLO O(n log n): Ordenar y verificar vecinos ===
bool tieneDuplicados_rapido(std::vector<int> v) {  // Copia para no modificar original
    std::sort(v.begin(), v.end());                  // O(n log n)
    for (size_t i = 1; i < v.size(); i++) {         // O(n)
        if (v[i] == v[i-1]) return true;
    }
    return false;                                   // Total: O(n log n)
}

// === EJEMPLO O(log n): Búsqueda binaria ===
int busquedaBinaria(const std::vector<int>& v, int target) {
    int izq = 0, der = static_cast<int>(v.size()) - 1;
    while (izq <= der) {
        int mid = izq + (der - izq) / 2;  // Evita overflow
        if (v[mid] == target) return mid;
        else if (v[mid] < target) izq = mid + 1;
        else der = mid - 1;
    }
    return -1;  // No encontrado
}

int main() {
    // Crear un vector grande para demostrar la diferencia
    const int N = 50000;
    std::vector<int> datos(N);
    for (int i = 0; i < N; i++) {
        datos[i] = i * 2;  // Números pares del 0 al 99998
    }

    std::cout << "=== DEMOSTRACIÓN DE COMPLEJIDAD ===" << std::endl;
    std::cout << "Tamaño del vector: " << N << " elementos\n" << std::endl;

    // Medir O(1)
    auto inicio = std::chrono::high_resolution_clock::now();
    int val = accederElemento(datos, N/2);
    auto fin = std::chrono::high_resolution_clock::now();
    auto duracion = std::chrono::duration_cast<std::chrono::nanoseconds>(fin - inicio);
    std::cout << "O(1)  - Acceso directo: " << duracion.count() << " ns (valor: " << val << ")" << std::endl;

    // Medir O(n) 
    inicio = std::chrono::high_resolution_clock::now();
    int suma = sumaVector(datos);
    fin = std::chrono::high_resolution_clock::now();
    duracion = std::chrono::duration_cast<std::chrono::nanoseconds>(fin - inicio);
    std::cout << "O(n)  - Suma vector:    " << duracion.count() << " ns (suma: " << suma << ")" << std::endl;

    // Medir O(n²)
    inicio = std::chrono::high_resolution_clock::now();
    bool dup1 = tieneDuplicados_lento(datos);
    fin = std::chrono::high_resolution_clock::now();
    duracion = std::chrono::duration_cast<std::chrono::milliseconds>(fin - inicio);
    std::cout << "O(n²) - Duplicados lento: " << duracion.count() << " ms (tiene dup: " << dup1 << ")" << std::endl;

    // Medir O(n log n)
    inicio = std::chrono::high_resolution_clock::now();
    bool dup2 = tieneDuplicados_rapido(datos);
    fin = std::chrono::high_resolution_clock::now();
    duracion = std::chrono::duration_cast<std::chrono::milliseconds>(fin - inicio);
    std::cout << "O(nlogn) - Duplicados rápido: " << duracion.count() << " ms (tiene dup: " << dup2 << ")" << std::endl;

    // Medir O(log n) - búsqueda binaria
    std::vector<int> ordenado = datos;  // Ya está ordenado
    inicio = std::chrono::high_resolution_clock::now();
    int pos = busquedaBinaria(ordenado, 48888);
    fin = std::chrono::high_resolution_clock::now();
    duracion = std::chrono::duration_cast<std::chrono::nanoseconds>(fin - inicio);
    std::cout << "O(logn) - Búsqueda binaria: " << duracion.count() << " ns (pos: " << pos << ")" << std::endl;

    std::cout << "\n=== CONCLUSIÓN ===" << std::endl;
    std::cout << "Nota cómo O(n²) tarda MUCHO más que O(n log n) para el mismo problema." << std::endl;
    std::cout << "En competencias, elegir el algoritmo correcto es LA diferencia." << std::endl;

    return 0;
}
