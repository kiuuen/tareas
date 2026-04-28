/*
 * TEMA 15: ALGORITMOS DE ORDENAMIENTO
 * 
 * TEORÍA COMPLETA:
 * 
 * ¿POR QUÉ IMPORTA ORDENAR?
 * Ordenar datos es una de las operaciones más comunes en programación.
 * Muchos algoritmos REQUIEREN datos ordenados para funcionar (búsqueda binaria, etc).
 * Entender cómo funcionan te enseña a pensar en eficiencia y divide-y-vencerás.
 * 
 * RESUMEN DE ALGORITMOS:
 * 
 * ┌─────────────────┬──────────────┬───────────────┬──────────┐
 * │ Algoritmo       │ Mejor caso   │ Peor caso     │ Espacio  │
 * ├─────────────────┼──────────────┼───────────────┼──────────┤
 * │ Bubble Sort     │ O(n)         │ O(n²)         │ O(1)     │
 * │ Selection Sort  │ O(n²)        │ O(n²)         │ O(1)     │
 * │ Insertion Sort  │ O(n)         │ O(n²)         │ O(1)     │
 * │ Merge Sort      │ O(n log n)   │ O(n log n)    │ O(n)     │
 * │ Quick Sort      │ O(n log n)   │ O(n²)         │ O(log n) │
 * │ std::sort       │ O(n log n)   │ O(n log n)    │ O(log n) │
 * └─────────────────┴──────────────┴───────────────┴──────────┘
 * 
 * TIPOS:
 * → Simples (O(n²)): Bubble, Selection, Insertion
 *   - Fáciles de entender e implementar
 *   - Buenos para vectores pequeños (< 1000 elementos)
 *   - IMPORTANTES para aprender la lógica
 * 
 * → Eficientes (O(n log n)): Merge Sort, Quick Sort
 *   - Usan la técnica "divide y vencerás"
 *   - Necesarios para vectores grandes
 *   - std::sort() de C++ usa una variante de Quick Sort (Introsort)
 * 
 * 1. BUBBLE SORT (Burbuja):
 *    Idea: Comparar pares adyacentes e intercambiar si están desordenados.
 *    Los valores grandes "burbujean" hacia el final.
 *    
 *    Paso 1: [5, 3, 8, 1] → compara (5,3) → swap → [3, 5, 8, 1]
 *    Paso 2: [3, 5, 8, 1] → compara (5,8) → ok   → [3, 5, 8, 1]
 *    Paso 3: [3, 5, 8, 1] → compara (8,1) → swap → [3, 5, 1, 8]
 *    ...se repite hasta que no haya más swaps
 * 
 * 2. SELECTION SORT (Selección):
 *    Idea: Encontrar el mínimo del resto y ponerlo en su posición.
 *    
 *    [5, 3, 8, 1] → mínimo es 1 → swap con pos 0 → [1, 3, 8, 5]
 *    [1, 3, 8, 5] → mínimo del resto es 3 → ya está → [1, 3, 8, 5]
 *    [1, 3, 8, 5] → mínimo del resto es 5 → swap    → [1, 3, 5, 8]
 * 
 * 3. INSERTION SORT (Inserción):
 *    Idea: Como ordenar cartas en la mano. Tomas una carta y la insertas
 *    en su posición correcta entre las que ya están ordenadas.
 *    
 *    [5, 3, 8, 1] → toma 3, inserta antes de 5   → [3, 5, 8, 1]
 *    [3, 5, 8, 1] → toma 8, ya está en posición   → [3, 5, 8, 1]
 *    [3, 5, 8, 1] → toma 1, inserta al inicio      → [1, 3, 5, 8]
 * 
 * 4. MERGE SORT (Mezcla) - DIVIDE Y VENCERÁS:
 *    Idea: Dividir el vector a la mitad, ordenar cada mitad recursivamente,
 *    y luego mezclar las dos mitades ordenadas.
 *    
 *    [5, 3, 8, 1] → divide → [5, 3] y [8, 1]
 *    [5, 3] → divide → [5] y [3] → merge → [3, 5]
 *    [8, 1] → divide → [8] y [1] → merge → [1, 8]
 *    [3, 5] y [1, 8] → merge → [1, 3, 5, 8]
 * 
 * 5. QUICK SORT - DIVIDE Y VENCERÁS:
 *    Idea: Elegir un "pivote", poner los menores a la izquierda
 *    y los mayores a la derecha, luego ordenar cada lado recursivamente.
 *    
 *    [5, 3, 8, 1, 7] → pivote = 5
 *    Menores: [3, 1]  Mayores: [8, 7]
 *    Ordenar cada lado → [1, 3] + [5] + [7, 8] = [1, 3, 5, 7, 8]
 */

#include <iostream>
#include <vector>
#include <algorithm>

// Función auxiliar para imprimir un vector
void imprimir(const std::vector<int>& v, const std::string& nombre) {
    std::cout << nombre << ": ";
    for (int x : v) std::cout << x << " ";
    std::cout << std::endl;
}

// === EJEMPLO: Merge Sort completo ===
void merge(std::vector<int>& v, int izq, int mid, int der) {
    std::vector<int> temp;
    int i = izq, j = mid + 1;
    
    // Mezclar las dos mitades ordenadas
    while (i <= mid && j <= der) {
        if (v[i] <= v[j]) {
            temp.push_back(v[i++]);
        } else {
            temp.push_back(v[j++]);
        }
    }
    // Copiar lo que quede de la mitad izquierda
    while (i <= mid) temp.push_back(v[i++]);
    // Copiar lo que quede de la mitad derecha
    while (j <= der) temp.push_back(v[j++]);
    
    // Copiar de vuelta al vector original
    for (int k = 0; k < static_cast<int>(temp.size()); k++) {
        v[izq + k] = temp[k];
    }
}

void mergeSort(std::vector<int>& v, int izq, int der) {
    if (izq >= der) return;  // Caso base: 1 elemento ya está ordenado
    
    int mid = izq + (der - izq) / 2;
    mergeSort(v, izq, mid);       // Ordenar mitad izquierda
    mergeSort(v, mid + 1, der);   // Ordenar mitad derecha
    merge(v, izq, mid, der);      // Mezclar las dos mitades
}

int main() {
    std::vector<int> datos = {38, 27, 43, 3, 9, 82, 10};
    
    std::cout << "=== MERGE SORT EJEMPLO ===" << std::endl;
    imprimir(datos, "Original");
    
    mergeSort(datos, 0, static_cast<int>(datos.size()) - 1);
    imprimir(datos, "Ordenado");
    
    // Comparación con std::sort
    std::vector<int> datos2 = {38, 27, 43, 3, 9, 82, 10};
    std::sort(datos2.begin(), datos2.end());
    imprimir(datos2, "std::sort");
    
    std::cout << "\nNota: std::sort() es la forma estándar en C++." << std::endl;
    std::cout << "Implementar los algoritmos a mano es para ENTENDER la lógica." << std::endl;
    
    return 0;
}
