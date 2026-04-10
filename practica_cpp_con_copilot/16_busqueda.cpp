/*
 * TEMA 16: ALGORITMOS DE BÚSQUEDA
 * 
 * TEORÍA COMPLETA:
 * 
 * 1. BÚSQUEDA LINEAL - O(n)
 *    Recorres elemento por elemento hasta encontrar el target.
 *    Funciona en CUALQUIER vector (ordenado o no).
 *    
 *    for (int i = 0; i < n; i++)
 *        if (v[i] == target) return i;
 *    return -1;
 * 
 * 2. BÚSQUEDA BINARIA - O(log n)
 *    SOLO funciona en vectores ORDENADOS.
 *    Divide el espacio de búsqueda a la mitad cada iteración.
 *    
 *    Ejemplo: Buscar 7 en [1, 3, 5, 7, 9, 11, 13]
 *    - izq=0, der=6, mid=3 → v[3]=7     → ¡ENCONTRADO!
 *    
 *    Ejemplo: Buscar 9 en [1, 3, 5, 7, 9, 11, 13]
 *    - izq=0, der=6, mid=3 → v[3]=7 < 9 → izq=4
 *    - izq=4, der=6, mid=5 → v[5]=11 > 9 → der=4
 *    - izq=4, der=4, mid=4 → v[4]=9 → ¡ENCONTRADO!
 * 
 *    ¿POR QUÉ ES TAN RÁPIDA?
 *    - Vector de 1,000 elementos → ~10 comparaciones
 *    - Vector de 1,000,000 → ~20 comparaciones
 *    - Vector de 1,000,000,000 → ~30 comparaciones
 *    log2(1,000,000,000) ≈ 30
 * 
 * 3. VARIANTES DE BÚSQUEDA BINARIA:
 *    - Encontrar la PRIMERA ocurrencia de un valor
 *    - Encontrar la ÚLTIMA ocurrencia de un valor
 *    - lower_bound: primer elemento >= target
 *    - upper_bound: primer elemento > target
 *    - Buscar en un espacio de respuestas (binary search on answer)
 * 
 * 4. PATRÓN GENERAL DE BÚSQUEDA BINARIA:
 *    int izq = 0, der = n - 1;
 *    while (izq <= der) {
 *        int mid = izq + (der - izq) / 2;  // Evita overflow vs (izq+der)/2
 *        if (condicion(mid)) {
 *            // Ajustar izq o der según lo que busques
 *        }
 *    }
 * 
 * 5. CUÁNDO USAR BÚSQUEDA BINARIA:
 *    ✓ El vector está ordenado
 *    ✓ Puedes descartar la mitad del espacio en cada paso
 *    ✓ Buscas un valor o una condición que "cambia" de false a true
 *    ✗ El vector NO está ordenado → usa búsqueda lineal o ordena primero
 * 
 * C++ STL tiene:
 *    std::binary_search(v.begin(), v.end(), target)  → bool
 *    std::lower_bound(v.begin(), v.end(), target)    → iterador
 *    std::upper_bound(v.begin(), v.end(), target)    → iterador
 */

#include <iostream>
#include <vector>
#include <algorithm>

// Búsqueda binaria básica
int busquedaBinaria(const std::vector<int>& v, int target) {
    int izq = 0, der = static_cast<int>(v.size()) - 1;
    while (izq <= der) {
        int mid = izq + (der - izq) / 2;
        if (v[mid] == target) return mid;
        else if (v[mid] < target) izq = mid + 1;
        else der = mid - 1;
    }
    return -1;
}

// Lower bound: primer índice donde v[i] >= target
int lowerBound(const std::vector<int>& v, int target) {
    int izq = 0, der = static_cast<int>(v.size());
    while (izq < der) {
        int mid = izq + (der - izq) / 2;
        if (v[mid] < target) izq = mid + 1;
        else der = mid;
    }
    return izq;
}

int main() {
    std::vector<int> v = {1, 3, 5, 7, 7, 7, 9, 11, 13};
    
    std::cout << "Vector: ";
    for (int x : v) std::cout << x << " ";
    std::cout << std::endl;
    
    // Búsqueda binaria básica
    int pos = busquedaBinaria(v, 7);
    std::cout << "Buscar 7: encontrado en índice " << pos << std::endl;
    
    // Lower bound (primera ocurrencia de 7)
    int lb = lowerBound(v, 7);
    std::cout << "Lower bound de 7: índice " << lb << " (valor: " << v[lb] << ")" << std::endl;
    
    // Usando STL
    auto it = std::lower_bound(v.begin(), v.end(), 7);
    std::cout << "STL lower_bound de 7: índice " << (it - v.begin()) << std::endl;
    
    bool existe = std::binary_search(v.begin(), v.end(), 7);
    std::cout << "¿Existe 7? " << (existe ? "Sí" : "No") << std::endl;
    
    return 0;
}
