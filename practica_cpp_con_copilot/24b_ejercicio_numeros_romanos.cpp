/*
 * EJERCICIO 24B: Números Romanos ↔ Enteros
 * 
 * TAREA:
 * Implementa dos funciones:
 * 1. int romanoAEntero(string s) - convierte "XIV" → 14
 * 2. string enteroARomano(int n) - convierte 14 → "XIV"
 * 
 * Valores:
 * I=1, V=5, X=10, L=50, C=100, D=500, M=1000
 * 
 * Regla especial (resta):
 * IV=4, IX=9, XL=40, XC=90, CD=400, CM=900
 * 
 * Algoritmo romanoAEntero:
 * - Recorre de izquierda a derecha
 * - Si valor actual < valor siguiente → RESTA
 * - Si no → SUMA
 * 
 * Algoritmo enteroARomano:
 * - Tabla de valores de mayor a menor: {1000,"M"}, {900,"CM"}, {500,"D"}, ...
 * - Mientras el número > 0: resta el valor más grande posible, agrega el símbolo
 * 
 * EJEMPLOS:
 * "III"     → 3        3    → "III"
 * "LVIII"   → 58       58   → "LVIII"
 * "MCMXCIV" → 1994     1994 → "MCMXCIV"
 * "IX"      → 9        9    → "IX"
 * "XLII"    → 42       42   → "XLII"
 * 
 * EJEMPLO DE SALIDA:
 * Romano a Entero:
 * "III"     = 3
 * "MCMXCIV" = 1994
 * "XLII"    = 42
 * 
 * Entero a Romano:
 * 3    = "III"
 * 1994 = "MCMXCIV"
 * 42   = "XLII"
 * 
 * Verificación ida y vuelta: ✓ (todas coinciden)
 * 
 * PISTA:
 * - Para romanoAEntero: map<char, int> valores = {{'I',1}, {'V',5},...}
 * - Para enteroARomano: vector<pair<int,string>> tabla (de mayor a menor)
 */

// Tu código aquí
