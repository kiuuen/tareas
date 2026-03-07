# Temas aprendidos a lo largo del semestre

Este documento rastrea tu progreso de Java/Python → C++, enfocándote en POO para el semestre actual.

## 📚 PARTE 1: Java y Python (Base Completada)

### Resumen general
- Pasaste de no conocer Java a resolver ejercicios y pequeñas tareas que aplican estructuras de control, colecciones básicas, entrada/salida y recursividad.
- También trabajaste scripting en Python para ejercicios puntuales.

### Conceptos básicos de Java que manejas
- Sintaxis básica: clases públicas, `public static void main`, tipos primitivos (int, boolean, etc.).
- Compilar y ejecutar programas Java (javac / java) y crear archivos `.java` con clases.
- Uso de `import` y librerías estándar (por ejemplo `java.util.Scanner`).

## Entrada y salida
- Uso de `Scanner` para leer entrada por consola (`nextLine()`, `nextInt()`, etc.).
- `System.out.println` para imprimir resultados.

## Estructuras de control
- Condicionales: `if`, `else if`, `else`.
- Bucles: `for`, `while` y `do-while`.
- Control de flujo con `break` y `continue` (implicado en tareas de bucles).

## Métodos y organización del código
- Declaración y uso de métodos (funciones): parámetros, tipo de retorno, `static`.
- Variables estáticas de clase (`static`) para compartir estado entre llamadas (por ejemplo `totalVocales`).
- Concepto de alcance (scope) de variables y retorno de valores.

## Recursividad
- Implementación de métodos recursivos para problemas sencillos (por ejemplo contar vocales procesando la cadena carácter a carácter).
- Identificación del caso base y llamada recursiva adecuada para evitar recursión infinita.

## Manejo de cadenas (Strings)
- Operaciones con `String`: `toLowerCase()`, `substring()`, `startsWith()`, `equals()`.
- Procesar cadenas carácter por carácter y contar/filtrar elementos (vocales, dígitos, etc.).

## Estructuras de datos y colecciones básicas
- Arrays (uso implícito en ejercicios de listas y manejo por índices).
- `ArrayList`: creación, añadir elementos, iteración.
- `HashMap`: mapas clave-valor, insertar y obtener valores.

## Tipos de datos y conversiones
- Conversión entre cadenas y números cuando es necesario (parseo de `String` a `int` y viceversa).

## Python (básico/práctico)
- Scripts Python para ejercicios (`.py`): escribir funciones, uso de listas y operaciones básicas.
- Uso de Python para resolver problemas rápidos o prototipar soluciones.

## Buenas prácticas que ya estás aplicando
- Dividir el problema en funciones/métodos más pequeños.
- Comentarios breves en los archivos para indicar la intención del ejercicio.

---

## 🚀 PARTE 2: C++ (Progreso Actual)

### ✅ Temas 01-09: Completados
- Sintaxis básica, tipos, operadores → traducción de Java
- Entrada/salida: `cin`, `cout`, `getline`
- Control de flujo: `if`, `for`, `while`, `switch`
- Funciones: sobrecarga, paso por valor/referencia
- Strings: `std::string`, métodos básicos
- Recursión: casos base, llamadas recursivas
- Vectores: `std::vector<T>` (equivalente a ArrayList)
- Mapas: `std::unordered_map<K,V>` (equivalente a HashMap)

### 🎯 Tema 10: POO Básica (NUEVO)
**Estado:** Teoría lista, 4 ejercicios pendientes

**Aprendido:**
- Clases y objetos en C++
- Constructores y **destructores** (~Clase)
- Lista de inicialización: más eficiente
- Modificadores: private, public, protected
- Métodos const (no modifican el objeto)
- **Diferencia clave con Java:** No hay garbage collector

**Archivos:**
- ✓ `10_poo_basica.cpp` - Teoría con ejemplos
- ⏳ `10a_ejercicio_estudiante.cpp` - Por hacer
- ⏳ `10b_ejercicio_libro.cpp` - Por hacer
- ⏳ `10c_ejercicio_cuenta_bancaria.cpp` - Por hacer
- ⏳ `10d_ejercicio_inventario.cpp` - Por hacer

### 🔧 Tema 11: Punteros y Referencias (NUEVO)
**Estado:** Teoría lista, 3 ejercicios pendientes

