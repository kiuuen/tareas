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

// ejemplo 1 
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
// ejemplo 2

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

7) Sobreescritura de métodos (Override): Continuación de Herencia, en este caso cuando modificas un método o atributo que viene de la clase padre
``` java
    class Animal {
        void hacerRuido {
            System.out.println("Ruido");
        }
    }
    class Perro extends Animal {
        @Override // IMPORTANTE, se usa @Override para aclarar que es reescritura, de otro modo el compilador puede confundir (o que escribas mal el método) y simplemente estes declarando otro método nuevo, no sobrescribiendo el de la clase padre
        void hacerRuido {  // si hubiera puesto "hagoRuido" me daria error, porque especifique que es @Override y hagoRuido no existe en padre, sin eso, solo creo otro método hagoRuido no reescribo nada
            System.out.println("Guauu");
        }
    }

// esto imprime: Guauu
// si quiero modificar solo una parte (sobreescribir parcialmente) y no todo el método, uso super

    class Animal {
        void hacerRuido {
            System.out.println("Ruido")
        }
    }
    class Perro extends Animal {
        @Override
        void hacerRuido {
            super.hacerRuido(); // con el super ejecuto el método en padre, antes de sobreescribirlo por eso es sobreescritura parcial
            System.out.println("Guauu")
        }
    }

// esto imprime; Ruido \n Guauu
```
8) Sobrecarga/Overloading: Tener un método con el mismo nombre pero con distintos parametros:
``` java
int sumar(int, int, int, int) {
}
double sumar(double, double) {
}
String sumar(String, String) {
}
```
9) Superclase, subclase, super():

    - Superclase: clase padre donde se desprenden las demas subclases
    - Subclase: Viene de una superclase
    Las propiedades con esto es que puedes modificar metodos de la superclase en tu subclase, pero los cambios generales los hace la superclase (que aplica para todas sus subclases)  
    
    - super() viene de llamar una funcion/método que se encuentraen la SUPERclase
    - Para poder crear un objeto en una subclase, ocupamos haber construido primero un objeto en la superclase

-> tenemos
``` java
    class Animal {
        String nombre;
        int edad;
        void moverse {

        }
    }

        Animal(String nombre, int edad) {
            this.nombre = nombre;
            this.edad = edad; // creamos un constructor de animal, cuando queramos crear otro objeto en una subclase, llamamos al constructor
        }
// este constructor lo pueden heredar SOLO SI <=> lo llaman con un super
        
si queremos hacer una objeto hijo

    class Perro extends Animal {

    Perro(String nombre, int edad) { // hago un constructor en la subclase, usando un método ya construido de la superclase, de no hacer esto nos daria error porque tenemos ese constructor de la superclase vacia
        super(nombre, edad);
    }
}
    Perro ludovico = new Perro("ludovico", edad)

```
entonces, uso el constructor en la clase padre, lo llamo con super en la hija y asi puedo crear objetos con el constructor del padre  "Perro ludovico = new Perro("ludovico", edad)"

10) Polimorfismo: Propiedad que permite a un método tener distintas formas según el objeto que la utilice, ocurre gracias a herencia

    - Polimorfismo por sobreescritura: Cuando un método es cambiado por la subclase mediante reescritura
``` java
    class Animal {
        void hacerRuido {
            System.out.println("Ruido");
        }
    }

    class Perro extends Animal {
        @Override
        void hacerRuido {
            System.out.println("Guauu");
        }
    }

    class Gato extends Animal {
        @Override
        void hacerRuido {
            System.out.println("Miauu");
        }
    }
```
    -> en este ejemplo se sobreescribe el mismo metódo "hacerRuido" y cambia según el objeto que lo usa

    - Polimorfismo por referencias/Upcasting: Guardas objetos dentro de variables de la superclase

    -> usando el ejemplo de la clase animal

    Animal ludovico = new perro(nombre, edad); // simplemente guardamos este objeto dentro de Animal y no dentro de Perro, asi podemos agrupar mejor los objetos

    -> suponiendo que tenemos todo construido
