/* Elaborar un programa en Java que aplique programación orientada a 
objetos, para calcular el área de un triángulo. Se requiere imprimir como 
salida el área del triángulo. Los datos disponibles para leer como entrada
 son la base y la altura del triángulo. El área se calcula:

Área = base * altura / 2

Crear una clase para main y otra para el triángulo. Poner los datos y los métodos 
necesarios para establecer y obtener el resultado.  */

import java.util.Scanner;

class Triangulo { // hago la clase triangulo, con la base y altura privados para poder verificarlos primero con el metodo
    private double BaseTriangulo;
    private double AlturaTriangulo;
    public Triangulo(double base, double altura) { // hago un constructor de triangulo
        if (base > 0 && altura > 0) {
            BaseTriangulo = base;
            AlturaTriangulo = altura;
        } else {
            throw new IllegalArgumentException("Introduce un número mayor a 0"); // para evitar que siga el programa con valores incorrectos
        }
    }
    public double getArea() {
        return (BaseTriangulo*AlturaTriangulo) / 2; // mejor que guardar area en una variable
    }
}
public class nov_15 {
    public static void main(String[] args) {
        boolean repetir = true;
        Scanner sc = new Scanner(System.in); 
        do {
            System.out.println("Calculadora de áreas de triangulo\nIntroduce la base del triangulo: ");
            double baseInput = sc.nextDouble();
            sc.nextLine();
            System.out.println("Introduce la altura del triangulo: ");
            double alturaInput = sc.nextDouble();
            sc.nextLine();
            Triangulo trianguloUsuario = new Triangulo(baseInput, alturaInput); // creo el objeto trianguloUsuario
            System.out.println("El área del triangulo es: " + trianguloUsuario.getArea());
            System.out.println("Deseas repetir? s/n");
            String eleccion = sc.nextLine();
            if (eleccion.equalsIgnoreCase("n")) {
                repetir = false;
                System.out.println("Saliendo del programa..\n");
            } else {
                System.out.println("Repitiendo el programa..\n");
            }
    } while (repetir);
    sc.close();
    }
}
