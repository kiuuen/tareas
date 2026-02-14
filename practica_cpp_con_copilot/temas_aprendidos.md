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

## Temas recientes (resumen)
- Serialización y persistencia: ideas clave (usar `Serializable`, declarar `serialVersionUID`, y marcar con `transient` los recursos no serializables) y el uso básico de `ObjectOutputStream`/`ObjectInputStream` para guardar/cargar estado.
- Buenas prácticas: usar colecciones tipadas (por ejemplo `ArrayList<Venta>`), diseñar clases de dominio pequeñas y evitar serializar campos `static` salvo que se gestione explícitamente su persistencia.
- Depuración y mantenimiento: inspeccionar stack traces para localizar `NotSerializableException`, limpiar archivos `.class` y borrar archivos de datos antiguos (`.dat`) si cambió la estructura de clases para evitar errores de compatibilidad.
- Flujo práctico recomendado: diseñar clases serializables, probar guardar y cargar en ciclos cortos (crear producto, registrar venta, guardar, reiniciar y cargar) y documentar cambios en el formato de persistencia.