**Aprendido:**
- Punteros: `int* ptr = &variable`, des-referencia con `*ptr`
- Referencias: `int& ref = variable` (alias)
- Diferencia: puntero puede ser nullptr, referencia no
- Paso por referencia: `void funcion(Tipo& param)`
- Smart pointers: `std::unique_ptr`, `std::shared_ptr`
- **Concepto nuevo vs Java:** En Java todo es referencia implícita

**Archivos:**
- ✓ `11_punteros_referencias.cpp` - Teoría con ejemplos
- ⏳ `11a_ejercicio_swap.cpp` - Por hacer
- ⏳ `11b_ejercicio_modificar_objeto.cpp` - Por hacer
- ⏳ `11c_ejercicio_buscar_puntero.cpp` - Por hacer

### ⭐ Tema 12: Herencia y Polimorfismo (TEMA DEL SEMESTRE - NUEVO)
**Estado:** Teoría lista, 4 ejercicios pendientes

**Aprendido:**
- Herencia: `class Hijo : public Padre`
- Métodos virtuales: `virtual void metodo()`
- Override: `void metodo() override`
- Clases abstractas: `virtual void metodo() = 0;`
- **Destructor virtual:** `virtual ~Clase() {}` (CRÍTICO)
- Polimorfismo: `Animal* ptr = new Perro();`
- protected: accesible desde clases hijas

**Conceptos críticos vs Java:**
- Java: Polimorfismo automático
- C++: **REQUIERE "virtual"** en clase base
- Java: No hay destructores
- C++: Destructor virtual es **obligatorio** en jerarquías

**Archivos:**
- ✓ `12_herencia_polimorfismo.cpp` - Teoría con ejemplos
- ⏳ `12a_ejercicio_empleados.cpp` - Jerarquía clásica (Por hacer)
- ⏳ `12b_ejercicio_vehiculos.cpp` - Clase abstracta (Por hacer)
- ⏳ `12c_ejercicio_figuras_3d.cpp` - Métodos virtuales puros (Por hacer)
- ⏳ `12d_ejercicio_universidad.cpp` - INTEGRADOR (Por hacer)

### 📁 Tema 13: Archivos (NUEVO)
**Estado:** Teoría lista, 3 ejercicios pendientes

**Aprendido:**
- `std::ifstream` - leer archivos
- `std::ofstream` - escribir archivos
- `std::getline(archivo, linea)` - leer línea por línea
- Modos: `ios::app` (agregar), `ios::trunc` (sobrescribir)
- Verificar apertura: `if (!archivo.is_open())`

**Archivos:**
- ✓ `13_archivos.cpp` - Teoría con ejemplos
- ⏳ `13a_ejercicio_calificaciones.cpp` - Por hacer
- ⏳ `13b_ejercicio_agenda_archivo.cpp` - Por hacer
- ⏳ `13c_ejercicio_analizador_texto.cpp` - Por hacer

---

## 📊 Estadísticas Generales

**Total de archivos de teoría C++:** 13 (todos con ejemplos ejecutables)
**Ejercicios completados:** ~20 (temas 01-09)
**Ejercicios pendientes:** 14 (temas 10-13)
**Enfoque del semestre:** POO (temas 10, 11, 12)

---

## 🎓 Conceptos Clave que Dominas Ahora

### De Java a C++ - Equivalencias:
| Java | C++ |
|------|-----|
| `ArrayList<T>` | `std::vector<T>` |
| `HashMap<K,V>` | `std::unordered_map<K,V>` |
| `String` | `std::string` |
| `null` | `nullptr` |
| `extends` | `: public` |
| `@Override` | `override` |
| `abstract` | `= 0` (virtual puro) |

### Nuevos Conceptos de C++ (no existen en Java):
- ✅ Destructores automáticos
- ✅ Punteros explícitos
- ✅ Referencias explícitas
- ✅ const correctness
- ✅ Lista de inicialización
- ✅ RAII (Resource Acquisition Is Initialization)
- ✅ Smart pointers

---

## 🎯 Próximos Pasos

