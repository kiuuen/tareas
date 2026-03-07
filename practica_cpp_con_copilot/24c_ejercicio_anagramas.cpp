/*
 * EJERCICIO 24C: Anagramas (LeetCode #242 + #49 style)
 * 
 * TAREA:
 * Dos palabras son ANAGRAMAS si tienen las mismas letras en diferente orden.
 * "listen" y "silent" son anagramas.
 * 
 * Parte 1: bool esAnagrama(string s, string t)
 * - Retorna true si s y t son anagramas
 * - Método 1: Ordena ambas y compara
 * - Método 2: Cuenta frecuencia de cada letra con array[26]
 * 
 * Parte 2: Agrupar anagramas (LeetCode #49)
 * Dado un vector de palabras, agrupa las que son anagramas entre sí.
 * 
 * Input:  ["eat","tea","tan","ate","nat","bat"]
 * Output: [["eat","tea","ate"], ["tan","nat"], ["bat"]]
 * 
 * Estrategia: Usa un map donde la KEY es la palabra ordenada
 * "eat" ordenada → "aet"
 * "tea" ordenada → "aet"   ← ¡misma key! → mismo grupo
 * "tan" ordenada → "ant"
 * 
 * map<string, vector<string>> grupos;
 * Para cada palabra: grupos[sorted(palabra)].push_back(palabra);
 * 
 * EJEMPLO DE SALIDA:
 * === Parte 1: ¿Son anagramas? ===
 * "listen" y "silent" → Sí
 * "hello" y "world"   → No
 * "anagram" y "nagaram" → Sí
 * 
 * === Parte 2: Agrupar anagramas ===
 * Input: ["eat","tea","tan","ate","nat","bat"]
 * Grupos:
 *   ["eat", "tea", "ate"]
 *   ["tan", "nat"]
 *   ["bat"]
 * 
 * PISTA:
 * - sort(s.begin(), s.end()) ordena los chars de un string
 * - unordered_map<string, vector<string>> para agrupar
 */

// Tu código aquí
