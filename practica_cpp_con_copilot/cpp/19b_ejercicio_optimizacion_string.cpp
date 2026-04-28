/*
 * EJERCICIO 19B: Transfiriendo Strings (Isolado)
 *
 * TAREA:
 * - Crea una funcion 'procesar_texto(std::string texto)'. (Nota: recibe por valor).
 * - Desde el main, crea un std::string muy largo ('AAAAAAAAAAAAAAAAAAAAAAA...').
 * - Llama a 'procesar_texto' pasando el string normal. Imprime despues el valor original (seguira ahi).
 * - Llama a 'procesar_texto' usando std::move(string_largo). Imprime despues el valor original (deberia quedar "vacio" o en un estado valido pero inespecificado).
 * - Imprime el tamanño de ambos, el string que no se movió y el que sí.
 */