1. **Ejecutar archivos de teoría:** Compila y corre `10_poo_basica.cpp`, `11_punteros_referencias.cpp`, `12_herencia_polimorfismo.cpp`
2. **Resolver ejercicios 10a-10d:** POO básica
3. **Resolver ejercicios 11a-11c:** Punteros y referencias
4. **Resolver ejercicios 12a-12d:** ⭐ HERENCIA (más importante para el semestre)
5. **Resolver ejercicios 13a-13c:** Archivos

---

**Última actualización:** Con temas 10-13 enfocados en POO (herencia, polimorfismo, clases abstractas)
- Uso de nombres descriptivos para variables (`cadenaInput`, `totalVocales`).

## Errores y lecciones comunes que ya viste
- Cuidado con el estado global (`static`): puede provocar que valores queden acumulados entre ejecuciones si no se reinician.
- Importancia de normalizar cadenas antes de comparar (`toLowerCase()`/`toUpperCase()`).
- Caso base en recursión: siempre definirlo claramente.

## Herramientas y flujo de trabajo
- Uso de un editor/IDE (probablemente VS Code) y estructura de proyecto con carpetas.
- Manejo básico de GitHub (tienes el repositorio local en `c:\Users\kiuuen\Documents\GitHub`).

## Qué puedes aprender luego (siguientes pasos recomendados)
- Programación orientada a objetos más profunda: herencia, interfaces, encapsulación y polimorfismo.
- Excepciones y manejo de errores (`try/catch`).
- Lectura/escritura de archivos (File I/O) y manipulación de streams.
- Tests unitarios en Java (JUnit) y diseño de programas más modulares.
- Estructuras de datos avanzadas y algoritmos básicos (ordenamiento, búsqueda, complejidad).

---

## 📚 PARTE 3: Algoritmos y Estructuras de Datos (preparación competitiva)

Sección de ejercicios para prepararte en algoritmos, desde lo básico hasta problemas estilo LeetCode/Codeforces/HackerRank. Cada tema tiene un archivo de teoría con ejemplos funcionales y ejercicios vacíos con instrucciones detalladas.

### Tema 14 — Complejidad Algorítmica (Big O)
| Archivo | Descripción | Estado |
|---------|-------------|--------|
| `14_complejidad_algoritmica.cpp` | Teoría: O(1), O(n), O(n²), O(log n), medición con chrono | 📖 |
| `14a_ejercicio_medir_tiempo.cpp` | Comparar O(n²) vs O(n) para detectar duplicados | ⬜ |
| `14b_ejercicio_comparar_busquedas.cpp` | Búsqueda lineal vs binaria con conteo de operaciones | ⬜ |

### Tema 15 — Algoritmos de Ordenamiento
| Archivo | Descripción | Estado |
|---------|-------------|--------|
| `15_ordenamiento.cpp` | Teoría: tabla comparativa, merge sort completo | 📖 |
| `15a_ejercicio_bubble_sort.cpp` | Implementar bubble sort con optimización | ⬜ |
| `15b_ejercicio_selection_sort.cpp` | Implementar selection sort | ⬜ |
| `15c_ejercicio_insertion_sort.cpp` | Implementar insertion sort | ⬜ |
| `15d_ejercicio_merge_sort.cpp` | Implementar merge sort (divide & conquer) | ⬜ |
| `15e_ejercicio_quick_sort.cpp` | Implementar quick sort (Lomuto partition) | ⬜ |
| `15f_ejercicio_ordenar_colores.cpp` | Dutch National Flag / LeetCode #75 | ⬜ |

### Tema 16 — Búsqueda
| Archivo | Descripción | Estado |
|---------|-------------|--------|
| `16_busqueda.cpp` | Teoría: binary search, lower_bound, STL | 📖 |
| `16a_ejercicio_busqueda_binaria.cpp` | Implementar búsqueda binaria con contador | ⬜ |
| `16b_ejercicio_primera_ultima.cpp` | Primera/última ocurrencia / LeetCode #34 | ⬜ |
| `16c_ejercicio_encontrar_pico.cpp` | Find Peak Element / LeetCode #162 | ⬜ |
| `16d_ejercicio_raiz_cuadrada.cpp` | Sqrt(x) con binary search / LeetCode #69 | ⬜ |

