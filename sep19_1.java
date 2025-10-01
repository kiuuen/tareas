// se paso de lanza la neta profe
// 1. Escribir los siguientes programas para practicar el uso de las sentencias
// si apropiadas para cada una de las siguientes condiciones:
//a) Si un ángulo es igual a 90 grados, imprimir el mensaje "El ángulo es un ángulo recto"sino imprimir el mensaje "El ángulo no es un ángulo recto".
//b) Si la temperatura es superior a 100 grados, visualizar el mensaje “por encima del punto de ebullición del agua” sino visualizar el mensaje “por debajo del punto de ebullición del agua”.
//c) Si el número es positivo, sumar el número a total de positivos, sino sumar al total de negativos.
//d) Si x es mayor que y, y z es menor que 20, leer un valor para p.
//e) Si distancia es mayor que 20 y menos que 35, leer un valor para tiempo.

import java.util.Scanner;
public class sep19_1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        boolean seguir = true;
        while (seguir) {
            System.out.println("que ejercicio quieres ver a/b/c/d/e (o escribe x para terminar)");
            String eleccion = scanner.nextLine();
            eleccion = eleccion.toLowerCase();
            if (eleccion.equals("a")) {
                System.out.println("detector de angulos rectos \n introduce los angulos del triangulo:");
                double angulo = scanner.nextDouble();
                if (angulo == 90) {
                    System.out.println("el triangulo efectivamente es recto, tiene 90 grados");
                } else {
                    System.out.println("este triangulo no es recto, no tiene 90 grados");
                }
                scanner.nextLine();
            }
            if (eleccion.equals("b")) {
                System.out.println("medidor de punto de ebullicion \n introduce los grados en celsius");
                double grado = scanner.nextDouble();
                if (grado >= 100) {
                    System.out.println("estas por encima del punto de ebullicion gg");
                }
                if (grado <= 99) {
                    System.out.println("aun no llegas al punto de ebullicion de 100 grados gg ez");
                }
                scanner.nextLine();
            }
            if (eleccion.equals("c")) {
                double totalpos = 0;
                double totalneg = 0;
                System.out.println("introduce un numero a agregar al total \n el total ahorita esta en = 0");
                double numero = scanner.nextDouble();
                if (numero > 0) {
                    totalpos = totalpos += numero;
                } else {
                    totalneg = totalneg += numero;
                }
                System.out.println("total positivos = " + totalpos + "  total negativos = " + totalneg);
                scanner.nextLine();
            }
            if (eleccion.equals("d")) {
                System.out.println("introduce el valor de x:");
                double x = scanner.nextDouble();
                System.out.println("introduce el valor de y:");
                double y = scanner.nextDouble();
                System.out.println("introduce el valor de z:");
                double z = scanner.nextDouble();
                if (x > y && z < 20) {
                    System.out.println("introduce p");
                    // no entendi que era leer un valor que operacion se hace
                }
                System.out.println("no se puede calcular p");
                scanner.nextLine();
            }
            if (eleccion.equals("e")) {
                System.out.println("introduce la distancia:");
                double distancia = scanner.nextDouble();
                if (distancia > 20 && distancia < 35) {
                    System.out.println("introduce el tiempo");
                }
                System.out.println("no se puede calcular el tiempo");
                scanner.nextLine();
            }
            if (eleccion.equals("x")) {
                seguir = false;
                System.out.println("programa terminado");
            }
        }
    }
}
// me complique de mas pero el if esta sencillo
