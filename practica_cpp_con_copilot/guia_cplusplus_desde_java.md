# Guía de aprendizaje C++ (desde tu experiencia en Java)

Objetivo: que aprendas C++ "haciendo" exactamente como lo hiciste en Java: leer rápido, implementar ejemplos, practicar con errores y repetir. Esta guía parte de que ya sabes Java básico (Scanner, ArrayList, HashMap, recursión, manejo de Strings, métodos estáticos, etc.) y te muestra el camino y ejercicios equivalentes en C++.

Principios de la primera fase
- Aprender haciendo: por cada tema lee lo mínimo necesario, implementa 2–4 ejercicios prácticos y varía el código.  
- Traducir mentalmente: para cada concepto en Java indica su equivalente en C++.  
- Enfócate en STL (vector, string, unordered_map) en lugar de reinventar estructuras.  
- Evita ejercicios tediosos inicialmente (p.ej. imprimir matrices enormes) pero haz 1–2 variantes visuales y 3 ejercicios prácticos más útiles.

Cómo usar esta guía
1. Lee la sección corta del tema.  
2. Implementa el ejemplo mínimo (compilar y ejecutar).  
3. Haz 2 ejercicios rápidos (10–30 min cada uno).  
4. Si el tema te costó, haz 2 ejercicios más.  

Estructura de la guía
- Bloques temáticos: teoría mínima, equivalencia Java→C++, ejercicios propuestos.
- En la siguiente fase (otro prompt) resolveremos ejercicios uno por uno con teoría en comentarios y comparaciones con Java.

---

1) Entorno y primeras compilaciones
- Leer: g++, flags comunes (-std=c++17), compilación y ejecución en Windows (cmd.exe).  
- Equivalencia: javac/java → g++/ejecutable.  
- Ejemplo mínimo: "Hola, C++!" con std::cout.  
- Ejercicios: compilar/ejecutar; crear script simple o tarea por lotes (.bat) para compilar.

2) Sintaxis básica y tipos
- Leer: variables, tipos primitivos (int, long, float, double, bool), const, auto.  
- Java→C++: tipos similares, pero cuidado con manejo de memoria y conversiones.  
- Ejercicios: traducir 3 programas Java simples a C++ (ej.: operaciones aritméticas, condiciones).

3) Entrada/Salida
- Leer: <iostream>, std::cin, std::cout, '
' vs std::endl, formato con iomanip.  
- Java: Scanner → C++: std::cin / getline(std::cin, str).  
- Ejercicios: replicar programas que pedían input en Java (leer nombre, edad, calcular IMC simple).

4) Strings
- Leer: std::string, métodos: size(), substr(), find(), stoi/sto
- Java: String → C++: std::string (similar, pero funciones libres).  
- Ejercicios: cuenta vocales (versión iterativa y recursiva), convertir case con <algorithm> (transform).

5) Control de flujo y funciones
- Leer: if/else, switch, for (range-based), while, do-while.  
- Funciones: declaración, definición, parámetros por valor/por referencia, sobrecarga.  
- Java: métodos estáticos → C++: funciones free o funciones estáticas en clases.  
- Ejercicios: traducir tus ejercicios de bucles y funciones a C++ (p. ej. factorial, fibonacci recursivo e iterativo).

6) Vectores y arrays dinámicos (ArrayList → std::vector)
- Leer: std::vector<T>, push_back, size(), operator[], at(), iteradores.  
- Java: ArrayList<String> → C++: std::vector<std::string>.  
- Ejercicios: implementar las tareas que hiciste con ArrayList (añadir, eliminar, buscar, iterar), ordenar vectores (std::sort).

7) Mapas (HashMap → std::unordered_map / std::map)
- Leer: std::unordered_map<K,V>, insert/emplace, find, iteración.  
- Ejercicios: migrar tus ejercicios de hashmap a C++ y añadir más casos (colisiones básicas, contar frecuencia de palabras en un texto, top-k palabras).

8) Recursión
- Leer: llamada recursiva, caso base, pila de llamadas (stack).  
- Ejercicios: contador de vocales recursivo (como tu `nov_11_3.java`), factorial recursivo, recorrido de estructuras (árboles pequeños si te interesa).

