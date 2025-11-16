POO : Programación Orientada a Objetos

1) Metódo/Función: Función propia en la que introducimos parámetros de un tipo y retorna valores de un tipo

```java
class Auto {
    ...
    ...
    void acelerar() { // Metódo sin parametros
        System.Out.Println("Acelerando");
        // es void, no retorna nada
    }
}
```

// Notése como al estar dentro de una clase (auto), no ocupamos declararlo como public static/private static/public/private, almenos que lo declaremos asi

2) Atributo: Variable dentro de la clase

```java
class Auto {
    String color = "verde"; // ese es un atributo
}
```

3) Clase: Es una plantilla que define como serán los objetos en ella, define atributos (datos) y metodos (funciones)

```java
class Auto {
    atributos...
    metodos...
}
class Persona {
    atributos...
    metodo...
    metodo...
}
```

// asi definimos la clase con sus metodos y atributos, es decir todas las caracteristicas que puede tomar dependiendo el valor que le demos, por eso se le dice plantilla (blueprint)

4) Objeto: Un objeto es una instancia de una clase, le damos unos valores como tal a la clase

```java
class Persona {
    String nombre;
    Int edad;
    void saludar {
        ...
    }
}

// le ponemos atributos: nombre y edad y el metodo saludar, estan vacios, la intencion es llamarlos luego y darle valores

Persona persona1 = new Persona();

// creamos el objeto "persona1" como objeto de la clase "Persona", si no tenemos la clase no podemos crear objetos de ella

persona1.nombre = "Ana";
persona1.edad = 20;
persona1.saludar();
```

5) Constructor: Metodo especial que inicializa un objeto sin darle valores
    - Hace que inicie con valores (de lo contrario esta vacío)
    - Le da valores al objeto según los parametros, al crear un objeto con new Objeto(Parámetros)
    
```java
class Perro {
    String nombre;
    int edad;
    void saludar {
        ...
    }
}

// CREACION DEL OBJETO CON CONSTRUCTOR

Perro(String nombre, int edad) { // inicializo el objeto Perro, que viene de la clase Perro, con parametros nombre y edad

    this.nombre = nombre;
    this.edad = edad; // usamos this. para aclarar que hablamos de los atributos de la clase
}

// CON CONSTRUCTOR

Perro salchicha = new Perro("Ludovico", 12);

// SIN CONSTRUCTOR

Perro perro = new Perro();  
perro.nombre = "Ludovico";
perro.edad = 12;
```

    - Java crea el objeto vacio como Perro() { } y tu le tienes que indicar que parametros le das cada vez, en este caso
    perro.nombre y perro.edad

6) Herencia: Usas una clase padre y la heredas a otra clase hija, que adquiere todos los métodos y atributos de la clase padre, y puede modificar o agregar distintos métodos o atributos, esto se hace para reutilizar partes que comparten las clases mayormente

```java
class Animal {
    int velocidad;
    Animal(int velocidad) {
        this.velocidad = velocidad;
    }
    void respirar {
        ...
    }
    void comer {
        ...
    }
    int edad;
    String nombre;
}

class Perro extends Animal {
    void ladrar  {
        ....
    }
    Perro () {
        super(20);
    }
}

Perro perro1 = new Perro(int edad, String nombre) {
    this.nombre = nombre;
    this.edad = edad;
}

class Perro extends Animal {
    void ladrar {
        ...
    }
}
Perro perro1 = new Perro(int edad, String nombre, int velocidad) {
    this.edad = edad;
    this.nombre = nombre;
    super(velocidad);
}
```

    En el ejemplo 1, el objeto "perro1" tenia nombre y edad únicos pero velocidad siempre era 20
    En el ejemplo 2, el objeto "perro1" tiene nombre, edad y velocidad únicos
    En ambos casos, usar herencia fue lo mejor para no repetir código ya que comparten muchos atributos y métodos que otros animales,  y creamos una plantilla para crear cuantos perros queramos!
