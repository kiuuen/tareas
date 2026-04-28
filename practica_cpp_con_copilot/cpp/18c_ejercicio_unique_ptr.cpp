/*
 * EJERCICIO 18C: Gestor de Recursos Unicos (Isolado)
 *
 * TAREA:
 * - Implementa una clase 'ConexionBD' que al construirse indique que se abrio conexion.
 * - Mantenla desde el main() unicamente usando std::unique_ptr<ConexionBD>.
 * - Crea una funcion 'procesar(std::unique_ptr<ConexionBD>& db)'. Demuestra que 
 *   para pasar un unique_ptr a una funcion debes usar referencias o std::move().
 */