### Tema 17 — Pilas y Colas
| Archivo | Descripción | Estado |
|---------|-------------|--------|
| `17_pilas_colas.cpp` | Teoría: stack, queue, priority_queue, deque | 📖 |
| `17a_ejercicio_pila_vector.cpp` | Implementar pila custom con vector | ⬜ |
| `17b_ejercicio_parentesis_validos.cpp` | Valid Parentheses / LeetCode #20 | ⬜ |
| `17c_ejercicio_cola_dos_pilas.cpp` | Queue con dos stacks / LeetCode #232 | ⬜ |
| `17d_ejercicio_min_stack.cpp` | Min Stack / LeetCode #155 | ⬜ |
| `17e_ejercicio_calculadora_postfija.cpp` | Calculadora postfija (Reverse Polish) | ⬜ |

### Tema 18 — Listas Enlazadas
| Archivo | Descripción | Estado |
|---------|-------------|--------|
| `18_listas_enlazadas.cpp` | Teoría: Nodo, insertar, imprimir, liberar | 📖 |
| `18a_ejercicio_lista_completa.cpp` | Clase LinkedList completa | ⬜ |
| `18b_ejercicio_invertir_lista.cpp` | Reverse Linked List / LeetCode #206 | ⬜ |
| `18c_ejercicio_detectar_ciclo.cpp` | Floyd's cycle detection / LeetCode #141 | ⬜ |
| `18d_ejercicio_merge_listas.cpp` | Merge Two Sorted Lists / LeetCode #21 | ⬜ |
| `18e_ejercicio_nodo_medio.cpp` | Middle of Linked List / LeetCode #876 | ⬜ |

### Tema 19 — Árboles Binarios
| Archivo | Descripción | Estado |
|---------|-------------|--------|
| `19_arboles.cpp` | Teoría: NodoArbol, recorridos, altura, BFS | 📖 |
| `19a_ejercicio_recorridos.cpp` | Inorder, preorder, postorder, level order | ⬜ |
| `19b_ejercicio_altura_arbol.cpp` | Max depth + contar nodos / LeetCode #104 | ⬜ |
| `19c_ejercicio_arbol_simetrico.cpp` | Symmetric Tree / LeetCode #101 | ⬜ |
| `19d_ejercicio_bst.cpp` | BST: insertar y buscar | ⬜ |
| `19e_ejercicio_validar_bst.cpp` | Validate BST / LeetCode #98 | ⬜ |

### Tema 20 — Programación Dinámica
| Archivo | Descripción | Estado |
|---------|-------------|--------|
| `20_programacion_dinamica.cpp` | Teoría: top-down, bottom-up, patrones DP | 📖 |
| `20a_ejercicio_fibonacci_memo.cpp` | Fibonacci: recursivo vs memo vs tabulation | ⬜ |
| `20b_ejercicio_subir_escaleras.cpp` | Climbing Stairs / LeetCode #70 | ⬜ |
| `20c_ejercicio_max_subarray.cpp` | Kadane's / Maximum Subarray / LeetCode #53 | ⬜ |
| `20d_ejercicio_mochila.cpp` | 0/1 Knapsack Problem | ⬜ |
| `20e_ejercicio_lcs.cpp` | Longest Common Subsequence / LeetCode #1143 | ⬜ |
| `20f_ejercicio_cambio_monedas.cpp` | Coin Change / LeetCode #322 | ⬜ |

### Tema 21 — Grafos
| Archivo | Descripción | Estado |
|---------|-------------|--------|
| `21_grafos.cpp` | Teoría: representación, BFS, DFS | 📖 |
| `21a_ejercicio_representar_grafo.cpp` | Lista de adyacencia + grados | ⬜ |
| `21b_ejercicio_bfs_camino.cpp` | BFS camino más corto sin pesos | ⬜ |
| `21c_ejercicio_dfs_componentes.cpp` | DFS componentes conexas | ⬜ |
| `21d_ejercicio_detectar_ciclo_grafo.cpp` | Detectar ciclo en grafo dirigido | ⬜ |
| `21e_ejercicio_dijkstra.cpp` | Dijkstra camino más corto con pesos | ⬜ |

