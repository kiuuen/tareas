/*
 * EJERCICIO 22B: Monedas - Greedy vs DP
 * 
 * TAREA:
 * Dado un monto y un conjunto de denominaciones de monedas,
 * encuentra el MÍNIMO número de monedas para dar el cambio.
 * 
 * Implementa DOS soluciones:
 * 
 * 1. GREEDY: Siempre usa la moneda más grande posible
 *    - Ordena monedas de mayor a menor
 *    - Toma la más grande que quepa, repite
 *    - ⚠️ NO SIEMPRE da la respuesta óptima
 * 
 * 2. DP: (ya lo viste en el tema 20)
 *    - dp[i] = mínimo monedas para monto i
 *    - Siempre da la respuesta óptima
 * 
 * PRUEBA CON ESTOS CASOS:
 * 
 * Caso 1 - Greedy funciona:
 *   Monedas: {1, 5, 10, 25}
 *   Monto: 36
 *   Greedy: 25+10+1 = 3 monedas ✓
 *   DP:     25+10+1 = 3 monedas ✓
 * 
 * Caso 2 - Greedy FALLA:
 *   Monedas: {1, 3, 4}
 *   Monto: 6
 *   Greedy: 4+1+1 = 3 monedas ✗
 *   DP:     3+3   = 2 monedas ✓
 * 
 * Caso 3 - Greedy FALLA:
 *   Monedas: {1, 15, 25}
 *   Monto: 30
 *   Greedy: 25+1+1+1+1+1 = 6 monedas ✗
 *   DP:     15+15 = 2 monedas ✓
 * 
 * EJEMPLO DE SALIDA:
 * === Caso 1: monedas {1,5,10,25}, monto 36 ===
 * Greedy: 3 monedas [25, 10, 1]
 * DP:     3 monedas
 * ¿Coinciden? Sí
 * 
 * === Caso 2: monedas {1,3,4}, monto 6 ===
 * Greedy: 3 monedas [4, 1, 1]
 * DP:     2 monedas
 * ¿Coinciden? No - ¡Greedy falló!
 * 
 * PISTA:
 * - Este ejercicio demuestra POR QUÉ Greedy no siempre funciona
 * - DP al ser exhaustivo siempre encuentra el mínimo
 */

// Tu código aquí
