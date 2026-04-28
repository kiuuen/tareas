/*
 * EJERCICIO 19C: Gestor de Memoria Grafica (Compuesto: Move Semantics + POO Dinamica)
 *
 * TAREA:
 * - Diseña la clase Imagen con int* pixeles, reservando 1 millon de enteros.
 * - Crea su Constructor de Copia que requiera crear un 'new int[1000000]' y copiar todos los valores.
 * - Crea su Constructor de Movimiento, que simplemente robe el puntero int* del objeto fuente.
 * - En un main crea la clase. Asignala a otra clase de forma normal. (Copiara 1 millon de veces).
 * - Ahora hazlo usando std::move. Apenas tardara 0 nanosegundos (robo de puntero).
 * - Mide el tiempo de ambos procesos usando std::chrono. Imprime la diferencia brutal.
 */