``` java
    Animal michi = new Gato(nombre, edad);
    Animal cobra = new Serpiente(nombre, edad);
    Animal cerdito = new Cerdo(nombre, edad);

    // los agrupamos a todos dentro de la superclase Animal
```
    - Polimorfismo de compilación/Poliformismo con overloading: Simplemente hacemos lo de un método con distintos parametros pero en este caso cada objeto usa el mismo método con distintos parametros

    -> hay muchos tipos, para este ejemplo cambiamos los datos
``` java
    class Prints {
        void imprimir(int entero) {
            System.out.println("Entero: ");
        }
        void imprimir(String texto) {
            System.out.println("Texto: ");
        }
    }
        // aqui "imprimir" es int y string

    Imprimir impresora = new Imprimir() // constructor

    impresora.imprimir(19);
    impresora.imprimir("hola");
```
11) Encapsulamiento: Protejes que una clase no pueda ser accedida asi como asi, le puedes poner métodos intermediarios
    - Getters, lees el valor de esa clase
    - Setters, modificas el valor de esa clase

-> por ejemplo
``` java
class Cuenta {
    private double dinero(); //  es un atributo, no un método
    public Cuenta(double saldoInicial) {
        if (saldoInicial >= 0) {
            this.dinero = saldoInicial;
        } else {
            this.dinero = 0; // no uso set por proteccion de la clase privada
        }
    }
    public void depositar(double cantidad) {
        if (cantidad >= 0) {
            dinero += deposito;
    }   } else {
            System.out.println("Introduce una cantidad mayor a 0");
    }
    public void retirar(double cantidad) {
        if (cantidad >= 0 && cantidad <= dinero) {
            dinero -= retiro;
        } else {
            System.out.println("Esa cantidad es incorrecta, no tienes ese dinero");
        }
    }
    public double getDinero() { // usamos get para leer Dinero
        return dinero;
    }
}

Cuenta cuenta1 = new Cuenta(100) // saldo inicial ese 100
cuenta1.depositar(200);
cuenta2.retirar(300);
```

esto nos permite modificar la clase privada dinero, pero pasando por los metodos retirar y depositar primero, se entiende muy fácil con este ejemplo de dinero ya que de este método tenemos muy protegido el atributo "dinero" y también es una manera muy controlada de introducir los valores, en lugar de usar muchos if y else, manejamos con encapsulamiento

12) Clases abstractas: Son clases que no pueden ser construidas en objetos, ya que no tienen valores como tal, no puedes crearlas como new, su propiedad es agrupar (upcasting) subclases dentro de esta, sirve cuando cada subclase se comporta o calcula distinto pero se pueden agrupar

-> por ejemplo
```java
    abstract class figura {
        abstract double perimetro();
        abstract double area();
        String nombre;
    // creas una abstract class figura sin valores, pero para que sus subclases comparten area y nombre, es necesario especificar abstract para no poder crear un objeto de ella
    Figura(String nombre) {
        this.nombre = nombre;
    } // figuese como puedo construir pq String nombre no es abstracto
}
    class Cuadrado extends figura {
        double lado;
        Cuadrado(String nombre, double lado) {
            super(nombre); // uso super ya que construi en la superclase
            this.lado = lado;
        }
        @Override
        double perimetro() {
            return lado*4
        }
        @Override
        double area() {
            return lado*lado
        }
    }

Figura cuadrado1 = new Cuadrado("cuadrado1", 10);
System.out.println("El perimetro es: " + cuadrado1.perimetro() + "\nEl area es: " + cuadrado1.area());
```

13) Interfaces: Lo contrario a una clase abstracta, aqui son métodos y atributos que quieres compartir entre distintas clases que no necesariamente están agrupadas o comparten herencia
    - Sigues lo mismo de abstracts, no puedes instanciarlas ni darles valor ni lógica en los métodos

-> por ejemplo

```java
    interface movibilidad {
        void mover();
    }

    class Perro implements movibilidad {
        @Override
        public void mover() {
            System.out.println("El perro se mueve");
        }
    }
    class Carro implements movibilidad {
        @Override 
        public void mover() {
            System.out.println("El carro se mueve");
        }
    }
```
es muy útil para reciclar comportamientos metodos atributos etc 