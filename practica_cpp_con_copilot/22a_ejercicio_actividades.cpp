/*
 * EJERCICIO 22A: Selección de actividades (Greedy)
 * 
 * TAREA:
 * Eres el organizador de una sala de conferencias. Tienes una lista
 * de charlas con hora de inicio y fin. Solo puedes tener una charla 
 * a la vez. ¿Cuál es el MÁXIMO número de charlas que puedes programar?
 * 
 * Algoritmo Greedy:
 * 1. Ordena las actividades por hora de FIN (menor primero)
 * 2. Selecciona la primera actividad
 * 3. Para cada actividad siguiente:
 *    - Si su inicio >= fin de la última seleccionada → selecciónala
 *    - Si no → ignórala
 * 
 * Entrada:
 * Charlas: {nombre, inicio, fin}
 * {"Intro C++", 9, 11}
 * {"Machine Learning", 10, 13}
 * {"Diseño Web", 11, 12}
 * {"Algoritmos", 12, 14}
 * {"Python Basics", 9, 10}
 * {"Data Science", 14, 16}
 * {"Bases de Datos", 13, 15}
 * 
 * EJEMPLO DE SALIDA:
 * Charlas disponibles (ordenadas por fin):
 * 1. Python Basics [9-10)
 * 2. Intro C++ [9-11)
 * 3. Diseño Web [11-12)
 * 4. Machine Learning [10-13)
 * 5. Algoritmos [12-14)
 * 6. Bases de Datos [13-15)
 * 7. Data Science [14-16)
 * 
 * Greedy seleccionó 4 charlas:
 * [9-10)  Python Basics
 * [11-12) Diseño Web
 * [12-14) Algoritmos
 * [14-16) Data Science
 * 
 * PISTA:
 * - Puedes usar vector<tuple<int, int, string>> o una struct
 * - sort con lambda: [](auto& a, auto& b){ return get<1>(a) < get<1>(b); }
 */

// Tu código aquí
