/*
 * TEMA 23: TWO POINTERS Y SLIDING WINDOW
 * 
 * TEORÍA COMPLETA:
 * 
 * Estas son TÉCNICAS (no estructuras de datos) que optimizan problemas
 * sobre arrays/strings, reduciendo O(n²) a O(n).
 * 
 * ═══════════════════════════════════════
 * PARTE 1: TWO POINTERS (Dos punteros)
 * ═══════════════════════════════════════
 * 
 * IDEA: Usa dos índices que se mueven según alguna condición.
 * 
 * Variantes:
 * 
 * a) Desde los extremos (izquierda/derecha):
 *    int izq = 0, der = n - 1;
 *    while (izq < der) {
 *        // decidir: mover izq++ o der-- según condición
 *    }
 *    Ejemplo: Two Sum en array ordenado, palindromo check
 * 
 * b) Mismo sentido (lento/rápido):
 *    int lento = 0;
 *    for (int rapido = 0; rapido < n; rapido++) {
 *        if (condición) lento++;
 *    }
 *    Ejemplo: Eliminar duplicados, mover zeros
 * 
 * ═══════════════════════════════════════
 * PARTE 2: SLIDING WINDOW (Ventana deslizante)
 * ═══════════════════════════════════════
 * 
 * IDEA: Mantén una "ventana" [izq, der] sobre el array.
 *       Expande por la derecha, contrae por la izquierda.
 * 
 * Template:
 *    int izq = 0;
 *    for (int der = 0; der < n; der++) {
 *        // 1. Agrega nums[der] a la ventana
 *        // 2. Mientras la ventana no sea válida: quita nums[izq], izq++
 *        // 3. Actualiza respuesta con la ventana actual
 *    }
 * 
 * Tipos:
 * - VENTANA FIJA: tamaño k constante
 * - VENTANA VARIABLE: tamaño cambia según condición
 * 
 * CUÁNDO USAR:
 * - "Subarreglo/subcadena contigua más larga/corta que cumple X"
 * - "Suma máxima de k elementos consecutivos"
 * - Cualquier cosa con elementos contiguos y una condición
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <climits>

// EJEMPLO TWO POINTERS: Two Sum en array ordenado
void twoSumOrdenado() {
    std::vector<int> nums = {2, 7, 11, 15, 20, 25};
    int target = 22;
    
    int izq = 0, der = static_cast<int>(nums.size()) - 1;
    
    std::cout << "=== Two Pointers: Two Sum ===" << std::endl;
    std::cout << "Array: ";
    for (int x : nums) std::cout << x << " ";
    std::cout << "\nBuscando suma = " << target << std::endl;
    
    while (izq < der) {
        int suma = nums[izq] + nums[der];
        if (suma == target) {
            std::cout << "Encontrado: " << nums[izq] << " + " << nums[der] 
                      << " = " << target << std::endl;
            break;
        } else if (suma < target) {
            izq++;  // necesitamos una suma mayor
        } else {
            der--;  // necesitamos una suma menor
        }
    }
}

// EJEMPLO SLIDING WINDOW: Subcadena más larga sin caracteres repetidos
void subcadenaSinRepetir() {
    std::string s = "abcabcbb";
    std::unordered_set<char> ventana;
    int maxLen = 0;
    int izq = 0;
    
    std::cout << "\n=== Sliding Window: Subcadena sin repetir ===" << std::endl;
    std::cout << "String: \"" << s << "\"" << std::endl;
    
    for (int der = 0; der < static_cast<int>(s.size()); der++) {
        while (ventana.count(s[der])) {
            ventana.erase(s[izq]);
            izq++;
        }
        ventana.insert(s[der]);
        maxLen = std::max(maxLen, der - izq + 1);
    }
    
    std::cout << "Longitud más larga sin repetir: " << maxLen << std::endl;
    // "abc" → 3
}

int main() {
    twoSumOrdenado();
    subcadenaSinRepetir();
    return 0;
}
