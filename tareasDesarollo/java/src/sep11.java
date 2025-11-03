//Elaborar un programa que permita leer un número e imprima una tabla con
// las potencias de los números desde 1 hasta el número leído. La potencia de 1 es 1 elevado a la potencia 1.
// La potencia de 2 es 2 elevado a la potencia 2, y así sucesivamente, hasta la potencia del número leído.
//Número Potencia
//
//────────────────────
//
//1            9999
//
//2            9999
//
//--
//
//8            9999

import java.util.Scanner;
public class sep11 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Introduce el número a calcular jeje");
        double numero = scanner.nextDouble();
        System.out.printf("Tabla de numeros elevados a si mismos hasta llegar a %.0f", numero);
        // ire sumando 1 el valor hasta llegar al limite q es el numero dado
        for (double i = 1; i <= numero; i++) {
            double potencia = Math.pow(i, i);
            //aqui nomas hago que se potencie a si mismo i, que es el que va subiendo de 1 en 1
            System.out.printf("\nNumero: %.0f Elevado a %.0f da: %.0f",  i, i, potencia);
        }
    }

}
