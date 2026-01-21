# Temas aprendidos a lo largo del semestre

Este documento no es formal: es una lista clara y práctica de los conceptos y habilidades que manejas según las tareas que hay en tu carpeta `tareasDesarollo/java/src` y los archivos Python. Está escrita desde la perspectiva de "lo que aprendí".

## Resumen general
- Pasaste de no conocer Java a resolver ejercicios y pequeñas tareas que aplican estructuras de control, colecciones básicas, entrada/salida y recursividad.
- También trabajaste scripting en Python para ejercicios puntuales.

## Conceptos básicos de Java que manejas
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