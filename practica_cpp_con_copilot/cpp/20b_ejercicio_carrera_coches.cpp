/*
 * EJERCICIO 20B: Simulacion Carrera de Caballos (Isolado)
 *
 * TAREA:
 * - Escribe una funcion `void correr_caballo(int id)` que ejecute un loop de 10 iteraciones.
 * - Cada loop, debe esperar (sleep_for) un numero aleatorio de milisegundos entre 100 y 500 ms.
 * - Cada caballo usa un mutex global std::mutex global_mtx; para imprimir en consola en que posicion va.
 * - Inicia 5 caballos al mismo tiempo std::thread c1(..), c2(..), etc. Haz join().
 * - Revisa que el output intercalado siga siendo coherente.
 */
