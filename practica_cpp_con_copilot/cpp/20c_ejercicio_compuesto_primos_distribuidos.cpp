/*
 * EJERCICIO 20C: Primos Distribuidos (Compuesto: STL + Multithreading + Future)
 *
 * TAREA:
 * - Genera un std::vector global con 1 millon de numeros aleatorios.
 * - Divide el vector en 2 mitades.
 * - Usa std::async(std::launch::async, contar_primos, begin, end) para delegar el chequeo
 *   de primalidad a 2 hilos diferentes simultaneamente.
 * - .get() devolverá la cantidad de primos encontrados en cada mitad. Sumalos.
 * - Compara el tiempo que la version en paralelo toma frente a std::count_if puro lineal.
 */
