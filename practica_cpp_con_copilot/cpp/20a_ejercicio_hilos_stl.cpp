/*
 * EJERCICIO 20A: Procesamiento en paralelo de Strings (Compuesto: Threads + STL)
 *
 * TAREA:
 * - Crea un vector gigante de strings.
 * - Divide el vector en 4 partes y asignalas a 4 hilos (std::thread).
 * - Cada hilo debe contar cuantas vocales hay en su parte.
 * - Protege la suma total con std::mutex.
 * - Imprime el tiempo de ejecucion usando std::chrono.
 */