9) Clases y POO básica
- Leer: class, private/public, constructores, métodos, this, destructores.  
- Java→C++: sin garbage collector: entender el constructor/destructor y RAII.  
- Ejercicios: crear clases equivalentes a ejercicios Java (p. ej. clase Persona con nombre/edad y métodos), transformar prácticas donde usabas métodos estáticos a instancias.

10) Punteros y referencias (concepto clave que no existe igual en Java)
- Leer: & (referencia), * (puntero), nullptr, dirección (&), referencia vs copia.  
- Ejercicios: pasar parámetros por referencia para modificar valores, uso básico de new/delete (pero preferir smart pointers luego).

11) Memoria, RAII y smart pointers
- Leer: qué es RAII, std::unique_ptr, std::shared_ptr, evitar new/delete manual cuando se pueda.  
- Ejercicios: refactorizar código que use new/delete a smart pointers.

12) STL y algoritmos (la forma idiomática)
- Leer: <algorithm> (sort, find, count), <numeric> (accumulate), lambda expressions.  
- Ejercicios: resolver problemas de colecciones usando STL en lugar de loops manuales.

13) Archivos y flujo (File I/O)
- Leer: std::ifstream, std::ofstream, lectura línea a línea.  
- Ejercicios: leer tus archivos de ejercicios (si hay) y calcular estadísticas, exportar resultados.

14) Excepciones y manejo de errores
- Leer: try/catch, std::exception, lanzar excepciones.  
- Ejercicios: añadir control de errores al parseo de input y abrir archivos.

15) Templates y genéricos
- Leer: plantillas (templates) de funciones y clases (equivalente a generics de Java).  
- Ejercicios: escribir una función template para buscar el máximo en un vector, o una clase de par simple.

16) Herramientas y flujo de trabajo
- Compiladores: g++, clang++.  
- Build: comandos g++ y luego CMake para proyectos más grandes.  
- Depuración: uso de VS Code + extensiones C/C++ y gdb (o lldb), configurar launch.json.  
- Tests: GoogleTest (opcional) o crear tests manuales.

17) Buenas prácticas desde Java aplicadas a C++
- Usar RAII y evitar leaks.  
- Preferir std::vector/std::string/unordered_map a arrays crudos.  
- Evitar using namespace std; en proyectos.

---

Plan de la primera fase (lo que haremos igual que en Java)
- Semana 1: Entorno, sintaxis básica, I/O, strings. Ejercicios: Hola Mundo, conversor, contar vocales (iterativo).  
- Semana 2: Funciones y recursión. Ejercicios: factorial, recursión de cadenas (tu `numeroVocales` en C++).  
- Semana 3: Vectores (ArrayList) + ordenamiento. Ejercicios: implementar operaciones de lista, filtrar datos.  
- Semana 4: Maps (HashMap) + frecuencia de palabras. Ejercicios: migrar tus ejercicios de hashmap y hacer top-k.  
- Semana 5: Clases básicas y POO; punteros y referencias intro.  

Ejercicios destacados a portar desde Java (prioridad)
- Contador de vocales (recursivo) — tu `nov_11_3.java`.  
- Ejercicios con ArrayList (`arraylistt.java`) → usar std::vector.  
- Ejercicios con HashMap (`hashmap.java`) → usar std::unordered_map.  
- Estructuras de control y bucles — traducir varios archivos `sep*.java` y `oct_*`.  

Ejercicios opcionales (visual / no prioritarios)
- Matrices y dibujo en consola (hacer 1–2 ejercicios): imprimir matrices pequeñas, multiplicación de matrices (entender loops anidados).  

Cómo seguiremos (siguiente prompt)
- En el próximo mensaje iremos ejercicio por ejercicio: tomaré uno de tus archivos Java (por ejemplo `nov_11_3.java`), explicaré la teoría mínima, la relación con Java y crearé el ejercicio en C++ con comentarios explicativos.  

---

¿Listo para que empecemos con el primer ejercicio (contador de vocales recursivo) o prefieres otro archivo para portar primero?