### Tema 22 — Greedy y Backtracking
| Archivo | Descripción | Estado |
|---------|-------------|--------|
| `22_greedy_backtracking.cpp` | Teoría: greedy pattern, backtracking template | 📖 |
| `22a_ejercicio_actividades.cpp` | Activity Selection (greedy clásico) | ⬜ |
| `22b_ejercicio_monedas_greedy.cpp` | Greedy vs DP para cambio de monedas | ⬜ |
| `22c_ejercicio_permutaciones.cpp` | Generar permutaciones / LeetCode #46 | ⬜ |
| `22d_ejercicio_n_reinas.cpp` | N-Queens (backtracking clásico) | ⬜ |
| `22e_ejercicio_sudoku.cpp` | Sudoku Solver (backtracking) | ⬜ |

### Tema 23 — Two Pointers y Sliding Window
| Archivo | Descripción | Estado |
|---------|-------------|--------|
| `23_two_pointers_sliding_window.cpp` | Teoría: two pointers, sliding window patterns | 📖 |
| `23a_ejercicio_two_sum.cpp` | Two Sum / LeetCode #1 (3 soluciones) | ⬜ |
| `23b_ejercicio_contenedor_agua.cpp` | Container With Most Water / LeetCode #11 | ⬜ |
| `23c_ejercicio_subcadena_sin_repetir.cpp` | Longest Substring Without Repeating / LC #3 | ⬜ |
| `23d_ejercicio_tres_suma.cpp` | 3Sum / LeetCode #15 | ⬜ |
| `23e_ejercicio_suma_ventana.cpp` | Suma máxima de ventana fija de tamaño k | ⬜ |

### Tema 24 — Problemas de Práctica Competitiva
| Archivo | Descripción | Estado |
|---------|-------------|--------|
| `24a_ejercicio_fizzbuzz.cpp` | FizzBuzz (clásico de entrevistas) | ⬜ |
| `24b_ejercicio_numeros_romanos.cpp` | Romano ↔ Entero | ⬜ |
| `24c_ejercicio_anagramas.cpp` | Anagramas + agrupar / LeetCode #49 | ⬜ |
| `24d_ejercicio_spiral_matrix.cpp` | Spiral Matrix / LeetCode #54 | ⬜ |
| `24e_ejercicio_merge_intervals.cpp` | Merge Intervals / LeetCode #56 | ⬜ |
| `24f_ejercicio_palindromo_largo.cpp` | Longest Palindromic Substring / LC #5 | ⬜ |

### Resumen de la sección de algoritmos
| Tema | Teoría | Ejercicios | Total archivos |
|------|--------|------------|----------------|
| 14. Complejidad | 1 | 2 | 3 |
| 15. Ordenamiento | 1 | 6 | 7 |
| 16. Búsqueda | 1 | 4 | 5 |
| 17. Pilas y Colas | 1 | 5 | 6 |
| 18. Listas Enlazadas | 1 | 5 | 6 |
| 19. Árboles | 1 | 5 | 6 |
| 20. Prog. Dinámica | 1 | 6 | 7 |
| 21. Grafos | 1 | 5 | 6 |
| 22. Greedy/Backtracking | 1 | 5 | 6 |
| 23. Two Pointers/SW | 1 | 5 | 6 |
| 24. Práctica Competitiva | 0 | 6 | 6 |
| **TOTAL** | **10** | **54** | **64** |

Leyenda: 📖 = archivo de teoría (para leer/estudiar), ⬜ = pendiente, ✅ = completado

## Temas recientes (resumen)
- Serialización y persistencia: ideas clave (usar `Serializable`, declarar `serialVersionUID`, y marcar con `transient` los recursos no serializables) y el uso básico de `ObjectOutputStream`/`ObjectInputStream` para guardar/cargar estado.
- Buenas prácticas: usar colecciones tipadas (por ejemplo `ArrayList<Venta>`), diseñar clases de dominio pequeñas y evitar serializar campos `static` salvo que se gestione explícitamente su persistencia.
- Depuración y mantenimiento: inspeccionar stack traces para localizar `NotSerializableException`, limpiar archivos `.class` y borrar archivos de datos antiguos (`.dat`) si cambió la estructura de clases para evitar errores de compatibilidad.
- Flujo práctico recomendado: diseñar clases serializables, probar guardar y cargar en ciclos cortos (crear producto, registrar venta, guardar, reiniciar y cargar) y documentar cambios en el formato de persistencia.