/*
 * EJERCICIO 16B: Primera y última ocurrencia (Lower/Upper Bound)
 * 
 * TAREA:
 * Dado un vector ORDENADO que puede tener valores repetidos, encuentra
 * la PRIMERA y ÚLTIMA posición de un valor dado.
 * (Equivalente a LeetCode #34: Find First and Last Position)
 * 
 * 1. Crea int primeraOcurrencia(vector<int>& v, int target):
 *    - Búsqueda binaria modificada
 *    - Cuando encuentras target, NO retornas inmediatamente
 *    - En vez, haces der = mid - 1 para buscar más a la izquierda
 *    - Guardas mid como candidato y sigues buscando
 * 
 * 2. Crea int ultimaOcurrencia(vector<int>& v, int target):
 *    - Similar, pero cuando encuentras target: izq = mid + 1
 *    - Para buscar más a la derecha
 * 
 * 3. En main():
 *    - Vector: {1, 2, 2, 2, 3, 4, 4, 5, 5, 5, 5, 6}
 *    - Busca primera y última ocurrencia de: 2, 5, 7
 * 
 * EJEMPLO DE SALIDA:
 * Vector: 1 2 2 2 3 4 4 5 5 5 5 6
 * 
 * Valor 2: primera=1, última=3 (aparece 3 veces)
 * Valor 5: primera=7, última=10 (aparece 4 veces)
 * Valor 7: no encontrado
 */

// Tu código aquí
