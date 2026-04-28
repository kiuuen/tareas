/*
 * EJERCICIO 18D: Evitar fugas circulares (Compuesto: Smart Pointers + Estructuras Enlazadas)
 *
 * TAREA:
 * - Crea una clase Persona. 
 * - Cada persona puede tener un std::shared_ptr<Persona> apuntando a su 'mejor_amigo'.
 * - Crea dos personas, y haz que sean amigos mutuamente (A apunta a B, y B apunta a A).
 * - Demuestra en el destructor por que la memoria *NUNCA* se libera (fuga de referencia circular).
 * - A continuacion, cambia el tipo del dato 'mejor_amigo' a std::weak_ptr<Persona>.
 * - Demuestra que ahora la memoria SI se libera al terminar.
 */
